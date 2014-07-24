#ifndef HITRECORD_H
#define HITRECORD_H

#include "ISceneObject.h"
#include "RaytracerMath.h"

class HitRecord {
public:
	void create(ISceneObject *hitSurface, Vec3 hitPoint);
	ISceneObject *getSurface();
	Vec3 getNormal();
	Vec3 getHitPoint();

private:
	ISceneObject *m_hitSurface;
	Vec3 m_normal;
	Vec3 m_hitPoint;
};

#endif