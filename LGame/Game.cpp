#include "Game.h"
#include <iostream>

/// <summary>
/// default constructor
/// setup the window properties
/// load and setup the text 
/// load and setup thne image
/// </summary>
Game::Game() :
	m_window{ sf::VideoMode{ 600, 400}, "L-Game" },
	m_exitGame{ false } //when true game will exit
{
	setupFontAndText(); // load font 
	block.setSize(sf::Vector2f(cellSize, cellSize));
	setupGrid();
}

/// <summary>
/// default destructor we didn't dynamically allocate anything
/// so we don't need to free it, but mthod needs to be here
/// </summary>
Game::~Game()
{
}

/// <summary>
/// main game loop
/// update 60 times per second,
/// process update as often as possible and at least 60 times per second
/// draw as often as possible but only updates are on time
/// if updates run slow then don't render frames
/// </summary>
void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	const float fps{ 60.0f };
	sf::Time timePerFrame = sf::seconds(1.0f / fps); // 60 fps
	while (m_window.isOpen())
	{
		processEvents(); // as many as possible
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents(); // at least 60 fps
			update(timePerFrame); //60 fps
		}
		render(); // as many as possible
	}
}

/// <summary>
/// handle user and system events/ input
/// get key presses/ mouse moves etc. from OS
/// and user :: Don't do game update here
/// </summary>
void Game::processEvents()
{
	sf::Event newEvent;
	while (m_window.pollEvent(newEvent))
	{
		if (sf::Event::Closed == newEvent.type) // window message
		{
			m_exitGame = true;
		}
		if (sf::Event::KeyPressed == newEvent.type) //user pressed a key
		{
			processKeys(newEvent);
		}
		if (sf::Event::MouseButtonPressed == newEvent.type)
		{
			if (sf::Mouse::Left == newEvent.mouseButton.button)
			{
				if (newEvent.mouseButton.x < 400 && grid[newEvent.mouseButton.y / 100][newEvent.mouseButton.x / 100].typeOfCell() == (0))
				{
					if (m_player == 2 || m_player == 3)
					{
						if (numberCheck())
						{
							checkForClicks(newEvent.mouseButton.x / 100, newEvent.mouseButton.y / 100);
							changeGridData(newEvent.mouseButton.x / 100, newEvent.mouseButton.y / 100);

							if (validateMovement())
							{
								m_turnythingy.setString("Valid Move switching turns!");
								std::cout << "Valid you invalid" << std::endl;
								m_tempPlayer = m_player;
								m_player = 1;
							}
							else 
							{
								if (maxPlayernum == 4)
								{
									m_turnythingy.setString("Invalid ! right click to reset");
									std::cout << "Invalid ! right click to reset" << std::endl;
								}
							}
						}
					}
				}
				if (m_player == 1)
				{
					if (!m_coinSelected)
					{
						coinSelection(newEvent.mouseButton.x / 100, newEvent.mouseButton.y / 100);
						m_tempRow = newEvent.mouseButton.y / 100;
						m_tempCol = newEvent.mouseButton.x / 100;
					}
					else
					{
						coinMoves(newEvent.mouseButton.x / 100, newEvent.mouseButton.y / 100);
					}
				}
			}
			if (m_player == 2 || m_player == 3)
			{
				if (sf::Mouse::Right == newEvent.mouseButton.button)
				{
					clearCurrent();
					
				}
			}
		}
	}
}


/// <summary>
/// deal with key presses from the user
/// </summary>
/// <param name="t_event">key press event</param>
void Game::processKeys(sf::Event t_event)
{
	if (sf::Keyboard::Escape == t_event.key.code)
	{
		m_exitGame = true;
	}
}

/// <summary>
/// Update the game world
/// </summary>
/// <param name="t_deltaTime">time interval per frame</param>
void Game::update(sf::Time t_deltaTime)
{
	if (m_exitGame)
	{
		m_window.close();
	}
}


/// <summary>
/// draw the frame and then switch buffers
/// </summary>
void Game::render()
{
	m_window.clear(sf::Color::Black);
	m_window.draw(m_welcomeMessage);
	for (int row = 0; row < numRows; row++)
	{
		for (int col = 0; col < numCols; col++)
		{
			m_window.draw(grid[row][col].getBox());
		}
	}	
	m_window.display();
}

/// <summary>
/// load the font and setup the text message for screen
/// </summary>
void Game::setupFontAndText()
{
	if (!m_ArialBlackfont.loadFromFile("FONTS\\ariblk.ttf"))
	{
		std::cout << "problem loading arial black font" << std::endl;
	}
	m_welcomeMessage.setFont(m_ArialBlackfont);
	m_welcomeMessage.setString("");
	m_welcomeMessage.setStyle(sf::Text::Underlined | sf::Text::Italic | sf::Text::Bold);
	m_welcomeMessage.setPosition(40.0f, 40.0f);
	m_welcomeMessage.setCharacterSize(80U);
	m_welcomeMessage.setOutlineColor(sf::Color::Red);
	m_welcomeMessage.setFillColor(sf::Color::Black);
	m_welcomeMessage.setOutlineThickness(3.0f);

}

bool Game::numberCheck()
{
	if (maxPlayernum < 4)
	{
		maxPlayernum++;
		return true;
	}
	else
	{
		return false;
	}
}

void Game::checkForClicks(int t_col,int t_row)
{
	if (data[t_row][t_col] == m_player)
	{
		samePosTracker++;
	}
}

