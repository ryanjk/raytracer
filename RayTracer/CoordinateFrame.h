#ifndef COORDINATE_FRAME_H
#define COORDINATE_FRAME_H

#include "RaytracerMath.h"

class CoordinateFrame {
public:
	CoordinateFrame();
	CoordinateFrame(Vec3 origin, Vec3 u, Vec3 v, Vec3 w);

	Vec3 getOrigin() const;
	Vec3 getU() const;
	Vec3 getV() const;
	Vec3 getW() const;

private:
	Vec3 m_origin;
	Vec3 m_u;
	Vec3 m_v;
	Vec3 m_w;
};

#endif