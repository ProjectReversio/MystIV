#pragma once

#define BASE_RD_CALL __cdecl

#ifdef _WIN32
    #ifdef BASE_RD_LIBRARY
        #define BASE_RD_API __declspec(dllexport)
    #else
        #define BASE_RD_API __declspec(dllimport)
    #endif
#else
    #define BASE_RD_API
#endif

namespace ubi
{
    class BASE_RD_API Allocator
    {
    public:
        Allocator();
        ~Allocator();

        void* Malloc(unsigned int a1);
    };

    class BASE_RD_API Mem
    {
    public:
        static Allocator* GetGeneralAlloc();
    };
}