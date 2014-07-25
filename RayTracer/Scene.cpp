#include "Scene.h"
#include "RaytracerMath.h"
#include <iostream>

Scene::Scene()
{
	m_ambientLight.colourIntensities = { 0.2, 0.2, 0.2 };
}

void Scene::addObject(ISceneObject* sceneObject)
{
	sceneObjects.push_back(sceneObject);
}

void Scene::addPointLight(PointLight* pointLight)
{
	pointLights.push_back(pointLight);
}

bool Scene::rayIntersect(const ViewingRay &viewingRay, const double lowerLimit, const double upperLimit, HitRecord &hitRecord) const
{
	// Check each object in the scene with the viewing ray
	// If an object is hit, see if it is the closest to the camera

	bool hit = false;
	double t = upperLimit;
	ISceneObject *hitObject = nullptr;

	for (unsigned int currentObject = 0; currentObject < sceneObjects.size(); ++currentObject)
	{
		ISceneObject *sceneObject = sceneObjects[currentObject];
		double tempHit;
		bool isHit = sceneObject->rayIntersect(viewingRay, lowerLimit, upperLimit, tempHit);
		if (isHit && (lowerLimit <= tempHit) && (tempHit <= t))
		{
			hit = true;
			t = tempHit;
			hitObject = sceneObject;
		}
	}

	if (hit)
	{
		Vec3 hitPoint = viewingRay.getOrigin() + t * viewingRay.getDirection();
		hitRecord.create(hitObject, hitPoint);
	}

	return hit;
}