#include "move.h"
#include "bitboard.h"

/* Constructor
input: white - The color of the player making the move*/
Move::Move(bool white){
    this->white = white;
    this->user_input = "";
    this->from = 0;
    this->to = 0;
}

// Destructor
Move::~Move(){
    // do nothing
}

// Get the `from` bitboard
bitboard Move::get_from_bb(){
    return 1ULL << this->from;
}
uint8_t Move::get_from_idx(){
    return this->from;
}

// Get the `to` bitboard
bitboard Move::get_to_bb(){
    return 1ULL << this->to;
}

uint8_t Move::get_to_idx(){
    return this->to;
}

/* Populate the `from` and `to` bitboards from chess notation.
Input: user_input - a string representing the move in chess notation.
Output: 1 on success, 0 on failure.
*/
int Move::from_cn(string user_input){
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

    uint8_t from_file = user_input[0] <= 'H' ? user_input[0] - 'A' : user_input[0] - 'a';
    uint8_t from_rank = user_input[1] - '1';
    uint8_t to_file = user_input[2] <= 'H' ? user_input[2] - 'A' : user_input[2] - 'a';
    uint8_t to_rank = user_input[3] - '1';

    this->from = from_rank * 8 + from_file;
    this->to = to_rank * 8 + to_file;

    return 1;
}

string Move::to_cn(){
    string result = "";
    char from_file = this->from % 8ULL;
    char from_rank = this->from / 8ULL;
    char to_file = this->to % 8ULL;
    char to_rank = this->to / 8ULL;

    result += (char)from_file + 'A';
    result += (char)from_rank + '1';
    result += (char)to_file + 'A';
    result += (char)to_rank + '1';

    return result;
}

// return whether the move is made by white
bool Move::is_white(){
    return this->white;
}