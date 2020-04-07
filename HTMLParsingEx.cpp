#include <cmath>
#include <cstdio>
#include <exception>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

string getToken (string& str, map<string, string>& attrVal){
    string tag, substr;
    vector<string> strVec;

    remove(str.begin(), str.end(), '<');
    str.pop_back();str.pop_back();

    for (auto it = str.begin(); it != str.end(); ++it) {
        if (*it != ' '){
            if ((*it != '"') && (*it != '='))
                substr += *it;
        }
        else {
            if (false == substr.empty())
                strVec.push_back(substr);
            substr.clear();
        }
    }
    strVec.push_back(substr);

    for (auto i = 2; i < strVec.size() ; i+=2) {
        attrVal[strVec[i-1]] = strVec[i];
    }

    tag = strVec[0];
    return tag;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, q;
    string str, tag, tagAttr, temp;
    cin >> n >> q;
    map<string, string> attrVal, tagAttrVal;
    vector<string> tagList;

    for (unsigned int i=0; i <= n; i ++) {
        getline(cin, str);
        if (false == str.empty()) {
            attrVal.clear();
            tagAttr.clear();

            tag = getToken (str, attrVal);

            if (string::npos == tag.find('/')) {
                tagList.push_back (tag);
                for (auto it = tagList.begin(); it != tagList.end(); ++it) {
                    tagAttr += *it;
                    tagAttr += '.';
                }

                tagAttr.pop_back();
                tagAttr += '~';

                for (auto it = attrVal.begin(); it != attrVal.end(); ++it) {
                    temp.clear();
                    temp = tagAttr;
                    temp += it->first;
                    tagAttrVal[temp] = it->second;
                }

            }
            else {
                tagList.pop_back();
            }
        }
    }

    for (unsigned int i=0; i < q; i ++) {
        getline(cin, str);

        auto it1 = tagAttrVal.find(str.c_str());

        if (it1 != tagAttrVal.end()) {
            cout << it1->second.c_str() << endl;
        }
        else {
        cout << "Not Found!" << endl;
        }
    }
    return 0;
}
