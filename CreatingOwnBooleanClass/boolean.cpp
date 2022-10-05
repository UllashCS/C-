//value of type 'boolean' is not contextually convertible to 'bool'
#include "boolean.hpp"
#include <iostream>

boolean::boolean (bool val) {
  m_Var = val;
}

boolean& boolean::operator=(bool val) {
  m_Var = val;
  return *this;
}

bool boolean::convert ()
 {
    if(m_Var)
      return false;
    else
      return true;
}

boolean::operator bool() {
  return convert ();
}

/****** DO NOT MODIFY MAIN ******/
int main()
{
  boolean var = true;
  std::cout << (var ? "true\n" : "false\n");
  var = false;
  std::cout << var << '\n';
}
