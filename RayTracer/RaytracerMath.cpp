#include "RaytracerMath.h"

bool isOrthonormal(Mat33 matrix)
{
	Mat33 transpose = gmtl::transpose(matrix);
	Mat33 inverse = gmtl::invert(matrix);

	return (transpose == inverse);
}