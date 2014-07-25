#include "RaytracerMath.h"

extern double const EPSILON = 0.0000001;
extern double const MIN_TRACE_DIST = 0;
extern double const MAX_TRACE_DIST = 100000;

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

Mat33 createMat33(Vec3 c1, Vec3 c2, Vec3 c3)
{
	Mat33 matrix;
	matrix.set(
		c1[0], c2[0], c3[0],
		c1[1], c2[1], c3[1],
		c1[2], c2[2], c3[2]
		);

	return matrix;
}

double matrixDeterminant(Mat33 matrix)
{
	double determinant =
		matrix(0, 0) * ((matrix(1, 1) * matrix(2, 2)) - (matrix(2, 1) * matrix(1, 2)))
		- matrix(0, 1) * ((matrix(1, 0) * matrix(2, 2)) - (matrix(2, 0) * matrix(1, 2)))
		+ matrix(0, 2) * ((matrix(1, 0) * matrix(2, 1)) - (matrix(2, 0) * matrix(1, 1)));

	return determinant;
}