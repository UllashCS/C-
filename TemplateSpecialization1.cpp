#include <iostream>
using namespace std;
enum class Fruit { apple, orange, pear };
enum class Color { red, green, orange };

template <typename T> struct Traits;
template <> struct Traits <Fruit> {
    static string name (int i) {
        string str;

        switch (i) {
        case (int)Fruit::apple: {str = "apple";}break;
        case (int)Fruit::orange: {str = "orange";}break;
        case (int)Fruit::pear: {str = "pear";}break;
        default: {str = "unknown";}break;
        }
        return str.c_str();
    }
};

template <> struct Traits <Color> {
    static string name (int i) {
        string str;

        switch (i) {
        case (int)Color::green: {str = "green";}break;
        case (int)Color::orange: {str = "orange";}break;
        case (int)Color::red: {str = "red";}break;
        default: {str = "unknown";}break;
        }
        return str.c_str();
    }
};


int main()
{
	int t = 0; std::cin >> t;

    for (int i=0; i!=t; ++i) {
        int index1; std::cin >> index1;
        int index2; std::cin >> index2;
        cout << Traits<Color>::name(index1) << " ";
        cout << Traits<Fruit>::name(index2) << "\n";
    }
}
