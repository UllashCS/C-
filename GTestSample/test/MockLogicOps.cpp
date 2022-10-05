#include "MockLogicOps.hpp"

string MockLogicOps::ConvertLessThan100Derived (unsigned char arg) {
    return LogicOps::ConvertLessThan100(arg);
}

string MockLogicOps::ConvertLessThan1000Derived (unsigned int arg){
    return LogicOps::ConvertLessThan1000(arg);
}