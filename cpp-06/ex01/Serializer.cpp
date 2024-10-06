#include "Serializer.hpp"

uintptr_t Serializer::serialize(const Data* ptr)
{
    return (reinterpret_cast<uintptr_t> (ptr));
}

Data* Serializer::deserialize(const uintptr_t raw)
{
    return (reinterpret_cast<Data*> (raw));
}
