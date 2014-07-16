#include "GL\glut.h"
#include <iostream>
#include <conio.h>

const int WIDTH = 640;
const int HEIGHT = 480;

char image[HEIGHT][WIDTH][3];

void init_image()
{
	for (int i = 0; i < HEIGHT; ++i)
	{
		for (int j = 0; j < WIDTH; ++j)
		{
			image[i][j][0] = 0;
			image[i][j][1] = 0;
			image[i][j][2] = 0;
		}
	}
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glDrawPixels(WIDTH, HEIGHT, 
		GL_RGB,
		GL_UNSIGNED_BYTE, 
		image);

	glutSwapBuffers();
}

int main(int argc, char** argv)
{
	init_image();
	
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

	getch();
	return 0;
}