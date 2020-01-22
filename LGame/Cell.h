#pragma once
#include "SFML/Graphics.hpp" 

class Cell
{
	
	private:
	int typeOfCellData;
		//0 could represent an empty cell, 1 a coin and 2 a tetro.
	sf::Vector2f index;
	//index is the cell's position in the array

	sf::RectangleShape box;
	sf::Vector2f size;
	sf::Vector2f position;


public:
	Cell();
	void setup();
	int typeOfCell();
	void setSize();
	void setDataType(int t_type);
	void setUpBoxColor();
	void setBoardPosition(int t_x, int t_y);


	sf::RectangleShape getBox();

	inline void setPosition() { box.setPosition(index.x * 100, index.y * 100); }
};