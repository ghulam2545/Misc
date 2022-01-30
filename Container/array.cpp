#include <cstddef>
#include <initializer_list>
#include <iostream>
#include <iterator>

namespace Container {
    template <class _T, std::size_t _S>
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

            // issue with const
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

        // ambigious behaviour
        // using Reverse_Iterator = std::reverse_iterator<Iterator>;
        // using Const_Reverse_Iterator = std::reverse_iterator<Const_Iterator>;

        Array() : _size(_S) { _data = new _T[_size]; }
        Array(const std::initializer_list<_T>& _init) {
            _size = _init.size();
            _data = new _T[_size];
            auto _index = 0;
            for (auto _i = _init.begin(); _i != _init.end(); ++_i) {
                _data[_index] = *_i;
                ++_index;
            }
        }

        // Public member goes here,
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

        constexpr reference back() { return _data[_size - 1]; }
        constexpr const_reference back() const { return _data[_size - 1]; };
        constexpr reference front() { return _data[0]; }
        constexpr const_reference front() const { return _data[0]; };

        constexpr bool empty() { return _size == 0; }
        constexpr bool empty() const { return _size == 0; }
        constexpr std::size_t const size() { return _size; }

       private:
        _T* _data;
        std::size_t _size;
    };
}  // namespace Container

using std::cout;

int main() {
    Container::Array<int, 4> bb{1, 2, 3, 4};
    // bb[0] = 10;
    // bb[1] = 20;
    // bb[2] = 30;
    // bb[3] = 40;
    for (auto e : bb) {
        std::cout << e << " ";
    }
    cout << "\n";
    std::cout << bb.back() << "\n";

    Container::Array<std::string, 6> aa{"ab", "cd", "ef", "gh", "ij", "kl"};
    cout << aa.size();

    Container::Array<std::string, 6>::Const_Iterator it;
    // for (it = aa.begin(); it != aa.end(); ++it) {
    //     cout << *it << " ";
    // }

    // std::cout << bb[0] << "\n";
    return 0;
}

//  -------------------------

/*  public members :

   [✓]    at()
   [✓]    operator[]
   [✓]    back()
   [✓]    begin()
   [✓]    cbegin()
   [✓]    empty()
   [✓]    front()
   [✓]    end()
   [✓]    cend()
   [✓]  size()
   []    crbegin()
   []    rend()
   []    crend()
   []    rbegin()
   []    data()
*/