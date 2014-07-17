#ifndef I_RAY_TRACER_H
#define I_RAY_TRACER_H

#include "Image.h"
#include "ViewingRay.h"

class Scene;
class Camera;

class IRaytracer {
public:
	IRaytracer();
	~IRaytracer();

protected:
	void traceScene(const Scene &scene, const Camera &camera, Image image);

private:
	virtual void computeRay() = 0;
	

};

#endif

void IRaytracer::traceScene(const Scene &scene, const Camera &camera, Image image)
{

}