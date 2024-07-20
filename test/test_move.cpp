#include <gtest/gtest.h>
#include "../src/move.h"

// Testing from_cn()
TEST(MoveTest_from_cn, TestParsingUserInput) {
    Move move;
    ASSERT_TRUE(move.from_cn("e2e4"));

    EXPECT_EQ(move.get_from_bb(), 0x0000000000001000);
    EXPECT_EQ(move.get_to_bb(), 0x0000000010000000);
}

TEST(MoveTest_from_cn, TestParsingUserInput2) {
    Move move;
    ASSERT_TRUE(move.from_cn("g7f8"));

    EXPECT_EQ(move.get_from_bb(), 1ULL << 54);
    EXPECT_EQ(move.get_to_bb(), 1ULL << 61);
}

TEST(MoveTest_from_cn, TestParsingCaseInsensitive) {
    Move move1, move2;
    ASSERT_TRUE(move1.from_cn("E2E4"));
    ASSERT_TRUE(move2.from_cn("e2e4"));

    EXPECT_EQ(move1.get_from_bb(), move2.get_from_bb());
    EXPECT_EQ(move1.get_to_bb(), move2.get_to_bb());
}

TEST(MoveTest_from_cn, TestParsingInvalidInput) {
    Move move;
    ASSERT_FALSE(move.from_cn("e2e"));
    ASSERT_FALSE(move.from_cn("e2e44"));
    ASSERT_FALSE(move.from_cn("e2e44"));
    ASSERT_FALSE(move.from_cn("e2e9"));
    ASSERT_FALSE(move.from_cn("e2eI"));
    ASSERT_FALSE(move.from_cn("e2e "));
    ASSERT_FALSE(move.from_cn("e2 e4"));
    ASSERT_FALSE(move.from_cn("e2 e4"));
    ASSERT_FALSE(move.from_cn("22e4"));
}

// Testing to_cn()
TEST(MoveTest_to_cn, TestConvertingToChessNotation) {
    Move move;
    move.from_cn("e2e4");
    EXPECT_EQ(move.to_cn(), "E2E4");
}

TEST(MoveTest_to_cn, TestConvertingToChessNotation2) {
    Move move;
    move.from_cn("G7F8");
    EXPECT_EQ(move.to_cn(), "G7F8");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}