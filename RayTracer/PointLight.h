#ifndef ILIGHT_H
#define ILIGHT_H

#include "RaytracerShapeHeader.h"
#include "RaytracerMath.h"
#include <vector>

class PointLight {
public:
	PointLight(Vec3 position, std::vector<float> lightIntensity) : m_lightIntensity(lightIntensity), m_position(position) {}
	PointLight(const PointLight *pointLight) { m_lightIntensity = pointLight->m_lightIntensity; m_position = pointLight->m_position; }

	float getRedIntensity() const { return m_lightIntensity[RGB_R]; }
	float getGreenIntensity() const { return m_lightIntensity[RGB_G]; }
	float getBlueIntensity() const { return m_lightIntensity[RGB_B]; }

	Vec3 getPosition() const { return m_position; }
private:
	std::vector<float> m_lightIntensity;
	Vec3 m_position;
};

#endif