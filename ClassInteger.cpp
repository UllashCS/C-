#include <iostream>
#include <memory>

using namespace std;

class Integer {
public:
  Integer(int x) {
      x_ = x;
  }
  
  operator int() {
      return x_;
  }

private:
  int x_;
};

int main()
{
    cout<<"Hello World" << endl;
    
    Integer a = 10;

    cout<< a << endl;
    
    return 0;
}
