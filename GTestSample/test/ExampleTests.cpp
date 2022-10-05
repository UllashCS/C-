#include <gtest/gtest.h>
#include "../src/MathOps.hpp"

#ifdef __STRICT_ANSI__
#undef __STRICT_ANSI__
#endif

TEST(ExampleTests, TestAdd) {
    Utils ut;
    MathOps utObj(&ut);
    int res = utObj.Add(5, 6);
    EXPECT_EQ(res, 11);
}
