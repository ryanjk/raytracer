#include "GL\glut.h"
#include "RaytracerMath.h"
#include <iostream>
#include <conio.h>
#include "Image.h"

const int WIDTH = 640;
const int HEIGHT = 480;

Image image(WIDTH, HEIGHT);

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glDrawPixels(WIDTH, HEIGHT, 
		GL_RGB,
		GL_UNSIGNED_BYTE, 
		image.getImage());

	glutSwapBuffers();
}

int main(int argc, char** argv)
{
	// Initialize glut
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glEnable(GL_DEPTH_TEST);
	glClearColor(0.0, 0.0, 0.0, 1.0);

	// Set up display window
	glutInitWindowSize(WIDTH, HEIGHT);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("Display");
	glutDisplayFunc(display);

	glutMainLoop();

	return 0;
}