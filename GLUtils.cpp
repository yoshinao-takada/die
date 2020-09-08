#include    "GLUtils.h"
#include    <map>
#include    <cstdlib>
#include    <cstdio>

static const char* GLEnumErrorString(GLenum errcode)
{
    static const std::map<GLenum,const char*> table = {
        { GL_NO_ERROR, "no error"},
        { GL_INVALID_ENUM, "invalid enum"},
        { GL_INVALID_VALUE, "invalid value"},
        { GL_INVALID_OPERATION, "invalid operation"},
        { GL_INVALID_FRAMEBUFFER_OPERATION, "invalid framebuffer operation"},
        { GL_OUT_OF_MEMORY, "out of memory"},
        { GL_STACK_UNDERFLOW, "stack underflow"},
        { GL_STACK_OVERFLOW, "stack overflow"}
    };
    std::map<GLenum, const char*>::const_iterator found_item = table.find(errcode);
    if (found_item == table.end())
    {
        return "no-item-found: invalid errcode";
    }
    return found_item->second;
}

void GLClearError()
{
    while (GL_NO_ERROR != glGetError())
    {
        ;
    }
}

int GLErrorHandler(const char* at_the_function, int at_the_line)
{
    int err = EXIT_SUCCESS;
    do {
        GLenum errcode;;
        while (GL_NO_ERROR != (errcode = glGetError()))
        {
            if (err == EXIT_SUCCESS)
            {
                err = EXIT_FAILURE;
                fprintf(stderr, "glGetError() detected errors at line %d, function %s\n", at_the_line, at_the_function);
            }
            fprintf(stderr, "%s\n", GLEnumErrorString(errcode));
        }
    } while (0);
    return err;
}


static int InitGLEW()
{
    int err = EXIT_SUCCESS;
    glewExperimental = GL_TRUE;
    if (GLEW_OK != glewInit())
    {
        fprintf(stderr, "glewInit() failed\n");
        err = EXIT_FAILURE;
    }
    return err;
}


static void SetViewport(GLFWwindow* window)
{
    GLint width, height;
    glfwGetFramebufferSize(window, &width, &height);
    glfwMakeContextCurrent(window);
    glViewport(0,0,(GLsizei)width,(GLsizei)height);
}

int InitGLFWWindow(GLFWwindow* *ppwindow, GLuint window_width, GLuint window_height, const GLchar* window_caption)
{
    int err = EXIT_SUCCESS;
    do {
        if (!glfwInit())
        {
            fprintf(stderr, "glfwInit() failed\n");
            err = EXIT_FAILURE;
            break;
        }
        // glfw3 required options
        glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 3 );
        glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 3 );
        glfwWindowHint( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE );
        glfwWindowHint( GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE );
        glfwWindowHint( GLFW_RESIZABLE, GL_FALSE );
        // create a window object
        *ppwindow = glfwCreateWindow(window_width, window_height, window_caption, nullptr, nullptr);
        if (*ppwindow == nullptr)
        {
            fprintf(stderr, "glfwCreateWindow() failed\n");
            glfwTerminate();
            err = EXIT_FAILURE;
        }
        glfwMakeContextCurrent(*ppwindow);
        if (EXIT_SUCCESS != (err = InitGLEW()))
        {
            break;
        }

        SetViewport(*ppwindow);
    } while (0);
    return err;
}
