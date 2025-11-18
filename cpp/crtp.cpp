#include <iostream>

template <typename Derived>
class Base {
 public:
  void interface() { static_cast<Derived*>(this)->implementation(); }

  void common() { std::cout << "Base: common behavior" << std::endl; }
};

class Derived : public Base<Derived> {
 public:
  void implementation() {
    std::cout << "Derived: derived implementation" << std::endl;
  }
};

int main() {
  Derived derived;
  derived.interface();
}