void Game::coinMoves(int t_col, int t_row)
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

			if (grid[m_tempRow][m_tempCol].typeOfCell() == 4)
			{
				if (m_coinSelected)
				{
					grid[m_tempRow][m_tempCol].setDataType(0);
					grid[m_tempRow][m_tempCol].setUpBoxColor();
					m_coinSelected = false;

					if (m_tempPlayer == 3)
					{
						m_player = 2;
					}
					else
					{
						m_player = 3;
					}
				}
			}
		}
	}
}

bool Game::coinSelection(int t_col, int t_row)
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



void Game::setupGrid()
// Initialize the game objects to play a new game
{
	//level data (local)
	int levelData[numRows][numCols] = {
		{1,2,2,0},
		{0,2,3,0},
		{0,2,3,0},
		{0,3,3,1},

	};

	for (int row = 0; row < numRows; row++)
	{
		for (int col = 0; col < numCols; col++)
		{
			//sets up the cell data and tells it to set itself up
			grid[row][col].setDataType(levelData[row][col]);
			grid[row][col].setBoardPosition(col, row);
			grid[row][col].setup();
		}
	}
}

void Game::changeGridData(int t_col, int t_row)
{
	
	grid[t_row][t_col].setDataType(m_player);
	grid[t_row][t_col].setup();
}

bool Game::validateMovement()
{
	for (int row = 0; row < numRows; row++)
	{
		for (int col = 0; col < numCols; col++)
		{
			if (samePosTracker == 3)
			{
				return false;
			}
				//its somewhat worken
				if (!(row + 1 > 3 || col + 1 > 3 || col + 2 > 3))
				{
					if (samePosTracker != 3)
					{
						if (grid[row + 1][col].typeOfCell() == m_player &&
							grid[row][col].typeOfCell() == m_player &&
							grid[row][col + 1].typeOfCell() == m_player &&
							grid[row][col + 2].typeOfCell() == m_player)
						{


							return true; //fuck no
						}
					}
				}
				if (!(row - 1 < 0 || col + 1 > 3 || col + 2 > 3))
				{
					if (samePosTracker != 3)
					{
						if (grid[row - 1][col].typeOfCell() == m_player &&
							grid[row][col].typeOfCell() == m_player &&
							grid[row][col + 1].typeOfCell() == m_player &&
							grid[row][col + 2].typeOfCell() == m_player)
						{
							return true;
						}
					}
				}
				if (!(row - 1 < 0 || col + 1 > 3 || col + 2 > 3))
				{
					if (samePosTracker != 3)
					{
						if (grid[row][col].typeOfCell() == m_player &&
							grid[row][col + 1].typeOfCell() == m_player &&
							grid[row][col + 2].typeOfCell() == m_player &&
							grid[row - 1][col + 2].typeOfCell() == m_player)

						{
							return true;
						}
					}
				}
				if (!(row + 1 < 0 || col + 1 > 3 || col + 2 > 3))
				{
					if (samePosTracker != 3)
					{
						if (grid[row][col].typeOfCell() == m_player &&
							grid[row][col + 1].typeOfCell() == m_player &&
							grid[row][col + 2].typeOfCell() == m_player &&
							grid[row + 1][col + 2].typeOfCell() == m_player)
						{
							return true;
						}
					}
				}
				if (!(col - 1 < 0 || row + 1 > 3 || row + 2 > 3))
				{
					if (samePosTracker != 3)
					{
						if (grid[row][col].typeOfCell() == m_player &&
							grid[row + 1][col].typeOfCell() == m_player &&
							grid[row + 2][col].typeOfCell() == m_player &&
							grid[row + 2][col - 1].typeOfCell() == m_player)
						{
							return true;//fuck no
						}
					}
				}
				if (!(col + 1 > 3 || row + 1 > 3 || row + 2 > 3))
				{
					if (samePosTracker != 3)
					{
						if ((grid[row][col].typeOfCell() == m_player &&
							grid[row + 1][col].typeOfCell() == m_player &&
							grid[row + 2][col].typeOfCell() == m_player &&
							grid[row + 2][col + 1].typeOfCell() == m_player)) //fuck no
						{
							return true;
						}
					}
				}
				if (!(col - 1 < 0 || row + 1 > 3 || row + 2 > 3))
				{
					if (samePosTracker != 3)
					{
						if (grid[row][col].typeOfCell() == m_player &&
							grid[row + 1][col].typeOfCell() == m_player &&
							grid[row + 2][col].typeOfCell() == m_player &&
							grid[row][col - 1].typeOfCell() == m_player) //fuck no
						{
							return true;
						}
					}
				}
				if (!(col + 1 > 3 || row + 1 > 3 || row + 2 > 3))
				{
					if (samePosTracker != 3)
					{
						if (grid[row][col].typeOfCell() == m_player &&
							grid[row + 1][col].typeOfCell() == m_player &&
							grid[row + 2][col].typeOfCell() == m_player &&
							grid[row][col + 1].typeOfCell() == m_player) //fuck no
						{
							return true;
						}
					}
				}
		}
	}
	return false;
}


// Clears the players L off the board
void Game::clearCurrent()
{
	for (int row = 0; row < numRows; row++)
	{
		for (int col = 0; col < numCols; col++)
		{
			if (grid[row][col].typeOfCell() == m_player && (currentPLayernum > -1))
			{
				currentPLayernum--;
				grid[row][col].setDataType(0);
				grid[row][col].setup();
			}
			else
			{
				grid[row][col].setPreviouslySelected(false);
			}
		}
	}
	currentPLayernum = 3;
	maxPlayernum = 0;
	samePosTracker = 0;
}

