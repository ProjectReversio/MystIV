#include "base_rd.hpp"

namespace ubi
{
    Allocator::Allocator()
    {

    }

    Allocator::~Allocator() = default;

    void* Allocator::Malloc(unsigned int a1)
    {
        return nullptr;
    }

    Allocator *Mem::GetGeneralAlloc()
    {
        return nullptr;
    }
}
