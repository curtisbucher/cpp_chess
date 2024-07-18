#ifndef MOVE_H
#define MOVE_H

#include <iostream>
#include <string>

using namespace std;

enum enumSquare {
  a1, b1, c1, d1, e1, f1, g1, h1,
  a2, b2, c2, d2, e2, f2, g2, h2,
  a3, b3, c3, d3, e3, f3, g3, h3,
  a4, b4, c4, d4, e4, f4, g4, h4,
  a5, b5, c5, d5, e5, f5, g5, h5,
  a6, b6, c6, d6, e6, f6, g6, h6,
  a7, b7, c7, d7, e7, f7, g7, h7,
  a8, b8, c8, d8, e8, f8, g8, h8
};

class Move{
    public:
    // constructor
    Move();
    // destructor
    ~Move();
	// get the `from` bitboard
    uint64_t get_from_bb();
    // get `to` bitboard
    uint64_t get_to_bb();
    // parse the move from chess_notation, return 1 on success, 0 on failure
    int from_cn(string user_input);
    // go from bitboard to chess notation
    string to_cn();

    private:
    // the indexes of the square A1 = 0, H8 = 63
    uint8_t from;
    uint8_t to;
    string user_input;
};

#endif // !DEBUG MOVE_H