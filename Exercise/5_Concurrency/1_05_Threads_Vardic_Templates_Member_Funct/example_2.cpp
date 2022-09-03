#include <iostream>
#include <string>
#include <thread>

void printName(std::string name, int &waitTime) {
  std::this_thread::sleep_for(std::chrono::milliseconds(waitTime));
  waitTime += 100;
  std::cout << "Name (from Thread) = " << name << std::endl;
  name += 'a';
}

int main() {
  std::string name1 = "My Thread 1";
  std::string name2 = "My Thread 2";
  
  int i = 100, j = 200;
  // starting threads using value-copy and move semantics
  std::thread t1(printName, name1, std::ref(i));
  std::thread t2(printName, std::move(name2), std::ref(j));

  // wait for threads before returning
  t1.join();
  t2.join();

  // print name from main
  std::cout << "Name (from Main) = " << name1 << std::endl;
  std::cout << "Name (from Main) = " << name2 << std::endl;

  std::cout << i << " " << j << std::endl;
  return 0;
}