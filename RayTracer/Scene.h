#ifndef SCENE_H
#define SCENE_H

#include "ISceneObject.h"
#include <vector>

typedef std::vector<ISceneObject*> SceneObjects;

class Scene {
public:
	Scene();

	void addObject(ISceneObject* sceneObject);

	bool rayIntersect(const ViewingRay &viewingRay, ISceneObject *&hitObject, double &intersectionPoint) const;

private:
	SceneObjects sceneObjects;
};

#endif //SCENE_H