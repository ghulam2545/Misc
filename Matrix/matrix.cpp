#include <bits/stdc++.h>
// #include <cstdint>
// #include <initializer_list>
// #include <iostream>
// #include <vector>

namespace matrix_impl {}

template <typename T, size_t N>
class matrix {
   public:
    static constexpr size_t order = N;
    using value_type = T;
    using iterator = typename std::vector<T>::iterator;
    using const_iterator = typename std::vector<T>::const_itrerator;

    matrix() = default;
    matrix(matrix&&) = default;
    matrix(matrix const&) = default;
    matrix& operator=(matrix&&) = default;
    matrix& operator=(matrix const&) = default;
    ~matrix() = default;

    // template <typename U>
    // matrix(const matrix_ref<U, N>&);

    // template <typename U>
    // matrix& operator=(const matrix_ref<U, N>&);

    template <typename... exts>
    explicit matrix(exts... _exts);

    // matrix(matrix_initializer<T, N>);
    // matrix& operator=(matrx_initializer<T, N>);

    // template <typename U>
    // matrix(initializer_list<U>) = delete;

    // template <typename U>
    // matrix& operator=(initializer_list<U>) = delete;

    // static constexpr size_t order();
    // const size_t extent(size_t n);
    // const size_t size();

    // const matrix_slice<T> descriptor();

    // T* data();
    // const T* data();

    //  ...more

   private:
    matrix_slice<T> desc;
    std::vector<T> elems;
};

struct slice {
    slice();
    explicit slice(size_t s);
    slice(size_t s, size_t l, size_t n = 1);

    const size_t operator(size_t i);

    static slice all;

    size_t start;
    size_t length;
    size_t stride;
};

template <typename T, size_t N>
struct matrix_init {
    using type = initializer_list<typename matrix_init<T, N - 1>::type>;
};

template <typename T>
struct matrix_init<T, 1> {
    using type = initializer_list<T>;
};

template <typename T>
struct matrix_init<T, 0>;
//

//

//

//
template <typename T, size_t N>
template <typename... exts>
matrix<T, N>::matrix(exts... _exts) : desc(_exts...), elems(desc.size) {}

// template <typename T, size_t N>
// matrix<T, N>::matrix(matrix_initializer<T, N> init) {
//     matrix_imp::deriv_extents(init, desc.extents);
//     elems.reserve(desc.size);
//     matrix_impl::insert_flat(init, elems);
//     assert(elems.size() == desc.size);
// }

int main() { return 0; }