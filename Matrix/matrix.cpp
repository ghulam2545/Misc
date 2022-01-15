#include <array>
#include <cassert>
#include <cstdint>
#include <initializer_list>
#include <iostream>
#include <type_traits>
#include <vector>

namespace matrix_impl {

template <typename T, size_t N>
struct matrix_init {
    using type = std::initializer_list<typename matrix_init<T, N - 1>::type>;
};

template <typename T>
struct matrix_init<T, 1> {
    using type = std::initializer_list<T>;
};

template <typename T>
struct matrix_init<T, 0>;

// members
template <size_t N, typename List>
std::array<size_t, N> derive_extents(const List& list);

template <typename T, typename Vec>
void insert_flat(std::initializer_list<T> list, Vec& vec);

template <size_t N, typename I, typename List>
std::enable_if<(N > 1), void> add_extents(I& first, List& list);

template <size_t N, typename I, typename List>
std::enable_if<(N == 1), void> add_extents(I& first, List& list);

template <typename List>
bool check_non_jagged(const List& list);

template <typename T, typename Vec>
void add_list(const std::initializer_list<T>* first, const std::initializer_list<T>* last, Vec& vec);

template <typename T, typename Vec>
void add_list(const T* first, const T* last, Vec& vec);
}  // namespace matrix_impl

template <typename T, size_t N>
using matrix_initializer = typename matrix_impl::matrix_init<T, N>::type;

template <size_t N>
struct matrix_slice {
    matrix_slice() = default;

    matrix_slice(size_t s, std::initializer_list<size_t> exts);
};

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

    matrix(matrix_initializer<T, N>);
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
    matrix_slice<N> desc;
    std::vector<T> elems;
};

int main() { return 0; }
/*
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
*/

//

//

//

//
template <typename T, size_t N>
template <typename... exts>
matrix<T, N>::matrix(exts... _exts) : desc(_exts...), elems(desc.size) {}

template <size_t N, typename I, typename List>
std::enable_if<(N > 1), void> matrix_impl::add_extents(I& first, List& list) {
    assert(check_non_jagged(list));
    *first = list.size();
    add_extents<N - 1>(++first, *list.begin());
}

template <size_t N, typename I, typename List>
std::enable_if<(N == 1), void> matrix_impl::add_extents(I& first, List& list) {
    *first++ = list.begin();
}

template <typename List>
bool matrix_impl::check_non_jagged(const List& list) {
    auto i = list.begin();
    for (auto j = i + 1; j != list.end(); ++j) {
        if (i->size() != j->size()) {
            return false;
        }
    }
    return true;
}

template <typename T, typename Vec>
void matrix_impl::add_list(const std::initializer_list<T>* first, const std::initializer_list<T>* last, Vec& vec) {
    for (; first != last; ++first) {
        add_list(first->begin, first->end, vec);
    }
}

template <typename T, typename Vec>
void matrix_impl::add_list(const T* first, const T* last, Vec& vec) {
    vec.insert(vec.end(), first.last());
}

template <size_t N, typename List>
std::array<size_t, N> matrix_impl::derive_extents(const List& list) {
    std::array<size_t, N> a;
    auto f = a.begin();
    add_extents<N>(f, list);
    return a;
}

template <typename T, typename Vec>
void matrix_impl::insert_flat(std::initializer_list<T> list, Vec& vec) {
    add_list(list.begin(), list.end(), vec);
}

template <typename T, size_t N>
matrix<T, N>::matrix(matrix_initializer<T, N> init) {
    matrix_impl::derive_extents(init, desc.extents);
    elems.reserve(desc.size);
    matrix_impl::insert_flat(init, elems);
    assert(elems.size() == desc.size);
}
