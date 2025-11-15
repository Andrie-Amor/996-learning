#include <string>
#include <mutex>

// Meyer's Singleton
struct MeyersSingleton {
public:
  const std::string data;


  [[nodiscard]] static MeyersSingleton& get() {
    if (!singleton_) {
      // Exit on trying to access singleton before creation
      std::exit(EXIT_FAILURE);
    }
    return *singleton_;
  }

  [[nodiscard]] static MeyersSingleton& create(std::string data) {
    std::call_once(once_flag_, [&]() {
      singleton_ = new MeyersSingleton(std::move(data));
    });

    return *singleton_;
  }
  
private:
  MeyersSingleton(std::string data) : data(std::move(data)) {}
  MeyersSingleton(const MeyersSingleton&) = delete;
  MeyersSingleton& operator=(const MeyersSingleton&) = delete;
  
  inline static MeyersSingleton* singleton_ = nullptr;
  inline static std::once_flag once_flag_;
};

int main() { return 0; }
