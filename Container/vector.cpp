#include <cstddef>           // std::ptrdiff_t
#include <initializer_list>  // std::initializer_list
#include <iostream>          // I/O
#include <iterator>          // std::random_access_iterator_tag
#include <iterator>          // std::reverse_iterator
#include <vector>            // for sample use

namespace ghulam {

    template <class __T>
    class vector {
       public:
        /* Forward declaration for different iterator class */
        class iterator;
        class const_iterator;
        // class reverse_iterator;
        // class const_reverse_iterator;

        using reference = __T&;
        using const_reference = const __T&;
        using pointer = __T*;
        using const_pointer = const __T*;

        using reverse_iterator = typename std::reverse_iterator<iterator>;
        using const_reverse_iterator = typename std::reverse_iterator<const_iterator>;

        /* construction process */
        constexpr vector() : __size(0), __capacity(0){};                                // defautl constructor
        constexpr vector(const vector& __other) { std::cout << "copy constructor\n"; }  // copy constructor
        constexpr vector(vector&& __other) { std::cout << "move constructor\n"; }       // move constructor
        constexpr vector(const __T& __sz, const __T& __value = 0) {
            __capacity = __sz;
            __size = __sz;
            __data = new __T[__sz];
            for (size_t __i = 0; __i < __size; ++__i) {
                __data[__i] = __value;
            }
        }

        constexpr vector& operator=(const vector& __other) { std::cout << "copy assignment\n"; }  // copy assignment
        constexpr vector& operator=(vector&& __other) { std::cout << "move assignment\n"; }       // move assignment
        constexpr vector(const std::initializer_list<__T>& __init) {
            __size = __init.size();
            __capacity = __size;
            __data = new __T[__size];
            int __index = 0;
            for (auto __i = __init.begin(); __i != __init.end(); ++__i) {
                __data[__index] = *__i;
                ++__index;
            }
        }

        /* Public family member goes here */

        /**
         * @brief Returns the number of elements in the container
         * @param  (none)
         * @return the number of elements in the container
         */
        constexpr size_t size() const { return __size; }

        /**
         * @brief Returns the number of elements that the container has currently allocated space for.
         * @param (none)
         * @return Capacity of the currently allocated storage.
         */
        constexpr size_t capacity() const { return __capacity; }

        /**
         * @brief Checks if the container has no elements
         * @param (none)
         * @return true if the container is empty, false otherwise
         */
        constexpr bool empty() const { return __size == 0; }

        /**
         * @brief Returns a reference to the element at specified location pos
         * @param pos position of the element to return
         * @return Reference to the requested element.
         */
        constexpr reference operator[](size_t __pos) { return __data[__pos]; }
        constexpr const_reference operator[](size_t __pos) const { return __data[__pos]; }

        /**
         * @brief Returns a reference to the element at specified location pos, with bounds checking.
         * @param pos 	position of the element to return
         * @return Reference to the requested element.
         */
        constexpr reference at(size_t __pos) { return __data[__pos]; }
        constexpr const_reference at(size_t __pos) const { return __data[__pos]; }

        /**
         * @brief Returns pointer to the underlying array serving as element storage.
         * @param (none)
         * @return Pointer to the underlying element storage. For non-empty containers, the returned pointer compares equal to the address of the first element.
         */
        constexpr pointer data() { return &__data[0]; }        // I'm not sure what exactly it does
        constexpr pointer data() const { return &__data[0]; }  // I'm not sure what exactly it does

        /**
         * @brief Returns a reference to the last element in the container.
         * @param (none)
         * @return Reference to the last element.
         */
        constexpr reference back() { return __data[__size - 1]; }
        constexpr reference back() const { return __data[__size - 1]; }

        /**
         * @brief Returns a reference to the first element in the container.
         * @param (none)
         * @return reference to the first element
         */
        constexpr reference front() { return __data[0]; }
        constexpr reference front() const { return __data[0]; }

        /*
        begin | cbegin | end | cend | rbegin | crbegin | rend | crend
        */
        constexpr iterator begin() { return iterator(__data); }
        constexpr const_iterator cbegin() const { return const_iterator(__data); }
        constexpr iterator end() { return iterator(__data + __size); }
        constexpr const_iterator cend() const { return const_iterator(__data + __size); }

        /* insertion process */
        constexpr void push_back(const __T& __value) {}  // TODO :
        constexpr void push_back(__T&& __value) {}       // TODO :
        void doubleCapacity() {
            __T* new__data;
            if (__size == 0) {
                new__data = new __T[1];
            } else {
                __capacity = __capacity * 2;
                new__data = new __T[__capacity];
                // move data from old one to new and release old one (...)
                for (size_t __i = 0; __i < __size; ++__i) {
                    new__data[__i] = std::move(__data[__i]);
                }
            }
            __data = new__data;
        }

       private:
        __T* __data;
        size_t __size;
        size_t __capacity;
    };

}  // namespace ghulam

namespace ghulam {

    template <class __T>
    class vector<__T>::iterator {
       public:
        using iterator_category = std::random_access_iterator_tag;
        using difference_type = std::ptrdiff_t;
        using value_type = __T;
        using reference = __T&;
        using pointer = __T*;

