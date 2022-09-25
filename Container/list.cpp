#include <utility>

namespace gh {
    template <class T>
    class list {
       private:
        struct node {
            node(const T& data = T{}, node* prev = nullptr, node* next = nullptr)
                : m_data{data}, m_prev{prev}, m_next{next} {}

            node(T&& data = T{}, node* prev = nullptr, node* next = nullptr)
                : m_data{std::move(data)}, m_prev{prev}, m_next{next} {}

            T m_data;
            node* m_prev;
            node* m_next;
        };

       public:
        class const_iterator {
           public:
            constexpr const_iterator() : m_curr{nullptr} {}

            constexpr const T& operator*() const { return retrieve(); }

            constexpr const_iterator& operator++() {
                m_curr = m_curr->next;
                return *this;
            }

            constexpr const_iterator operator++(int) {
                auto old = *this;
                ++(*this);
                return old;
            }

            constexpr bool operator==(const_iterator& rhs) const { return (m_curr == rhs.m_curr); }

            constexpr bool operator!=(const_iterator& rhs) const { return !(*this == rhs); }

           protected:
            node* m_curr;
            constexpr T& retrieve() const { return (m_curr->m_data); }
            constexpr const_iterator(node* itr) : m_curr{itr} {}

            friend class list<T>;
        };
        class iterator : public const_iterator {
           public:
            iterator() = default;

            constexpr T& operator*() { return const_iterator::retrieve(); }

            constexpr const T& operator*() const { return const_iterator::operator*(); }

            constexpr iterator& operator++() {
                this->m_curr = this->m_curr->next;
                return *this;
            }

            constexpr iterator operator++(int) {
                auto old = *this;
                ++(*this);
                return old;
            }

           protected:
            constexpr iterator(node* itr) : const_iterator{itr} {}

            friend class list<T>;
        };

        constexpr list() { init(); }

        list(const list& rhs) {
            init();
            for (auto& e : rhs) push_back(e);
        }

        constexpr list(list&& rhs) : m_size{rhs.m_size}, m_head{rhs.m_head}, m_tail{rhs.m_tail} {}

        constexpr list& operator=(const list& rhs) {
            auto copy = rhs;
            std::swap(*this, copy);
            return *this;
        }

        constexpr list& operator=(list&& rhs) {
            std::swap(m_size, rhs.m_size);
            std::swap(m_head, rhs.m_head);
            std::swap(m_tail, rhs.m_tail);
            return *this;
        }

        virtual ~list() {
            clear();
            delete m_head;
            delete m_tail;
        }

        constexpr iterator begin() { return {m_head->m_next}; }

        constexpr iterator end() { return {m_tail}; }

        constexpr const_iterator begin() const { return {m_head->m_next}; }

        constexpr const_iterator end() const { return {m_tail}; }

        constexpr int size() const { return m_size; }

        constexpr bool empty() const { return (m_size == 0); }

        constexpr void clear() {
            while (!empty()) pop_front();
        }

        constexpr T& front() { return *begin(); }

        constexpr const T& front() const { return *begin(); }

        constexpr T& back() { return *--end(); }

        constexpr const T& back() const { *--end(); }

        constexpr void push_front(const T& val) { insert(begin(), val); }

        constexpr void push_front(T&& val) { insert(begin(), std::move(val)); }

        constexpr void push_back(const T& val) { insert(end(), val); }

        constexpr void push_back(T&& val) { insert(end(), std::move(val)); }

        constexpr void pop_front() { erase(begin()); }

        constexpr void pop_back() { erase(--end()); }

        constexpr iterator insert(iterator itr, const T& val) {
            auto curr = itr.m_curr;
            ++m_size;
            return {curr->m_prev = curr->m_prev->m_next = new node{val, curr->m_prev, curr}};
        }

        constexpr iterator insert(iterator itr, T&& val) {
            auto curr = itr.m_curr;
            ++m_size;
            return {curr->m_prev = curr->m_prev->m_next =
                        new node{std::move(val), curr->m_prev, curr}};
        }

        constexpr iterator erase(iterator itr) {
            // TODO:
        }

        constexpr iterator erase(iterator from, iterator to) {
            // TODO:
        }

       private:
        int m_size;
        node* m_head;
        node* m_tail;
        constexpr void init() {
            m_size = 0;
            m_head = new node{};
            m_tail = new node{};
            m_head->next = m_tail;
            m_tail->prev = m_head;
        }
    };
}

int main() { return 0; }
