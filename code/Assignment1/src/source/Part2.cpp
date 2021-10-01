#include "loadShaders.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

//Settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

//Vertex Buffer Object (VBO)
unsigned int VBOs[4];

//Vertex Array Object (VAO)
unsigned int VAOs[4];

//Shader Program (shaderProgram)'s ID
unsigned int shaderGreen;
unsigned int shaderRed;
unsigned int shaderBlue;
unsigned int shaderCyan;

char change = 'a';

int nWidth, nHeight;
float ratio, ratio2;

void init(void)
{
	nWidth = SCR_WIDTH;
	nHeight = SCR_HEIGHT;
	ratio = (float)nHeight / (float)nWidth;

	//Return shaderProgram, which is used to set the shader program's ID
	//i.e., shaderProgram1 and shaderProgram2
	shaderGreen = loadShader("../../src/shader/triangles1.vert", "../../src/shader/green.frag");
	shaderRed = loadShader("../../src/shader/triangles1.vert", "../../src/shader/red.frag");
	shaderBlue = loadShader("../../src/shader/triangles1.vert", "../../src/shader/blue.frag");
	shaderCyan = loadShader("../../src/shader/triangles1.vert", "../../src/shader/cyan.frag");

	//Set up vertex data (and buffer(s)) and configure vertex attributes
	float firstTriangle[] = {
	    0.0f, 0.0f, 0.0f,   
		0.0f, 0.66f, 0.0f,
	    0.66f * ratio, 0.0f, 0.0f,
	};
	float secondTriangle[] = {
		0.0f, 0.0f, 0.0f,
		0.0f, -0.66f, 0.0f,
		0.66f * ratio, 0.0f, 0.0f,
	};
	float thirdTriangle[] = {
	    0.0f, 0.0f, 0.0f,
		0.0f, -0.66f, 0.0f,
		-0.66f * ratio, 0.0f, 0.0f,
	};
	float fourthTriangle[] = {
		0.0f, 0.0f, 0.0f,
		0.0f, 0.66f, 0.0f,
		-0.66f * ratio, 0.0f, 0.0f,
	};

	//We can also generate multiple VAOs and VBOs at the same time
	glGenVertexArrays(4, VAOs);
	glGenBuffers(4, VBOs);

	//First triangle setup
	glBindVertexArray(VAOs[0]);
	glBindBuffer(GL_ARRAY_BUFFER, VBOs[0]);
	//Document: https://www.khronos.org/registry/OpenGL-Refpages/gl4/html/glBufferData.xhtml
	glBufferData(GL_ARRAY_BUFFER, sizeof(firstTriangle), firstTriangle, GL_STATIC_DRAW);
	//Vertex attributes stay the same
	//Document: https://www.khronos.org/registry/OpenGL-Refpages/gl4/html/glVertexAttribPointer.xhtml
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	//The Second triangle setup
	glBindVertexArray(VAOs[1]);	//Note that we bind to a different VAO now
	glBindBuffer(GL_ARRAY_BUFFER, VBOs[1]);	//And a different VBO
	glBufferData(GL_ARRAY_BUFFER, sizeof(secondTriangle), secondTriangle, GL_STATIC_DRAW);

	//Because the vertex data is tightly packed
	//We can also specify 0 as the vertex attribute's stride to let OpenGL figure it out
	//glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
	//You can also use the stride: 3 * sizeof(float)
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	//third triangle
	glBindVertexArray(VAOs[2]);	//Note that we bind to a different VAO now
	glBindBuffer(GL_ARRAY_BUFFER, VBOs[2]);	//And a different VBO
	glBufferData(GL_ARRAY_BUFFER, sizeof(thirdTriangle), thirdTriangle, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	//third triangle
	glBindVertexArray(VAOs[3]);	//Note that we bind to a different VAO now
	glBindBuffer(GL_ARRAY_BUFFER, VBOs[3]);	//And a different VBO
	glBufferData(GL_ARRAY_BUFFER, sizeof(fourthTriangle), fourthTriangle, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	
	//Uncomment this call to draw in wireframe polygons.
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}

void display()
{
	//Render
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	//A pressed
	if (change == 'a')
	{
		glUseProgram(shaderBlue);
		glBindVertexArray(VAOs[0]);
		glDrawArrays(GL_TRIANGLES, 0, 3);

		glUseProgram(shaderCyan);
		glBindVertexArray(VAOs[1]);
		glDrawArrays(GL_TRIANGLES, 0, 3);

		glUseProgram(shaderRed);
		glBindVertexArray(VAOs[2]);
		glDrawArrays(GL_TRIANGLES, 0, 3);

		glUseProgram(shaderGreen);
		glBindVertexArray(VAOs[3]);
		glDrawArrays(GL_TRIANGLES, 0, 3);
	}
	else if (change == 'b')
	{
		glUseProgram(shaderCyan);
		glBindVertexArray(VAOs[0]);
		glDrawArrays(GL_TRIANGLES, 0, 3);

		glUseProgram(shaderRed);
		glBindVertexArray(VAOs[1]);
		glDrawArrays(GL_TRIANGLES, 0, 3);

		glUseProgram(shaderGreen);
		glBindVertexArray(VAOs[2]);
		glDrawArrays(GL_TRIANGLES, 0, 3);

		glUseProgram(shaderBlue);
		glBindVertexArray(VAOs[3]);
		glDrawArrays(GL_TRIANGLES, 0, 3);
	}
	else if (change == 'c')
	{
		glUseProgram(shaderRed);
		glBindVertexArray(VAOs[0]);
		glDrawArrays(GL_TRIANGLES, 0, 3);

		glUseProgram(shaderGreen);
		glBindVertexArray(VAOs[1]);
		glDrawArrays(GL_TRIANGLES, 0, 3);

		glUseProgram(shaderBlue);
		glBindVertexArray(VAOs[2]);
		glDrawArrays(GL_TRIANGLES, 0, 3);

		glUseProgram(shaderCyan);
		glBindVertexArray(VAOs[3]);
		glDrawArrays(GL_TRIANGLES, 0, 3);
	}
	else if (change == 'd')
	{
		glUseProgram(shaderGreen);
		glBindVertexArray(VAOs[0]);
		glDrawArrays(GL_TRIANGLES, 0, 3);

		glUseProgram(shaderBlue);
		glBindVertexArray(VAOs[1]);
		glDrawArrays(GL_TRIANGLES, 0, 3);

		glUseProgram(shaderCyan);
		glBindVertexArray(VAOs[2]);
		glDrawArrays(GL_TRIANGLES, 0, 3);

		glUseProgram(shaderRed);
		glBindVertexArray(VAOs[3]);
		glDrawArrays(GL_TRIANGLES, 0, 3);
	}
}

int main()
{
	//glfw: initialize and configure
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//glfw window creation
	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Assignment 01: Q2 Zack Hardee, Ben Abrams, Griffin Megeff", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	//glad: load all OpenGL function pointers
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	init();

	//Render loop
	while (!glfwWindowShouldClose(window))
	{
		//Input
		processInput(window);

		display();

		//glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	//Optional: de-allocate all resources once they've outlived their purpose:
	glDeleteVertexArrays(4, VAOs);
	glDeleteBuffers(4, VBOs);

	//glfw: terminate, clearing all previously allocated GLFW resources.
	glfwTerminate();
	return 0;
}

//Process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
void processInput(GLFWwindow *window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
	}
	else if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
	{
		change = 'a';
	}
	else if (glfwGetKey(window, GLFW_KEY_B) == GLFW_PRESS)
	{
		change = 'b';
	}
	else if (glfwGetKey(window, GLFW_KEY_C) == GLFW_PRESS)
	{
		change = 'c';
	}
	else if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
	{
		change = 'd';
	}
}

//glfw: whenever the window size changed (by OS or user resize) this callback function executes
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	//Make sure the viewport matches the new window dimensions; note that width and 
	//height will be significantly larger than specified on retina displays.
	glViewport(0, 0, width, height);

	ratio = (float)height / (float)width;

	float firstTriangle[] = {
		0.0f, 0.0f, 0.0f,
		0.0f, 0.66f, 0.0f,
		0.66f * ratio , 0.0f, 0.0f,
	};
	float secondTriangle[] = {
		0.0f, 0.0f, 0.0f,
		0.0f, -0.66f, 0.0f,
		0.66f * ratio, 0.0f, 0.0f,
	};
	float thirdTriangle[] = {
		0.0f, 0.0f, 0.0f,
		0.0f, -0.66f, 0.0f,
		-0.66f * ratio, 0.0f, 0.0f,
	};
	float fourthTriangle[] = {
		0.0f, 0.0f, 0.0f,
		0.0f, 0.66f, 0.0f,
		-0.66f * ratio, 0.0f, 0.0f,
	};


	//First triangle setup
	glBindVertexArray(VAOs[0]);
	glBindBuffer(GL_ARRAY_BUFFER, VBOs[0]);
	//Document: https://www.khronos.org/registry/OpenGL-Refpages/gl4/html/glBufferData.xhtml
	glBufferData(GL_ARRAY_BUFFER, sizeof(firstTriangle), firstTriangle, GL_STATIC_DRAW);
	//Vertex attributes stay the same
	//Document: https://www.khronos.org/registry/OpenGL-Refpages/gl4/html/glVertexAttribPointer.xhtml
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	//The Second triangle setup
	glBindVertexArray(VAOs[1]);	//Note that we bind to a different VAO now
	glBindBuffer(GL_ARRAY_BUFFER, VBOs[1]);	//And a different VBO
	glBufferData(GL_ARRAY_BUFFER, sizeof(secondTriangle), secondTriangle, GL_STATIC_DRAW);

	//Because the vertex data is tightly packed
	//We can also specify 0 as the vertex attribute's stride to let OpenGL figure it out
	//glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
	//You can also use the stride: 3 * sizeof(float)
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	//third triangle
	glBindVertexArray(VAOs[2]);	//Note that we bind to a different VAO now
	glBindBuffer(GL_ARRAY_BUFFER, VBOs[2]);	//And a different VBO
	glBufferData(GL_ARRAY_BUFFER, sizeof(thirdTriangle), thirdTriangle, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	//third triangle
	glBindVertexArray(VAOs[3]);	//Note that we bind to a different VAO now
	glBindBuffer(GL_ARRAY_BUFFER, VBOs[3]);	//And a different VBO
	glBufferData(GL_ARRAY_BUFFER, sizeof(fourthTriangle), fourthTriangle, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
}

