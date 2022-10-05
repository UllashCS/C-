#include "Person.hpp"
#include <iostream>
#include <vector>

Person::Person()
{
  pName_ = new string("");
}
Person::Person(string name)
{
  pName_ = new string(name);
}

Person::Person(const Person& person)
{
  pName_ = new string(*(person.getpName()));
}
Person& Person::operator=(const Person& person)
{
  pName_ = new string(*(person.getpName()));
  return *this;
}

Person::~Person()
{
  delete pName_;
}

string* Person::getpName() const
{
  return pName_;
}

void Person::printName()
{
  cout<< *pName_ << endl;
}

int main()
{
  vector<Person> persons;
  cout << "Vector Size : " << persons.size() <<endl;
  cout << "Vector Capacity : " << persons.capacity() << endl;

  for (int i = 0; i < 50; ++i)
  {
	persons.push_back(Person("Index : " + to_string(i)));
	persons.back().printName();

	cout << "Size : " << persons.size() << endl;
	cout << "Capacity : " << persons.capacity() << endl;
  }

  cout << "Goodbye" << endl;
}
