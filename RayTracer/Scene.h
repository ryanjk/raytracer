#ifndef SCENE_H
#define SCENE_H

#include "ISceneObject.h"
#include <vector>
#include "PointLight.h"

typedef std::vector<ISceneObject*> SceneObjects;
typedef std::vector<PointLight*> PointLights;

class Scene {
public:
	Scene();

	void addObject(ISceneObject* sceneObject);
	void addPointLight(PointLight* pointLight);

	PointLights getPointLights() const { return pointLights; }

	bool rayIntersect(const ViewingRay &viewingRay, ISceneObject *&hitObject, double &t) const;

private:
	SceneObjects sceneObjects;
	PointLights pointLights;
};

#endif //SCENE_H