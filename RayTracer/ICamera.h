#ifndef ICAMERA_H
#define ICAMERA_H

#include "RaytracerMath.h"
#include "CoordinateFrame.h"

typedef float Dimension;

class ICamera {
public:
	ICamera();
	ICamera(Vec3 position, Vec3 direction, Vec3 up, 
		Dimension length, Dimension height);

	~ICamera();

	Vec3 getDirection() const;
	Vec3 getUp() const;
	Vec3 getViewpoint() const;

	
private:
	CoordinateFrame cameraFrame;
	Dimension m_left;
	Dimension m_right;
	Dimension m_top;
	Dimension m_bottom;
};

#endif