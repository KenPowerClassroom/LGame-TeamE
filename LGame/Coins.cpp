#include "Coins.h"

Coins::Coins()
{
}

void Coins::coinMoves(int t_col, int t_row, int t_tempRow, int t_tempCol, Cell grid[4][4])
{
	if (m_coinSelected) // If the coin is selected
	{
		if (grid[t_row][t_col].typeOfCell() == 0) // If the cell is empty
		{
			grid[t_row][t_col].setDataType(1); // Place the coin in the empty space
			grid[t_row][t_col].setUpBoxColor(); // Set the cell color
			m_coinSelected = false; // You are no longer holding the coin
		}

		if (!m_coinSelected) // If the coin is not selected
		{
			if (grid[t_tempRow][t_tempCol].typeOfCell() == 4) // If the previously selected cell is green (selected)
			{
				grid[t_tempRow][t_tempCol].setDataType(0); // Set the cell to empty
				grid[t_tempRow][t_tempCol].setUpBoxColor(); // Set the cell color
			}
		}
	}
}

bool Coins::coinSelection(int t_col, int t_row, Cell grid[4][4])
{
	if (grid[t_row][t_col].typeOfCell() == 1) // If you select a coin
	{
		if (!m_coinSelected) // And you arent already holding a coin
		{
			grid[t_row][t_col].setDataType(4); // Pick up the coin
			grid[t_row][t_col].setUpBoxColor(); // Set the cell color
			m_coinSelected = true; // You are now holding the coin
			return true; // You have successfully selected a coin
		}
	}

	return false; // You have failed to select a coin
}

