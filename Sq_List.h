#ifndef _SQ_LIST_0_2_H_
#define _SQ_LIST_0_2_H_

#include <functional>

typedef int Status;

template <typename T>
class SqList
{
    public:
        SqList(int n) : list(new int[n]), size(0), capacity(n) {};
        ~SqList(){};

        Status insert(T e)
        {
            if (size < capacity) {
                list[size++] = e;
                return true;
            }
            return false;
        }

        void traversal(const std::function<void(const T &)> &visit) 
        {
            for (int i = 0; i < size; i++) visit(*list + i);
        }
    class iterator 
    {
        public:
            explicit iterator(T *node) : node(node) {}
            iterator &operator++() 
            {
                node++;
                return *this;
            }
            iterator operator++(int) 
            {
                iterator retval = *this;
                ++(*this);
                return retval;
            }
            bool operator==(iterator other) const { return node == other.node; }
            bool operator!=(iterator other) const { return !(node == other.node); }
            T operator*() const { return *node; }
        private:
            T *node;
    };

    iterator begin() { return iterator(list); }
    iterator end() { return iterator(list + size); }

    private:    
        T *list;
        int size;
        int capacity;
};

#endif
