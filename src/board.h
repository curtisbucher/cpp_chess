#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include "move.h"

class Board
{
  public:
    // bitboards for representation
    uint64_t white_pawns_bb;
    uint64_t white_rooks_bb;
    uint64_t white_knights_bb;
    uint64_t white_bishops_bb;
    uint64_t white_queens_bb;
    uint64_t white_kings_bb;

    uint64_t black_pawns_bb;
    uint64_t black_rooks_bb;
    uint64_t black_knights_bb;
    uint64_t black_bishops_bb;
    uint64_t black_queens_bb;
    uint64_t black_kings_bb;

    Board();
    ~Board();
    void print_board();
    void execute_move(Move move);
};

#endif