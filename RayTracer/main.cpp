#include "GL\glut.h"
#include "RaytracerMath.h"
#include <iostream>
#include <ctime>
#include <conio.h>
#include "Image.h"
#include "OrthographicCamera.h"
#include "PerspectiveCamera.h"
#include "Raytracer.h"
#include "Scene.h"
#include "Sphere.h"
#include "Triangle.h"
#include "ObjectProperties.h"
#include "RaytracerShapeHeader.h"
#include "PointLight.h"

extern int const WIDTH = 240;
extern int const HEIGHT = 160;

const double CAMERA_WIDTH = 30;
const double CAMERA_HEIGHT = 20;

Image image(WIDTH, HEIGHT);

Vec3 viewpoint(0, 7, 1);
Vec3 direction(0, 0, 1);
Vec3 up(0, 1, 0);
OrthographicCamera camera(viewpoint, direction, up, CAMERA_WIDTH, CAMERA_HEIGHT);
PerspectiveCamera p_camera(viewpoint, direction, up, CAMERA_WIDTH, CAMERA_HEIGHT, 20);

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
	ObjectProperties *redSphereProperties = new ObjectProperties();
	redSphereProperties->setColour({ 255, 0, 0 });
	Sphere *redSphere = new Sphere(Vec3(-5, 0, 10), 3, redSphereProperties);

	ObjectProperties *greenSphereProperties = new ObjectProperties();
	greenSphereProperties->setColour({ 0, 255, 0 });
	Sphere *greenSphere = new Sphere(Vec3(0, 0, 3), 3, greenSphereProperties);

	ObjectProperties *blueSphereProperties = new ObjectProperties();
	blueSphereProperties->setColour({ 0, 0, 255 });
	Sphere *blueSphere = new Sphere(Vec3(5, 0, 10), 3, blueSphereProperties);

	Triangle *triangle = new Triangle({ -20, -3, 0 }, { 20, -3, 0 }, { 0, -3, 40 }, blueSphereProperties);

	PointLight light(Vec3(0, 5, 2), { 1, 1, 1 });
//	PointLight light2(Vec3(0, 0, 2), { 0.5, 0.5, 0.5 });

	Scene scene;
	scene.addObject(redSphere);
	scene.addObject(greenSphere);
	scene.addObject(blueSphere);
	scene.addObject(triangle);
	scene.addPointLight(&light);
//	scene.addPointLight(&light2);

	
	std::clock_t start = clock();
	raytracer.traceScene(scene, p_camera, image);
	std::clock_t finish = clock();

	double duration = (finish - start) / (double)CLOCKS_PER_SEC;
	std::cout << "Time taken to raytrace scene: " << duration << " seconds." << std::endl;
	
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