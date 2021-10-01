#  include <GL/glew.h>
#  include <GL/freeglut.h>
#  include <GL/freeglut_ext.h>

using namespace std;

GLuint InitShader(const char* vertexShaderFile, const char* fragmentShaderFile);

GLuint vertexbuffer;
GLuint programID;

#define BUFFER_OFFSET(bytes) ((GLvoid*) (bytes))

void init(void)
{
	// Dark blue background
	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

	static const GLfloat g_vertex_buffer_data[] = {
		-0.8f, -0.8f, 0.0f,
		 0.5f, -0.5f, 0.0f,
		 0.0f,  0.5f, 0.1f,
	};

	GLuint VertexArrayID;
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);

	//GLuint vertexbuffer;
	glGenBuffers(1, &vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data),
		g_vertex_buffer_data, GL_STATIC_DRAW);

	// Load shaders and use the resulting shader program
	programID = InitShader("../../src/shader/vshader01.glsl",
		"../../src/shader/fshader01.glsl");

	// Use our shader
	glUseProgram(programID);

	// attribute buffer : vertices
	GLuint loc;
	loc = glGetAttribLocation(programID, "vPosition");
	glEnableVertexAttribArray(loc);
	glVertexAttribPointer(
		0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
		3,                  // size
		GL_FLOAT,           // type
		GL_FALSE,           // normalized?
		0,                  // stride
		BUFFER_OFFSET(0)    // array buffer offset
	);	
}

void mydisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	// Draw the triangle !
	glDrawArrays(GL_TRIANGLES, 0, 3); // 3 indices starting at 0 -> 1 triangle

	glFlush();
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case 033:
		exit(EXIT_SUCCESS);
		break;
	}
}

int main(int argc, char **argv)
{

	FreeConsole();
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(512, 512);
	glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH) - 640) / 2,
							(glutGet(GLUT_SCREEN_HEIGHT) - 480) / 2);
	glutInitContextVersion(3, 2);
	glutInitContextProfile(GLUT_CORE_PROFILE);
	glutCreateWindow("A Simple GLSL example");

	glewInit();
	init();

	glutDisplayFunc(mydisplay);
	glutKeyboardFunc(keyboard);
	glutMainLoop();

	return 0;
}
