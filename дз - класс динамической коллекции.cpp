#include <iostream>
#include <new>
#include <algorithm>


// размещение в себе элементов произвольного типа;
// добавление и удаление элементов;
// предоставление доступа к элементам массива;
// возможность работы с колеекцией через range based for, sdt::size;
// корректная передача по параметру в функции.


template<class Type>
class DynamicArray
{
public:
    
    // создание массива 
    DynamicArray():size_(1)
    {
        capacity_ = size_;
        data_ = new Type[size_]{};
        
    }

    // копирование массива
    DynamicArray(const DynamicArray &a)
    {
        this->size_ = a.size_;
        this->data_ = new Type[size_];

        ::memcpy(a.data_, this->data_, size_);
    }

    // изменить размер массива
    void resize(int size)
    {
        if (size > capacity_)
        {
            int new_capacity = std::max(size, size_ * 2);
            Type* new_data = new Type[new_capacity];
            for (int i = 0; i < size_; ++i) {
                new_data[i] = data_[i];
            }
            delete[] data_;
            data_ = new_data;
            capacity_ = new_capacity;
        }
        size_ = size;
    }

    //узнать размер массива
    int size() const
    {
        return size_;
    }

    // добавить элемент
    void push_back(Type val)
    {
        if (data_[0] == 0)
        {
            data_[0] = val;
        }
        else {
            resize(size_ + 1);
            data_[size_ - 1] = val;
        }

    }

    // удалить последний элемент
    void pop_back()
    {
        if (data_)
        {
            Type* tmp = new Type[size_ - 1]{};
            for (int i = 0; i < size_-1; i++)
            {
                tmp[i] = data_[i];
            } 
            size_--;
            capacity_--;
            std::swap(data_,tmp);
            delete[] tmp;
        }
    }

    // вывести
    void print()
    {
        for (int i = 0; i < size_; i++)
        {
            std::cout << data_[i];
        }
    }

    Type& operator[](int i) {
        return data_[i];
    }

    int* begin()
    {
        return *data_[0];
    }

    int* end()
    {
        return *data_[size_];
    }

    ~DynamicArray()
    {
        if (data_)
        {
            delete[]data_;
        }
    }

private:

    int size_;
    int capacity_;
    Type *data_;

};

int main()
{
    
    DynamicArray <int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(4);
    a.push_back(5);
    a.push_back(6);
    a.pop_back();
    a[2] = 0;
    a.print();

    return 0;
     
}

void M00(DynamicArray<int> obj)
{
    obj.print();
}

void M00(DynamicArray<std::string> obj)
{
    obj.print();
}