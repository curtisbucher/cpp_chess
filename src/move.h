#ifndef MOVE_H
#define MOVE_H

#include <iostream>
#include <string>

using namespace std;

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