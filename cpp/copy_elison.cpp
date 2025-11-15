#include <iostream>

struct A {
  A() { std::cout << "A()\n"; }

  // Copy constructor
  A(const A&) { std::cout << "A copy()\n"; }

  ~A() { std::cout << "A destructor\n"; }
};

A makeA() { return A(); }

int main() { A a = makeA(); }
