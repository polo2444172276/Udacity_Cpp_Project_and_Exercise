#include <iostream>

void myFunction(int &&val) { std::cout << "val = " << val << std::endl; }
// void myFunction(int &val) {val++; }
// void myFunction(int val){ val++; }

int main() {
  myFunction(42);

  int i = 23;
  // myFunction(std::move(i));
  myFunction(i);

  return 0;
}
