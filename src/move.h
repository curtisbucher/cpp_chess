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
    // parse the move, return 1 on success, 0 on failure
    int parse_move(string user_input);

    private:
    uint64_t from;
    uint64_t to;
    string user_input;
};

#endif // !DEBUG MOVE_H