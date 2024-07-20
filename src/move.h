#ifndef MOVE_H
#define MOVE_H

#include <iostream>
#include <string>
#include "bitboard.h"

using namespace std;

class Move{
    public:
    // constructor
    Move(bool white);
    // destructor
    ~Move();
	// get the `from` bitboard
    bitboard get_from_bb();
    uint8_t get_from_idx();
    // get `to` bitboard
    bitboard get_to_bb();
    uint8_t get_to_idx();
    // parse the move from chess_notation, return 1 on success, 0 on failure
    int from_cn(string user_input);
    // go from bitboard to chess notation
    string to_cn();
    // return the color of the player
    bool is_white();

    private:
    // the indexes of the square A1 = 0, H8 = 63
    uint8_t from;
    uint8_t to;
    string user_input;
    bool white;
};

#endif // !DEBUG MOVE_H