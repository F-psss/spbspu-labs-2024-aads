#ifndef LIST_HPP
#define LIST_HPP

#include "node.hpp"
//#include "Iterator.hpp"
#include <iostream>
#include <limits>

namespace susidko
{
  template< typename T >
  class List
  {
    public:
    class Iterator;
    class ConstIterator;

      List():
        first_(nullptr),
        last_(nullptr),
        val_iter_(),
        size_(0)
      {}
      List(size_t count);
      List(size_t count, const T & value);
      List(List< T > & p);
      List(List< T > && moved);
      List< T > & operator=(List< T > & p);
      List< T > & operator=(List< T > && moved);

      T & operator[](size_t index);

      void assign(T data_);
      void pushBack(T data_);
      void pushFront(T data_);
      void popBack();
      void popFront();
      void remove(const T & value);
      void remove_if(bool (*p)(T));
      void clear();
      bool empty();
      size_t size();
      Iterator begin();
      Iterator end();
      ConstIterator cbegin();
      ConstIterator cend();
      T front();
      T back();
      T getValue(size_t);
      T getSum();
      void print();
      void printpr();
      void printne();
      void swap(List< T > & other);
    private:
      Node< T > * first_;
      Node< T > * last_;
      ConstIterator val_iter_;
      size_t size_;
  };

  template< typename T >
  class List< T >::ConstIterator
  {
    public:
      friend class List< T >;
      using this_t = ConstIterator;
      using node_t = Node< T > *;

      ConstIterator(): node(nullptr) {}
      ConstIterator(Node< T > * nd): node(nd) {}
      ConstIterator(const this_t&) = default;
      ~ConstIterator() = default;

      this_t & operator=(const this_t &) = default;
      this_t & operator++();
      this_t operator++(int);
      this_t & operator--();
      this_t operator--(int);
      this_t operator+(size_t index);

      const T & operator*() const;
      const T * operator->() const;

      bool operator!=(const this_t &) const;
      bool operator==(const this_t &) const;

    private:
      node_t node;
      ConstIterator(node_t*, const List< T >*);
  };
  //template< typename T >
  //using iterator = typename List< T >::Iterator;
  template< typename T >
  using const_iterator = typename List< T >::ConstIterator;
  template< typename T >
  typename List< T >::ConstIterator & List< T >::ConstIterator::operator++()
  {
    assert(node != nullptr);
    node = node->next;
    return *this;
  }
  template< typename T >
  typename List< T >::ConstIterator List< T >::ConstIterator::operator++(int)
  {
    assert(node != nullptr);
    ConstIterator result(*this);
    ++(*this);
    return result;
  }
  template< typename T >
  typename List< T >::ConstIterator & List< T >::ConstIterator::operator--()
  {
    assert(node != nullptr);
    node = node->prev;
    return *this;
  }
  template< typename T >
  typename List< T >::ConstIterator List< T >::ConstIterator::operator+(size_t index)
  {
    assert(node != nullptr);
    for (size_t i = 0; i < index; i++)
    {
      (*this)++;
    }
    return *this;
  }
  template< typename T >
  typename List< T >::ConstIterator List< T >::ConstIterator::operator--(int)
  {
    assert(node != nullptr);
    ConstIterator result(*this);
    --(*this);
    return result;
  }
  template< typename T >
  bool List< T >::ConstIterator::operator==(const List< T >::ConstIterator & rhs) const
  {
    return node == rhs.node;
  }
  template< typename T >
  bool List< T >::ConstIterator::operator!=(const List< T >::ConstIterator & rhs) const
  {
    return !(rhs == *this);
  }
  template< typename T >
  const T &  List< T >::ConstIterator::operator*() const
  {
    assert(node != nullptr);
    return node->data;
  }
  template< typename T >
  const T *  List< T >::ConstIterator::operator->()const
  {
    assert(node != nullptr);
    return std::addressof(node->data);
  }

  
  template< typename T >
  class List< T >::Iterator
  {
    public:
      friend class List< T >;
      using this_t = Iterator;
      Iterator(): iter_(ConstIterator()) {}
      Iterator(ConstIterator iter): iter_(iter) {}
      Iterator(Node< T > * nd): iter_(ConstIterator(nd)) {}
      Iterator(const this_t &) = default;
      ~Iterator() = default;

      this_t & operator=(const this_t &) = default;
      this_t & operator++();
      this_t operator++(int);
      this_t & operator--();
      this_t operator--(int);
      this_t operator+(size_t index);

      T & operator*();
      T * operator->();
      const T & operator*() const;
      const T * operator->() const;

      bool operator!=(const this_t&) const;
      bool operator==(const this_t&) const;

