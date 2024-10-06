#include "Base.hpp"

int main()
{
  try
  {
    A a;
    B b;
    C c;
    A *a_ptr = &a;
    Base *ret;

    ret = NULL;
    ret = generate();
    identify(ret);
    identify(a_ptr);
    identify(NULL);
    identify(a);
    identify(b);
    identify(c);
    delete ret;
    return (0);
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what() << '\n';
  }
}
