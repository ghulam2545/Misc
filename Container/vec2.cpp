#include <iostream>
#include <utility>

namespace gh {
    template <class T>
    class vector {
       public:
        vector(int size = 0);
        vector(const vector& rhs);
        vector(vector&& rhs);
        vector& operator=(const vector& rhs);
        vector& operator=(vector&& rhs);
        virtual ~vector();

        constexpr void resize(const int& new_size);
        constexpr void reserve(const int& new_cap);
        constexpr T& operator[](const int& idx);
        constexpr T& operator[](const int& idx) const;
        constexpr bool empty() const;
        constexpr int size() const;
        constexpr int capacity() const;

        constexpr void push_back(const T& val);
        constexpr void push_back(T&& val);
        constexpr void pop_back();
        constexpr const T& back() const;
        constexpr const T& front() const;

        using iterator = T*;
        using const_iterator = const T*;

        constexpr iterator begin() { return &m_data[0]; }
        constexpr const_iterator begin() const { return &m_data[0]; }
        constexpr iterator end() { return &m_data[size()]; }
        constexpr const_iterator end() const { return &m_data[size()]; }

       private:
        int m_size;
        int m_cap;
        T* m_data;
    };
}

int main() {
    gh::vector<int> arr;
    arr.push_back(0);
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);

    for (auto& e : arr) std::cout << e << ' ';

    std::cout << '\n';
    std::cout << arr.front() << ' ' << arr.back();
    std::cout << "\n";
    std::cout << arr.size() << ' ' << arr.capacity();

    return 0;
}

namespace gh {
    template <class T>
    vector<T>::vector(int size) : m_size{size}, m_cap{size} {
        m_data = new T[m_size];
    }

    template <class T>
    vector<T>::vector(const vector& rhs) : m_size{rhs.m_size}, m_cap{rhs.m_cap}, m_data{nullptr} {
        m_data = new T[m_cap];
        for (int i = 0; i < m_size; ++i) {
            m_data[i] = rhs.m_data[i];
        }
    }

    template <class T>
    vector<T>::vector(vector&& rhs) : m_size{rhs.m_size}, m_cap{rhs.m_cap}, m_data{rhs.m_data} {
        m_data = nullptr;
        m_size = 0;
        m_cap = 0;
    }

    template <class T>
    vector<T>& vector<T>::operator=(const vector& rhs) {
        auto copy = rhs;
        std::swap(*this, rhs);
        return *this;
    }

    template <class T>
    vector<T>& vector<T>::operator=(vector&& rhs) {
        std::swap(m_size, rhs.m_size);
        std::swap(m_cap, rhs.m_cap);
        std::swap(m_data, rhs.m_data);
        return *this;
    }

    template <class T>
    vector<T>::~vector() {
        delete[] m_data;
    }

    template <class T>
    constexpr void vector<T>::resize(const int& new_size) {
        if (new_size > m_cap) reserve(new_size * 2);
        m_size = new_size;
    }

    template <class T>
    constexpr void vector<T>::reserve(const int& new_cap) {
        if (new_cap < m_size) return;

        auto new_data = new T[new_cap];
        for (int i = 0; i < m_size; ++i) new_data[i] = std::move(m_data[i]);
        m_cap = new_cap;
        std::swap(m_data, new_data);
        delete[] new_data;
    }

    template <class T>
    constexpr T& vector<T>::operator[](const int& idx) {
        return m_data[idx];
    }

    template <class T>
    constexpr T& vector<T>::operator[](const int& idx) const {
        return m_data[idx];
    }

    template <class T>
    constexpr bool vector<T>::empty() const {
        return m_size == 0;
    }

    template <class T>
    constexpr int vector<T>::size() const {
        return m_size;
    }

    template <class T>
    constexpr int vector<T>::capacity() const {
        return m_cap;
    }

    template <class T>
    constexpr void vector<T>::push_back(const T& val) {
        if (m_size == m_cap) reserve(2 * m_cap + 1);
        m_data[m_size++] = val;
    }

    template <class T>
    constexpr void vector<T>::push_back(T&& val) {
        if (m_size == m_cap) reserve(2 * m_cap + 1);
        m_data[m_size++] = std::move(val);
    }

    template <class T>
    constexpr void vector<T>::pop_back() {
        --m_size;
    }

    template <class T>
    constexpr const T& vector<T>::back() const {
        if (m_size == 0) throw;
        return m_data[m_size - 1];
    }

    template <class T>
    constexpr const T& vector<T>::front() const {
        if (m_size == 0) throw;
        return m_data[0];
    }
}