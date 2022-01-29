#include <cstddef>
#include <initializer_list>
#include <iostream>
#include <iterator>

namespace container {
    template <class _T, std::size_t _S>
    class array {
       public:
        class iterator {
           public:
            using iterator_category = std::random_access_iterator_tag;
            using diffrence_type = std::ptrdiff_t;
            using size_type = std::size_t;
            using value_type = _T;
            using pointer = _T*;
            using reference = _T&;

            iterator(pointer ptr = nullptr) : m_ptr(ptr) {}
            constexpr reference operator*() { return *m_ptr; }
            constexpr pointer operator->() { return m_ptr; }

            // ...
            constexpr iterator& operator++() {
                ++m_ptr;
                return *this;
            }
            constexpr iterator& operator++(int) {
                auto _temp = *this;
                m_ptr++;
                return _temp;
            }
            constexpr iterator& operator--() {
                --m_ptr;
                return *this;
            }
            constexpr iterator& operator--(int) {
                auto _temp = *this;
                m_ptr--;
                return _temp;
            }
            constexpr bool operator<(const iterator& _other) { return this->m_ptr < _other.m_ptr; }
            constexpr bool operator<=(const iterator& _other) { return this->m_ptr <= _other.m_ptr; }
            constexpr bool operator>(const iterator& _other) { return this->m_ptr > _other.m_ptr; }
            constexpr bool operator>=(const iterator& _other) { return this->m_ptr >= _other.m_ptr; }
            constexpr bool operator==(const iterator& _other) { return this->m_ptr == _other.m_ptr; }
            constexpr bool operator!=(const iterator& _other) { return this->m_ptr != _other.m_ptr; }

           private:
            pointer m_ptr;
        };

        class const_iterator {
           public:
            using iterator_category = std::random_access_iterator_tag;
            using diffrence_type = std::ptrdiff_t;
            using size_type = std::size_t;
            using value_type = const _T;
            using pointer = const _T*;
            using reference = const _T&;

            const_iterator(pointer ptr = nullptr) : m_ptr(ptr) {}
            constexpr reference operator*() const { return *m_ptr; }
            constexpr pointer operator->() const { return m_ptr; }

            // ...
            constexpr const_iterator& operator++() const {
                ++m_ptr;
                return *this;
            }
            constexpr const_iterator& operator++(int) const {
                auto _temp = *this;
                m_ptr++;
                return _temp;
            }
            constexpr const_iterator& operator--() const {
                --m_ptr;
                return *this;
            }
            constexpr const_iterator& operator--(int) const {
                auto _temp = *this;
                m_ptr--;
                return _temp;
            }
            constexpr bool operator<(const const_iterator& _other) const { return this->m_ptr < _other.m_ptr; }
            constexpr bool operator<=(const const_iterator& _other) const { return this->m_ptr <= _other.m_ptr; }
            constexpr bool operator>(const const_iterator& _other) const { return this->m_ptr > _other.m_ptr; }
            constexpr bool operator>=(const const_iterator& _other) const { return this->m_ptr >= _other.m_ptr; }
            constexpr bool operator==(const const_iterator& _other) const { return this->m_ptr == _other.m_ptr; }
            constexpr bool operator!=(const const_iterator& _other) const { return this->m_ptr != _other.m_ptr; }

           private:
            pointer m_ptr;
        };
        using iterator_category = std::random_access_iterator_tag;
        using diffrence_type = std::ptrdiff_t;
        using size_type = std::size_t;
        using value_type = _T;
        using pointer = _T*;
        using const_pointer = const _T*;
        using reference = _T&;
        using const_reference = const _T&;

        // using reverse_iterator = ;
        // using const_reverse_iterator = ;

        // public member
        constexpr iterator begin() { return iterator(_data); }
        constexpr const_iterator begin() const { return begin(); }
        constexpr const_iterator cbegin() const { return begin(); }

        constexpr iterator end() { return iterator(_data + _size); }
        constexpr const_iterator end() const { return end(); }
        constexpr const_iterator cend() const { return end(); }

        //   constexpr reference at(size_type _pos) { return (*this)[_pos]; }
        //   constexpr const_reference at(size_type _pos) const { return (*this)[_pos]; }
        //   constexpr reference operator[](size_type _pos) { return (*this)[_pos]; }
        //   constexpr const_reference operator[](size_type _pos) const { return (*this)[_pos]; }

        array() : _size(_S) { _data = new _T[_size]; }

       private:
        _T* _data;
        std::size_t _size;
    };
}  // namespace container

int main() {
    container::array<int, 5> aa = {1, 2, 3, 4, 5};  // ask for initializer list
    container::array<double, 10> bb;

    container::array<double, 10>::iterator it;
    bb.begin();
    bb.end();

    return 0;
}

//  -------------------------

/*  public members :

   []    assign
   []    at()
   []    operator[]
   []    back()
   [✓]    begin()
   []    rbegin()
   [✓]    cbegin()
   []    crbegin()
   [✓]    end()
   []    rend()
   [✓]    cend()
   []    crend()
   []    data()
   []    empty()
   []    front()
   []    fill()
   []  size()
   []    swap()

*/