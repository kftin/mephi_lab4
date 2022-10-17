#ifndef F_LAB2_ARRAYSequance
#define F_LAB2_ARRAYSequance

#include "f_lab2_sequance.h"
#include "f_lab2_dynamicarray.h"

template <typename T>
class ArraySequance: public Sequance<T> {
    private:
        DynamicArray<T> *items;

    public:

        ArraySequance() { this->items = new DynamicArray<T>; }
        ArraySequance(T *items, int count, int h, int w);
        ArraySequance(DynamicArray<T> *dynamicArray);

        T Get(int index) const override {
            return this->items->Get(index);
        }
        void Set(int index, T value) override {
            this->items->Set(index, value);
        }
        //void Resize(int newSize) override {
        //    this->items->Resize(newSize);
        //}
        T GetFirst() const override {
            return this->items->Get(0);
        }
        T GetLast() const override {
            return this->items->Get(this->items->GetLength() - 1);
        }
        int GetLength() const override {
            return this->items->GetLength();
        }
        int GetHeigth() const override {
            return this->items->GetHeigth();
        }
        int GetWidth() const override {
            return this->items->GetWidth();
        }


        void Append(T item) override {
            this->items->Resize(this->items->GetLength() + 1);
            this->items->Set(this->items->GetLength() - 1, item);
        }
        void Prepend(T item) override {
            int size = this->items->GetLength();
            this->items->Resize(this->items->GetLength() + 1);
            for (int i = size - 1; i >= 0; i--) {
                this->items->Set(i + 1, this->items->Get(i));
            }
            this->items->Set(0, item);
        }
        void InsertAt(T item, int index) override;
        Sequance<T> *Concat(Sequance<T> *list) override;
        Sequance<T> *GetSubSequance(int startIndex, int endIndex) const override;

        Sequance<T> *Copy() const override {
            ArraySequance<T> *res = new ArraySequance<T>(this->items->Copy());
            return res;
        }

        ~ArraySequance() { delete items; }
};

template <typename T>
void ArraySequance<T>::InsertAt(T item, int index) {
    this->items->Resize(this->items->GetLength() + 1);
    for (int i = this->items->GetLength() - 1; i > index; i--) {
        this->items->Set(i, this->items->Get(i - 1));
    }
    this->items->Set(index, item);

}

template <typename T>
ArraySequance<T>::ArraySequance(T *items, int count, int h, int w) {
    this->items = new DynamicArray<T>(items, count, h, w);
}

template <typename T>
ArraySequance<T>::ArraySequance(DynamicArray<T> *dynamicArray) {
    this->items = new DynamicArray<T>(dynamicArray);
}

template <typename T>
Sequance<T> *ArraySequance<T>::Concat(Sequance<T> *list) {
    int oldSize = this->items->GetLength();
    this->items->Resize(oldSize + list->GetLength());
    for (int i = 0; i < list->GetLength(); i++) {
        this->items->Set(oldSize + i, list->Get(i));
    }
    return this;
}

template <typename T>
Sequance<T> *ArraySequance<T>::GetSubSequance(int startIndex, int endIndex) const {
    T *array = new T[endIndex - startIndex + 1];
    for (int i = 0; i < endIndex - startIndex + 1; i++) {
        array[i] = items->Get(startIndex + i);
    }
    ArraySequance<T> *newArraySequance = new ArraySequance(array, endIndex - startIndex + 1, 1, endIndex - startIndex + 1);
    delete[] array;
    return newArraySequance;
}


#endif
