#include "CoordinateFrame.h"

CoordinateFrame::CoordinateFrame() {}

CoordinateFrame::CoordinateFrame(Vec3 origin, Vec3 u, Vec3 v, Vec3 w)
{	
	gmtl::normalize(u);
	gmtl::normalize(v);
	gmtl::normalize(w);

	Mat33 baseMatrix;
	baseMatrix.set(
		u[0], v[0], w[0],
		u[1], v[1], w[1],
		u[2], v[2], w[2]
	);

	assert(isOrthonormal(baseMatrix));

	m_origin = origin;
	m_u = u;
	m_v = v;
	m_w = w;
}