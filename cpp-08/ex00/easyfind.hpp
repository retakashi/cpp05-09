#pragma once

#include <exception>

template <typename T>
typename T::const_iterator easyfind(const T &c, int num) {
  typename T::const_iterator ret = std::find(c.begin(), c.end(), num);
  return (ret);
}
