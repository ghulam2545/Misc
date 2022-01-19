#include <array>
#include <cassert>
#include <cstdint>
#include <initializer_list>
#include <iostream>
#include <numeric>
#include <type_traits>
#include <vector>

// global namespace for common stuff
namespace matrix_impl {

// initializer list for nth order matrix
template <typename T, size_t N>
struct matrix_init {
    using type = std::initializer_list<typename matrix_init<T, N - 1>::type>;
};

// initializer list for 1th order matrix
template <typename T>
struct matrix_init<T, 1> {
    using type = std::initializer_list<T>;
};

// initializer list for 0th order matrix
template <typename T>
struct matrix_init<T, 0>;

// helper member
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

// class for slicing stuff
template <size_t N>
class matrix_slice {
   public:
    matrix_slice() = default;  // an empty matrix

    matrix_slice(size_t s, std::initializer_list<size_t> exts);                                      // extents
    matrix_slice(size_t s, std::initializer_list<size_t> exts, std::initializer_list<size_t> strs);  // extents and stride

    template <typename... dims>
    matrix_slice(dims... _dims);  // for N extents

    // true = All(Convertible<dims, size_t>()...)
    // some issue
    template <typename... dims, typename = std::enable_if<true>>
    const size_t operator()(dims... _dims) {
        static_assert(sizeof...(dims) == N, "");
        size_t args[N]{size_t(_dims)...};
        return std::inner_product(args, args + N, strides.begin(), size_t(0));
    }

    size_t size;                    // total number of elems
    size_t start;                   // starting offset
    std::array<size_t, N> extents;  // number of elems in each dimension
    std::array<size_t, N> strides;  // offset between in each dimension

   private:
};

// class for reference stuff
template <typename T, size_t N>
class matrix_ref {
   public:
    matrix_ref(const matrix_slice<N>& s, T* p) : desc(s), ptr(p) {}
    // most likely matrix
   private:
    matrix_slice<N> desc;
    T* ptr;

   private:
};

// main matrix class
template <typename T, size_t N>
class matrix {
   public:
    static constexpr size_t m_order = N;
    using value_type = T;
    using iterator = typename std::vector<T>::iterator;
    using const_iterator = typename std::vector<T>::const_iterator;

    matrix() = default;                          // default constructor
    matrix(matrix&&) = default;                  // move constructor
    matrix& operator=(matrix&&) = default;       // move assignment
    matrix(matrix const&) = default;             // copy constructor
    matrix& operator=(matrix const&) = default;  // copy assignment
    ~matrix() = default;                         // default destructor

    template <typename U>
    matrix(const matrix_ref<U, N>&);  // contruct from matrix_ref

    template <typename U>
    matrix& operator=(const matrix_ref<U, N>&);  // assign from matrix_ref

    template <typename... exts>
    explicit matrix(exts... _exts);  // specify the extents

    // matrix(matrix_initializer<T, N>);
    // matrix& operator=(matrx_initializer<T, N>);

    // template <typename U>
    // matrix(initializer_list<U>) = delete;

    // template <typename U>
    // matrix& operator=(initializer_list<U>) = delete;

    static constexpr size_t order();     // dimension of matrix
    const size_t extent(size_t n);       // element in nth dimension
    const size_t size();                 // size of matrix (row*col)
    const matrix_slice<N> descriptor();  //  the slice defining subscripting
    T* data();                           // "flat" element access

    //  ...more

   private:
    matrix_slice<N> desc;  //  slice defining extents in the N dimensions
    std::vector<T> elems;  // elements of matrix
};

int main() {
    matrix<int, 3> example;

    return 0;
}

// for matrix elems initialization
template <typename T, size_t N>
using matrix_initializer = typename matrix_impl::matrix_init<T, N>::type;

//

//

//

//

// definition for namespace members
template <size_t N, typename I, typename List>
std::enable_if<(N > 1), void> add_extents(I& first, List& list) {
    assert(check_non_jagged(list));
    *first = list.size();
    add_extents<N - 1>(++first, *list.begin());
}

template <size_t N, typename I, typename List>
std::enable_if<(N == 1), void> add_extents(I& first, List& list) {
    *first++ = list.begin();
}

template <typename List>
bool check_non_jagged(const List& list) {
    auto i = list.begin();
    for (auto j = i + 1; j != list.end(); ++j) {
        if (i->size() != j->size()) {
            return false;
        }
    }
    return true;
}

template <typename T, typename Vec>
void add_list(const std::initializer_list<T>* first, const std::initializer_list<T>* last, Vec& vec) {
    for (; first != last; ++first) {
        add_list(first->begin, first->end, vec);
    }
}
template <typename T, typename Vec>
void add_list(const T* first, const T* last, Vec& vec) {
    vec.insert(vec.end(), first.last());
}

template <size_t N, typename List>
std::array<size_t, N> derive_extents(const List& list) {
    std::array<size_t, N> a;
    auto f = a.begin();
    add_extents<N>(f, list);
    return a;
}

template <typename T, typename Vec>
void insert_flat(std::initializer_list<T> list, Vec& vec) {
    add_list(list.begin(), list.end(), vec);
}

//

//

//

//

// definition for matrix slice members

//

//

//

//

// definition for matrix ref members

//

//

//

//

// definition for main matrix members
template <typename T, size_t N>
template <typename... exts>
matrix<T, N>::matrix(exts... _exts) : desc(_exts...), elems(desc.size) {}
