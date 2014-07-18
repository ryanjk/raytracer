#include "ViewingRay.h"

ViewingRay::ViewingRay()
{

}

ViewingRay::ViewingRay(Vec3 origin, Vec3 direction)
: m_origin(origin), m_direction(direction) 
{

}

Vec3 ViewingRay::getDirection() const
{
	return m_direction;
}

Vec3 ViewingRay::getOrigin() const
{
	return m_origin;
}

void ViewingRay::setDirection(Vec3 direction)
{
	m_direction = direction;
}

void ViewingRay::setOrigin(Vec3 origin)
{
	m_origin = origin;
}