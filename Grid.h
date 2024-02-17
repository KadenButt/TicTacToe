//
// Created by kadenbutt on 17/02/24.

//Contain declarations

#ifndef TICTACTOE_GRID_H
#define TICTACTOE_GRID_H


class Grid {




public:

    //checks that nobody has won
    bool getGameRunning();

    //check for valid input
    bool validInput(int row,int column);

    //prints out grid
    void display();

    //places the X on the grid
    void placeX(int row, int column);

    //places the X on the grid
    void placeO(int row, int column);

    //outputs who have won
    void checkWinner();

    char getWinner();

    //resets the grid
    void reset();



};


#endif //TICTACTOE_GRID_H
