#ifndef PERSON_HPP
#define PERSON_HPP

#include "string"
using namespace std;

class Person {
public:
  Person();
  Person(string name);
  Person(const Person& person);
  Person& operator=(const Person& person);
  ~Person();
  string* getpName() const;
  void printName();
private:
  string *pName_;
};

#endif  //PERSON_HPP
