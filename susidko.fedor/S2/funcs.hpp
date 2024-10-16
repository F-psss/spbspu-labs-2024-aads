#ifndef FUNCS_HPP
#define FUNCS_HPP

#include "stack.hpp"
#include "types.hpp"
#include <iostream>
#include <string>

namespace susidko
{
  bool isNumeric(const std::string & str);
  Elem makeElem(std::string a);
  void fillStack(std::istream & in, Stack< Elem > & container);
}

#endif
