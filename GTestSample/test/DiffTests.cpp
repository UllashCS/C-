#include "gtest/gtest.h"
#include "../src/MathOps.hpp"
#include "Mock_Test.hpp"

using ::testing::Return;

TEST(DiffTests, AbsoluteDiffBothZero) {
    MockTest mt;
    MathOps utObj(&mt);
    EXPECT_CALL(mt, Large(0,0))
    .Times(1)
    .WillOnce(Return(false));

    int res = utObj.AbsoluteDiff(0, 0);
    EXPECT_EQ(res, 0);
}

TEST(DiffTests, AbsoluteDiffOneZero) {
    MockTest mt;
    MathOps utObj(&mt);

    EXPECT_CALL(mt, Large(1,0))
    .Times(1)
    .WillOnce(Return(true));

    int res = utObj.AbsoluteDiff(1, 0);
    EXPECT_EQ(res, 1);
}

TEST(DiffTests, AbsoluteDiffZeroOne) {
    MockTest mt;
    MathOps utObj(&mt);
    EXPECT_CALL(mt, Large(0,1))
    .Times(1)
    .WillOnce(Return(false));

    int res = utObj.AbsoluteDiff(0, 1);
    EXPECT_EQ(res, 1);
}

TEST(DiffTests, AbsoluteDiffNegPos) {
    MockTest mt;
    MathOps utObj(&mt);
    EXPECT_CALL(mt, Large(-1,1))
    .Times(1)
    .WillOnce(Return(false));

    int res = utObj.AbsoluteDiff(-1, 1);
    EXPECT_EQ(res, 2);
}

TEST(DiffTests, AbsoluteDiffPosNeg) {
    MockTest mt;
    MathOps utObj(&mt);
 
    EXPECT_CALL(mt, Large(1,-1))
    .Times(1)
    .WillOnce(Return(true));

    int res = utObj.AbsoluteDiff(1, -1);
    EXPECT_EQ(res, 2);
}