    private:
      ConstIterator iter_;
};

  template< typename T >
  typename List< T >::Iterator & List< T >::Iterator::operator++()
  {
    assert(iter_ != ConstIterator());
    iter_++;
    return iter_;
  }
  template< typename T >
  typename List< T >::Iterator List< T >::Iterator::operator++(int)
  {
    assert(iter_ != ConstIterator());
    ++iter_;
    return iter_;
  }
  template< typename T >
  typename List< T >::Iterator & List< T >::Iterator::operator--()
  {
    assert(iter_ != ConstIterator());
    iter_--;
    return iter_;
  }
  template< typename T >
  typename List< T >::Iterator List< T >::Iterator::operator+(size_t index)
  {
    assert(iter_ != ConstIterator());
    for (size_t i = 0; i < index; i++)
    {
      (*this)++;
    }
    return *this;
  }
  template< typename T >
  typename List< T >::Iterator List< T >::Iterator::operator--(int)
  {
    assert(iter_ != ConstIterator());
    --iter_;
    return iter_;
  }
  template< typename T >
  bool List< T >::Iterator::operator==(const List< T >::Iterator & rhs) const
  {
    return iter_ == rhs.iter_;
  }
  template< typename T >
  bool List< T >::Iterator::operator!=(const List< T >::Iterator & rhs) const
  {
    return !(rhs == *this);
  }
  template< typename T >
  const T &  List< T >::Iterator::operator*() const
  {
    assert(iter_ != ConstIterator());
    return iter_.node.data;
  }
  template< typename T >
  const T *  List< T >::Iterator::operator->()const
  {
    assert(iter_ != ConstIterator());
    return std::addressof(iter_.node.data);
  }
  
  
  
  
  