        constexpr iterator(__T* __ptr = nullptr) : current(__ptr) {}
        /*
        constexpr iterator(const iterator&) {}
        constexpr iterator(iterator&&) {}
        constexpr iterator& operator=(const iterator&) {}
        constexpr iterator& operator=(iterator&&) {}
        */
        ~iterator() {}

        constexpr reference operator*() const { return *current; }
        constexpr pointer operator->() const { return current; }
        constexpr reference operator[](size_t __index) const { return __data[__index]; }

        /* Operator family */
        constexpr iterator& operator++() {
            ++current;
            return *this;
        }
        constexpr iterator& operator++(int) {
            auto __temp = *this;
            ++current;
            return __temp;
        }
        constexpr iterator& operator--() {
            --current;
            return *this;
        }
        constexpr iterator& operator--(int) {
            auto __temp = *this;
            --current;
            return __temp;
        }
        constexpr iterator& operator+=(size_t __value) {
            current = this->current + __value;
            return *this;
        }
        constexpr iterator& operator-=(size_t __value) {
            current = this->current - __value;
            return *this;
        }
        constexpr iterator operator+(size_t __value) { return this->current + __value; }
        constexpr iterator operator-(size_t __value) { return this->current - __value; }

        /**
         * @brief Checks if the contents of lhs and rhs are equal OR Compares the contents of lhs and rhs lexicographically
         * @param lhs first vectors whose contents to compare
         * @param rhs second vectors whose contents to compare
         * @return returns the same as what you expect
         */
        constexpr const friend bool operator<(const iterator& __lhs, const iterator& __rhs) { return __lhs.current < __rhs.current; }
        constexpr const friend bool operator<=(const iterator& __lhs, const iterator& __rhs) { return __lhs.current <= __rhs.current; }
        constexpr const friend bool operator>(const iterator& __lhs, const iterator& __rhs) { return __lhs.current > __rhs.current; }
        constexpr const friend bool operator>=(const iterator& __lhs, const iterator& __rhs) { return __lhs.current >= __rhs.current; }
        constexpr const friend bool operator==(const iterator& __lhs, const iterator& __rhs) { return __lhs.current == __rhs.current; }
        constexpr const friend bool operator!=(const iterator& __lhs, const iterator& __rhs) { return __lhs.current != __rhs.current; }

       private:
        __T* current;
    };

}  // namespace ghulam

namespace ghulam {

    template <class __T>
    class vector<__T>::const_iterator {
       public:
        using iterator_category = std::random_access_iterator_tag;
        using difference_type = std::ptrdiff_t;
        using value_type = const __T;
        using reference = const __T&;
        using pointer = const __T*;

        constexpr const_iterator(__T* __ptr = nullptr) : current(__ptr) {}
        /*
        constexpr const_iterator(const const_iterator&) {}
        constexpr const_iterator(const_iterator&&) {}
        constexpr const_iterator& operator=(const const_iterator&) {}
        constexpr const_iterator& operator=(const_iterator&&) {}
        */
        ~const_iterator() {}

        constexpr reference operator*() const { return *current; }
        constexpr pointer operator->() const { return current; }
        constexpr reference operator[](size_t __index) const { return __data[__index]; }

        /* Operator family */
        constexpr const_iterator& operator++() {
            ++current;
            return *this;
        }
        constexpr const_iterator& operator++(int) {
            auto __temp = *this;
            ++current;
            return __temp;
        }
        constexpr const_iterator& operator--() {
            --current;
            return *this;
        }
        constexpr const_iterator& operator--(int) {
            auto __temp = *this;
            --current;
            return __temp;
        }
        constexpr const_iterator& operator+=(size_t __value) {
            current = this->current + __value;
            return *this;
        }
        constexpr const_iterator& operator-=(size_t __value) {
            current = this->current - __value;
            return *this;
        }
        constexpr const_iterator operator+(size_t __value) { return this->current + __value; }
        constexpr const_iterator operator-(size_t __value) { return this->current - __value; }

        /**
         * @brief Checks if the contents of lhs and rhs are equal OR Compares the contents of lhs and rhs lexicographically
         * @param lhs first vectors whose contents to compare
         * @param rhs second vectors whose contents to compare
         * @return returns the same as what you expect
         */
        constexpr const friend bool operator<(const const_iterator& __lhs, const const_iterator& __rhs) { return __lhs.current < __rhs.current; }
        constexpr const friend bool operator<=(const const_iterator& __lhs, const const_iterator& __rhs) { return __lhs.current <= __rhs.current; }
        constexpr const friend bool operator>(const const_iterator& __lhs, const const_iterator& __rhs) { return __lhs.current > __rhs.current; }
        constexpr const friend bool operator>=(const const_iterator& __lhs, const const_iterator& __rhs) { return __lhs.current >= __rhs.current; }
        constexpr const friend bool operator==(const const_iterator& __lhs, const const_iterator& __rhs) { return __lhs.current == __rhs.current; }
        constexpr const friend bool operator!=(const const_iterator& __lhs, const const_iterator& __rhs) { return __lhs.current != __rhs.current; }

       private:
        __T* current;
    };

}  // namespace ghulam

using std::cout;
int main() {
    ghulam::vector<int> arr = {1, 2, 3, 4, 5};
    cout << "size : " << arr.size() << "  capacity : " << arr.capacity() << "\n";
    for (auto& e : arr) {
        cout << e << " ";
    }
    cout << "\n";

    return 0;
}