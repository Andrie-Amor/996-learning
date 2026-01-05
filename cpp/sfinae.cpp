#include <iostream>

// Function overloads
#include <type_traits>
template <typename T>
std::enable_if_t<std::is_integral_v<T>, void> describe(T) {
  std::cout << "integral\n";
}

template <typename T>
std::enable_if_t<std::is_floating_point_v<T>, void> describe(T) {
  std::cout << "floating\n";
}
