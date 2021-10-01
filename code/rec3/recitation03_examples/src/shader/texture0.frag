#version 430 core
out vec4 FragColor;

in vec3 ourColor;
in vec2 TexCoord;

// texture samplers
uniform sampler2D texture1;

void main()
{
	//FragColor = texture(texture1, TexCoord);
	FragColor = texture(texture1, TexCoord) * vec4(0.0, ourColor.x, ourColor.z, 1.0);  
}

