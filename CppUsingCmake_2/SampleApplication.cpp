#include "SampleApplication.hpp"
#include "iostream"

using namespace std;

void normalFunction() {
    SampleApplication sampleObject;
    SampleApplication sampleObject1;

    sampleObject.setPriVar(5);
    cout << "Get Private Variable : " << sampleObject.getPriVar() << endl;

//    sampleObject1.m_priVar = 7;
//    cout << "Get Private Variable : " << sampleObject1.m_priVar << endl;
}

void friendFunction() {
    SampleApplication sampleObject;

    sampleObject.m_priVar = 7;
    cout << "Get Private Variable : " << sampleObject.m_priVar << endl;
}

int main () {
    cout << " +++++++++++++++++ Sample Application +++++++++++++++++ " << endl;
    normalFunction();
    friendFunction();
}