#ifndef LOGICOPS_HPP
#define LOGICOPS_HPP
#include "string"
#include "sstream"

using namespace std;

class LogicOps {
    unsigned int num;
    string numInString;
protected:
    virtual string ConvertLessThan1000 (unsigned int arg);
    virtual string ConvertLessThan100 (unsigned char arg);
public:
    LogicOps() : num(0), numInString("Zero"){}
    virtual void setNum (unsigned int argNum);
    virtual unsigned int getNum ();
    virtual void ConvertToString ();
    virtual string getNumInString();
};

#endif //LOGICOPS_HPP