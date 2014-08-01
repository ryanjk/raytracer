#ifndef I_RAY_TRACER_H
#define I_RAY_TRACER_H

#include "Image.h"
#include "ViewingRay.h"
#include "ICamera.h"
#include "Scene.h"

class Raytracer {
public:
	Raytracer();
	void traceScene(const Scene &scene, const ICamera &camera, Image image);

private:
	ViewingRay m_viewingRay;
	Colour m_backgroundColour;
	Colour rayColour(const ViewingRay &viewingRay, const Scene &scene, const double min_t, const double max_t, int callsToMake);
	Colour shadePixel(const PointLights &pointLights, const Scene &scene, const HitRecord &hitRecord);

};

#endif