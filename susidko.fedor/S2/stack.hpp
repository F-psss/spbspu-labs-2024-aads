#ifndef STACK_HPP
#define STACK_HPP

#include "node.hpp"
#include "list.hpp"
namespace susidko
{
  template< typename T >
  class Stack
  {
    public:
      Stack():
        body_(List< T >())
      {}
      Stack(Stack< T > & p);
      Stack(Stack && other);
      ~Stack() = default;
      void push(T & rhs);
      T pop();
      T top();
      bool isEmpty();
      void print();
      size_t size();
    private:
      List< T > body_;
  };
}

template< typename T >
void susidko::Stack< T >::push(T & rhs)
{
  body_.pushBack(rhs);
}
template< typename T >
T susidko::Stack< T >::pop()
{
  if (isEmpty())
  {
    throw std::logic_error("wdwdwdwd");
  }
  T temp = body_.back();
  body_.popBack();
  return temp;
}
template< typename T >
T susidko::Stack< T >::top()
{
  if (isEmpty())
  {
    throw std::logic_error("top");
  }
  T temp = body_.back();
  return temp;
}
template< typename T >
bool susidko::Stack< T >::isEmpty()
{
  return body_.empty();
}
template< typename T >
void susidko::Stack< T >::print()
{
  while (not isEmpty())
  {
    std::cout << pop().get();
  }
}
template< typename T >
size_t susidko::Stack< T >::size()
{
  return body_.size();
}
#endif
