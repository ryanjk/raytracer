#ifndef MATH_TYPES_H
#define MATH_TYPES_H

#include "gmtl\gmtl.h"

typedef gmtl::Vec3d Vec3;
typedef gmtl::Matrix33d Mat33;

extern bool isOrthonormal(Mat33 matrix);
extern bool isPerpendicular(Vec3 a, Vec3 b);

extern Mat33 createMat33(Vec3 c1, Vec3 c2, Vec3 c3);
extern double matrixDeterminant(Mat33 matrix);

extern double const EPSILON;
extern double const MIN_TRACE_DIST;
extern double const MAX_TRACE_DIST;

#endif