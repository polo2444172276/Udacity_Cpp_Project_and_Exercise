#include <iostream>

int main()
{
    int i;
    std::cout << "Enter an integer value for i: ";
    std::cin >> i;
    constexpr int j = i * 2;  
                              // "constexpr must be evaluated at compile time."
                              // "So this code will produce a compilation error."
}