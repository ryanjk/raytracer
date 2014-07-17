#include "Image.h"
#include "ViewingRay.h"

#ifndef I_RAY_TRACER_H
#define I_RAY_TRACER_H

class Scene;
class ISceneObject;

class IRaytracer {
public:
	IRaytracer();
	~IRaytracer();

protected:
	void traceScene(const Scene &scene, Image image);

private:
	virtual void computeRay() = 0;
	

};

#endif