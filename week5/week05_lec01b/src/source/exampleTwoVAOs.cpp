#include "loadShaders.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

//Settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;
	
//Vertex Buffer Object (VBO)
unsigned int VBOs[2];

//Vertex Array Object (VAO)
unsigned int VAOs[2];

//Shader Program (shaderProgram)'s ID
unsigned int shaderProgram;

void init(void)
{
	//Return shaderProgram, which is used to set the Shader Program (shaderProgram)'s ID
	shaderProgram = loadShader("../../src/shader/vshaderTwoVAOs.glsl", "../../src/shader/fshaderTwoVAOs.glsl");

	//Set up vertex data (and buffer(s)) and configure vertex attributes
    float firstTriangle[] = {
        -0.9f, -0.5f, 0.0f,  //left 
        -0.0f, -0.5f, 0.0f,  //right
        -0.45f, 0.5f, 0.0f,  //top 
    };
    float secondTriangle[] = {
        0.0f, -0.5f, 0.0f,  //left
        0.9f, -0.5f, 0.0f,  //right
        0.45f, 0.5f, 0.0f   //top 
    };

	//We can also generate multiple VAOs or buffers at the same time
	glGenVertexArrays(2, VAOs);
	glGenBuffers(2, VBOs);

    //First triangle setup
    glBindVertexArray(VAOs[0]);
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(firstTriangle), firstTriangle, GL_STATIC_DRAW);
	//Vertex attributes stay the same
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);	
    glEnableVertexAttribArray(0);
    
	//The Second triangle setup
    glBindVertexArray(VAOs[1]);	//We bind to a different VAO now
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[1]);	//And a different VBO
    glBufferData(GL_ARRAY_BUFFER, sizeof(secondTriangle), secondTriangle, GL_STATIC_DRAW);
	//Because the vertex data is tightly packed, we can also specify 0 as 
	//the vertex attribute's stride to let OpenGL figure it out
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0); 
    glEnableVertexAttribArray(0);

	//Uncomment this call to draw in wireframe polygons.
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}

void display()
{
	//Render
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	
	glUseProgram(shaderProgram);

	//Draw the first triangle using the data from the first Vertex Array Object (VAO)
    glBindVertexArray(VAOs[0]);
    glDrawArrays(GL_TRIANGLES, 0, 3);
	//No need to unbind at all as we directly bind a different VAO the next few lines
    //glBindVertexArray(0); 	
    
    //then we draw the second triangle using the data from the second VAO
    glBindVertexArray(VAOs[1]);
    glDrawArrays(GL_TRIANGLES, 0, 3);

	//No need to unbind it every time 
	//glBindVertexArray(0); 
}

int main()
{
	FreeConsole();
	//glfw: initialize and configure
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//glfw window creation
	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Draw A Triangle Using Shaders", NULL, NULL);
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
	glDeleteVertexArrays(2, VAOs);
	glDeleteBuffers(2, VBOs);

	//glfw: terminate, clearing all previously allocated GLFW resources.
	glfwTerminate();
	return 0;
}

//Process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
void processInput(GLFWwindow *window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}

//glfw: whenever the window size changed (by OS or user resize) this callback function executes
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	//Make sure the viewport matches the new window dimensions; note that width and 
	//height will be significantly larger than specified on retina displays.
	glViewport(0, 0, width, height);
}

