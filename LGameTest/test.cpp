#include "gtest/gtest.h"
#include "..//LGame/Cell.h"
#include "..//LGame/Game.h"

#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-network-d.lib") 
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#endif 

TEST()
{
	int levelData[4][4] = {
		{1,2,2,0},
		{0,2,3,0},
		{0,2,3,0},
		{0,3,3,1},
	};

	Cell selectedCell[4][4];
	Game game;
	Coins coin;
	bool m_coinSelected = false;
	sf::Event newEvent;

	if (sf::Event::MouseButtonPressed == newEvent.type)
	{
		if (sf::Mouse::Left == newEvent.mouseButton.button)
		{
			if (!m_coinSelected)
			{
				coin.coinSelection(newEvent.mouseButton.x / 100, newEvent.mouseButton.y / 100, game.grid);
				game.m_tempRow = newEvent.mouseButton.y / 100;
				game.m_tempCol = newEvent.mouseButton.x / 100;
			}
			else
			{
				coin.coinMoves(newEvent.mouseButton.x / 100, newEvent.mouseButton.y / 100,  game.m_player, game.m_tempRow, game.m_tempCol, game.grid);
			}
		}
	}	

	EXPECT_EQ(selectedCell[0][3].typeOfCell(), 1);
}

TEST(TestCaseName, TestName) 
{
	int levelData[4][4] = {
		{1,2,2,0},
		{0,2,3,0},
		{0,2,3,0},
		{0,3,3,1},
	};

	Cell help[4][4];

	for (int row = 0; row < 4; row++)
	{
		for (int col = 0; col < 4; col++)
		{
			//sets up the cell data and tells it to set itself up
			help[row][col].setDataType(levelData[col][row]);
			help[row][col].setBoardPosition(row, col);
			help[row][col].setup();
		}
	}

	for (int row = 0; row < 4; row++)
	{
		for (int col = 0; col < 4; col++)
		{
			EXPECT_EQ(help[row][col].getBox().getPosition().x, row * 100);
			EXPECT_EQ(help[row][col].getBox().getPosition().y, col * 100);
		}
	}
	

	EXPECT_EQ(help[0][0].typeOfCell(), 1);
	EXPECT_EQ(help[0][1].typeOfCell(), 0);
	EXPECT_EQ(help[0][2].typeOfCell(), 0);
	EXPECT_EQ(help[0][3].typeOfCell(), 0);

	EXPECT_EQ(help[1][0].typeOfCell(), 2);
	EXPECT_EQ(help[1][1].typeOfCell(), 2);
	EXPECT_EQ(help[1][2].typeOfCell(), 2);
	EXPECT_EQ(help[1][3].typeOfCell(), 3);

	EXPECT_EQ(help[2][0].typeOfCell(), 2);
	EXPECT_EQ(help[2][1].typeOfCell(), 3);
	EXPECT_EQ(help[2][2].typeOfCell(), 3);
	EXPECT_EQ(help[2][3].typeOfCell(), 3);

	EXPECT_EQ(help[3][0].typeOfCell(), 0);
	EXPECT_EQ(help[3][1].typeOfCell(), 0);
	EXPECT_EQ(help[3][2].typeOfCell(), 0);
	EXPECT_EQ(help[3][3].typeOfCell(), 1);

	EXPECT_EQ(help[0][0].getBox().getFillColor(), sf::Color::Yellow);
	EXPECT_EQ(help[0][1].getBox().getFillColor(), sf::Color::White);
	EXPECT_EQ(help[1][3].getBox().getFillColor(), sf::Color::Red);
	EXPECT_EQ(help[2][0].getBox().getFillColor(), sf::Color::Blue);

	//EXPECT_EQ(help[0][0].getBox().getPosition().x, 0);

    //EXPECT_TRUE(true);
	
}

TEST(MouseClick, ColourChanged)
{
	int levelData[4][4] = {
		{1,2,2,0},
		{0,2,3,0},
		{0,2,3,0},
		{0,3,3,1},
	};
	bool mouseTest = false;
	bool clickedOn = true;
	Cell help[4][4];

	for (int row = 0; row < 4; row++)
	{
		for (int col = 0; col < 4; col++)
		{
			//sets up the cell data and tells it to set itself up
			help[row][col].setDataType(levelData[col][row]);
			help[row][col].setBoardPosition(row, col);
			help[row][col].setup();
		}
	}
	if (clickedOn)
	{
		help[0][0].setDataType(2);
		help[0][0].setup();
	}
	EXPECT_EQ(help[0][0].typeOfCell(), 2);
	EXPECT_EQ(help[0][0].getBox().getFillColor(), sf::Color::Blue);
}