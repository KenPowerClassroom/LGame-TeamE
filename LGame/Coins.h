#pragma once
#include <SFML/Graphics.hpp>
#include "Cell.h"

class Coins
{
public:
	Coins();

	// Handles coin validation
	void coinMoves(int t_col, int t_row, int t_tempRow, int t_tempCol, Cell grid[4][4]);
	bool coinSelection(int t_col, int t_row, Cell grid[4][4]);

	// Checks if a coin is selected
	bool m_coinSelected = false;

private:
	// Checking if L is placed
	bool m_coinTurn = false;
};

