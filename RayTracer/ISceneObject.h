#ifndef SCENE_OBJECT_H
#define SCENE_OBJECT_H

#include "ViewingRay.h"
#include "ObjectProperties.h"
#include <vector>

class ISceneObject {
public:
	virtual bool rayIntersect(const ViewingRay &viewingRay, const double lowerLimit, const double upperLimit, double &t) = 0;
	
	virtual Vec3 getNormalAt(const Vec3 &surfaceLocation) const = 0;

	ObjectProperties *getObjectProperties() const {
		return m_objectProperties;
	}

	void setObjectProperties(ObjectProperties *objectProperties) {
		m_objectProperties = objectProperties;
	}

private:
	ObjectProperties *m_objectProperties;
};

#endif