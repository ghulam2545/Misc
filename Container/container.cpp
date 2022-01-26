#include <iostream>
#include <iterator>

namespace container {
    template <class T>
    class DLL {
       public:
        struct iterator {
           public:
            using iterator_category = std::random_access_iterator_tag;
            using diffrence_type = std::ptrdiff_t;
            using value_type = T;
            using pointer = T*;
            using const_pointer = const T*;
            using reference = T&;
            using const_reference = const T&;

            iterator(pointer ptr) : m_ptr(ptr) {}

            constexpr reference operator*();
            constexpr reference operator*() const;

            constexpr pointer operator->();
            constexpr pointer operator->() const;

           private:
            pointer m_ptr;
        };

       private:
    };
}  // namespace container

int main() {}
/*
template <class T>
class DLL {
   public:
    DLL() : _size(0) {}

    // do it later
    struct iterator {
       public:
       private:
    };

    constexpr DLL<T>* GetNewNode(const T&);

    // insertion operation
    constexpr DLL<T>* push_back(DLL<T>*, const T&);
    constexpr DLL<T>* push_front(DLL<T>*, const T&);
    // constexpr DLL<T>* insert(DLL<T>*, const T&);

    // deletion operation
    // constexpr DLL<T>* pop_back(DLL<T>* _root);

    // find key

    constexpr const size_t size() { return _size; }

   private:
    T data;
    DLL<T>* prev;
    DLL<T>* next;
    size_t _size;
};

int main() {
    //
    return 0;
}

template <class T>
constexpr DLL<T>* DLL<T>::GetNewNode(const T& _data) {
    DLL<T>* node = new DLL<T>();
    node->data = _data;
    node->prev = nullptr;
    node->next = nullptr;
    return node;
}

template <class T>
constexpr DLL<T>* DLL<T>::push_back(DLL<T>* _root, const T& _data) {
    if (_root == nullptr) {
        _root = GetNewNode(_data);
        return _root;
    }
    DLL<T>* _new = GetNewNode(_data);
    DLL<T>* last = _root;
    while (last->next != nullptr) {
        last = last->next;
    }
    last->next = _new;
    _new->prev = last;
    return _root;
}

template <class T>
constexpr DLL<T>* DLL<T>::push_front(DLL<T>* _root, const T& _data) {
    if (_root == nullptr) {
        _root = GetNewNode(_data);
        return _root;
    }
    DLL<T>* _new = GetNewNode(_data);
    _new->next = _root;
    _new->prev = nullptr;
    _root->prev = _new;
    _root = _new;
    return _root;
}
*/