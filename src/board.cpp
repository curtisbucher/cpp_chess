#include "board.h"

// constructor
Board::Board(){
    // initialize bitboards
    this->white_pawns_bb = W_PAWNS_DEFAULT;
    this->white_rooks_bb = W_ROOKS_DEFAULT;
    this->white_knights_bb = W_KNIGHTS_DEFAULT;
    this->white_bishops_bb = W_BISHOPS_DEFAULT;
    this->white_queens_bb = W_QUEENS_DEFAULT;
    this->white_kings_bb = W_KINGS_DEFAULT;

    this->black_pawns_bb = B_PAWNS_DEFAULT;
    this->black_rooks_bb = B_ROOKS_DEFAULT;
    this->black_knights_bb = B_KNIGHTS_DEFAULT;
    this->black_bishops_bb = B_BISHOPS_DEFAULT;
    this->black_queens_bb = B_QUEENS_DEFAULT;
    this->black_kings_bb = B_KINGS_DEFAULT;
}

// destructor
Board::~Board(){
    // do nothing
}

// print the board
void Board::print_board(){
    // print the board
    cout << "    A B C D E F G H" << endl;
    cout << "  ┌─────────────────┐" << endl; // Add a space between the row/column labels and the board
    for (int i = 0; i < 8; i++){
        cout << 8 - i << " │ ";
        for (int j = 0; j < 8; j++){
            uint64_t square = 1ULL << (i * 8 + j);
            if (this->white_pawns_bb & square){
                cout << "P ";
            } else if (this->white_rooks_bb & square){
                cout << "R ";
            } else if (this->white_knights_bb & square){
                cout << "N ";
            } else if (this->white_bishops_bb & square){
                cout << "B ";
            } else if (this->white_queens_bb & square){
                cout << "Q ";
            } else if (this->white_kings_bb & square){
                cout << "K ";
            } else if (this->black_pawns_bb & square){
                cout << "p ";
            } else if (this->black_rooks_bb & square){
                cout << "r ";
            } else if (this->black_knights_bb & square){
                cout << "n ";
            } else if (this->black_bishops_bb & square){
                cout << "b ";
            } else if (this->black_queens_bb & square){
                cout << "q ";
            } else if (this->black_kings_bb & square){
                cout << "k ";
            } else {
                cout << ". ";
            }
        }
        cout << "│ " << 8 - i << endl;
    }
    cout << "  └─────────────────┘" << endl; // Add a space between the row/column labels and the board
    cout << "    A B C D E F G H" << endl;
}

// Execute a move without checking legality
void Board::execute_move(Move move){
    // get the from and to squares
    uint64_t from_square = move.get_from_bb();
    uint64_t to_square = move.get_to_bb();

    // check the piece type
    if (this->white_pawns_bb & from_square){
        this->white_pawns_bb &= ~from_square;
        this->white_pawns_bb |= to_square;
    } else if (this->white_rooks_bb & from_square){
        this->white_rooks_bb &= ~from_square;
        this->white_rooks_bb |= to_square;
    } else if (this->white_knights_bb & from_square){
        this->white_knights_bb &= ~from_square;
        this->white_knights_bb |= to_square;
    } else if (this->white_bishops_bb & from_square){
        this->white_bishops_bb &= ~from_square;
        this->white_bishops_bb |= to_square;
    } else if (this->white_queens_bb & from_square){
        this->white_queens_bb &= ~from_square;
        this->white_queens_bb |= to_square;
    } else if (this->white_kings_bb & from_square){
        this->white_kings_bb &= ~from_square;
        this->white_kings_bb |= to_square;
    } else if (this->black_pawns_bb & from_square){
        this->black_pawns_bb &= ~from_square;
        this->black_pawns_bb |= to_square;
    } else if (this->black_rooks_bb & from_square){
        this->black_rooks_bb &= ~from_square;
        this->black_rooks_bb |= to_square;
    } else if (this->black_knights_bb & from_square){
        this->black_knights_bb &= ~from_square;
        this->black_knights_bb |= to_square;
    } else if (this->black_bishops_bb & from_square){
        this->black_bishops_bb &= ~from_square;
        this->black_bishops_bb |= to_square;
    } else if (this->black_queens_bb & from_square){
        this->black_queens_bb &= ~from_square;
        this->black_queens_bb |= to_square;
    } else if (this->black_kings_bb & from_square){
        this->black_kings_bb &= ~from_square;
        this->black_kings_bb |= to_square;
    } else {
        cout << "Invalid move" << endl;
    }
}
