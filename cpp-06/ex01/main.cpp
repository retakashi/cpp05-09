#include "Serializer.hpp"

int main()
{
    Data data;
    Data *d_ptr;
    data.srt = "hello";
    d_ptr = &data;
    uintptr_t u_ptr = 0;
    std::cout << "d_ptr before: " << d_ptr << std::endl;
    u_ptr = Serializer::serialize(d_ptr);
    std::cout << "u_ptr: 0x" << std::hex << u_ptr << std::endl;
    d_ptr = Serializer::deserialize(u_ptr);
    std::cout << "d_ptr: after: " << d_ptr << std::endl;
    std::cout << "str: " << d_ptr->srt << std::endl;
    return (0);
}
