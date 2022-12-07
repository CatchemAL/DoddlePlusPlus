#include <cstring>
#include <iostream>

static void increment(int* x)
{
    (*x)++;
}

void fun_with_pointers()
{
    void* ptr1 = 0;
    void* ptr2 = nullptr;

    int a = 5;
    int* ap = &a;
    int** app = &ap;
    int b = 5;
    int* bp = &b;
    int** bpp = &bp;

    bpp = nullptr;

    constexpr int size = 8;
    char* buffer = new char[size];
    memset(buffer, 65, 8);

    for (int i = 0; i < size + 3; i++)
    {
	    const char c = buffer[i];
        if (i < size)
            std::cout << "The char has a value of " << c << std::endl;
        else
            std::cout << "Overflow char has a value of " << c << std::endl;
    }

    delete[] buffer;

    std::cout << "The value of a is: " << a << std::endl;
    increment(ap);
    std::cout << "The value of a is: " << a << std::endl;
}
