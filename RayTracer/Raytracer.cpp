#include "Raytracer.h"
#include <iostream>
#include "HitRecord.h"
#include "RaytracerMath.h"

extern int const WIDTH;
extern int const HEIGHT;

extern PixelColour const MAX_COLOUR;
extern PixelColour const MIN_COLOUR;

Raytracer::Raytracer() {
	m_backgroundColour = { MIN_COLOUR, MIN_COLOUR, MIN_COLOUR };
}

void Raytracer::traceScene(const Scene &scene, const ICamera &camera, Image image)
{
	for (int currentRow = 0; currentRow < HEIGHT; ++currentRow)
	{
		for (int currentColumn = 0; currentColumn < WIDTH; ++currentColumn)
		{
			camera.computeRay(currentRow, currentColumn, m_viewingRay);
			Colour pixelColour = rayColour(m_viewingRay, scene, MIN_TRACE_DIST, MAX_TRACE_DIST, 5);
			Pixel pixel = image.getPixel(currentRow, currentColumn);

			pixel[RGB_R] = pixelColour[RGB_R];
			pixel[RGB_G] = pixelColour[RGB_G];
			pixel[RGB_B] = pixelColour[RGB_B];
		}
	}
}

Colour Raytracer::rayColour(const ViewingRay &viewingRay, const Scene &scene, const double min_t, const double max_t, int callsToMake)
{
	if (callsToMake == 0)
	{
		return Colour({ MIN_COLOUR, MIN_COLOUR, MIN_COLOUR });
	}
	
	Colour pixelColour;
	
	HitRecord hitRecord;
	bool hit = scene.rayIntersect(viewingRay, EPSILON, MAX_TRACE_DIST, hitRecord);

	if (hit)
	{
		Colour surfaceColour = hitRecord.getSurfaceColour();
		pixelColour[RGB_R] = surfaceColour[RGB_R] * scene.getAmbientLight().colourIntensities[RGB_R];
		pixelColour[RGB_G] = surfaceColour[RGB_G] * scene.getAmbientLight().colourIntensities[RGB_G];
		pixelColour[RGB_B] = surfaceColour[RGB_B] * scene.getAmbientLight().colourIntensities[RGB_B];

		PointLights pointLights = scene.getPointLights();

		Colour pointLighting = shadePixel(pointLights, scene, hitRecord);
		if (hitRecord.getSpecularColour() != Colour({ MIN_COLOUR, MIN_COLOUR, MIN_COLOUR }))
		{
			Vec3 d = viewingRay.getDirection();
			Vec3 n = hitRecord.getNormal();
			double scalar = gmtl::dot(n, d);
			Vec3 r = d - (2 * (scalar)* n);
			gmtl::normalize(r);

			ViewingRay reflectionRay;
			reflectionRay.setOrigin(hitRecord.getHitPoint());
			reflectionRay.setDirection(r);
			Colour reflectionColour = rayColour(reflectionRay, scene, EPSILON, MAX_TRACE_DIST, --callsToMake);

			Colour reflectiveProperty = hitRecord.getSpecularColour();
			reflectionColour[RGB_R] *= reflectiveProperty[RGB_R];
			reflectionColour[RGB_G] *= reflectiveProperty[RGB_G];
			reflectionColour[RGB_B] *= reflectiveProperty[RGB_B];

			pointLighting += reflectionColour;
		}
		pixelColour += pointLighting;
	}

	else
	{
		pixelColour = m_backgroundColour;
	}

	return pixelColour;
}

Colour Raytracer::shadePixel(const PointLights &pointLights, const Scene &scene, const HitRecord &hitRecord)
{
	PixelColour red = MIN_COLOUR;
	PixelColour blue = MIN_COLOUR;
	PixelColour green = MIN_COLOUR;

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
			Vec3 surfaceNormal = hitRecord.getNormal();
			Vec3 viewingDirection = -hitRecord.getViewDirection();
			
			double angle = gmtl::dot(surfaceToLight, surfaceNormal);
			double lambertianScalar = gmtl::Math::Max((double)0, angle);

			Vec3 halfway = viewingDirection + surfaceToLight;
			gmtl::normalize(halfway);
			double phongAngle = gmtl::dot(surfaceNormal, halfway);
			double phongScalar = gmtl::Math::Max((double)0, phongAngle);

			Colour surfaceColour = hitRecord.getSurfaceColour();
			Colour specularColour = hitRecord.getSpecularColour();
			double phongExponent = hitRecord.getSurface()->getObjectProperties()->getPhongExponent();

			double redTerm = light.getRedIntensity()
				* (surfaceColour[RGB_R] * lambertianScalar
						+ specularColour[RGB_R] * gmtl::Math::pow(phongScalar, phongExponent)
				);
			red += redTerm;
			blue += light.getBlueIntensity()
				* (surfaceColour[RGB_B] * lambertianScalar 
				+ specularColour[RGB_B] * gmtl::Math::pow(phongScalar, phongExponent)
				);
			green += light.getGreenIntensity()
				* (surfaceColour[RGB_G] * lambertianScalar 
				+ specularColour[RGB_G] * gmtl::Math::pow(phongScalar, phongExponent)
				);
		}
	}

	Colour finalColour = { red, green, blue };
	return finalColour;
}