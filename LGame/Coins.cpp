#include "Coins.h"

Coins::Coins()
{
}

void Coins::coinMoves(int t_col, int t_row, int t_tempRow, int t_tempCol, Cell grid[4][4])
{
	if (m_coinSelected)
	{
		if (grid[t_row][t_col].typeOfCell() == 0)
		{
			if (m_coinSelected)
			{
				grid[t_row][t_col].setDataType(1);
				grid[t_row][t_col].setUpBoxColor();
			}

			if (grid[t_tempRow][t_tempCol].typeOfCell() == 4)
			{
				if (m_coinSelected)
				{
					grid[t_tempRow][t_tempCol].setDataType(0);
					grid[t_tempRow][t_tempCol].setUpBoxColor();
					m_coinSelected = false;
				}
			}
		}
	}
}

bool Coins::coinSelection(int t_col, int t_row, Cell grid[4][4])
{
	if (grid[t_row][t_col].typeOfCell() == 1)
	{
		if (!m_coinSelected)
		{
			grid[t_row][t_col].setDataType(4);
			grid[t_row][t_col].setUpBoxColor();
			m_coinSelected = true;
			return true;
		}
	}

	return false;
}

