#ifndef FUNCS_HPP
#define FUNCS_HPP

#include "stack.hpp"
#include "types.hpp"
#include <iostream>
#include <string>

namespace susidko
{
  std::string cutName(std::string & str);
  bool isNumeric(const std::string & str);
  Elem makeElem(std::string a);
  void fillStack(std::istream & in, Stack< std::string> & container);
  Infix createInfix(std::string q);
}
std::string susidko::cutName(std::string & str)
{
  std::string name = str.substr(0, str.find_first_of(" ", 0));
  if (str.find_first_of(" ") == std::string::npos)
  {
    str = "";
  }
  else
  {
    str = str.substr(str.find_first_of(" ") + 1);
  }
  return name;
}
bool susidko::isNumeric(const std::string & str)
{
  return str.find_first_not_of("0123456789") == std::string::npos && str.size() != 0;
}

susidko::Elem susidko::makeElem(std::string i)
{
  if (susidko::isNumeric(i))
  {
    susidko::Elem temp{"operand", i};
    return temp;
  }
  else if (i == "(" or i == ")")
  {
    susidko::Elem temp{"bracket", i};
    return temp;
  }
  else
  {
    susidko::Elem temp{"operator", i};
    return temp;
  }
}

void susidko::fillStack(std::istream & in, susidko::Stack< std::string > & container)
{
  std::string input;
  while (getline(in, input))
  {
    if(input.length() == 0)
    {
      continue;
    }
    container.push(input);
  }
}
susidko::Infix susidko::createInfix(std::string i)
{
  susidko::Queue<susidko::Elem> temp;
  while (i != "")
  {
    std::string t = susidko::cutName(i);
    susidko::Elem tt = susidko::makeElem(t);
    temp.push(tt);
  }
  susidko::Infix tet(temp);
  return tet;
}

#endif
