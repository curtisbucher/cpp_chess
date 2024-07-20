#include <iostream>
#include "board.h"


int main() {
    std::cout << "Welcome to BucherChess!\n" << std::endl;

    Board board = Board();
    board.print_board();

    return 0;
}