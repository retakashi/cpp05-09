#include <iostream>
#include <list>
#include <vector>

#include "MutantStack.hpp"

int main() {
  std::cout << "\n[ instance test ]" << std::endl;
  MutantStack<int> mstack;
  std::list<int> list;
  mstack.push(5);
  list.push_back(5);
  mstack.push(17);
  list.push_back(17);
  std::cout << "mstack top: " << mstack.top() << std::endl;
  std::cout << "list top: " << *list.rbegin() << std::endl;
  mstack.pop();
  list.pop_back();
  std::cout << "mstack size: " << mstack.size() << std::endl;
  std::cout << "list size: " << list.size() << std::endl;
  mstack.push(3);
  list.push_back(3);
  mstack.push(5);
  list.push_back(5);
  mstack.push(737);
  list.push_back(737);
  MutantStack<int>::iterator mit = mstack.begin();
  std::list<int>::iterator lit = list.begin();
  MutantStack<int>::iterator mite = mstack.end();
  std::list<int>::iterator lite = list.end();
  std::cout << "mstack: " << std::flush;
  while (mit != mite) {
     std::cout << *mit << " " << std::flush;
    mit++;
  }
  std::cout <<  "\nlist: " << std::flush;;
  while (lit != lite) {
    std::cout << *lit << " " << std::flush;
    lit++;
  }

  std::cout << "\n\n[ copy test ]" << std::endl;
  MutantStack<int> copy(mstack);
  std::cout << "mstack size: " << mstack.size() << std::endl;
  std::cout << "copy size: " << copy.size() << std::endl;
  MutantStack<int>::iterator it = mstack.begin();
  MutantStack<int>::iterator it_copy = copy.begin();
  MutantStack<int>::iterator ite = mstack.end();
  MutantStack<int>::iterator ite_copy = copy.end();
  while (it != ite && it_copy != ite_copy) {
    std::cout << "mstack it: " << *it << std::endl;
    std::cout << "copy it: " << *it_copy << std::endl;
    it++;
    it_copy++;
  }

  std::cout << "\n[ rbegin/rend test ] " << std::endl;
  MutantStack<int>::reverse_iterator rit = mstack.rbegin();
  MutantStack<int>::reverse_iterator rite = mstack.rend();
  for (rit = mstack.rbegin(); rit != rite; rit++)
    std::cout << "mstack rit: " << *rit << std::endl;
  mstack.push(0);
  it = mstack.begin();
  ite = mstack.end();

  std::cout << "\n[ mstack iterator increment/decrement test ]" << std::endl;
  ++it;
  --it;
  while (it != ite) {
    std::cout << "mstack after: " << *it << std::endl;
    ++it;
  }

  std::cout << "\n [ base class test ]" << std::endl;
  std::stack<int> s(mstack);
  for (int i = 0; i < 100000; i++) {
    s.push(i);
  }
  std::cout << "s size: " << s.size() << std::endl;
  std::stack<std::string> *sp = new MutantStack<std::string>;
  std::stack<std::string> *sp2 = new MutantStack<std::string>;
  sp->push("42");
  sp2->push("tokyo");
  sp->swap(*sp2);
  std::cout << "sp: " << sp->top() << std::endl;
  std::cout << "sp2: " << sp2->top() << std::endl;
  delete sp;
  delete sp2;

  std::cout << "\n[ MutantStack<std::string> test ] " << std::endl;
  MutantStack<std::string> str_stack;
  str_stack.push("hello");
  str_stack.push("world");
  std::cout << "str_stack size: " << str_stack.size() << std::endl;
  MutantStack<std::string>::iterator its = str_stack.begin();
  MutantStack<std::string>::iterator itse = str_stack.end();
  while (its != itse) {
    std::cout << "str_stack: " << *its << std::endl;
    its++;
  }
  str_stack.pop();
  std::cout << "str_stack size: " << str_stack.size() << std::endl;
  its = str_stack.begin();
  itse = str_stack.end();
  while (its != itse) {
    std::cout << "str_stack: " << *its << std::endl;
    its++;
  }
  return 0;
}
