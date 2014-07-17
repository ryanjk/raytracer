#include "gmtl\Vec.h"

#ifndef VIEWING_RAY_H
#define VIEWING_RAY_H

typedef gmtl::Vec3d Vec3;

class ViewingRay {
public:
	ViewingRay();
	ViewingRay(Vec3 origin, Vec3 direction);

	~ViewingRay();

	Vec3 getOrigin();
	void setOrigin(Vec3 origin);

	Vec3 getDirection();
	void setDirection(Vec3 direction);

private:
	Vec3 m_origin;
	Vec3 m_direction;
};

#endif