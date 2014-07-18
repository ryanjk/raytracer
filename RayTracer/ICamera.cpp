#include "ICamera.h"
#include <iostream>

void ICamera::initializeCamera(Vec3 viewpoint, Vec3 direction, Vec3 up, Dimension length, Dimension height)
{
	assert(isPerpendicular(direction, up));

	Vec3 u = -(gmtl::cross(u, direction, up));
	Vec3 v = up;
	Vec3 w = -direction;

	cameraFrame = CoordinateFrame(viewpoint, u, v, w);

	Dimension lengthRadius = length / 2;
	m_left = -lengthRadius;
	m_right = lengthRadius;

	Dimension heightRadius = height / 2;
	m_top = heightRadius;
	m_bottom = -heightRadius;
}