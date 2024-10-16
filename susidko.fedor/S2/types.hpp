#ifndef TYPES_HPP
#define TYPES_HPP

#include "queue.hpp"
#include "stack.hpp"

namespace susidko
{
  class Operand
  {
    friend class Operator;
    public:
      Operand(long long value):
        value_(value)
      {}
      Operand operator+(const Operand & rhs);
      const long long getValue() const noexcept;
    private:
      long long value_;
  };
  
  class Operator
  {
    public:
      Operator(char value):
        value_(value),
        priority_(0)
      {
        if (value == '+' or value == '-')
        {
          priority_ = 1;
        }
        else
        {
          priority_ = 2;
        }
      }
      long long perf(Operand a, Operand b);
      char getValue() const noexcept;
      const int getPriority() const noexcept;
    private:
      char value_;
      int priority_;
  };

  class Bracket
  {
    public:
      Bracket(char value):
        value_(value)
      {}
      const char getValue() const noexcept;
    private:
      char value_;
  };
  
  class Elem
  {
    public:
      Elem(std::string type, std::string value):
        operand_(Operand(1)),
        operator_(Operator('q')),
        bracket_(Bracket('q'))
      {
        if (type == "operand")
        {
          type_ = 'n';
          operand_ = Operand(std::stoll(value));
        }
        else if (type == "operator")
        {
          type_ = 't';
          operator_ = Operator(value.c_str()[0]);
        }
        else if (type == "bracket")
        {
          type_ = 'b';
          bracket_ = Bracket(value.c_str()[0]);
        }
        else
        {
          std::cout << "ASDFGHJHGFDSASDFGHJKJHGFDSADFGHJ";
        }
      }
      Elem(Operand operand):
        operand_(operand),
        operator_(Operator('q')),
        bracket_(Bracket('q')),
        type_('n')
      {}
      Elem(Operator operatorr):
        operand_(Operand(1)),
        operator_(operatorr),
        bracket_(Bracket('q')),
        type_('t')
      {}
      Elem(Bracket bracket):
        operand_(Operand(1)),
        operator_(Operator('q')),
        bracket_(bracket),
        type_('b')
      {}
      std::string get();
      char getType();

      char type_;
      Operand operand_;
      Operator operator_;
      Bracket bracket_;
    
  };

  class Postfix
  {
    public:
      Postfix(Queue< Elem > body):
       body_(body)
      {}
      bool isEmpty();
      void print();
    private:
      Queue< Elem > body_;
  };

  class Infix
  {
    public:
      Infix(Queue< Elem > body):
        body_(body)
      {}
      bool isEmpty();
      void print();
      Postfix infToPost();
    private:
      Queue< Elem > body_;
  };
}
susidko::Operand susidko::Operand::operator+(const susidko::Operand & rhs)
{
  return susidko::Operand(getValue() + rhs.getValue());
}
const long long susidko::Operand::getValue() const noexcept
{
  return value_;
}
long long susidko::Operator::perf(susidko::Operand a, susidko::Operand b)
{
  switch (value_)
  {
    case '+':
      return (a.value_ + b.value_);
    case '-':
      return (a.value_ - b.value_);
    case '*':
      return (a.value_ * b.value_);
    case '%':
      return (a.value_ % b.value_);
  }
  return 0;
}
char susidko::Operator::getValue() const noexcept
{
  return value_;
}
const int susidko::Operator::getPriority() const noexcept
{
  return priority_;
}
const char susidko::Bracket::getValue() const noexcept
{
  return value_;
}
std::string susidko::Elem::get()
{
  if (type_ == 'n')
  {
    return std::to_string(operand_.getValue());
  }
  else if (type_ == 't')
  {
    return std::string(1, operator_.getValue());
  }
  else
  {
    return std::string(1, bracket_.getValue());
  }
}
char susidko::Elem::getType()
{
  return type_;
}
bool susidko::Infix::isEmpty()
{
  return body_.isEmpty();
}
bool susidko::Postfix::isEmpty()
{
  return body_.isEmpty();
}
void susidko::Infix::print()
{
  body_.print();
}
void susidko::Postfix::print()
{
  body_.print();
}

susidko::Postfix susidko::Infix::infToPost()
{
  susidko::Infix inf(body_);
  susidko::Queue< susidko::Elem > res;
  susidko::Stack< Elem > stack;
  std::cout << "start";
  while (not inf.isEmpty())
  {
    susidko::Elem i = inf.body_.pop();
    if (i.getType() == 'n')
    {
      std::cout << "n" << std::endl;
      res.push(i);
    }
    else if (i.getType() == 't')
    {
      while (!stack.isEmpty() and stack.top().getType() == 't' && i.operator_.getPriority() <= stack.top().operator_.getPriority())
      {
        susidko::Elem temp = stack.top();
        res.push(temp);
        stack.pop();
      }
      stack.push(i);
      std::cout << "t" << std::endl;
    }
    else if (i.getType() == 'b')
    {
      std::cout << "b" << std::endl;
      if (i.get() == "(")
      {
        stack.push(i);
      }
      else
      {
        while (!stack.isEmpty() and stack.top().getType() != 'b')
        {
          susidko::Elem temp = stack.top();
          res.push(temp);
          stack.pop();
        }
        stack.pop();
      }
    }
  }
  while (!stack.isEmpty())
  {
    susidko::Elem temp = stack.top();
    res.push(temp);
    stack.pop();
  }
//res.print();
susidko::Postfix ress = susidko::Postfix(res);
return ress;
}

#endif
