#include <iostream>
#include "board.h"
#include "bitboard.h"

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

bitboard Board::get_white_spaces(){
    return this->white_pawns_bb | this->white_rooks_bb | this->white_knights_bb |
        this->white_bishops_bb | this->white_queens_bb | this->white_kings_bb;
}

bitboard Board::get_black_spaces(){
    return this->black_pawns_bb | this->black_rooks_bb | this->black_knights_bb |
        this->black_bishops_bb | this->black_queens_bb | this->black_kings_bb;

}

bitboard Board::get_empty_spaces(){
    return ~(this->get_black_spaces() | this->get_white_spaces());
}
// print the board
void Board::print_board(){
    // print the board
    cout << "    A B C D E F G H" << endl;
    cout << "  ┌─────────────────┐" << endl; // Add a space between the row/column labels and the board
    for (int i = 0; i < 8; i++){
        cout << 8 - i << " │ ";
        for (int j = 0; j < 8; j++){
            bitboard square = 1ULL << (i * 8 + j);
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
    bitboard from_square = move.get_from_bb();
    bitboard to_square = move.get_to_bb();


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

bool Board::is_legal(Move move){
    bitboard from = move.get_from_bb();
    bitboard to = move.get_to_bb();

    // check if the move is legal
    bitboard white_pieces = this->get_white_spaces();
    bitboard black_pieces = this->get_black_spaces();

    // check that `from` peice corresponds to player
    if(move.is_white() && !(from & white_pieces)){
        return false;
    } else if(!move.is_white() && !(from & black_pieces)){
        return false;
    }

    // go through each piece type and check if the move is legal
    if(from & (this->white_pawns_bb | this->black_pawns_bb)){
        return this->is_legal_pawn(move);
    }
    else if(from & (this->white_rooks_bb | this->black_rooks_bb)){
        return this->is_legal_rook(move);
    }
    else if(from & (this->white_knights_bb | this->black_knights_bb)){
        return this->is_legal_knight(move);
    }
    else if(from & (this->white_bishops_bb | this->black_bishops_bb)){
        return this->is_legal_bishop(move);
    }
    else if(from & (this->white_queens_bb | this->black_queens_bb)){
        return this->is_legal_queen(move);
    }
    else if(from & (this->white_queens_bb | this->black_queens_bb)){
        return this->is_legal_king(move);
    }
    else {
        // should be unreachable
        return false;
    }

    // legal
    return true;
}

bool Board::is_legal_pawn(Move move){
    bool white = move.is_white();

    bitboard legal_moves = 0;
    bitboard empty = this->get_empty_spaces();
    bitboard black = this->get_black_spaces();

    bitboard from_bb = move.get_from_bb();
    uint8_t from_idx = move.get_from_idx();
    bitboard to_bb = move.get_to_bb();
    uint8_t to_idx = move.get_to_idx();

    /** WHITE PAWN **/
    if(white){
        // 1 forward if not blocked
        legal_moves |= ((from_bb << 8) & empty);
        // 2 forward if not blocked and on first square
        if((from_bb & RANK_2) && ((from_bb << 8) & empty)){
            legal_moves |= (from_bb << 16) & empty;
        }
        // diagonal capture if black is there
        legal_moves |= (from_bb << 7 & black) | (from_bb << 9 & black);
        print_bb(legal_moves);

        return (to_bb & legal_moves) && (from_bb & this->white_pawns_bb);
    }

    /* BLACK PAWN */
    // 1 forward if not blocked
    legal_moves |= (from_bb >> 8 & empty);
    // 2 forward if not blocked and on first square
    if((from_bb & RANK_2) && (from_bb >> 8 & empty)){
        legal_moves |= (from_bb >> 16 & empty);
    }
    // diagonal capture if black is there
    legal_moves |= (from_bb >> 7 & black) | (from_bb >> 9 & black);
    return to_bb & legal_moves && (from_bb && this->black_pawns_bb);
}

bool Board::is_legal_rook(Move move){
    return true;
}

bool Board::is_legal_knight(Move move){
    return true;
}

bool Board::is_legal_bishop(Move move){
    return true;
}

bool Board::is_legal_queen(Move move){
    return true;
}

bool Board::is_legal_king(Move move){
    return true;
}
