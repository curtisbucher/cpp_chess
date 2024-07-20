#include <gtest/gtest.h>
#include <string>
#include "../src/board.h"
#include "../src/move.h"

// test the constructor
TEST(TestBoard, TestConstructor) {
    Move move;
    Board board;
    EXPECT_EQ(board.white_pawns_bb ^ FILE_B, 0);
    EXPECT_EQ(board.white_rooks_bb ^ (IDX_TO_BB(A1) | IDX_TO_BB(H1)), 0);
    EXPECT_EQ(board.white_knights_bb ^ (IDX_TO_BB(B1) | IDX_TO_BB(G1)), 0);
    EXPECT_EQ(board.white_bishops_bb ^ (IDX_TO_BB(C1) | IDX_TO_BB(F1)), 0);
    EXPECT_EQ(board.white_queens_bb ^ IDX_TO_BB(D1), 0);
    EXPECT_EQ(board.white_kings_bb ^ IDX_TO_BB(E1), 0);

    EXPECT_EQ(board.black_pawns_bb ^ FILE_G, 0);
    EXPECT_EQ(board.black_rooks_bb ^ (IDX_TO_BB(A8) | IDX_TO_BB(H8)), 0);
    EXPECT_EQ(board.black_knights_bb ^ (IDX_TO_BB(B8) | IDX_TO_BB(G8)), 0);
    EXPECT_EQ(board.black_bishops_bb ^ (IDX_TO_BB(C8) | IDX_TO_BB(F8)), 0);
    EXPECT_EQ(board.black_queens_bb ^ IDX_TO_BB(D8), 0);
    EXPECT_EQ(board.black_kings_bb ^ IDX_TO_BB(E8), 0);
}

// test executing a move for white pawns
TEST(TestBoard, TestExecuteMoveWhitePawns) {
    Board board;
    Move move;
    move.from_cn("B2B4"); // Move white pawn from B2 to B4
    board.execute_move(move);

    // check that all other bitboards are the same
    EXPECT_NE(board.white_pawns_bb & IDX_TO_BB(B4), 0);
    EXPECT_EQ(board.white_pawns_bb & IDX_TO_BB(B2), 0);

    EXPECT_EQ(board.white_rooks_bb, W_ROOKS_DEFAULT);
    EXPECT_EQ(board.white_rooks_bb, W_ROOKS_DEFAULT);
    EXPECT_EQ(board.white_knights_bb, W_KNIGHTS_DEFAULT);
    EXPECT_EQ(board.white_bishops_bb, W_BISHOPS_DEFAULT);
    EXPECT_EQ(board.white_queens_bb, W_QUEENS_DEFAULT);
    EXPECT_EQ(board.white_kings_bb, W_KINGS_DEFAULT);

    EXPECT_EQ(board.black_pawns_bb, B_PAWNS_DEFAULT);
    EXPECT_EQ(board.black_rooks_bb, B_ROOKS_DEFAULT);
    EXPECT_EQ(board.black_knights_bb, B_KNIGHTS_DEFAULT);
    EXPECT_EQ(board.black_bishops_bb, B_BISHOPS_DEFAULT);
    EXPECT_EQ(board.black_queens_bb, B_QUEENS_DEFAULT);
    EXPECT_EQ(board.black_kings_bb, B_KINGS_DEFAULT);

}

// test executing a move for black rooks
TEST(TestBoard, TestExecuteMoveWhiteKnight) {
    Board board;
    Move move;
    move.from_cn("B1C3"); // Move white knight from B1 to C3
    board.execute_move(move);

    // check that all other bitboards are the same
    EXPECT_EQ(board.white_pawns_bb, W_PAWNS_DEFAULT);
    EXPECT_EQ(board.white_knights_bb, (W_KNIGHTS_DEFAULT & ~IDX_TO_BB(B1)) | IDX_TO_BB(C3));
    EXPECT_EQ(board.white_rooks_bb, W_ROOKS_DEFAULT);
    EXPECT_EQ(board.white_bishops_bb, W_BISHOPS_DEFAULT);
    EXPECT_EQ(board.white_queens_bb, W_QUEENS_DEFAULT);
    EXPECT_EQ(board.white_kings_bb, W_KINGS_DEFAULT);

    EXPECT_EQ(board.black_pawns_bb, B_PAWNS_DEFAULT);
    EXPECT_EQ(board.black_rooks_bb, B_ROOKS_DEFAULT);
    EXPECT_EQ(board.black_knights_bb, B_KNIGHTS_DEFAULT);
    EXPECT_EQ(board.black_bishops_bb, B_BISHOPS_DEFAULT);
    EXPECT_EQ(board.black_queens_bb, B_QUEENS_DEFAULT);
    EXPECT_EQ(board.black_kings_bb, B_KINGS_DEFAULT);
}