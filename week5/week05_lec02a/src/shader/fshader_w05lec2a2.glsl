#version 430 core

out vec4 FragColor;
  
//we set this variable in the OpenGL code.
uniform vec4 ourColor; 

void main()
{
    FragColor = ourColor;
}  
