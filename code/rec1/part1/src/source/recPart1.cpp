#include<GL/glut.h>
#include<GL/gl.h>
#include<GL/glu.h>

void myRender() {
	//set display window's background color 
	glClearColor(0.0, 0.0, 0.0, 0.0);
	//clears our buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//perform any other matrix transformations here

	
	glBegin(GL_LINE_STRIP);
		// COLOR: Yellow
		glColor3f(1.0f, 1.0f, 0.0f);

		glVertex2f(-0.50f, 0.0f);
		glVertex2f(0.50f, 0.0f);
		glVertex2f(0.36f, 0.25f);
		glVertex2f(-0.36f, 0.25f);
		glVertex2f(-0.50f, 0.0f);
		glVertex2f(0.0f, -0.80f);
		glVertex2f(0.50f, 0.0f);
		glVertex2f(0.0f, 0.0f);
		glVertex2f(0.0f, -0.80f);
		glVertex2f(0.25f, 0.0f);
		glVertex2f(-0.25f, 0.0f);
		glVertex2f(0.0f, -0.80f);
		glVertex2f(-0.25f, 0.0f);
		glVertex2f(-0.36f, 0.25f);
		glVertex2f(-0.25f, 0.0f);
		glVertex2f(-0.12f, 0.25f);
		glVertex2f(0.0f, 0.0f);
		glVertex2f(0.12f, 0.25f);
		glVertex2f(0.25f, 0.0f);
		glVertex2f(0.36f, 0.25f);

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