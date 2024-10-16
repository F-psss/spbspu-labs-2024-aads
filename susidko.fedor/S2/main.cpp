#include <algorithm>
#include "queue.hpp"
#include "stack.hpp"
#include "types.hpp"
#include "funcs.hpp"
#include <fstream>
#include <iostream>
#include <string>


int main(int argc, char *argv[])
{
  susidko::Stack< std::string > stack;
  if (argc == 1)
  {
    susidko::fillStack(std::cin, stack);
  }
  else if (argc == 2)
  {
    std::ifstream input(argv[1]);
    susidko::fillStack(input, stack);
  }
  else
  {
    std::cerr << "Empty input\n";
    return 11;
  }
  long long sz = stack.size();
  if (sz == 0)
  {
    std::cout << "\n";
    return 0;
  }
  for (long long i = 0; i < sz; i++)
  {
    try
    {
      long long size = 0;
      susidko::Infix tet = susidko::createInfix(stack.top());
      susidko::Postfix posss = tet.infToPost();
      if (i < (sz - 1))
      {
        std::cout << posss.countPostfix() << " ";
      }
      else
      {
        std::cout << posss.countPostfix() << "\n";
      }
      stack.pop();
    }
    catch(const std::exception& e)
    {
      std::cerr << e.what() << '\n';
      return 1;
    }
  }

  return 0;
	/*susidko::Operand bb(2);
	susidko::Operand cc(3);
	susidko::Operand aa(1);
	susidko::Operator minus('-');
	//susidko::Queue< susidko::Elem > st = susidko::Queue< susidko::Elem >();
	susidko::Stack<susidko::Elem> st = susidko::Stack<susidko::Elem>();
  susidko::Elem c = susidko::Elem(aa);
	susidko::Elem d = susidko::Elem(bb);

	susidko::Elem g = susidko::Elem(cc + cc);

	susidko::Elem e = susidko::Elem(cc);
	st.push(c);
	st.push(d);
	st.push(e);
	st.push(g);
	//st.push(susidko::Any(bb));
	//st.push(susidko::Any(minus));
	//std::cout << aa.getValue() << std::endl;
	//std::cout << minus.perf(aa, bb) << std::endl;
	susidko::List<int> li = susidko::List<int>{1, 2, 3, 4, 5};
	//li.print();
	susidko::List<int> lii(li);

	//li.popBack();
  //lii.print();
  //li.print();
	susidko::Elem a1 = susidko::Elem(susidko::Bracket('('));
	susidko::Elem a2 = susidko::Elem(susidko::Operand(5));
	susidko::Elem a3 = susidko::Elem(susidko::Operator('-'));
	susidko::Elem a4 = susidko::Elem(susidko::Operand(15));
	susidko::Elem a5 = susidko::Elem(susidko::Bracket(')'));

	susidko::Elem a6 = susidko::Elem(susidko::Operator('/'));

	susidko::Elem a7 = susidko::Elem(susidko::Bracket('('));
	susidko::Elem b1 = susidko::Elem(susidko::Operand(4));
	susidko::Elem b2 = susidko::Elem(susidko::Operator('+'));
	susidko::Elem b3 = susidko::Elem(susidko::Operand(7));
	susidko::Elem b4 = susidko::Elem(susidko::Operator('-'));
	susidko::Elem b5 = susidko::Elem(susidko::Operand(1));
	susidko::Elem b6 = susidko::Elem(susidko::Bracket(')'));


	susidko::Queue< susidko::Elem > te;
	te.push(a1);
	te.push(a2);
	te.push(a3);
	te.push(a4);
	te.push(a5);
	te.push(a6);
	te.push(a7);

	te.push(b1);
	te.push(b2);
	te.push(b3);
	te.push(b4);
	te.push(b5);
	te.push(b6);

  susidko::Queue< susidko::Elem > te2(te);
  //te.print();
  //te2.print();

	susidko::Infix tet(te);
	//tet.infToPost();
	susidko::Postfix posss = tet.infToPost();
	posss.print();
	posss.print();


	//std::cout << st.pop().get();
	//std::cout << st.pop().get();
	//std::cout << st.pop().get();
	//std::cout << st.pop().get();*/
	return 0;
}
