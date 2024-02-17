//implementation file
#include "Grid.h"
#include <iostream>

bool gameRunning = true;
char winner;
char grid[9];
char* gridPtr = &grid[0];

bool Grid::getGameRunning()
{
    return gameRunning;
}

void Grid::display()
{
    for(int i = 0; i < 3; i++)
    {
        //forms row and columns
        std::cout << *(gridPtr + 3*i) << *(gridPtr + 1 + 3*i) << *(gridPtr + 2 + 3*i) << std::endl;
    }
    std::cout << std::endl;
}

bool Grid::validInput(int row, int column)
{

    if(row > 2 || column > 2  || row < 0 || column < 0) {return false;}

    if (*(gridPtr + row + column * 3) == '\0') { return true; }

    return false;
}


void Grid::placeX(int row, int column)
{
    *(gridPtr + row+column*3) = 'X';
}

void Grid::placeO(int row, int column)
{
    *(gridPtr + row+column*3) = 'O';
}

void Grid::checkWinner()
{
    //horizontal
    for(int i = 0; i < 3; i ++)
    {
        if(*(gridPtr + 3*i) != '\0' && *(gridPtr + 3*i) == *(gridPtr + 1 + 3*i) && *(gridPtr + 1 + 3*i) == *(gridPtr + 2 + 3*i))
        {
            gameRunning = false;
            winner = *(gridPtr + 3*i);
        }
    }

    //vertical
    for(int i = 0; i < 3; i ++)
    {
        if(*(gridPtr + i) != '\0' && *(gridPtr + i) == *(gridPtr + 3 + i) && *(gridPtr + 3 + i) == *(gridPtr + 6 + i))
        {
            gameRunning = false;
            winner =  *(gridPtr + i);
        }
    }

    //diagonal  left -> right
    if(*(gridPtr) != '\0' && *(gridPtr) == *(gridPtr +4) && *(gridPtr + 4) == *(gridPtr + 8))
    {
        gameRunning = false;
        winner =  *(gridPtr);
    }

    //diagonal right -> left
    if(*(gridPtr + 2) != '\0' && *(gridPtr+2) == *(gridPtr +4) && *(gridPtr + 4) == *(gridPtr + 6))
    {
        gameRunning = false;
        winner = *(gridPtr + 2);
    }
}

char Grid::getWinner()
{
    return winner;
}

void Grid::reset()
{
    for(int i = 0; i < 9; i++)
    {
        *(gridPtr + i) = '\0';
    }
}