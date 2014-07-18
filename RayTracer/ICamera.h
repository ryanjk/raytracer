#ifndef ICAMERA_H
#define ICAMERA_H

#include "RaytracerMath.h"
#include "CoordinateFrame.h"

class ViewingRay;

typedef double Dimension;

class ICamera {
public:
	void initializeCamera(Vec3 viewpoint, Vec3 direction, Vec3 up,
		Dimension length, Dimension height);

	virtual void computeRay(int pixelRow, int pixelColumn, ViewingRay &viewingRay) const = 0;
	
protected:
	CoordinateFrame cameraFrame;
	Dimension m_left;
	Dimension m_right;
	Dimension m_top;
	Dimension m_bottom;
};

#endif