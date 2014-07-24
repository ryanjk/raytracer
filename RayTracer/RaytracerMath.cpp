#include "RaytracerMath.h"

extern double const EPSILON = 0.0000001;
extern double const MIN_TRACE_DIST = 0;
extern double const MAX_TRACE_DIST = 10;

bool isOrthonormal(Mat33 matrix)
{
	Mat33 transpose = gmtl::transpose(matrix);
	Mat33 inverse = gmtl::invert(matrix);

	return (transpose == inverse);
}

bool isPerpendicular(Vec3 a, Vec3 b)
{
	double dotProduct = gmtl::dot(a, b);
	return (dotProduct == 0);
}