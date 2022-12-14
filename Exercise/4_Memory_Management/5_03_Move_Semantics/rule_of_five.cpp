#include <stdlib.h>
#include <iostream>

class MyMovableClass {
 private:
  int _size;
  int *_data;

 public:
  // 1. constructor
  MyMovableClass(size_t size) {
    _size = size;
    _data = new int[_size];
    std::cout << "CREATING instance of MyMovableClass at " << this
              << " allocated with size = " << _size * sizeof(int) << " bytes."
              << std::endl;
  }

  // 1. destructor
  ~MyMovableClass() {
    std::cout << "DELETING instance of MyMovableClass at " << this << std::endl;
    delete[] _data;
  }

  // 2. copy constructor
  MyMovableClass(const MyMovableClass &source) {
    _size = source._size;
    _data = new int[_size];
    *_data = *source._data;
    std::cout << "COPYING content of instance " << &source << " to instance "
              << this << std::endl;
  }

  // 3. copy assignment constructor
  MyMovableClass &operator=(const MyMovableClass &source) {
    std::cout << "ASSIGNING content of instance " << &source << " to instance "
              << this << std::endl;

    // standard boiler plate if statement to protect against self assignment
    if (this == &source) return *this;

    delete[] _data;
    _data = new int[source._size];
    *_data = *source._data;
    _size = source._size;
    return *this;
  }

  // 4. move constructor
  MyMovableClass(MyMovableClass &&source) {
    std::cout << "MOVING (c’tor) instance " << &source << " to instance "
              << this << std::endl;
    _data = source._data;
    _size = source._size;
    source._data = nullptr;
    source._size = 0;
  }

  // 5. move assignment operator
  MyMovableClass &operator=(MyMovableClass &&source) {
    std::cout << "MOVING (assign) instance " << &source << " to instance "
              << this << std::endl;
    
    return *this;
    if (this == &source) return *this;

    delete[] _data;

    _data = source._data;
    _size = source._size;

    source._data = nullptr;
    source._size = 0;

    return *this;
  }
};

int main() {

  // MyMovableClass obj1(100), obj2(200);  // constructor

  // MyMovableClass obj3(obj1);  // copy constructor

  // MyMovableClass obj4 = obj1;  // copy constructor

  // obj4 = obj2;  // copy assignment operator

  //cons + cons + move assignment + cons + move assignment + cons + move copy const + cons + move copy const
  //des, des, des
  std::cout << "Initial Part. \n";
  // ==================================== //

  MyMovableClass obj10(100);  // constructor   //cons

  obj10 = MyMovableClass(200);  // move assignment operator //cons + move assign

  MyMovableClass obj20 = std::move(MyMovableClass(300));  // cons + move constructor

  std::cout << "address of obj20: " << &obj20 << std::endl;

  MyMovableClass obj30(std::move(MyMovableClass(300))); //cons + move copy cons.

  std::cout << "address of obj30: " << &obj30 << std::endl;

  // Moving lvalues
  std::cout << "Moving Lvalue. \n";
  MyMovableClass useObject(std::move(obj10)); //move cons

  return 0;
}

// compile using this command
// g++ -std=c++11 -fno-elide-constructors rule_of_five.cpp -o output
// run using this command
// ./output
