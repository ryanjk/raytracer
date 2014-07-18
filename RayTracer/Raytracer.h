#ifndef I_RAY_TRACER_H
#define I_RAY_TRACER_H

#include "Image.h"
#include "ViewingRay.h"
#include "ICamera.h"

class Scene;

class Raytracer {
public:
	void traceScene(const Scene &scene, const ICamera &camera, Image image);

private:
	ViewingRay viewingRay;

};

#endif