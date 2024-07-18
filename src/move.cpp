#include "move.h"

// Constructor
Move::Move(){
    this->user_input = "";
    this->from = 0;
    this->to = 0;
}

// Destructor
Move::~Move(){
    // do nothing
}

// Get the `from` bitboard
uint64_t Move::get_from_bb(){
    return this->from;
}

// Get the `to` bitboard
uint64_t Move::get_to_bb(){
    return this->to;
}

/* Populate the `from` and `to` bitboards from chess notation.
Input: user_input - a string representing the move in chess notation.
Output: 1 on success, 0 on failure.
*/
int Move::parse_move(string user_input){
    // FIXME: currently only supports a subset of chess notation (e.g. "e2e4" or "E2E4")
    this->user_input = user_input;
    this->from = 0;
    this->to = 0;

    // check if the input is valid
    if (user_input.length() != 4) {
        return 0;
    }
    // check if the first value is a letter a-h or A-H
    if ((user_input[0] < 'a' || user_input[0] > 'h') &&
            (user_input[0] < 'A' || user_input[0] > 'H')){
        return 0;
    }
    // check if the second value is a number 1-8
    if (user_input[1] < '1' || user_input[1] > '8'){
        cout << "Invalid move: " << user_input << endl;
        return 0;
    }
    // check if the third value is a letter a-h or A-H
    if ((user_input[2] < 'a' || user_input[2] > 'h') &&
            (user_input[2] < 'A' || user_input[2] > 'H')){
        cout << "Invalid move: " << user_input << endl;
        return 0;
    }
    // check if the fourth value is a number 1-8
    if (user_input[3] < '1' || user_input[3] > '8'){
        cout << "Invalid move: " << user_input << endl;
        return 0;
    }

    // convert the `from` square to a bitboard
    this->from = 1ULL << (8 * (8 - (int)user_input[1] + '0') +
        (int)user_input[0] - 'a');

    // convert the `to` square to a bitboard
    this->to = 1ULL << (8 * (8 - (int)user_input[3] + '0') +
        (int)user_input[2] - 'a');

    return 1;
}
