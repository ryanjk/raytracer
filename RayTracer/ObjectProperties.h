#ifndef OBJECT_PROPERTIES_H
#define OBJECT_PROPERTIES_H

#include "RaytracerShapeHeader.h"

class ObjectProperties {
public:
	ObjectProperties() {};
	
	Colour getColour() const;
	void setColour(Colour newColour);

private:
	Colour m_colour;
};

#endif