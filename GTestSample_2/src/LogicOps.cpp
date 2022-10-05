#include "LogicOps.hpp"
#include "iostream"
#include "vector"

using namespace std;

void LogicOps::setNum (unsigned int argNum) {
    num = argNum;
}

unsigned int LogicOps::getNum () {
    return num;
}

string LogicOps::ConvertLessThan100 (unsigned char arg) {
    stringstream ss;
    int tenthPlaceAbove20 = 0;
    int firstPlace = 0;
    if (arg >= 20) {
        tenthPlaceAbove20 = arg / 10;
        firstPlace = arg % 10;
        switch (tenthPlaceAbove20)
        {
            case 2:{
                ss << "twenty ";
            }break;
            case 3:{
                ss << "thirthy ";
            }break;
            case 4:{
                ss << "fourty ";
            }break;
            case 5:{
                ss << "fifty ";
            }break;
            case 6:{
                ss << "sixty ";
            }break;
            case 7:{
                ss << "seventy ";
            }break;
            case 8:{
                ss << "eighty ";
            }break;
            case 9:{
                ss << "ninty ";
            }break;
            default:
                break;
        }
    }
    else if (arg > 9){
        firstPlace = 0;
        switch (arg)
        {
            case 10:{
                ss << "ten";
            }break;
            case 11:{
                ss << "eleven";
            }break;
            case 12:{
                ss << "twelve";
            }break;
            case 13:{
                ss << "thirteen";
            }break;
            case 14:{
                ss << "fourteen";
            }break;
            case 15:{
                ss << "fifteen";
            }break;
            case 16:{
                ss << "sixteen";
            }break;
            case 17:{
                ss << "seventeen";
            }break;
            case 18:{
                ss << "eighteen";
            }break;
            case 19:{
                ss << "nineteen";
            }break;
            default:
                break;
        }
    }
    else {
        firstPlace = arg;
    }

    if (firstPlace) {
        switch (firstPlace)
        {
            case 1:{
                ss << "one";
            }break;
            case 2:{
                ss << "two";
            }break;
            case 3:{
                ss << "three";
            }break;
            case 4:{
                ss << "four";
            }break;
            case 5:{
                ss << "five";
            }break;
            case 6:{
                ss << "six";
            }break;
            case 7:{
                ss << "seven";
            }break;
            case 8:{
                ss << "eight";
            }break;
            case 9:{
                ss << "nine";
            }break;
            default:
                break;
        }
    }

    return ss.str();    
}

string LogicOps::ConvertLessThan1000 (unsigned int arg) {
    int hundredPlace = arg / 100;
    int final = arg % 100;
    stringstream ss;

    if (hundredPlace) {
        ss << ConvertLessThan100(hundredPlace) << " hundred ";
    }

    if (final){
        ss << ConvertLessThan100(final);
    }
    
    return ss.str();
}

void LogicOps::ConvertToString () {
    unsigned int n = num;
    unsigned int reminder = 0;
    vector<unsigned int> reminders;
    stringstream ss;

    while (n) {
        reminder = n%1000;
        reminders.push_back(reminder);
        n /= 1000;
    }

    for (int i = (int) reminders.size() - 1; i >= 0; i--){
        if (0 != reminders[i]) {
           ss << ConvertLessThan1000(reminders[i]);
        }

        switch (i) {
            case 3 : {
                ss << " billion, ";
            }break;
            case 2 : {
                ss << " million, ";
            }break;
            case 1 : {
                ss << " thousand, ";
            }break;
        }

        numInString = ss.str();
    }
}

string LogicOps::getNumInString() {
    ConvertToString ();
    return numInString;
}
