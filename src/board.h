#ifndef BOARD_H
#define BOARD_H

#include "move.h"
#include "bitboard.h"

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
    bitboard white_pawns_bb;
    bitboard white_rooks_bb;
    bitboard white_knights_bb;
    bitboard white_bishops_bb;
    bitboard white_queens_bb;
    bitboard white_kings_bb;

    bitboard black_pawns_bb;
    bitboard black_rooks_bb;
    bitboard black_knights_bb;
    bitboard black_bishops_bb;
    bitboard black_queens_bb;
    bitboard black_kings_bb;

    Board();
    ~Board();
    void print_board();
    void execute_move(Move move);
    bool is_legal(Move move);

  protected:
    bitboard get_white_spaces();
    bitboard get_black_spaces();
    bitboard get_empty_spaces();
    bool is_legal_pawn(Move move);
    bool is_legal_rook(Move move);
    bool is_legal_knight(Move move);
    bool is_legal_bishop(Move move);
    bool is_legal_queen(Move move);
    bool is_legal_king(Move move);
};

#endif