#include <gtest/gtest.h>
#include "MockLogicOps.hpp"

using ::testing::HasSubstr;
using ::testing::Return;

TEST(TestLogicOps, TestGetSetNum0) {
    LogicOps baseObj;
    unsigned int res;

    baseObj.setNum(0);
    res = baseObj.getNum();

    EXPECT_EQ(res, 0);
}

TEST(TestLogicOps, TestGetSetNum0xFFFFFFFF) {
    LogicOps baseObj;
    unsigned int res;

    baseObj.setNum(0xFFFFFFFF);
    res = baseObj.getNum();

    EXPECT_EQ(res, 0xFFFFFFFF);
}

TEST(TestLogicOps, TestGetNumInString) {
    MockLogicOps mockObj;

    EXPECT_CALL(mockObj, ConvertToString ())
    .Times(1);

    mockObj.LogicOps::getNumInString();
}

TEST(TestLogicOps, TestConvertLessThan100With99) {
    MockLogicOps mockObj;
    string res = mockObj.ConvertLessThan100Derived(99);

    EXPECT_THAT(res, HasSubstr("ninty nine"));
}

TEST(TestLogicOps, TestConvertLessThan100With21) {
    MockLogicOps mockObj;
    string res = mockObj.ConvertLessThan100Derived(21);

    EXPECT_THAT(res, HasSubstr("twenty one"));
}

TEST(TestLogicOps, TestConvertLessThan100With20) {
    MockLogicOps mockObj;
    string res = mockObj.ConvertLessThan100Derived(20);

    EXPECT_THAT(res, HasSubstr("twenty"));
}

TEST(TestLogicOps, TestConvertLessThan100With19) {
    MockLogicOps mockObj;
    string res = mockObj.ConvertLessThan100Derived(19);

    EXPECT_THAT(res, HasSubstr("nineteen"));
}

TEST(TestLogicOps, TestConvertLessThan100With10) {
    MockLogicOps mockObj;
    string res = mockObj.ConvertLessThan100Derived(10);

    EXPECT_THAT(res, HasSubstr("ten"));
}

TEST(TestLogicOps, TestConvertLessThan100With9) {
    MockLogicOps mockObj;
    string res = mockObj.ConvertLessThan100Derived(9);

    EXPECT_THAT(res, HasSubstr("nine"));
}

TEST(TestLogicOps, TestConvertLessThan100With1) {
    MockLogicOps mockObj;
    string res = mockObj.ConvertLessThan100Derived(1);

    EXPECT_THAT(res, HasSubstr("one"));
}

TEST(TestLogicOps, TestConvertLessThan100With0) {
    MockLogicOps mockObj;
    string res = mockObj.ConvertLessThan100Derived(0);

    EXPECT_EQ(res, "");
}

TEST(TestLogicOps, TestConvertLessThan1000with999) {
    MockLogicOps mockObj;
    string res;

    EXPECT_CALL(mockObj, ConvertLessThan100 (9))
    .WillOnce(Return("nine"));

    EXPECT_CALL(mockObj, ConvertLessThan100 (99))
    .WillOnce(Return("ninety nine"));

    res = mockObj.ConvertLessThan1000Derived(999);

    EXPECT_THAT(res, HasSubstr("ninety nine"));
}

TEST(TestLogicOps, TestConvertLessThan1000with100) {
    MockLogicOps mockObj;
    string res;

    EXPECT_CALL(mockObj, ConvertLessThan100 (1))
    .WillOnce(Return("one"));

    res = mockObj.ConvertLessThan1000Derived(100);

    EXPECT_THAT(res, HasSubstr("one hundred"));
}

TEST(TestLogicOps, TestConvertLessThan1000with99) {
    MockLogicOps mockObj;
    string res;

    EXPECT_CALL(mockObj, ConvertLessThan100 (99))
    .WillOnce(Return("ninety nine"));

    res = mockObj.ConvertLessThan1000Derived(99);

    EXPECT_THAT(res, HasSubstr("ninety nine"));
}

TEST(TestLogicOps, TestConvertToStringwith0xFFFFFFFF) {
    MockLogicOps mockObj;
    string res;

    EXPECT_CALL(mockObj, ConvertLessThan1000 (4))
    .WillOnce(Return("four"));

    EXPECT_CALL(mockObj, ConvertLessThan1000 (294))
    .WillOnce(Return("two hundred ninty four"));

    EXPECT_CALL(mockObj, ConvertLessThan1000 (967))
    .WillOnce(Return("nine hundred sixty seven"));

    EXPECT_CALL(mockObj, ConvertLessThan1000 (295))
    .WillOnce(Return("two hundred ninty five"));

    mockObj.LogicOps::setNum(0xFFFFFFFF);
    mockObj.LogicOps::ConvertToString ();

    EXPECT_CALL(mockObj, ConvertToString ())
    .Times(1);

    res = mockObj.getNumInString();

    EXPECT_THAT(res, HasSubstr("four billion, two hundred ninty four million, nine hundred sixty seven thousand, two hundred ninty five"));
}

TEST(TestLogicOps, TestConvertToStringwith3999999999) {
    MockLogicOps mockObj;
    string res;

    EXPECT_CALL(mockObj, ConvertLessThan1000 (3))
    .WillOnce(Return("three"));

    EXPECT_CALL(mockObj, ConvertLessThan1000 (999))
    .Times(3)
    .WillRepeatedly(Return("nine hundred ninty nine"));

    mockObj.LogicOps::setNum(3999999999);
    mockObj.LogicOps::ConvertToString ();

    EXPECT_CALL(mockObj, ConvertToString ())
    .Times(1);

    res = mockObj.getNumInString();

    EXPECT_THAT(res, HasSubstr("three billion, nine hundred ninty nine million, nine hundred ninty nine thousand, nine hundred ninty nine"));
}