#include "Cell.h"
#include "Game.h"

Cell::Cell()
{
	box.setFillColor(sf::Color::White);
	box.setOutlineColor(sf::Color::Green);
	box.setOutlineThickness(2);
	
}

void Cell::setup()
{
	setSize();
	setPosition();
	setUpBoxColor();
}

int Cell::typeOfCell()
{
	return typeOfCellData;
}

void Cell::setSize()
{
	box.setSize(sf::Vector2f(100, 100));
}

void Cell::setDataType(int t_type)
{
	typeOfCellData = t_type;
}

void Cell::setUpBoxColor()
{
	if (typeOfCellData == 0)
	{
		box.setFillColor(sf::Color::White);
	}
	if (typeOfCellData == 1)
	{
		box.setFillColor(sf::Color::Yellow);
	}
	if (typeOfCellData == 2)
	{
		box.setFillColor(sf::Color::Blue);
	}
	if (typeOfCellData == 3)
	{
		box.setFillColor(sf::Color::Red);
	}
	if (typeOfCellData == 4)
	{
		box.setFillColor(sf::Color::Green);
	}


}

void Cell::setBoardPosition(int t_x, int t_y)
{
	
	index.x = t_x;
	index.y = t_y;
}



sf::RectangleShape Cell::getBox()
{
	return box;
}