  template< typename T >
  List< T >::List(size_t count)
  {
    first_ = nullptr;
    size_ = 0;
    for (size_t i = 0; i < count; i++)
    {
      pushBack(T{});
    }
  }
  template< typename T >
  List< T >::List(size_t count, const T & value)
  {
    first_ = nullptr;
    size_ = 0;
    for (size_t i = 0; i < count; i++)
    {
      pushBack(value);
    }
  }
  template< typename T >
  List< T >::List(List< T > & p)
  {
    first_ = nullptr;
    last_ = nullptr;
    Iterator val_iter_;
    size_ = 0;
    for (size_t i = 0; i < p.size_; i++)
    {
      auto temp = p.getValue(i);
      pushBack(temp);
    }
  }
  template< typename T >
  List< T >::List(List< T > && moved)
  {
    first_ = moved.first_;
    last_ = moved.last_;
    val_iter_ = moved.val_iter_;
    size_ = moved.size_;
    moved.first_ = nullptr;
    moved.last_ = nullptr;
    moved.size_ = 0;
    }
  template< typename T >
  List< T > & List< T >::operator=(List< T > & p)
  {
    first_ = nullptr;
    last_ = nullptr;
    Iterator val_iter_;
    size_ = 0;
    for (size_t i = 0; i < p.size_; i++)
    {
      auto temp = p.getValue(i);
      pushBack(temp);
    }
    return *this;
  }
  template< typename T >
  List< T > & List< T >::operator=(List< T > && moved)
  {
    first_ = moved.first_;
    last_ = moved.last_;
    val_iter_ = moved.val_iter_;
    size_ = moved.size_;
    moved.first_ = nullptr;
    moved.last_ = nullptr;
    moved.size_ = 0;
    return *this;
    }
  template< typename T >
  T & List< T >::operator[](size_t index)
  {
    if (index >= size_)
    {
      throw std::out_of_range("List index out of range");
    }
    Iterator temp_iter = begin();
    temp_iter = temp_iter + index;
    return temp_iter.iter_.node->data;
  }
  template< typename T >
  void List< T >::assign(T data_)
  {
    Iterator temp_iter = begin();
    for (size_t i = 0; i < size_; i++)
    {
      temp_iter.iter_.node->data = data_;
      temp_iter++;
    }
  }
  template< typename T >
  void List< T >::pushBack(T data_)
  {
    Node< T > * ptr = new Node < T >(data_);
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
  void List< T >::pushFront(T data_)
  {
    Node< T > * ptr = new Node < T >(data_);
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
      Node< T > * temp = new Node < T >(last_->prev->data, nullptr, last_->prev->prev);
      last_->prev->prev->next = temp;
      //delete last_->prev;
      delete last_;
      last_ = temp;
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
      Node< T > * temp = new Node < T >(first_->next->data, first_->next->next, nullptr);
      //delete last_->prev;
      delete first_;
      first_ = temp;
    }
    size_--;
  }
  template< typename T >
  void List< T >::remove(const T & value)
  {
    if (empty())
    {
      return;
    }
    else
    {
      Iterator temp_iter = begin();
      while (temp_iter.iter_.node->data == value)
      {
        Node< T > * temp_node = temp_iter.iter_.node;
        temp_iter++;
        first_ = temp_iter.iter_.node;
        delete temp_node;
        size_--;
      }
      size_t temp_size = size_;
      temp_iter++;
      for (size_t i = 1; i < temp_size - 1; i++)
      {
        if (temp_iter.iter_.node->data == value)
        {
          Node< T > * temp_node = temp_iter.iter_.node;
          temp_iter.iter_.node->prev->next = temp_iter.iter_.node->next;
          temp_iter.iter_.node->next->prev = temp_iter.iter_.node->prev;
          temp_iter++;
          delete temp_node;
          size_--;
        }
        else
        {
          temp_iter++;
        }
      }
      if (temp_iter.iter_.node->data == value)
      {
        Node< T > * temp_node = temp_iter.iter_.node;
        temp_iter.iter_.node->prev->next = nullptr;
        last_ = temp_iter.iter_.node->prev;
        delete temp_node;
        size_--;
      }
    }
  }
  template< typename T >
  void List< T >::remove_if(bool (*p)(T))
  {
    if (empty())
    {
      return;
    }
    else
    {
      Iterator temp_iter = begin();
      while (p(temp_iter.iter_.node->data))
      {
        Node< T > * temp_node = temp_iter.iter_.node;
        temp_iter++;
        first_ = temp_iter.iter_.node;
        delete temp_node;
        size_--;
      }
      size_t temp_size = size_;
      temp_iter++;
      for (size_t i = 1; i < temp_size - 1; i++)
      {
        if (p(temp_iter.iter_.node->data))
        {
          Node< T > * temp_node = temp_iter.iter_.node;
          temp_iter.iter_.node->prev->next = temp_iter.iter_.node->next;
          temp_iter.iter_.node->next->prev = temp_iter.iter_.node->prev;
          temp_iter++;
          delete temp_node;
          size_--;
        }
        else
        {
          temp_iter++;
        }
      }
      if (p(temp_iter.iter_.node->data))
      {
        Node< T > * temp_node = temp_iter.iter_.node;
        temp_iter.iter_.node->prev->next = nullptr;
        last_ = temp_iter.iter_.node->prev;
        delete temp_node;
        size_--;
      }
    }
  }
  template< typename T >
  void List< T >::clear()
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
  typename List< T >::Iterator List< T >::begin()
  {
    return typename List< T >::Iterator(first_);
  }
  template< typename T >
  typename List< T >::Iterator List< T >::end()
  {
    return typename List< T >::Iterator(last_->next);
  }
  template< typename T >
  T List< T >::front()
  {
    return first_.data;
  }
  template< typename T >
  T List< T >::back()
  {
    return last_.data;
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
      Iterator val_iter(begin());
      return (val_iter + index).node->data;
    }
  }
  template< typename T >
  T List< T >::getSum()
  {
    Iterator sum_iter(begin());
    T summ {};
    while (sum_iter.iter_.node != nullptr)
    {
      if (sum_iter.iter_.node->data > std::numeric_limits< unsigned long long >::max() - summ)
      {
        throw std::overflow_error("vjw");
      }
      summ += sum_iter.iter_.node->data;
      sum_iter++;
    }
    return summ;
  }
  template< typename T >
  void List< T >::print()
  {
    if (empty())
    {
      return;
    }
    Iterator printIter = begin();
    while (printIter.iter_.node->next)
    {
      std::cout << printIter.iter_.node->data << ' ';
      printIter++;
    }
    std::cout << printIter.iter_.node->data << '\n';
  }
  template< typename T >
  void List< T >::printne()
  {
    Iterator printIter(begin());
    while (printIter.iter_.node->next->next != nullptr)
    {
      std::cout << printIter.iter_.node->next->data << ' ';
      printIter++;
    }
    std::cout << printIter.iter_.node->next->data << '\n';
    printIter.iter_.node = first_;
  }
  template< typename T >
  void List< T >::printpr()
  {
    Iterator printIter(begin() + 1);
    while (printIter.iter_.node->next != nullptr)
    {
      std::cout << printIter.iter_.node->prev->data << ' ';
      printIter++;
    }
    std::cout << printIter.iter_.node->prev->data << '\n';
    printIter.iter_.node = first_;
  }
  template< typename T >
  void List< T >::swap(List< T > & other)
  {
    std::swap(first_, other.first_);
    std::swap(last_, other.last_);
    std::swap(size_, other.size_);
  }
  
  
}

#endif
