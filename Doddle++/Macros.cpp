#include <iostream>


#if _DEBUG == 1
	#define PRINT(x) std::cout << (x) << std::endl
#else
	#define PRINT(x)
#endif

void fun_with_macros()
{
	PRINT("A really cool Banner");
}
