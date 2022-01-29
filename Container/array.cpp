#include <iostream>
#include <iterator>

namespace Container {
    template <class _T, size_t _S>
    class Array {
       public:
        class Iterator {
           public:
            using iterator_category = std::random_access_iterator_tag;
            using diffrence_type = std::ptrdiff_t;
            using size_type = size_t;
            using value_type = _T;
            using pointer = _T*;
            using reference = _T&;

            Iterator(pointer ptr = nullptr) : m_ptr(ptr) {}
            constexpr reference operator*() { return *m_ptr; }
            constexpr pointer operator->() { return m_ptr; }

            // ...
            constexpr Iterator& operator++() {
                ++m_ptr;
                return *this;
            }
            constexpr Iterator& operator++(int) {
                auto _temp = *this;
                m_ptr++;
                return _temp;
            }
            constexpr Iterator& operator--() {
                --m_ptr;
                return *this;
            }
            constexpr Iterator& operator--(int) {
                auto _temp = *this;
                m_ptr--;
                return _temp;
            }
            constexpr bool operator<(const Iterator& _other) { return this->m_ptr < _other.m_ptr; }
            constexpr bool operator<=(const Iterator& _other) { return this->m_ptr <= _other.m_ptr; }
            constexpr bool operator>(const Iterator& _other) { return this->m_ptr > _other.m_ptr; }
            constexpr bool operator>=(const Iterator& _other) { return this->m_ptr >= _other.m_ptr; }
            constexpr bool operator==(const Iterator& _other) { return this->m_ptr == _other.m_ptr; }
            constexpr bool operator!=(const Iterator& _other) { return this->m_ptr != _other.m_ptr; }

           private:
            pointer m_ptr;
        };

        class Const_Iterator {
           public:
            using iterator_category = std::random_access_iterator_tag;
            using diffrence_type = std::ptrdiff_t;
            using size_type = size_t;
            using value_type = const _T;
            using pointer = const _T*;
            using reference = const _T&;

            Const_Iterator(pointer ptr = nullptr) : m_ptr(ptr) {}
            constexpr reference operator*() const { return *m_ptr; }
            constexpr pointer operator->() const { return m_ptr; }

            // ...
            constexpr Const_Iterator& operator++() const {
                ++m_ptr;
                return *this;
            }
            constexpr Const_Iterator& operator++(int) const {
                auto _temp = *this;
                m_ptr++;
                return _temp;
            }
            constexpr Const_Iterator& operator--() const {
                --m_ptr;
                return *this;
            }
            constexpr Const_Iterator& operator--(int) const {
                auto _temp = *this;
                m_ptr--;
                return _temp;
            }
            constexpr bool operator<(const Const_Iterator& _other) const { return this->m_ptr < _other.m_ptr; }
            constexpr bool operator<=(const Const_Iterator& _other) const { return this->m_ptr <= _other.m_ptr; }
            constexpr bool operator>(const Const_Iterator& _other) const { return this->m_ptr > _other.m_ptr; }
            constexpr bool operator>=(const Const_Iterator& _other) const { return this->m_ptr >= _other.m_ptr; }
            constexpr bool operator==(const Const_Iterator& _other) const { return this->m_ptr == _other.m_ptr; }
            constexpr bool operator!=(const Const_Iterator& _other) const { return this->m_ptr != _other.m_ptr; }

           private:
            pointer m_ptr;
        };
        using iterator_category = std::random_access_iterator_tag;
        using diffrence_type = std::ptrdiff_t;
        using size_type = size_t;
        using value_type = _T;
        using pointer = _T*;
        using const_pointer = const _T*;
        using reference = _T&;
        using const_reference = const _T&;

        // using reverse_Iterator = ;
        // using const_reverse_Iterator = ;

        // public member
        constexpr Iterator begin() { return Iterator(_data); }
        constexpr Const_Iterator begin() const { return begin(); }
        constexpr Const_Iterator cbegin() const { return begin(); }

        constexpr Iterator end() { return Iterator(_data + _size); }
        constexpr Const_Iterator end() const { return end(); }
        constexpr Const_Iterator cend() const { return end(); }

        constexpr reference at(size_type _pos) { return _data[_pos]; }
        constexpr const_reference at(size_type _pos) const { return _data[_pos]; }
        constexpr reference operator[](size_type _pos) { return _data[_pos]; }
        constexpr const_reference operator[](size_type _pos) const { return _data[_pos]; }

        Array() : _size(_S) { _data = new _T[_size]; }

       private:
        _T* _data;
        size_t _size;
    };
}  // namespace Container

int main() {
    Container::Array<int, 4> bb;
    bb[0] = 10;
    bb[1] = 20;
    bb[2] = 30;
    bb[3] = 40;
    for (auto e : bb) {
        std::cout << e << " ";
    }

    // std::cout << bb[0] << "\n";
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