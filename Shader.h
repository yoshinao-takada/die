#ifndef SHADER_H_
#define SHADER_H_
#include    <GL/glew.h>
#ifdef __cplusplus
extern "C" {
#endif
    typedef struct {
        GLuint program;
    } Shader_t, *pShader_t;
    typedef const Shader_t *pcShader_t;

    /*!
    \brief initialize a shader program object with a vertex shader and a fragment shader
    \param shader [out] target object to initialize
    \param srcv [in] source program text of a vertex shader
    \param srcf [in] source program text of a fragment shader
    \return error code
    */
    int Shader_init(pShader_t shader, const GLchar* srcv, const GLchar* srcf);

    /*!
    \brief set the shader in use.
    */
    void Shader_use(pcShader_t shader);
#ifdef __cplusplus
}
#endif
#endif