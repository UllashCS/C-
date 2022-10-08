#include <iostream>
#include <vector>

using namespace std;

class A {
public:
  A (int x) {
    cout << " A default constructor" << endl;
    x_ = x;
  }

  A (A & rhs) {
    cout << " A copy constructor" << endl;
    x_ = rhs.x_;
  }
  
  A& operator=(A& rhs) {
    cout << " A copy operator=" << endl;
    x_ = rhs.x_;
    return *this;
  }

  A (A && rhs) {
    cout << " A move constructor" << endl;
    x_ = rhs.x_;
  }
  
  A& operator=(A&& rhs) {
    cout << " A move operator=" << endl;
    x_ = rhs.x_;
    return *this;
  }

  int x_;
};

int main () {
  cout << "Hello World" << endl;

  A obj1(10);
  A obj2(obj1);
  vector<A> obj3;
  
  obj3.push_back(A(20));
  cout << obj1.x_ << " " << obj2.x_ << " " << obj3[0].x_ <<endl;
  
  obj3[0] = obj2;
  cout << obj1.x_ << " " << obj2.x_ << " " << obj3[0].x_ <<endl;
  
  obj3[0] = A(30);
  cout << obj1.x_ << " " << obj2.x_ << " " << obj3[0].x_ <<endl;

  return 0;
}
