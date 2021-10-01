#version 450 core

out vec4 FragColor;
uniform float timeVal;

void main()
{
    FragColor = vec4(abs(sin(timeVal)) - 0.17, 0.75, 0.0, 1.0);
}
