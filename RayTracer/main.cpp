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
#include "Quad.h"
#include "ObjectProperties.h"
#include "RaytracerShapeHeader.h"
#include "PointLight.h"

extern int const WIDTH = 480;
extern int const HEIGHT = 320;

const double CAMERA_WIDTH = 30;
const double CAMERA_HEIGHT = 20;

extern PixelColour const MAX_COLOUR = 1.0f;
extern PixelColour const MIN_COLOUR = 0.0f;

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
		GL_FLOAT, 
		image.getImage());

	glutSwapBuffers();
}

int main(int argc, char** argv)
{	
	ObjectProperties *redSphereProperties = new ObjectProperties();
	redSphereProperties->setColour({ MAX_COLOUR, MIN_COLOUR, MIN_COLOUR });
	redSphereProperties->setSpecularColor({ 0.0f, 0.0f, 0.0f });
	redSphereProperties->setPhongExponent(10000);
	Sphere *redSphere = new Sphere(Vec3(-6, 0, 5), 3, redSphereProperties);

	ObjectProperties *greenSphereProperties = new ObjectProperties();
	greenSphereProperties->setColour({ MAX_COLOUR, 0.84f, MIN_COLOUR });
	greenSphereProperties->setSpecularColor({ 1.0f, 0.84f, 0.2f });
	greenSphereProperties->setPhongExponent(10000);
	Sphere *greenSphere = new Sphere(Vec3(0, 3, 14), 6, greenSphereProperties);

	ObjectProperties *blueSphereProperties = new ObjectProperties();
	blueSphereProperties->setColour({ MIN_COLOUR, MIN_COLOUR, MAX_COLOUR });
	blueSphereProperties->setSpecularColor({ 0.0f, 0.0f, 0.0f });
	blueSphereProperties->setPhongExponent(10000);
	Sphere *blueSphere = new Sphere(Vec3(4, -2, 7), 1, blueSphereProperties);

	ObjectProperties *whiteSphereProperties = new ObjectProperties();
	whiteSphereProperties->setColour({ 0.3f, 0.3f, 0.3f });
	whiteSphereProperties->setSpecularColor({ MAX_COLOUR, MAX_COLOUR, MAX_COLOUR });
//	whiteSphereProperties->setSpecularColor({ MIN_COLOUR, MIN_COLOUR, MIN_COLOUR });
	whiteSphereProperties->setPhongExponent(10000);

	ObjectProperties *darkSphereProperties = new ObjectProperties();
	darkSphereProperties->setColour({ 0.3f, 0.3f, 0.3f });
	darkSphereProperties->setSpecularColor({ MIN_COLOUR, MIN_COLOUR, MIN_COLOUR });
	darkSphereProperties->setPhongExponent(10000);

	Dimension xLeft = -CAMERA_WIDTH / 2;
	Dimension xRight = CAMERA_WIDTH / 2;
	Dimension yBottom = -3;
	Dimension yTop = CAMERA_HEIGHT - 3;
	Dimension zFront = 1;
	Dimension zBack = 50;

	Quad *floor = new Quad({ xLeft, yBottom, zFront }, { xRight, yBottom, zFront }, { xRight, yBottom, zBack }, { xLeft, yBottom, zBack }, whiteSphereProperties);
	Quad *leftWall = new Quad({ xLeft, yBottom, zFront }, { xLeft, yBottom, zBack }, { xLeft, yTop, zBack }, { xLeft, yTop, zFront }, whiteSphereProperties);
	Quad *rightWall = new Quad({ xRight, yBottom, zFront }, { xRight, yTop, zFront }, { xRight, yTop, zBack }, { xRight, yBottom, zBack }, whiteSphereProperties);
	Quad *backWall = new Quad({ xLeft, yBottom, zBack }, { xRight, yBottom, zBack }, { xRight, yTop, zBack }, { xLeft, yTop, zBack }, whiteSphereProperties);
	Quad *ceiling = new Quad({ xLeft, yTop, zFront }, { xLeft, yTop, zBack }, { xRight, yTop, zBack }, { xRight, yTop, zFront }, whiteSphereProperties);
	

	PointLight light(Vec3(-5, 8, 4), { 0.6f, 0.6f, 0.6f });
	PointLight light2(Vec3(0, 15, 4), { 0.4f, 0.4f, 0.4f });
	PointLight light3(Vec3(14, 13, 2), { 0.5f, 0.5f, 0.5f });

	Scene scene;
	scene.addObject(redSphere);
	scene.addObject(greenSphere);
	scene.addObject(blueSphere);
	scene.addObject(floor);
//	scene.addObject(leftWall);
//	scene.addObject(rightWall);
//	scene.addObject(backWall);
//	scene.addObject(ceiling);
	scene.addPointLight(&light);
	scene.addPointLight(&light2);
//	scene.addPointLight(&light3);

	
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