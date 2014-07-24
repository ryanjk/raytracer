#ifndef I_RAY_TRACER_H
#define I_RAY_TRACER_H

#include "Image.h"
#include "ViewingRay.h"
#include "ICamera.h"
#include "Scene.h"

class Raytracer {
public:
	void traceScene(const Scene &scene, const ICamera &camera, Image image);

private:
	ViewingRay viewingRay;
	void shadePixel(const PointLights &pointLights, const ISceneObject *surface, const Vec3 &intersectionPoint, Pixel &pixel);

};

#endif