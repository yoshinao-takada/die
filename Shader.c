#include    "Shader.h"
#include    <stdlib.h>
#include    <stdio.h>
#include    <string.h>

const char* Shader_type_namestring(GLenum shader_type)
{
    if (shader_type == GL_VERTEX_SHADER)
    {
        return "VERTEX_SHADER";
    }
    else if (shader_type == GL_FRAGMENT_SHADER)
    {
        return "FRAGMENT_SHADER";
    }
    else
    {
        return "UNKNOWN_SHADER_TYPE";
    }
}

int Shader_compile(GLuint* compiled_object, GLenum shader_type, const GLchar* source_program)
{
    int err = EXIT_SUCCESS;
    GLint success;
    GLchar err_info_buffer[512];
    do {
        *compiled_object = glCreateShader(shader_type);
        glShaderSource(*compiled_object, 1, &source_program, NULL);
        glCompileShader(*compiled_object);
        glGetShaderiv(*compiled_object, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(*compiled_object, sizeof(err_info_buffer), NULL, err_info_buffer);
            fprintf(stderr, "ERROR::%s::COMPILATION_FAILURE\n", Shader_type_namestring(shader_type));
            fprintf(stderr, "%s\n", err_info_buffer);
            err = EXIT_FAILURE;
        }
    } while (0);
    return err;
}

int Shader_link(GLuint* linked_program, GLuint vertex_shader, GLuint fragment_shader)
{
    int err = EXIT_SUCCESS;
    GLint success;
    GLchar err_info_buffer[512];
    do {
        *linked_program = glCreateProgram();
        glAttachShader(*linked_program, vertex_shader);
        glAttachShader(*linked_program, fragment_shader);
        glLinkProgram(*linked_program);
        glGetShaderiv(*linked_program, GL_LINK_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(*linked_program, sizeof(err_info_buffer), NULL, err_info_buffer);
            fprintf(stderr, "ERROR::SHADER::LINKING_FAILURE\n");
            fprintf(stderr, "%s\n", err_info_buffer);
            err = EXIT_FAILURE;
        }
    } while (0);
    return err;
}

int Shader_init(pShader_t shader, const GLchar* srcv, const GLchar* srcf)
{
    int err = EXIT_SUCCESS;
    GLuint vertex_shader, fragment_shader;
    do {
        if (EXIT_SUCCESS != (err = Shader_compile(&vertex_shader, GL_VERTEX_SHADER, srcv)))
        {
            break;
        }
        if (EXIT_SUCCESS != (err = Shader_compile(&fragment_shader, GL_FRAGMENT_SHADER, srcf)))
        {
            break;
        }
        if (EXIT_SUCCESS != (err = Shader_link(&shader->program, vertex_shader, fragment_shader)))
        {
            break;
        }
    } while (0);
    glDeleteShader(vertex_shader);
    glDeleteShader(fragment_shader);
    return err;
}

void Shader_use(pcShader_t shader)
{
    glUseProgram(shader->program);
}
