#ifndef SHADERDEFS_H_
#define SHADERDEFS_H_

#define VERTEX_SHADER_SRC_DEF   \
"#version 330 core\n" \
"layout (location = 0) in vec3 position;" \
"layout (location = 1) in vec3 color;" \
"layout (location = 2) in vec2 texCoord;" \
"out vec3 ourColor;" \
"out vec2 TexCoord;" \
"void main() {" \
"   gl_Position = vec4(position, 1.0f);" \
"   ourColor = color;" \
"   TexCoord = vec2(texCoord.x, 1.0 - texCoord.y);" \
"}\0"

#define VERTEX_ROTATING_SHADER_SRC_DEF   \
"#version 330 core\n" \
"layout (location = 0) in vec3 position;" \
"layout (location = 1) in vec3 color;" \
"layout (location = 2) in vec2 texCoord;" \
"out vec3 ourColor;" \
"out vec2 TexCoord;" \
"uniform mat4 transform;" \
"void main() {" \
"   gl_Position = transform * vec4(position, 1.0f);" \
"   ourColor = color;" \
"   TexCoord = vec2(texCoord.x, 1.0 - texCoord.y);" \
"}\0"

#define VERTEX_POSITIONING_SHADER_SRC_DEF   \
"#version 330 core\n" \
"layout (location = 0) in vec3 position;" \
"layout (location = 1) in vec2 texCoord;" \
"out vec3 ourColor;" \
"out vec2 TexCoord;" \
"uniform mat4 model;" \
"uniform mat4 view;" \
"uniform mat4 projection;" \
"void main() {" \
"   gl_Position = projection * view * model * vec4(position, 1.0f);" \
"   TexCoord = vec2(texCoord.x, 1.0 - texCoord.y);" \
"}\0"

#define FRAGMENT_SHADER_SRC_DEF \
"#version 330 core\n" \
"in vec3 ourColor;" \
"in vec2 TexCoord;" \
"out vec4 color;" \
"uniform sampler2D ourTexture1;" \
"void main() {" \
"   color = texture(ourTexture1, TexCoord);" \
"}\0"

//"   color = texture(ourTexture1, TexCoord);" \
//"   color = vec4(ourColor, 1.0f);" \

#endif /* SHADERDEFS_H_ */
