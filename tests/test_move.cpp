#include <gtest/gtest.h>

TEST(AdditionTest, HandlesFailure) {
    EXPECT_EQ(1 + 2, 4);
}

TEST(AdditionTest, HandlesPositiveNumbers) {
    EXPECT_EQ(1 + 2, 3);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}