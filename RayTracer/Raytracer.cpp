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
			double t;
			bool hit = scene.rayIntersect(viewingRay, sceneObject, t);

			if (hit)
			{
					Pixel pixel = image.getPixel(currentRow, currentColumn);
					PointLights pointLights = scene.getPointLights();
					Vec3 intersectionPoint = viewingRay.getOrigin() + (t * viewingRay.getDirection());
					shadePixel(pointLights, sceneObject, intersectionPoint, pixel);
			}

		}
	}
}

void Raytracer::shadePixel(const PointLights &pointLights, const ISceneObject *surface, const Vec3 &intersectionPoint, Pixel pixel)
{
	Vec3 surfaceNormal = surface->getNormalAt(intersectionPoint);

	Colour surfaceColour = surface->getObjectProperties()->getColour();
	unsigned char surfaceRed = surfaceColour[RGB_R];
	unsigned char surfaceBlue = surfaceColour[RGB_B];
	unsigned char surfaceGreen = surfaceColour[RGB_G];

	double finalRed = 0;
	double finalBlue = 0;
	double finalGreen = 0;

	for (unsigned int currentLight = 0; currentLight < pointLights.size(); ++currentLight)
	{
		PointLight light = pointLights[currentLight];
		Vec3 surfaceToLight = light.getPosition() - intersectionPoint;
		gmtl::normalize(surfaceToLight);

		double angle = gmtl::dot(surfaceToLight, surfaceNormal);
		double scalar = gmtl::Math::Max((double)0, angle);

		finalRed += surfaceRed * scalar * light.getRedIntensity();
	//	std::cout << "Surface red: " << (int)surfaceRed << " Scalar: " << scalar << "Intensity: " << light.getRedIntensity() << std::endl;
		finalBlue += surfaceBlue * scalar * light.getBlueIntensity();
		finalGreen += surfaceGreen * scalar * light.getGreenIntensity();
	}

	finalRed = (finalRed > 255) ? 255 : finalRed;
	finalGreen = (finalGreen > 255) ? 255 : finalGreen;
	finalBlue = (finalBlue > 255) ? 255 : finalBlue;

	pixel[RGB_R] = finalRed;
//	std::cout << finalRed << std::endl;
	pixel[RGB_G] = finalGreen;
	pixel[RGB_B] = finalBlue;

}