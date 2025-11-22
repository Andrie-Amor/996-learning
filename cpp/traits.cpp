#include <iostream>
#include <string>

// Primary template
template <typename T>
struct Printer {
  static void print(const T& value) {
    std::cout << "generic: " << value << std::endl;
  }
};

// Full specialization
// Must appear after the primary is declared; must match exact arguments
template <>
struct Printer<std::string> {
  static void print(const std::string& value) {
    std::cout << "std::string specialized: " << value << std::endl;
  }
};

// Partial specialization
// Customize subset of args or pattern
// NOTE: For primary specialization, can't define like struct IsPointer<T> or
// IsPointer<>.
// NOTE: Only for class/variable templates, NOT function templates
template <typename T>
struct IsPointer {
  static constexpr bool value = false;
};

// Partial specialization
template <typename T>
struct IsPointer<T*> {  // Only takes pointer types
  static constexpr bool value = true;
};

// Example 2:
template <typename Key, typename Value>
class KeyValuePair {};

template <>
class KeyValuePair<int, std::string> {};

template <typename Key>
class KeyStringPair : public KeyValuePair<Key, std::string> {};

template <typename Value>
class IntegerValuePair : public KeyValuePair<int, Value> {};

// Traits

// Detect std::string
template <typename T>
struct isStdString : std::false_type {};

template <>
struct isStdString<std::string> : std::true_type {};

// Detect const-qualified types
template <typename T>
struct IsConst : std::false_type {};

template <typename T>
struct IsConst<const T> : std::true_type {};

// Remove references
template <typename T>
struct RemoveReference {
  using type = T;
};
