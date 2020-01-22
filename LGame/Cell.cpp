#include "Cell.h"
#include "Game.h"

Cell::Cell()
{
	box.setFillColor(sf::Color::White);
	box.setOutlineColor(sf::Color::Green);
	box.setOutlineThickness(2);
}

int Cell::typeOfCell()
{
	return typeOfCellData;
}

sf::RectangleShape Cell::getBox()
{
	return box;
}
