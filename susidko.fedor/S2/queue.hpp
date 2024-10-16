#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "node.hpp"
#include "list.hpp"
namespace susidko
{
  template< typename T >
  class Queue
  {
    public:
      Queue():
        body_(List< T >())
      {}
      Queue(Queue< T > & p);
      Queue(Queue && other);
      ~Queue() = default;
      void push(T & rhs);
      T pop();
      bool isEmpty();
      void print();
      size_t size();
    private:
      List< T > body_;
  };
}

template< typename T >
void susidko::Queue< T >::push(T & rhs)
{
  body_.pushBack(rhs);
}
template< typename T >
T susidko::Queue< T >::pop()
{
  if (isEmpty())
  {
    throw std::logic_error("wdwdwdwd");
  }
  T temp = body_.front();
  body_.popFront();
  return temp;
}
template< typename T >
bool susidko::Queue< T >::isEmpty()
{
  return body_.empty();
}
template< typename T >
void susidko::Queue< T >::print()
{
  susidko::Queue< T > temp = susidko::Queue< T >(*this);
  while (not temp.isEmpty())
  {
    std::cout << temp.pop().get();
  }
  std::cout << "EMPTY";
}
template< typename T >
susidko::Queue< T >::Queue(susidko::Queue< T > & p):
  body_(p.body_)
{
  std::cout << "copQ" << std::endl;
}
template < typename T >
susidko::Queue< T >::Queue(Queue && other):
  body_(std::move(other.body_))
{}
template< typename T >
size_t susidko::Queue< T >::size()
{
  return body_.size();
}
#endif
