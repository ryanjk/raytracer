#include "GL\glut.h"
#include "RaytracerMath.h"
#include <iostream>
#include <conio.h>
#include "Image.h"
#include "OrthographicCamera.h"
#include "Raytracer.h"
#include "Scene.h"

extern int const WIDTH = 500;
extern int const HEIGHT = 500;

Image image(WIDTH, HEIGHT);

Vec3 viewpoint(0, 0, 0);
Vec3 direction(0, 0, 1);
Vec3 up(0, 1, 0);

OrthographicCamera camera(viewpoint, direction, up, 500, 500);
Scene scene;
Raytracer raytracer;

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
	raytracer.traceScene(scene, camera, image);
	
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