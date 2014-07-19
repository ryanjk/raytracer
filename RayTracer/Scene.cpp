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

void Scene::addPointLight(PointLight* pointLight)
{
	pointLights.push_back(pointLight);
}

bool Scene::rayIntersect(const ViewingRay &viewingRay, ISceneObject *&hitObject, double &t) const
{
	bool hit = false;
	t = MAX_TRACE_DIST;
	for (unsigned int currentObject = 0; currentObject < sceneObjects.size(); ++currentObject)
	{
		ISceneObject *sceneObject = sceneObjects[currentObject];
		double tempHit;
		bool isHit = sceneObject->rayIntersect(viewingRay, tempHit);
		if (isHit && (MIN_TRACE_DIST <= tempHit) && (tempHit <= t))
		{
			hit = true;
			hitObject = sceneObject;
			t = tempHit;
		}
	}
	return hit;
}