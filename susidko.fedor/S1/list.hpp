#ifndef LIST_HPP
#define LIST_HPP

#include "node.hpp"
#include "Iterator.hpp"
#include <iostream>

namespace susidko
{
  template< typename T >
  class List
  {
    public:
      List():
        first_(nullptr),
        last_(nullptr),
        endPrint(0)
      {}
      void pushBack(T date_)
      {
        Node< T > * ptr = new Node < int >(date_);
        if (isEmpty()) {
          first_ = ptr;
          last_ = ptr;
          left_iter_.node = ptr;
        }
        last_->next = ptr;
        last_ = ptr;
        right_iter_.node = ptr;
      }
      /*void free()
      {
        Node< T > * curr = last_;
        while (curr != first_)
        {
          curr = curr->prev;
          delete curr->next;
        }
        delete curr;
      }*/
      bool isEmpty()
      {
        return first_ == nullptr;
      }
      ListIterator< T > begin()
      {
        return left_iter_;
      }
      ListIterator< T > end()
      {
        return right_iter_;
      }
      T front()
      {
        return first_.date;
      }
      T back()
      {
        return last_.date;
      }
      T getValue()
      {
        if (isEmpty() or endPrint)
        {
          return 0;
        }
        else
        {
          return left_iter_.node->data;
        }
      }
      void printNext(int flag)
      {
        if (isEmpty() or endPrint) return;
        if (right_iter_ == left_iter_)
        {
          endPrint = 1;
        }
        std::cout << left_iter_.node->data;
        if (flag)
        {
          std::cout << ' ';
        }
        left_iter_++;
      }
    private:
      ListIterator< T > left_iter_;
      ListIterator< T > right_iter_;
      Node< T > * first_;
      Node< T > * last_;
      bool endPrint;
  };
}
#endif
