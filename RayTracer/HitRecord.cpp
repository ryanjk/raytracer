#include "HitRecord.h"

void HitRecord::create(ISceneObject *hitSurface, Vec3 hitPoint, Vec3 viewDirection)
{
	m_hitSurface = hitSurface;
	m_hitPoint = hitPoint;
	m_viewDirection = viewDirection;
	m_normal = m_hitSurface->getNormalAt(hitPoint);
	m_surfaceColour = hitSurface->getObjectProperties()->getColour();
	m_specularColour = hitSurface->getObjectProperties()->getSpecularColor();
}

ISceneObject *HitRecord::getSurface() const
{
	return m_hitSurface;
}

Vec3 HitRecord::getHitPoint() const
{
	return m_hitPoint;
}

Vec3 HitRecord::getNormal() const
{
	return m_normal;
}

Vec3 HitRecord::getViewDirection() const
{
	return m_viewDirection;
}

Colour HitRecord::getSurfaceColour() const
{
	return m_surfaceColour;
}

Colour HitRecord::getSpecularColour() const
{
	return m_specularColour;
}