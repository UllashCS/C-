#include "MathOpsC.hpp"
#include "MathOps.hpp"
#include "iostream"
#include "Utils.hpp"
#include "LogicOps.hpp"

using namespace std;

int main () {
    Utils ut;
    MathOps testObj(&ut);
    LogicOps logicTestObj;

    cout << "5 + 6 = " << testObj.Add(5,6) << endl;
    cout << "Difference betwen -5 and 5 is " << testObj.AbsoluteDiff(-5,5) << endl;
    cout << "Difference betwen 5 and -5 is " << testObj.AbsoluteDiff(5,-5) << endl;
 
    cout << "Result of MultForOddAddForEven for -1 is "<< MultForOddAddForEven (-1) << endl;
    cout << "Result of MultForOddAddForEven for 0 is "<< MultForOddAddForEven (0) << endl;
    cout << "Result of MultForOddAddForEven for 1 is "<< MultForOddAddForEven (1) << endl;
    cout << "Result of MultForOddAddForEven for 2 is "<< MultForOddAddForEven (2) << endl;
    cout << "Result of MultForOddAddForEven for 8 is "<< MultForOddAddForEven (8) << endl;
    cout << "Result of MultForOddAddForEven for 9 is "<< MultForOddAddForEven (9) << endl;
    cout << "Result of MultForOddAddForEven for 10 is "<< MultForOddAddForEven (10) << endl;

    logicTestObj.setNum(0xFFFFFFFF);
    cout << "0xFFFFFFFF / " <<  logicTestObj.getNum() << " in string = " << logicTestObj.getNumInString() << endl;
    logicTestObj.setNum(1111111111);
    cout << logicTestObj.getNum() <<" in string = " << logicTestObj.getNumInString() << endl;

    testMemset ();
}