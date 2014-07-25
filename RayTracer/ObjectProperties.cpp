#include "ObjectProperties.h"

Colour ObjectProperties::getColour() const
{
	return m_colour;
}

void ObjectProperties::setColour(Colour newColour)
{
	m_colour = newColour;
}

Colour ObjectProperties::getSpecularColor() const
{
	return m_specularColour;
}

void ObjectProperties::setSpecularColor(Colour specularColour)
{
	m_specularColour = specularColour;
}

double ObjectProperties::getPhongExponent() const
{
	return m_phongExponent;
}

void ObjectProperties::setPhongExponent(double phongExponent)
{
	m_phongExponent = phongExponent;
}