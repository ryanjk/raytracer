#ifndef ORTHO_CAM
#define ORTHO_CAM

#include "ICamera.h"
#include "ViewingRay.h"

class OrthographicCamera : public ICamera {
public:
	OrthographicCamera(Vec3 viewpoint, Vec3 direction, Vec3 up,
		Dimension length, Dimension height);

	void computeRay(int pixelRow, int pixelColumn, ViewingRay &viewingRay) const;
};

#endif