#include "Raytracer.h"
#include <iostream>

extern int const WIDTH;
extern int const HEIGHT;

void Raytracer::traceScene(const Scene &scene, const ICamera &camera, Image image)
{
	for (int currentRow = 0; currentRow < HEIGHT; ++currentRow)
	{
		for (int currentColumn = 0; currentColumn < WIDTH; ++currentColumn)
		{
			camera.computeRay(currentRow, currentColumn, viewingRay);
		//	std::cout << "Viewing ray: " << viewingRay.getOrigin() << std::endl;
			ISceneObject *sceneObject = nullptr;
			double intersectionPoint;
			bool hit = scene.rayIntersect(viewingRay, sceneObject, intersectionPoint);

			if (hit && sceneObject)
			{
			//		std::cout << "Hit Registered with Raytracer";
					Pixel pixel = image.getPixel(currentRow, currentColumn);
					Colour colour = sceneObject->getObjectProperties()->getColour();
					pixel[RGB_R] = colour[RGB_R];
					pixel[RGB_G] = colour[RGB_G];
					pixel[RGB_B] = colour[RGB_B]; 
			}

		}
	}
}