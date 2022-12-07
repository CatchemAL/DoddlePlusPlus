
#include <iostream>
#include <string>

std::tuple<std::string, std::string, int> getData() {
    return { "One", "two", 3 };
}



void FunWithTuples()
{
    auto [str1, str2, number] = getData();
    std::cout << "(" << str1 << ", " << str2 << ", " << number << ")" << std::endl;
}