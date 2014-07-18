#include "ObjectProperties.h"

Colour ObjectProperties::getColour() const
{
	return m_colour;
}

void ObjectProperties::setColour(Colour newColour)
{
	m_colour = newColour;
}