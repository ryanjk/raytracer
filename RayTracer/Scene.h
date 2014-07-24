#ifndef SCENE_H
#define SCENE_H

#include "ISceneObject.h"
#include <vector>
#include "PointLight.h"
#include "HitRecord.h"

typedef std::vector<ISceneObject*> SceneObjects;
typedef std::vector<PointLight*> PointLights;

struct AmbientLight
{
	gmtl::Vec<double, 3U> colourIntensities;
};

class Scene {
public:
	Scene();
	Scene(AmbientLight ambientLight) : m_ambientLight(ambientLight) {};

	void addObject(ISceneObject* sceneObject);
	void addPointLight(PointLight* pointLight);

	PointLights getPointLights() const { return pointLights; }

	AmbientLight getAmbientLight() const { return m_ambientLight; }

	bool rayIntersect(const ViewingRay &viewingRay, const double lowerLimit, const double upperLimit, HitRecord &hitRecord) const;

private:
	SceneObjects sceneObjects;
	PointLights pointLights;
	AmbientLight m_ambientLight;
};

#endif //SCENE_H