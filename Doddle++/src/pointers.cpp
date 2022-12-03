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

    /*
	// Rust              C/C++
	    a: &T       ==   const T* const a; // can't mutate either
	mut a: &T       ==   const T* a;       // can't mutate what is pointed to
	    a: &mut T   ==   T* const a;       // can't mutate pointer
	mut a: &mut T   ==   T* a;             // can mutate both
	 */

    int k = 21;
    int m = 38;
    int* ptr = &k;                // A    mutable reference to a    mutable variable
    int* const ptr_nc = &k;       // An immutable reference to a    mutable variable
    const int* ptr_cn = &k;       // A    mutable reference to an immutable variable
    const int* const ptr_cc = &k; // An immutable reference to an immutable variable

    ptr = &m;       //    allowed
    (*ptr)++;       //    allowed
    
    // ptr_nc = &m; // disallowed
    (*ptr_nc)++;    //    allowed
    
    ptr_cn = &m;    //    allowed
    // (*ptr_cn)++; // disallowed
    
    // ptr_cc = &m; // disallowed
    // (*ptr_cc)++; // disallowed
}
