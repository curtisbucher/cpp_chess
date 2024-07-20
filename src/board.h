#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include "move.h"

// define starting poositions
// initialize bitboards
#define W_PAWNS_DEFAULT (0x000000000000FF00)
#define W_ROOKS_DEFAULT (0x0000000000000081)
#define W_KNIGHTS_DEFAULT (0x0000000000000042)
#define W_BISHOPS_DEFAULT (0x0000000000000024)
#define W_QUEENS_DEFAULT  (0x0000000000000008)
#define W_KINGS_DEFAULT (0x0000000000000010)

#define B_PAWNS_DEFAULT (0x00FF000000000000)
#define B_ROOKS_DEFAULT (0x8100000000000000)
#define B_KNIGHTS_DEFAULT (0x4200000000000000)
#define B_BISHOPS_DEFAULT (0x2400000000000000)
#define B_QUEENS_DEFAULT (0x0800000000000000)
#define B_KINGS_DEFAULT (0x1000000000000000)

// define rank, files and squares
#define RANK_1 (0x0101010101010101)
#define RANK_2 (0x0202020202020202)
#define RANK_3 (0x0404040404040404)
#define RANK_4 (0x0808080808080808)
#define RANK_5 (0x1010101010101010)
#define RANK_6 (0x2020202020202020)
#define RANK_7 (0x4040404040404040)
#define RANK_8 (0x8080808080808080)

#define FILE_A (0x00000000000000FF)
#define FILE_B (0x000000000000FF00)
#define FILE_C (0x0000000000FF0000)
#define FILE_D (0x00000000FF000000)
#define FILE_E (0x000000FF00000000)
#define FILE_F (0x0000FF0000000000)
#define FILE_G (0x00FF000000000000)
#define FILE_H (0xFF00000000000000)

#define IDX_TO_BB(x) (1ULL << (x))

enum EnumSquare {
  A1, B1, C1, D1, E1, F1, G1, H1,
  A2, B2, C2, D2, E2, F2, G2, H2,
  A3, B3, C3, D3, E3, F3, G3, H3,
  A4, B4, C4, D4, E4, F4, G4, H4,
  A5, B5, C5, D5, E5, F5, G5, H5,
  A6, B6, C6, D6, E6, F6, G6, H6,
  A7, B7, C7, D7, E7, F7, G7, H7,
  A8, B8, C8, D8, E8, F8, G8, H8
};

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