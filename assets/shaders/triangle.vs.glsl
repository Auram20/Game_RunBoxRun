# version 330 core

layout(location = 0) in vec3 aVertexPosition;
layout(location = 1) in vec3 aVertexNormal;
layout(location = 2) in vec2 aVertexTexCoords;

out vec3 vColor;

void main() {
    vColor = vec3(1.f, 0.f, 0.f);
    gl_Position = vec4(aVertexPosition, 1);
}
