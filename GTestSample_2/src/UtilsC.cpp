#include "UtilsC.hpp"
#include "iostream"

using namespace std;

int AddoToN (int num){
    int res = 0;
 
    while (num) {
        res+=num;
        num--;
    }
    return res;
}

int Fact(int num){
    int res = 1;

    while (num) {
        res*=num;
        num--;
    }
    return res;
}
