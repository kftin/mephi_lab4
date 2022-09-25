#ifndef F_LAB2_DYNAMICARRAY
#define F_LAB2_DYNAMICARRAY

#include <stdexcept>

using namespace std;

template <typename T>
class DynamicArray {
    private:
        int length;
        T *pointer;
        int width;
        int heigth;

    public:
        DynamicArray(T *items, int count, int h, int w);
        DynamicArray(int size);
        DynamicArray(DynamicArray<T> *dynamicArray);

        T Get(int index);
        int GetLength();
        int GetHeigth();
        int GetWidth();

        void Set(int index, T value);
        void Resize(int newSize);

        ~DynamicArray() {
            delete[] pointer;
        }
};

//////////////////////////////////////////////////////////////

template <typename T>
DynamicArray<T>::DynamicArray(T *items, int count, int h, int w) {
    pointer = new T[count];
    width = w;
    heigth = h;
    for (int i = 0; i < count; i++) {
        pointer[i] = items[i];
    }
    length = count;
}

template <typename T>
DynamicArray<T>::DynamicArray(int size) {
    pointer = new T[size];
    length = size;
}

template <typename T>
T DynamicArray<T>::Get(int index) {
    if (index > length || index < 0) {
        throw out_of_range("index out of range");
    }
    return pointer[index];
}

template <typename T>
int DynamicArray<T>::GetLength() {
    return length;
}

template <typename T>
void DynamicArray<T>::Set(int index, T value) {
    if (index < 0 || index > length) {
        throw out_of_range("index out of range");
    }
    pointer[index] = value;
}

template <typename T>
void DynamicArray<T>::Resize(int newSize) {
    T *ptr = new T[newSize];
    int copySize = min(newSize, length);
    for (int i = 0; i < copySize; i++) {
        ptr[i] = pointer[i];
    }
    delete[] pointer;
    pointer = ptr;
    length = newSize;
}

#endif
