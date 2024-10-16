#include <algorithm>
#include "list.hpp"
#include "queue.hpp"
#include "stack.hpp"
#include "funcs.hpp"
#include "types.hpp"
#include <iostream>
#include <string>


bool susidko::isNumeric(const std::string & str)
{
  return str.find_first_not_of("0123456789") == std::string::npos && str.size() != 0;
}

susidko::Elem makeElem(std::string i)
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

void susidko::fillStack(std::istream & in, susidko::Stack< susidko::Elem > & container)
{
  std::string input;
  while (getline(in, input))
  {
    if(input.length() == 0)
    {
      continue;
    }
    susidko::Elem temp = susidko::makeElem(input);
    container.push(temp);
  }
}
