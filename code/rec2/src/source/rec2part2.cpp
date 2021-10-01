#include "loadShaders.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

//Settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

//Vertex Buffer Object (VBO)
unsigned int VBOs[3];

//Vertex Array Object (VAO)
unsigned int VAOs[3];

//Element Buffer Object (EBO)
unsigned int EBO[2];

//Shader Program (shaderProgram)'s ID
unsigned int shaderProgramOrange;
unsigned int shaderProgramYellow;
unsigned int shaderProgramBlue;

void init(void)
{
	//Build and compile the shader program
	// ------------------------------------
	//Here we skipped compile log checks this time for readability (if you do encounter issues, add the compile-checks! see previous code samples)
	unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
	unsigned int fragmentShaderOrange = glCreateShader(GL_FRAGMENT_SHADER); // the first fragment shader that outputs the color orange
	unsigned int fragmentShaderYellow = glCreateShader(GL_FRAGMENT_SHADER); // the second fragment shader that outputs the color yellow
	unsigned int fragmentShaderBlue = glCreateShader(GL_FRAGMENT_SHADER);//the third shader

	shaderProgramOrange = glCreateProgram(); //The first shader program
	shaderProgramYellow = glCreateProgram(); //The second shader program
	shaderProgramBlue = glCreateProgram();

	//Return shaderProgram, which is used to set the shader program's ID
	//i.e., shaderProgramOrange and shaderProgramYellow
	shaderProgramOrange = loadShader("../../src/shader/vshaderTwoShaders.glsl", "../../src/shader/fshaderTwoShaders4.glsl");
	shaderProgramYellow = loadShader("../../src/shader/vshaderTwoShaders.glsl", "../../src/shader/fshaderTwoShaders5.glsl");
	shaderProgramBlue = loadShader("../../src/shader/vshaderTwoShaders.glsl", "../../src/shader/fshaderTwoShaders3.glsl");

	//Set up vertex data (and buffer(s)) and configure vertex attributes
	float vertices[] = {
			 0.5f,  0.5f, 0.0f,  //top right
			 0.5f, -0.5f, 0.0f,  //bottom right
			0.0f, -0.5f, 0.0f,  //bottom left
			0.0f,  0.5f, 0.0f   //top left 
	};
	unsigned int indices[] = {  //note that we start from 0!
		0, 1, 3,  //first Triangle
		1, 2, 3   //second Triangle
	};

	float secondVertices[] = {
		0.0f, 0.5f, 0.0f,	//top right
		0.0f, -0.5f, 0.0f,	//bottom right
		-0.5f, -0.5f, 0.0f, //bottom left
		-0.5f, 0.5f, 0.0f	//top left
	};
	unsigned int secondIndices[] = {
		0, 1, 3,
		1, 2, 3
	};

	float triangle[] = {
		-0.5f, 0.5f, 0.0f, //top right
		-0.9f, 0.0f, 0.0f, //middle
		-0.5f, -0.5f, 0.0f //bottom right
	};

	glGenVertexArrays(3, VAOs);
	glGenBuffers(3, VBOs);
	glGenBuffers(2, EBO);

	//Bind the Vertex Array Object first, 
	//then bind and set vertex buffer(s), and then configure vertex attributes(s).
	glBindVertexArray(VAOs[0]);

	//Copy our vertices array in a buffer for OpenGL to use
	glBindBuffer(GL_ARRAY_BUFFER, VBOs[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	//Copy our index array in a element buffer for OpenGL to use
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO[0]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	//Then set the vertex attributes pointers
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	//Use the shader program when we want to render an object
	glUseProgram(shaderProgramBlue);

	glBindVertexArray(0);

	glBindVertexArray(VAOs[1]);

	//Copy our vertices array in a buffer for OpenGL to use
	glBindBuffer(GL_ARRAY_BUFFER, VBOs[1]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(secondVertices), secondVertices, GL_STATIC_DRAW);

	//Copy our index array in a element buffer for OpenGL to use
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO[1]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(secondIndices), secondIndices, GL_STATIC_DRAW);

	//Then set the vertex attributes pointers
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	//Use the shader program when we want to render an object
	glUseProgram(shaderProgramYellow);

	//Note that this is allowed, the call to glVertexAttribPointer registered VBO as 
	//the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	//The Second triangle setup
	glBindVertexArray(VAOs[2]);	//Note that we bind to a different VAO now
	glBindBuffer(GL_ARRAY_BUFFER, VBOs[2]);	//And a different VBO
	glBufferData(GL_ARRAY_BUFFER, sizeof(triangle), triangle, GL_STATIC_DRAW);
	//Because the vertex data is tightly packed
	//We can also specify 0 as the vertex attribute's stride to let OpenGL figure it out
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
	glEnableVertexAttribArray(0);
	//You can unbind the VAO afterwards, so other VAO calls won't accidentally modify this VAO, 
	//but this rarely happens. Modifying other VAOs requires a call to glBindVertexArray anyways 
	//So we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
	glBindVertexArray(0);

	//Uncomment this call to draw in wireframe polygons.
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}

void display()
{
	//Render
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	//When we draw the triangle we first use the vertex and orange fragment shader from the first program
	glUseProgram(shaderProgramOrange);
	//Draw the first triangle using the data from our first VAO
	glBindVertexArray(VAOs[0]);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0); //This call should output an orange triangle

	//Then we draw the second triangle using the data from the second VAO
	//When we draw the second triangle we want to use a different shader program so we switch 
	//to the shader program with our yellow fragment shader.
	glUseProgram(shaderProgramYellow);
	glBindVertexArray(VAOs[1]);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0); //This call should output an orange triangle

	glUseProgram(shaderProgramYellow);
	glBindVertexArray(VAOs[2]);
	glDrawArrays(GL_TRIANGLES, 0, 3); //This call should output a blue triangle	

	//No need to unbind it every time 
	glBindVertexArray(0);
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
	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Recitation 2 Question 2 (Ben Abrams)", NULL, NULL);
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

