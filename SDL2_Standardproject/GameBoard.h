//
// Created by clement on 01/06/17.
//

#ifndef SNAKE_PLUSPLUS_GAMEBOARD_H
#define SNAKE_PLUSPLUS_GAMEBOARD_H

class GameBoard{
public:
    GameBoard(int width, int height);


    ~GameBoard();
private:
    int width;
    int height;
    Node board[][];
};

#endif //SNAKE_PLUSPLUS_GAMEBOARD_H
