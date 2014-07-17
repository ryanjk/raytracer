#include "RaytracerMath.h"

#ifndef VIEWING_RAY_H
#define VIEWING_RAY_H

class ViewingRay {
public:
	ViewingRay();
	ViewingRay(Vec3 origin, Vec3 direction);

	~ViewingRay();

	Vec3 getOrigin() const;
	void setOrigin(Vec3 origin);

	Vec3 getDirection() const;
	void setDirection(Vec3 direction);

private:
	Vec3 m_origin;
	Vec3 m_direction;
};

#endif