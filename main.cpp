//Contain definitions
#include <iostream>
#include "Grid.h"
#include <stdio.h>



int main() {
    Grid grid;
    int tempRow;
    int tempColumn;

    while(grid.getGameRunning())
    {

        while(true)
        {
            //player 1 input
            grid.display();
            std::cout << "Player 1\nRow:";
            std::cin >> tempRow;
            tempRow--;
            std::cout << "Column: ";
            std::cin >> tempColumn;
            tempColumn--;
            if(grid.validInput(tempRow, tempColumn))
            {
                break;
            }
            std::cout << "Input was not valid" << std::endl;

        }
        grid.placeX(tempRow, tempColumn);
        grid.checkWinner();


        while(true)
        {
            //player 2
            grid.display();
            std::cout << "Player 2\nRow:";
            std::cin >> tempRow;
            tempRow--;
            std::cout << "Column: ";
            std::cin >> tempColumn;
            tempColumn--;
            if(grid.validInput(tempRow, tempColumn))
            {
                break;
            }
            std::cout << "Input was not valid" << std::endl;
        }

        grid.placeO(tempRow, tempColumn);
        grid.checkWinner();

    }

    return 0;
}