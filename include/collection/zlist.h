// 双向链表
// Created by Administrator on 2020/10/29.
//

#ifndef DATASTRUCT_ZLIST_H
#define DATASTRUCT_ZLIST_H

#include <algorithm>

template<typename T>
class zlist
{
private:
    struct Node
    {
        T data;
        Node* prev;
        Node* next;

        explicit Node(const T& d = T{}, Node* p = nullptr, Node* n = nullptr)
            :data{d}, prev{p}, next{n} { }
        explicit Node(const T&& d, Node* p = nullptr, Node* n = nullptr)
            :data{std::move(d)}, prev{p}, next{n} { }
    };

public:
    class const_iterator
    {
    public:
        const_iterator() : current(nullptr) {}
        const T& operator*() const
        {
            return retrieve();
        }
        const_iterator& operator++()
        {
            current = current->next;
            return *this;
        }
        const_iterator operator++(int)
        {
            const_iterator old = *this;
            ++(*this);
            return old;
        }
        const_iterator operator--()
        {
            current = current->prev;
            return *this;
        }
        const_iterator operator--(int)
        {
            const_iterator old = *this;
            --(*this);
            return old;
        }
        bool operator==(const const_iterator& rhs)
        {
            return current == rhs.current;
        }
        bool operator!=(const const_iterator& rhs)
        {
            return !(*this == rhs);
        }

    protected:
        Node* current;
        T& retrieve() const
        {
            return current->data;
        }
        explicit const_iterator(Node* n) : current(n) { }
        friend class zlist<T>;
    };

    class iterator : public const_iterator
    {
        iterator() : const_iterator() {}
        T& operator* ()
        {
            return const_iterator::retrieve();
        }
        const T& operator* () const
        {
            return const_iterator::operator*();
        }
        iterator& operator++ ()
        {
            this->current = this->current->next;
            return *this;
        }
        iterator operator++ (int)
        {
            iterator old = *this;
            ++(*this);
            return old;
        }
        iterator& operator-- ()
        {
            this->current = this->current->prev;
            return *this;
        }
        iterator operator-- (int)
        {
            iterator old = *this;
            --(*this);
            return old;
        }

    protected:
        explicit iterator(Node* p) : const_iterator{p} {}
        friend class zlist<T>;
    };

public:
    zlist()
        :_size{0}
    {
        init();
    }
    zlist(const zlist& rhs)
            :_size{0}
    {
        init();
        for(auto& x : rhs)
        {
            push_back(x);
        }
    }
    zlist& operator= (const zlist rhs)
    {
        std::swap(*this, rhs);
        return *this;
    }
    zlist(zlist&& rhs) noexcept
        :_size{rhs.size}, _head{rhs.head}, _tail{rhs.tail}
    {
        rhs.size = 0;
        rhs.head = nullptr;
        rhs.tail = nullptr;
    }
    zlist& operator= (zlist&& rhs) noexcept
    {
        std::swap(_size, rhs.size);
        std::swap(_head, rhs.head);
        std::swap(_tail, rhs.tail);

        return *this;
    }
    ~zlist()
    {
        clear();
        delete _head;
        delete _tail;
    }

    iterator begin()
    {
        return _head->next;
    }
    const_iterator begin() const
    {
        return _head->next;
    }
    iterator end()
    {
        return _tail;
    }
    const_iterator end() const
    {
        return _tail;
    }

    int size() const
    {
        return _size;
    }
    bool empty() const
    {
        return size() == 0;
    }

    void clear()
    {
        while(!empty())
        {
            pop_front();
        }
    }

    T& front()
    {
        return *begin();
    }
    const T& front() const
    {
        return *begin();
    }
    T& back()
    {
        return *--end();
    }
    const T& back() const
    {
        return *--end();
    }
    void push_front(const T& x)
    {
        insert(begin(), x);
    }
    void push_front(T&& x)
    {
        insert(begin(), std::move(x));
    }
    void push_back(const T& x)
    {
        insert(end(), x);
    }
    void push_back(T&& x)
    {
        insert(end(), x);
    }
    void pop_front()
    {
        erase(begin());
    }
    void pop_back()
    {
        erase(--end());
    }

    iterator insert(iterator it, const T& x)
    {

    }
    iterator insert(iterator it, T&& x)
    {

    }
    iterator erase(iterator it)
    {

    }
    iterator erase(iterator from, iterator to)
    {

    }

private:
    int _size;
    Node* _head;
    Node* _tail;

    void init()
    {
        _head = new Node;
        _tail = new Node;
        _head->next = _tail;
        _tail->next = _head;
    }
};

#endif //DATASTRUCT_ZLIST_H
