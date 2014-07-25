#ifndef PERSPECTIVE_CAMERA_H
#define PERSPECTIVE_CAMERA_H

#include "ICamera.h"

class PerspectiveCamera : public ICamera {
public:
	PerspectiveCamera(Vec3 viewpoint, Vec3 direction, Vec3 up,
		Dimension length, Dimension height, Dimension focalLength);

	void computeRay(int pixelRow, int pixelColumn, ViewingRay &viewingRay) const;

private:
	Dimension m_focalLength;
};

#endif