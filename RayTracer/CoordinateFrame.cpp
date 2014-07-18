#include "CoordinateFrame.h"

CoordinateFrame::CoordinateFrame() {}

CoordinateFrame::CoordinateFrame(const CoordinateFrame &coordinateFrame)
{
	m_origin = coordinateFrame.m_origin;
	m_u = coordinateFrame.m_u;
	m_v = coordinateFrame.m_v;
	m_w = coordinateFrame.m_w;
}

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

Vec3 CoordinateFrame::getOrigin() const
{
	return m_origin;
}

Vec3 CoordinateFrame::getU() const
{
	return m_u;
}

Vec3 CoordinateFrame::getV() const
{
	return m_v;
}

Vec3 CoordinateFrame::getW() const
{
	return m_w;
}