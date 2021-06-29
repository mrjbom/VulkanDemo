#version 450

layout(binding = 0) uniform MVP_matrixes {
    mat4 model;
    mat4 view;
    mat4 projection;
} MVP_matrixes_ubo;

layout(location = 0) in vec3 inPosition;
layout(location = 1) in vec3 inColor;
layout(location = 2) in vec3 inTexCoord;

layout(location = 0) out vec3 fragColor;
layout(location = 1) out vec3 texCoord;

void main()
{
    gl_Position = MVP_matrixes_ubo.projection * MVP_matrixes_ubo.view * MVP_matrixes_ubo.model * vec4(inPosition, 1.0);
    fragColor = inColor;
    texCoord = inTexCoord;
}
