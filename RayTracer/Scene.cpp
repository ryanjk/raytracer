#include "Scene.h"
#include "RaytracerMath.h"
#include <iostream>

Scene::Scene()
{

}

void Scene::addObject(ISceneObject* sceneObject)
{
	sceneObjects.push_back(sceneObject);
}

bool Scene::rayIntersect(const ViewingRay &viewingRay, ISceneObject *&hitObject, double &intersectionPoint) const
{
	bool hit = false;
	intersectionPoint = MAX_TRACE_DIST;
	for (int currentObject = 0; currentObject < sceneObjects.size(); ++currentObject)
	{
		ISceneObject *sceneObject = sceneObjects[currentObject];
		double tempHit;
		bool isHit = sceneObject->rayIntersect(viewingRay, tempHit);
		if (isHit && (MIN_TRACE_DIST <= tempHit) && (tempHit <= intersectionPoint))
		{
			hit = true;
			hitObject = sceneObject;
			intersectionPoint = tempHit;
		}
	}
	return hit;
}