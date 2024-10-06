#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "Data.hpp"

class Serializer {
 private:
  Serializer();

 public:
  static uintptr_t serialize(const Data* ptr);
  static Data* deserialize(const uintptr_t raw);
};
#endif
