#include "RaytracerMath.h"

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