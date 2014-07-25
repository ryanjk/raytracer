#include "Raytracer.h"
#include <iostream>
#include "HitRecord.h"
#include "RaytracerMath.h"

extern int const WIDTH;
extern int const HEIGHT;

Raytracer::Raytracer() {
	m_backgroundColour = { 0, 0, 0 };
}

void Raytracer::traceScene(const Scene &scene, const ICamera &camera, Image image)
{
	for (int currentRow = 0; currentRow < HEIGHT; ++currentRow)
	{
		for (int currentColumn = 0; currentColumn < WIDTH; ++currentColumn)
		{
			Colour pixelColour;
			Pixel pixel = image.getPixel(currentRow, currentColumn);
			
			camera.computeRay(currentRow, currentColumn, m_viewingRay);
			HitRecord hitRecord;
			bool hit = scene.rayIntersect(m_viewingRay, MIN_TRACE_DIST, MAX_TRACE_DIST, hitRecord);

			if (hit)
			{
				Colour surfaceColour = hitRecord.getSurfaceColour();
				pixelColour[RGB_R] = surfaceColour[RGB_R] * scene.getAmbientLight().colourIntensities[RGB_R];
				pixelColour[RGB_G] = surfaceColour[RGB_G] * scene.getAmbientLight().colourIntensities[RGB_G];
				pixelColour[RGB_B] = surfaceColour[RGB_B] * scene.getAmbientLight().colourIntensities[RGB_B];

				PointLights pointLights = scene.getPointLights();

				Colour pointLighting = shadePixel(pointLights, scene, hitRecord);
				pixelColour = addColours(pixelColour, pointLighting);
				
			}

			else
			{
				pixelColour = m_backgroundColour;
			}

			pixel[RGB_R] = pixelColour[RGB_R];
			pixel[RGB_G] = pixelColour[RGB_G];
			pixel[RGB_B] = pixelColour[RGB_B];
		}
	}
}

Colour Raytracer::shadePixel(const PointLights &pointLights, const Scene &scene, const HitRecord &hitRecord)
{
	double red = 0;
	double blue = 0;
	double green = 0;
	Vec3 surfaceNormal = hitRecord.getNormal();
	Colour surfaceColour = hitRecord.getSurfaceColour();

	for (unsigned int currentLight = 0; currentLight < pointLights.size(); ++currentLight)
	{
		PointLight light = pointLights[currentLight];
		Vec3 surfaceToLight = light.getPosition() - hitRecord.getHitPoint();
		double distSurfaceToLight = gmtl::length(surfaceToLight);
		gmtl::normalize(surfaceToLight);

		HitRecord shadowHitRecord;
		ViewingRay shadowRay(hitRecord.getHitPoint(), surfaceToLight);
		bool shadowHit = scene.rayIntersect(shadowRay, EPSILON, distSurfaceToLight, shadowHitRecord);

		if (!shadowHit)
		{
			double angle = gmtl::dot(surfaceToLight, surfaceNormal);
			double scalar = gmtl::Math::Max((double)0, angle);

			red += surfaceColour[RGB_R] * scalar * light.getRedIntensity();
			blue += surfaceColour[RGB_B] * scalar * light.getBlueIntensity();
			green += surfaceColour[RGB_G] * scalar * light.getGreenIntensity();
		}

	}

	PixelColour finalRed = (red > 255) ? 255 : red;
	PixelColour finalGreen = (green > 255) ? 255 : green;
	PixelColour finalBlue = (blue > 255) ? 255 : blue;

	Colour finalColour = { finalRed, finalGreen, finalBlue };
	return finalColour;
}

void Raytracer::cleanPixelColour(Colour &pixelColour)
{
	PixelColour &red = pixelColour[RGB_R];
	PixelColour &green = pixelColour[RGB_G];
	PixelColour &blue = pixelColour[RGB_B];

	red = (red > 255) ? 255 : red;
	green = (green > 255) ? 255 : green;
	blue = (blue > 255) ? 255 : blue;
}

Colour Raytracer::addColours(const Colour &c1, const Colour &c2)
{
	Colour sum;
	
	int redTest = (int) c1[RGB_R] + (int) c2[RGB_R];
	sum[RGB_R] = (redTest > 255) ? 255 : redTest;

	int greenTest = (int)c1[RGB_G] + (int)c2[RGB_G];
	sum[RGB_G] = (greenTest > 255) ? 255 : greenTest;

	int blueTest = (int)c1[RGB_B] + (int)c2[RGB_B];
	sum[RGB_B] = (blueTest > 255) ? 255 : blueTest;

	return sum;
}