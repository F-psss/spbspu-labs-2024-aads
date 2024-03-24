#ifndef TASK_HPP
#define TASK_HPP
#include <iostream>
#include <string>
#include "list.hpp"

namespace zheleznyakov
{
  void processTask(std::ostream&, List<std::pair<std::string, List<unsigned long long>>>&);
}

void zheleznyakov::processTask(std::ostream& out, List<std::pair<std::string, List<unsigned long long>>>& pairs)
{
  if (pairs.isEmpty())
  {
    throw std::logic_error("List is empty");
  }
  if (pairs[0].second.isEmpty())
  {
    throw std::logic_error("List is empty");
  }

  for (size_t i = 0; i < pairs.getSize(); i++)
  {
    out << pairs[i].first << (i < pairs.getSize() - 1 ? " " : "\n");
  }

  size_t maxSequenceLength = 0;
  for (size_t i = 0; i < pairs.getSize(); i++)
  {
    maxSequenceLength = std::max(maxSequenceLength, pairs[i].second.getSize());
  }
  zheleznyakov::List<unsigned long long> sums;
  unsigned long long currentSum = 0;
  for (size_t i = 0; i < maxSequenceLength; i++)
  {
    currentSum = 0;
    for (size_t j = 0; j < pairs.getSize(); j++)
    {
      if (pairs[j].second.getSize() > i)
      {
        if (currentSum != 0)
        {
          std::cout << ' ';
        }
        std::cout << pairs[j].second[i];
        currentSum += pairs[j].second[i];
      }
    }
    sums.pushBack(currentSum);
    std::cout << '\n';
  }

  for (size_t i = 0; i < sums.getSize(); i++)
  {
    out << sums[i] << (i == sums.getSize() - 1 ? '\n' : ' ');
  }
}
#endif
