#ifndef LIST_HPP
#define LIST_HPP

#include "node.hpp"
#include "Iterator.hpp"
#include <iostream>
#include <limits>

namespace susidko
{
  template< typename T >
  class List
  {
    public:
      List():
        first_(nullptr),
        last_(nullptr),
        val_iter_(),
        size_(0)
      {}
      void pushBack(T date_);
      void pushFront(T date_);
      void popBack();
      void popFront();
      void free();
      bool empty();
      size_t size();
      ListIterator< T > begin();
      ListIterator< T > end();
      T front();
      T back();
      T getValue(size_t);
      T getSum();
      void print();
      void printpr();
      void printne();
    private:
      Node< T > * first_;
      Node< T > * last_;
      ListIterator< T > val_iter_;
      size_t size_;
  };
  
  template< typename T >
  void List< T >::pushBack(T date_)
  {
    Node< T > * ptr = new Node < T >(date_);
    if (empty())
    {
      first_ = ptr;
      last_ = ptr;
    }
    else
    {
      last_->next = ptr;
      Node< T > * temp = last_;
      last_ = ptr;
      last_->prev = temp;
    }
    size_++;
  }
  template< typename T >
  void List< T >::pushFront(T date_)
  {
    Node< T > * ptr = new Node < T >(date_);
    if (empty())
    { 
      first_ = ptr;
      last_ = ptr;
    }
    else
    {
      first_->prev = ptr;
      Node< T > * temp = first_;
      first_ = ptr;
      first_->next = temp;
    }
    size_++;
  }
  template< typename T >
  void List< T >::popBack()
  {
    if (empty())
    {
      throw std::logic_error("List is empty");
    }
    else
    {
      std::cout << 's';
      //Node< T > * temp = last_;
      //delete last_;
      //last_ = temp;
      //right_iter_.node = last_->next;
    }
    size_--;
  }
  template< typename T >
  void List< T >::popFront()
  {
    if (empty())
    {
      throw std::logic_error("List is empty");
    }
    else
    {
      //left_iter_++;
      //delete first_;
      //first_ = left_iter_.node;
    }
    size_--;
  }
  template< typename T >
  void List< T >::free()
  {
    while(first_)
    {
      Node< T > * temp = first_->next;
      delete first_;
      first_ = temp;
    }
  }
  template< typename T >
  bool List< T >::empty()
  {
    return first_ == nullptr;
  }
  template< typename T >
  size_t List< T >::size()
  {
    return size_;
  }
  template< typename T >
  ListIterator< T > List< T >::begin()
  {
    return ListIterator< T >(first_);
  }
  template< typename T >
  ListIterator< T > List< T >::end()
  {
    return ListIterator< T >(last_->next);
  }
  template< typename T >
  T List< T >::front()
  {
    return first_.date;
  }
  template< typename T >
  T List< T >::back()
  {
    return last_.date;
  }
  template< typename T >
  T List< T >::getValue(size_t index)
  {
    if (empty() or index >= size_)
    {
      return 0;
    }
    else
    {
      ListIterator< T > val_iter(begin());
      return (val_iter + index).node->data;
    }
  }
  template< typename T >
  T List< T >::getSum()
  {
    ListIterator< T > sum_iter(begin());
    T summ {};
    while (sum_iter.node != nullptr)
    {
      if (sum_iter.node->data > std::numeric_limits< unsigned long long >::max() - summ)
      {
        throw std::overflow_error("vjw");
      }
      summ += sum_iter.node->data;
      sum_iter++;
    }
    return summ;
  }
  template< typename T >
  void List< T >::print()
  {
    ListIterator< T > printIter(begin());
    while (printIter.node->next != nullptr)
    {
      std::cout << printIter.node->data << ' ';
      printIter++;
    }
    std::cout << printIter.node->data << '\n';
    printIter.node = first_;
  }
  template< typename T >
  void List< T >::printpr()
  {
    ListIterator< T > printIter(begin());
    while (printIter.node->next->next != nullptr)
    {
      std::cout << printIter.node->next->data << ' ';
      printIter++;
    }
    std::cout << printIter.node->next->data << '\n';
    printIter.node = first_;
  }
  template< typename T >
  void List< T >::printne()
  {
    ListIterator< T > printIter(begin());
    while (printIter.node != nullptr)
    {
      std::cout << printIter.node->prev->data << ' ';
      printIter++;
    }
    std::cout << printIter.node->prev->data << '\n';
    printIter.node = first_;
  }
}

#endif
