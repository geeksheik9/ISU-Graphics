#version 430 core

out vec4 FragColor;

in vec3 ourColor;
in vec2 TexCoord;

// texture sampler
uniform sampler2D ourTexture1;

void main()
{
	FragColor = texture(ourTexture1, TexCoord) * vec4(ourColor, 1.0);  
}

