#include <memory>
#include <type_traits>
template <typename stream>
struct io {
    io(stream) : b(false) {}
    alignas(64) bool b;
};
int main() {
    auto pi = std::make_unique<int>(543);
    using iio = io<int>;
    io x(7);
    static_assert(std::is_same_v<decltype(x), iio>);
}
