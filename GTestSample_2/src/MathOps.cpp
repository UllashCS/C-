#include "MathOps.hpp"
#include "Utils.hpp"
#include "iostream"
using namespace std;

MathOps::MathOps(Utils *_instance){
    __utils_instance = _instance;
}
int MathOps::Add (int a, int b) {
    return a + b;
}

int MathOps::AbsoluteDiff (int a, int b) {
    if (__utils_instance->Large (a, b)){
        cout << a << " is greater than " << b << endl; 
        return a - b;
    }
    else {
        cout << b << " is greater than " << a << endl;
        return b - a;
    }
}
