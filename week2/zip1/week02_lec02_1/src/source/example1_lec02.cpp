#include<GL/glut.h>
#include<GL/gl.h>
#include<GL/glu.h>

void myRender(){
	//set display window's background color 
	glClearColor(0.0, 0.0, 0.0, 0.0); 
	//clears our buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//perform any other matrix transformations here

	//DRAW OBJECTS HERE!
	glBegin(GL_QUADS);
		glColor3f(1.0, 0.0, 1.0);//sets color to blue 
		glVertex2f(-0.5, -0.5);
		glVertex2f(-0.5, 0.5);
		glVertex2f(0.5, 0.5);
		glVertex2f(0.5, -0.5);
	glEnd();

	//ensures our objects are drawn right away
	glFlush(); 

	//if we are using double buffering
	glutSwapBuffers(); 
}

int main(int argc, char ** argv )
{
	glutInit(&argc, argv); //process arguments

	//Initialize buffers
	glutInitDisplayMode( GLUT_RGBA | GLUT_DOUBLE ); 
	
	//Sets some initial stuff
	glutInitWindowPosition(400, 200 ); 
	glutInitWindowSize(500, 500);

	//Creates window
	static int window = glutCreateWindow( "Welcome, OpenGL!"); 

	//Display callback function, etc. myRender()
	glutDisplayFunc(myRender);

	//Enters main processing loop
	glutMainLoop(); 

	exit(0);
}