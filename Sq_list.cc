#include <iostream>

typedef int Status;

class Sqlist
{
    public:
        Sqlist(int n) : capacity(n), size(0), list(new int[n]){};
        ~Sqlist(){};
        Status insert(int e)
        {
            if (this -> size >= this -> capacity) 
                return false;

            for (int j = size -1; j >= 0; j--) 
                this -> list[j + 1] = this -> list[j];
            
            this -> list[0] = e;
            size++;
            return true;
        }

        void traversal() 
        {
            for (int i = 0; i < this->size; ++i)
                std::cout << this -> list[i] << std::endl;
        }
    
    private:
        int *list;
        int size;
        int capacity;
};

int main()
{
    Sqlist L(20);

    for (int i = 1; i < 11; i++)
        L.insert(i);

    L.traversal();
    return 0;
}
