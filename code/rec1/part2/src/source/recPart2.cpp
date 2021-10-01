#include<GL/glut.h>
#include<GL/gl.h>
#include<GL/glu.h>

void myRender() {
	//set display window's background color 
	glClearColor(0.0, 0.0, 0.0, 0.0);
	//clears our buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//perform any other matrix transformations here

	// Each set of 3 vertices form a triangle
	glBegin(GL_TRIANGLES);
	//cyan middle
	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex2f(-0.15f, 0.00f);
	glVertex2f(0.0f, 0.25f);
	glVertex2f(0.15f, 0.00f);

	//cyan left1
	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex2f(-0.01f, 0.25f);
	glVertex2f(-0.16f, 0.0f);
	glVertex2f(-0.31f, 0.25f);

	//cyan left2
	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex2f(-0.17f, 0.0f);
	glVertex2f(-0.32f, 0.25f);
	glVertex2f(-0.47f, 0.0f);

	//cyan right1
	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex2f(0.01f, 0.25f);
	glVertex2f(0.16f, 0.0f);
	glVertex2f(0.31f, 0.25f);

	//cyan right2
	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex2f(0.17f, 0.0f);
	glVertex2f(0.32f, 0.25f);
	glVertex2f(0.47f, 0.0f);

	//gradient bottom middle
	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex2f(-0.16f, -0.01f);
	glVertex2f(0.16f, -0.01f);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(0.0f, -0.80f);

	//gradient bottom left
	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex2f(-0.17f, -0.01f);
	glVertex2f(-0.47f, -0.01f);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(-0.01f, -0.80f);

	//gradient bottom right
	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex2f(0.17f, -0.01f);
	glVertex2f(0.47f, -0.01f);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(0.01f, -0.80f);



	glEnd();

	//ensures our objects are drawn right away
	glFlush();

	//if we are using double buffering
	glutSwapBuffers();
}

int main(int argc, char ** argv)
{
	glutInit(&argc, argv); //process arguments

	FreeConsole();

	//Initialize buffers
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);

	//Sets some initial stuff
	glutInitWindowPosition(400, 200);
	glutInitWindowSize(640, 480);

	//Creates window
	static int window = glutCreateWindow("Ben Abrams Recitation 1");

	//Display callback function, etc. myRender()
	glutDisplayFunc(myRender);

	//Enters main processing loop
	glutMainLoop();

	exit(0);
}