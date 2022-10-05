#ifndef MOCKLOGICOPS_HPP
#define MOCKLOGICOPS_HPP
#include <gmock/gmock.h>
#include "../src/LogicOps.hpp"

class MockLogicOps : public LogicOps {
    public:
    MOCK_METHOD(void, ConvertToString, ());

    MOCK_METHOD(string, ConvertLessThan100, (unsigned char arg));
    MOCK_METHOD(string, ConvertLessThan1000, (unsigned int arg));

    string ConvertLessThan100Derived (unsigned char arg);
    string ConvertLessThan1000Derived (unsigned int arg);
}; //MockLogicOps

#endif //MOCKLOGICOPS_HPP