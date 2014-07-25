#include "PerspectiveCamera.h"

PerspectiveCamera::PerspectiveCamera(Vec3 viewpoint, Vec3 direction, Vec3 up,
	Dimension length, Dimension height, Dimension focalLength)
{
	ICamera::initializeCamera(viewpoint, direction, up, length, height);
	m_focalLength = focalLength;
}

void PerspectiveCamera::computeRay(int pixelRow, int pixelColumn, ViewingRay &viewingRay) const
{
	viewingRay.setOrigin(cameraFrame.getOrigin() + cameraFrame.getW() * m_focalLength);
	
	Dimension u = m_left + (pixelColumn + 0.5) * (m_right - m_left) / WIDTH;
	Dimension v = m_bottom + (pixelRow + 0.5) * (m_top - m_bottom) / HEIGHT;
	Vec3 pointOnPlane = cameraFrame.getOrigin() + u * cameraFrame.getU() + v * cameraFrame.getV();
	viewingRay.setDirection(pointOnPlane - viewingRay.getOrigin());
}