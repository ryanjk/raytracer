#ifndef HITRECORD_H
#define HITRECORD_H

#include "ISceneObject.h"
#include "RaytracerMath.h"

class HitRecord {
public:
	void create(ISceneObject *hitSurface, Vec3 hitPoint);
	ISceneObject *getSurface() const;
	Vec3 getNormal() const;
	Vec3 getHitPoint() const;
	Colour getSurfaceColour() const;
	Colour getSpecularColour() const;

private:
	ISceneObject *m_hitSurface;
	Colour m_surfaceColour;
	Colour m_specularColour;
	Vec3 m_normal;
	Vec3 m_hitPoint;
};

#endif