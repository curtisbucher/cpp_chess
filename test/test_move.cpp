#include <gtest/gtest.h>

#include "../src/move.h"

TEST(MoveTests, TestParsingUserInputLowerCase) {
    Move move;
    move.parse_move("e2e4");

    EXPECT_EQ(move.get_from_bb(), 0x00080000000000);
    EXPECT_EQ(move.get_to_bb(), 0x000000008000000);
}

TEST(MoveTests, TestParsingUserInputUpperCase) {
    Move move;
    move.parse_move("A2A4");

    EXPECT_EQ(move.get_from_bb(), 0);
    EXPECT_EQ(move.get_to_bb(), 0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}