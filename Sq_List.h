#ifndef _SQ_LIST_1_0_H_
#define _SQ_LIST_1_0_H_

#include <functional>

typedef int Status;

template <typename T>
class SqList
{
    public:
        SqList(int n) : list(new int[n]), size(0), capacity(n) {};
        ~SqList() {};

        Status IsEmpty() { return 0 == size; };

        T get(int index) 
        {
            if (index >= size || index < 0) exit(1);
            return list[index ];
        }

        bool set(int index, T data)
        {
            if (index >= size || index < 0) exit(1);
            list[index] = data;
            return true;
        }

        void insert(int index, T data) 
        {
            if (size >= capacity || index >= size || index < 0) exit(1);
            for (int i = size; i > index ; i--) list[i] = list[i - 1];
            list[index] = data;
            size++;
        }

        T remove(int index)
        {
            if (index >= size || index < 0 || IsEmpty()) exit(1);

            int tmp = list[index]
            for (int i = index; i < size; index++) list[index] = list[index + 1];
            size--;
            return tmp;
        }

        int removeAll(T data)
        {
            int count = 0;
            for (int i = 0; i < size; i++) {
                if (data == list[i]) {
                    count++;
                    remove(i);
                }
            }

            return count;
        }

        int contains(T data)
        {
            int count = 0;
            for (int i = 0; i < size; i++) {
                if (data == list[i]) count++;
            }
            return count;
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
