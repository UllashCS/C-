#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Person {
    int age;
    string name;
    
    public:
    virtual void getdata() {
        cin >> name >> age;
    }

    virtual void putdata() {
        cout << name << " " << age;
    }
};

class Professor : public Person{
    int publications;
    int curId;
    static int pcur_id;
    
    public:

    Professor () {pcur_id++; curId = pcur_id;}
    void getdata() {
        Person::getdata();
        cin >> publications;
    }

    void putdata() {
        Person::putdata();
        cout << " " << publications << " " << curId << endl;
    }
};

class Student : public Person{
    vector<int> marks;
    int curId;
    static int scur_id;
    
    public:

    Student () {scur_id++;curId = scur_id;}
    void getdata() {
        int temp;
        Person::getdata();

        for (auto i = 0; i < 6; i++){
            cin >> temp;
            marks.push_back(temp);
        }
    }

    void putdata() {
        int total = 0;
        Person::putdata();
        for (auto i = 0; i < 6; i++)
            total += marks[i];
        cout << " " << total << " " << curId << endl;
    }
};

int Professor::pcur_id = 0;
int Student::scur_id = 0;

int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}
