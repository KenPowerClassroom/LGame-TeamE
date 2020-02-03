#ifndef GAME_HPP
#define GAME_HPP
/// <summary>
/// include guards used so we don't process this file twice
/// same as #pragma once
/// Don't forget the endif at the bottom
/// </summary>
#include <SFML/Graphics.hpp>
#include "Cell.h"

class Game
{
public:
	Game();
	~Game();
	/// <summary>
	/// main method for game
	/// </summary>
	void run();

private:
	//functiones
	void processEvents();
	void processKeys(sf::Event t_event);
	void update(sf::Time t_deltaTime);
	void render();
	void setupGrid();
	void changeGridData(int t_col, int t_row);
	

	void setupFontAndText();

	sf::RenderWindow m_window; // main SFML window
	sf::Font m_ArialBlackfont; // font used by message
	sf::Text m_welcomeMessage; // text used for message on screen
	sf::Texture m_logoTexture; // texture used for sfml logo
	sf::Sprite m_logoSprite; // sprite used for sfml logo
	bool m_exitGame; // control exiting game
	bool m_clickedOver;
	//grid setup
	static const int numRows = 4;
	static const int numCols = 4;
	const int cellSize = 100;
	const int MAX_CELLS = 16;

	Cell grid[numRows][numCols]; //2d array to create the maze
	int data[numRows][numCols] = { 0 };
	
	sf::RectangleShape block;


};

#endif // !GAME_HPP

