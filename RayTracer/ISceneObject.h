#ifndef SCENE_OBJECT_H
#define SCENE_OBJECT_H

#include "ViewingRay.h"
#include "ObjectProperties.h"
#include <vector>

class ISceneObject {
public:
	virtual bool rayIntersect(const ViewingRay &viewingRay, double &intersectionPoint) = 0;

	ObjectProperties *getObjectProperties() {
		return m_objectProperties;
	}

	void setObjectProperties(ObjectProperties *objectProperties) {
		m_objectProperties = objectProperties;
	}

private:
	ObjectProperties *m_objectProperties;
};

#endif