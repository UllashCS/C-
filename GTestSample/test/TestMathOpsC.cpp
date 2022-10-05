#include <gtest/gtest.h>
#include "../src/MathOpsC.hpp"
#include "MockMathOpsC.hpp"

using ::testing::Return;
using ::testing::_;

TEST(TestMathOpsC, TestMinusOne) {
    int res = MultForOddAddForEven (-1);
    EXPECT_EQ(res, 0);
}

TEST(TestMathOpsC, TestZero) {
    int res = MultForOddAddForEven (0);
    EXPECT_EQ(res, 0);
}

TEST(TestMathOpsC, TestOne) {
    MockMathOpsCEnv envObj;

    EXPECT_CALL(*envObj.GetInstance(), Fact(1))
    .WillOnce(Return(1));

    int res = MultForOddAddForEven (1);
    EXPECT_EQ(res, 1);
}

TEST(TestMathOpsC, TestTwo) {
    MockMathOpsCEnv envObj;

    EXPECT_CALL(*envObj.GetInstance(), AddoToN(2))
    .WillOnce(Return(3));

    int res = MultForOddAddForEven (2);
    EXPECT_EQ(res, 3);
}

TEST(TestMathOpsC, TestEight) {
    MockMathOpsCEnv envObj;

    EXPECT_CALL(*envObj.GetInstance(), AddoToN(8))
    .WillOnce(Return(36));

    int res = MultForOddAddForEven (8);
    EXPECT_EQ(res, 36);
}

TEST(TestMathOpsC, TestNine) {
    MockMathOpsCEnv envObj;

    EXPECT_CALL(*envObj.GetInstance(), Fact(9))
    .WillOnce(Return(362880));

    int res = MultForOddAddForEven (9);

    EXPECT_EQ(res, 362880);
}

TEST(TestMathOpsC, TestTen) {
    int res = MultForOddAddForEven (10);
    EXPECT_EQ(res, 0);
}

TEST(TestMathOpsC, DISABLED_Test11) {
    MockMathOpsCEnv envObj;

    EXPECT_CALL(*envObj.GetInstance(), fake_memset (_, 5, 10 * sizeof(int)))
    .Times(1);
    
    testMemset();
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
