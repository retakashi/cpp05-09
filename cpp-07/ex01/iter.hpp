#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T, typename F>
void iter(T *array, const size_t arr_len, F f) {
    if (array != NULL && f != NULL) {
        for (size_t i = 0; i < arr_len; i++) {
            f(array[i]);
        }
    }
}

template <typename T>
void func(T& t)
{
    std::cout << t << std::endl;
}

template <typename T>
void funcConst(const T& t)
{
    std::cout << t << std::endl;
}

#endif
