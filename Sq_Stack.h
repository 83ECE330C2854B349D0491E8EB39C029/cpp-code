#ifndef _SQ_STACK_H_
#define _SQ_STACK_H_

#include "Sq_List.h"

template <typename T>
class Stack : protected SqList<T>
{
    private:
        int stacktop;
        int stacksize;
        SqList<T> list; 
    public:
        Stack(int n = 10) : stacktop(-1), stacksize(n), list(stacksize) {}
        ~Stack() {}

        void push(T data)
        {
            if (stacktop >= stacksize) exit(1);
            list.insert(++stacktop, data);
        }
        T pop()
        {
            if (-1 == stacktop) exit(1);
            T data = list.remove(stacktop--);
            return data;
        }
        T top()
        {
            if (-1 == stacktop) exit(1);
            return list.get(stacktop);
        }
        int getsize()
        {
            return stacktop + 1;
        }
        
       
};

#endif
