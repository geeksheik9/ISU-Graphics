#version 430 core
out vec4 FragColor;

in vec3 FragPos;  
  
uniform vec3 lightColor;
uniform vec3 objectColor;

void main()
{
    // ambient
    float ambientStrength = 0.2;
    vec3 ambient = ambientStrength * lightColor;

    vec3 result = ambient  * objectColor;
    FragColor = vec4(result, 1.0);
} 
  	
