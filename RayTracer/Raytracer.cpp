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
			Pixel pixel = image.getPixel(currentRow, currentColumn);
			camera.computeRay(currentRow, currentColumn, viewingRay);

		}
	}
}