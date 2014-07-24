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

private:
	ISceneObject *m_hitSurface;
	Colour m_surfaceColour;
	Vec3 m_normal;
	Vec3 m_hitPoint;
};

#endif