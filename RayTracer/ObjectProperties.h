#ifndef OBJECT_PROPERTIES_H
#define OBJECT_PROPERTIES_H

#include "RaytracerShapeHeader.h"

class ObjectProperties {
public:
	ObjectProperties() {
		m_colour = { MIN_COLOUR, MIN_COLOUR, MIN_COLOUR };
		m_specularColour = { MIN_COLOUR, MIN_COLOUR, MIN_COLOUR };
		m_phongExponent = 0;
	};
	
	Colour getColour() const;
	void setColour(Colour newColour);

	Colour getSpecularColor() const;
	void setSpecularColor(Colour specularColour);

	double getPhongExponent() const;
	void setPhongExponent(double phongExponent);

private:
	Colour m_colour;
	Colour m_specularColour;
	double m_phongExponent;
};

#endif