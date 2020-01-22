#pragma once
#include "SFML/Graphics.hpp" 

class Cell
{
	
	public:
	int typeOfCellData;
		//0 could represent an empty cell, 1 a coin and 2 a tetro.

	sf::RectangleShape box;

public:
	Cell();
	int typeOfCell();


	sf::RectangleShape getBox();

	inline void setPosition(sf::Vector2f t_pos) { box.setPosition(t_pos); }
};