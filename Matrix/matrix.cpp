#include <array>
#include <cassert>
#include <iostream>
#include <numeric>
#include <type_traits>
#include <vector>

template <bool B, typename T = void>
using Enable_if = typename std::enable_if<B, T>::type;

constexpr bool All() { return true; }

template <typename... args>
constexpr bool All(bool b, args... _args) {
    return b && All(_args...);
}

template <typename X, typename Y>
constexpr bool Convertible() {
    return std::is_convertible<X, Y>::value;
}

// This is globally available namespace for common working
namespace matrix_impl {

    // constructing initializer list for nth order matrix
    template <typename T, size_t N>
    struct matrix_init {
        using type = std::initializer_list<typename matrix_init<T, N - 1>::type>;
    };

    // constructing initializer list for 1th order matrix
    template <typename T>
    struct matrix_init<T, 1> {
        using type = std::initializer_list<T>;
    };

    // for 0th order matrix (undefined behaviour)
    template <typename T>
    struct matrix_init<T, 0>;

    // Helper members
    /*
     * derive_extents() determines the shape of the Matrix:
     * Checks that the tree really is N deep
     * Checks that each row (sub-initialize_list) has the same number of elements
     * Sets the extent of each row
     */
    template <size_t N, typename List>
    std::array<size_t, N> derive_extents(const List& list);

    // insert_flat() copies the elements of the tree of initializer_list<T>s into the elems of a Matrix
    template <typename T, typename Vec>
    void insert_flat(std::initializer_list<T> list, Vec& vec);

    template <size_t N, typename I, typename List>
    Enable_if<(N > 1), void> add_extents(I& first, List& list);

    template <size_t N, typename I, typename List>
    Enable_if<(N == 1), void> add_extents(I& first, List& list);

    template <size_t N, typename List>
    bool check_non_jagged(const List& list);

    template <typename T, typename Vec>
    void add_list(const std::initializer_list<T>* first, const std::initializer_list<T>* last, Vec& vec);

    template <typename T, typename Vec>
    void add_list(const T* first, const T* last, Vec& vec);

    template <typename... args>
    constexpr bool requesting_element();

    template <typename... args>
    constexpr bool requesting_slice();

}  // namespace matrix_impl

// for matrix elems initialization
template <typename T, size_t N>
using matrix_initializer = typename matrix_impl::matrix_init<T, N>::type;

// class for slicing purpose
template <size_t N>
class matrix_slice {
   public:
    matrix_slice() = default;  // an empty matrix

    matrix_slice(size_t s, std::initializer_list<size_t> exts);                                      // extents
    matrix_slice(size_t s, std::initializer_list<size_t> exts, std::initializer_list<size_t> strs);  // extents and stride

    template <typename... dims>
    matrix_slice(dims... _dims);  // for N extents

    template <typename... dims, typename = Enable_if<All(Convertible<dims, size_t>()...)>>
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

// class for referencing purpose
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

// This is main matrix class
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

    matrix(matrix_initializer<T, N>);             // initialize from list
    matrix& operator=(matrix_initializer<T, N>);  // assign from list

    // don't use {} except for elements
    template <typename U>
    matrix(std::initializer_list<U>) = delete;
    template <typename U>
    matrix& operator=(std::initializer_list<U>) = delete;

    static constexpr size_t order();     // dimension of matrix
    const size_t extent(size_t n);       // element in nth dimension
    const size_t size();                 // size of matrix (row*col)
    const matrix_slice<N> descriptor();  //  the slice defining subscripting
    T* data();                           // "flat" element access
    // const T* data();

    /*
    template <typename... args>
    std::enable_if<matrix_impl::requesting_element<args..>(), T&> operator()(args... _args);
    template <typename... args>
    std::enable_if<matrix_impl::requesting_element<args..>(), const T&> operator()(args... _args) const;

    template <typename... args>
    std::enable_if<matrix_impl::requesting_slice<args..>(), matrix_ref<T, N>> operator()(const args&... _args);
    template <typename... args>
    std::enable_if<matrix_impl::requesting_slice<args..>(), matrix_ref<const T, N>> operator()(const args&... _args) const;
    */
    matrix_ref<T, N - 1> operator[](size_t i);
    matrix_ref<const T, N - 1> operator[](size_t i) const;  // m[i] row access

    matrix_ref<T, N - 1> row(size_t n);
    matrix_ref<const T, N - 1> row(size_t n) const;  // row access

    matrix_ref<T, N - 1> col(size_t n);
    matrix_ref<const T, N - 1> col(size_t n) const;  // column access

    // more...

   private:
    matrix_slice<N> desc;  //  slice defining extents in the N dimensions
    std::vector<T> elems;  // elements of matrix
};

int main() {
    matrix<int, 2> example;

    return 0;
}

//

//

//

// definition for namespace member goes here

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

template <size_t N, typename I, typename List>
Enable_if<(N > 1), void> matrix_impl::add_extents(I& first, List& list) {
    // there might be some issue (add_extents())
    assert(check_non_jagged(list));
    *first = list.size();
    add_extents<N - 1>(++first, *list.begin());
}

template <size_t N, typename I, typename List>
Enable_if<(N == 1), void> matrix_impl::add_extents(I& first, List& list) {
    *first++ = list.size();  // 1.
}

template <size_t N, typename List>
bool matrix_impl::check_non_jagged(const List& list) {
    auto i = list.begin();
    for (auto j = i + 1; j != list.end(); ++j) {
        if (derive_extents<N - 1>(*i) != derive_extents<N - 1>(*j)) return false;
    }
    return true;
}

template <typename T, typename Vec>
void matrix_impl::add_list(const std::initializer_list<T>* first, const std::initializer_list<T>* last, Vec& vec) {
    for (; first != last; ++first) {
        add_list(first->begin(), first->end(), vec);
    }
}

template <typename T, typename Vec>
void matrix_impl::add_list(const T* first, const T* last, Vec& vec) {
    vec.insert(vec.end(), first, last);
}

//

//

//

// definition for matrix slice member goes here

//

//

//

// definition for matrix ref member goes here

//

//

//

// definition for main matrix member goes here

template <typename T, size_t N>
template <typename U>
matrix<T, N>::matrix(const matrix_ref<U, N>& x) : desc(x.desc), elems{x.begin(), x.end()} {
    static_assert(Convertible<U, T>(), "Matrix constructor : incompatible elements type");
}

template <typename T, size_t N>
template <typename U>
matrix<T, N>& matrix<T, N>::operator=(const matrix_ref<U, N>& x) {
    static_assert(Convertible<U, T>(), "Matrix : incompatible elements type");
    desc = x.desc;
    elems.assign(x.begin(), x.end());
    return *this;
}

// TODO :
template <typename T, size_t N>
matrix<T, N>::matrix(matrix_initializer<T, N>) {}
template <typename T, size_t N>
matrix<T, N>& matrix<T, N>::operator=(matrix_initializer<T, N>) {}