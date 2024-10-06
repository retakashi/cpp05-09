#include "Base.hpp"

Base::~Base() {}

static const int total = 3;

Base *generate(void)
{
  std::srand(static_cast<unsigned int>(std::time(NULL)));
  int ret = std::rand();
    if (ret % total == 0)
    {
      A *a_p = new A;
      return (a_p);
    }
    else if (ret % total == 1)
    {
      B *b_p = new B;
      return (b_p);
    }
    else if (ret % total == 2)
    {
      C *c_p = new C;
      return (c_p);
    }
  return (NULL);
}

void identify(Base *p)
{
  A *a_ptr = dynamic_cast<A *>(p);
  B *b_ptr = dynamic_cast<B *>(p);
  C *c_ptr = dynamic_cast<C *>(p);
  if (a_ptr != NULL)
    std::cout << "pointer: A" << std::endl;
  else if (b_ptr != NULL)
    std::cout << "pointer: B" << std::endl;
  else if (c_ptr != NULL)
    std::cout << "pointer: C" << std::endl;
  else
    std::cerr << "failed to dynamic cast" << std::endl;
}

void identify(Base &p)
{
  int err_cnt = 0;
  try
  {
    A &a_r = dynamic_cast<A &>(p);
    std::cout << "reference: A (" << &a_r << ")" << std::endl;
  }
  catch (std::exception &e)
  {
    err_cnt++;
  }
  try
  {
    B &b_r = dynamic_cast<B &>(p);
    std::cout << "reference: B (" << &b_r << ")" << std::endl;
  }
  catch (const std::exception &e)
  {
    err_cnt++;
  }
  try
  {
    C &c_r = dynamic_cast<C &>(p);
    std::cout << "reference: C (" << &c_r << ")" << std::endl;
  }
  catch (const std::exception &e)
  {
    err_cnt++;
    if (err_cnt == total)
      std::cerr << e.what() << std::endl;
  }
}
