#include <gtest/gtest.h>
#include <string>
#include "../src/board.h"
#include "../src/move.h"

// test the constructor
TEST(TestBoard, TestConstructor) {
    Move move(true);
    Board board;
    EXPECT_EQ(board.white_pawns_bb ^ RANK_2, 0);
    EXPECT_EQ(board.white_rooks_bb ^ (IDX_TO_BB(A1) | IDX_TO_BB(H1)), 0);
    EXPECT_EQ(board.white_knights_bb ^ (IDX_TO_BB(B1) | IDX_TO_BB(G1)), 0);
    EXPECT_EQ(board.white_bishops_bb ^ (IDX_TO_BB(C1) | IDX_TO_BB(F1)), 0);
    EXPECT_EQ(board.white_queens_bb ^ IDX_TO_BB(D1), 0);
    EXPECT_EQ(board.white_kings_bb ^ IDX_TO_BB(E1), 0);

    EXPECT_EQ(board.black_pawns_bb ^ RANK_7, 0);
    EXPECT_EQ(board.black_rooks_bb ^ (IDX_TO_BB(A8) | IDX_TO_BB(H8)), 0);
    EXPECT_EQ(board.black_knights_bb ^ (IDX_TO_BB(B8) | IDX_TO_BB(G8)), 0);
    EXPECT_EQ(board.black_bishops_bb ^ (IDX_TO_BB(C8) | IDX_TO_BB(F8)), 0);
    EXPECT_EQ(board.black_queens_bb ^ IDX_TO_BB(D8), 0);
    EXPECT_EQ(board.black_kings_bb ^ IDX_TO_BB(E8), 0);
}

// test executing a move for white pawns
TEST(TestBoard, TestExecuteMoveWhitePawns) {
    Board board;
    Move move(true);
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
    Move move(false);
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

/** TEST LEGALITY **/
TEST(TestBoardLegality, TestMoveFromNothing){
    Board board;
    Move move(true);
    move.from_cn("A3A4");
    EXPECT_FALSE(board.is_legal(move));
}

// test legal pawn moves
TEST(TestBoardLegality, TestPawnForwardOneSpace){
    Board board;
    Move move(true);
    move.from_cn("E2E3");
    EXPECT_TRUE(board.is_legal(move));
}

TEST(TestBoardLegality, TestPawnForwardInitialTwoSpaces){
    Board board;
    Move move(true);
    move.from_cn("E2E4");
    EXPECT_TRUE(board.is_legal(move));
}

TEST(TestBoardLegality, TestPawnForwardTwoSpacesAfterInitialMove){
    Board board;
    Move move(true);
    move.from_cn("E2E4");
    board.execute_move(move);
    move.from_cn("E4E6");
    EXPECT_FALSE(board.is_legal(move));
}

TEST(TestBoardLegality, TestPawnForwardOneSpacsAfterInitialMove){
    Board board;
    Move move(true);
    move.from_cn("E2E4");
    board.execute_move(move);
    move.from_cn("E4E5");
    EXPECT_TRUE(board.is_legal(move));
}

TEST(TestBoardLegality, TestPawnCapture){
    Board board;
    Move move(true);
    move.from_cn("A2A4");   // Move white pawn from A2 to A4
    board.execute_move(move);
    // black pawn moves from B7 to B5
    move.from_cn("B7B5");
    board.execute_move(move);
    // white pawn captures black pawn
    move.from_cn("A4B5");
    EXPECT_TRUE(board.is_legal(move));
}

TEST(TestBoardLegality, TestPawnCaptureOwnPiece){
    Board board;
    Move move(true);
    move.from_cn("A2A3");   // Move white pawn from A2 to A4
    board.execute_move(move);

    move.from_cn("B7B5");   // irrelevant move
    board.execute_move(move);

    move.from_cn("B2A3");   // Move white pawn from A2 to A4
    EXPECT_FALSE(board.is_legal(move));

}

TEST(TestBoardLegality, TestPawnCaptureNothing){
    Board board;
    Move move(true);
    move.from_cn("A2B3");   // Move white pawn from A2 to A4
    EXPECT_FALSE(board.is_legal(move));
}

TEST(TestBoardLegality, TestPawnBackward){
    Board board;
    Move move(true);
    move.from_cn("A2A4");   // Move white pawn from A2 to A1
    board.execute_move(move);

    move.from_cn("A7A5");   // Move black pawn from A7 to A5
    board.execute_move(move);

    move.from_cn("A4A3");   // Move white pawn from A1 to A2
    EXPECT_FALSE(board.is_legal(move));
}

TEST(TestBoardLegality, TestPawnForwardCannotCapture){
    Board board;
    Move move(true);
    move.from_cn("A2A4");   // Move white pawn from A2 to A1
    board.execute_move(move);

    move.from_cn("A7A5");   // Move black pawn from A7 to A5
    board.execute_move(move);

    move.from_cn("A4A5");   // Move white pawn from A1 to A2
    EXPECT_FALSE(board.is_legal(move));
}