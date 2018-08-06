#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec4 aCol;

out vec4 vertexColor;

uniform vec2 transform;

void main()
{
    gl_Position = vec4(aPos.x + transform.x, aPos.y + transform.y, aPos.z, 1.0);
    vertexColor = aCol;
}
