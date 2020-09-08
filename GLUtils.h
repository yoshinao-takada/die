#ifndef GLUTILS_H_
#define GLUTILS_H_
#include    <GL/glew.h>
#include    <GLFW/glfw3.h>
#ifdef __cplusplus
extern "C" {
#endif
/*!
\brief clear OpenGL API errors
*/
void GLClearError();

/*!
\brief retrieving stored errors generating by preceding OpenGL API calls.
And print the function name and the source line number as a side effect.
\param at_the_function [in] the function name calling the OpenGL APIs under investigation
\param at_the_line [in] the source line just after OpenGL API calls under investigation
\return EXIT_SUCCESS : no error, EXIT_FAILURE : error
*/
int GLErrorHandler(const char* at_the_function, int at_the_line);

/*!
\brief initialize a GLFW window as a single window application
\param ppwindow [out] pointer-pointer to GLFWwindow object
\param window_width [in]
\param window_height [in] 
\param window_caption [in]
\return EXIT_SUCCESS : no error, EXIT_FAILURE : error
*/
int InitGLFWWindow(GLFWwindow* *ppwindow, GLuint window_width, GLuint window_height, const GLchar* window_caption);

#ifdef __cplusplus
}
#endif
#endif /* GLUTILS_H_ */
