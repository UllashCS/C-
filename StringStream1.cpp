#include <cstdio>
#include <sstream>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> parseInts(string str) {
	// Complete this function
    size_t n = count(str.begin(), str.end(), ',');
    vector<int> vec;
    int a;
    char ch;
    stringstream ss(str.c_str());

    for (int i = 0; i <= n; i++) {
        ss >> a >> ch;
        vec.push_back(a);
    }

    return vec;
}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }
    
    return 0;
}