# Minimal Viable Product (MVP) 

## Outline MVP functionality

The simplest version of this game that we can create will still be fairly complicated. The L game is a big game, and contains a lot of small things that a 'not engineer' won't think about or undestand. It will setup the game, allow both players to move around and move coins, and see if a player has no moves left. If there are no moves left, the game will end. This is the least amount of functionality that needs to be implemented, that will create a viable L game.

## List the features of the MVP
- Display the board
- Display the Coins, Tetrominos and empty spaces on the board
- Allow player one to move his tetromino by clicking and dragging
- Validate to see if the move is legal, otherwise go back to above step
- Player One's coin movement and validation of it
- A check to see if there are any available moves left
- Switch turns to player Two
- If player two has available turns, allow him to do the previous steps, or else the game ends

## Out Of Scope

Explicity describe what is not part of MVP


## List of stories needed to complete the MVP `aim for 8 stories`

1. `Create Board` Create the board which contains the game data

The board needs to contain all the possible data that the player will need to know; If the tile contains a friendly tetromino, or a rival tetromino, if the tile contains a coin or if the tile is empty. This will be done by creating a 2D array of Tile classes. The Tile class will contain an int where it's type is set. eq, a tile of type 4 will be blank. The game and player's actions will interacact with this data to test for validity of moves, or to tell the player how many moves are left.

2. Story-name

As a user `usually player, but can be developer` I need to be able to `do something` so that I can `complete and objective`.


