#include "OrthographicCamera.h"

extern int const WIDTH;
extern int const HEIGHT;

OrthographicCamera::OrthographicCamera(Vec3 viewpoint, Vec3 direction, Vec3 up, Dimension length, Dimension height)
{
	ICamera::initializeCamera(viewpoint, direction, up, length, height);
}

void OrthographicCamera::computeRay(int pixelRow, int pixelColumn, ViewingRay &viewingRay) const
{
	Vec3 rayDirection = -(cameraFrame.getW());
	viewingRay.setDirection(rayDirection);
	
	Dimension u = m_left + (m_right - m_left) * (pixelColumn + 0.5) / WIDTH;
	Dimension v = m_bottom + (m_top - m_bottom) * (pixelRow + 0.5) / HEIGHT;
	Vec3 rayOrigin = cameraFrame.getOrigin() + (u * cameraFrame.getU()) + (v * cameraFrame.getV());
	viewingRay.setOrigin(rayOrigin);
}