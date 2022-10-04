#ifndef F_LAB2_LINKEDLISTSEQUANCE
#define F_LAB2_LINKEDLISTSEQUANCE

#include "f_lab2_linkedlist.h"
#include "f_lab2_sequance.h"

template <typename T>
class LinkedListSequance : public Sequance<T> {
    private:
        LinkedList<T> *items;

    public:
        LinkedListSequance() {
            this->items = new LinkedList<T>; 
        }
        LinkedListSequance(T *items, int count, int h, int w) {
            this->items = new LinkedList<T>(items, count, h, w);
        }
        LinkedListSequance(LinkedList<T> *list) {
            this->items = new LinkedList<T>(list);
        }

        void Set(int index, T item) override {
            this->items->Set(index, item);
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

        T GetFirst() const override {
            return this->items->GetFirst();
        }
        T GetLast() const override {
            return this->items->GetLast();
        }
        T Get(int index) const override {
            return this->items->Get(index);
        }

        Sequance<T> *GetSubSequance(int startIndex, int endIndex) const override {
            LinkedList<T> *list = this->items->GetSubList(startIndex, endIndex);
            LinkedListSequance<T> *listsequance = new LinkedListSequance<T>(list);
            delete list;
            return listsequance;
        }
        void Append(T item) override {
            this->items->Append(item);
        }
        void Prepend(T item) override {
            this->items->Prepend(item);
        }
        void InsertAt(T item, int index) override {
            this->items->InsertAt(item, index);
        }
        Sequance<T> *Concat(Sequance<T> *list) override {
            for (int i = 0; i < list->GetLength(); i++) {
                this->items->Append(list->Get(i));
            }
            return this;
        }

        Sequance<T> *Copy() const override {
            LinkedListSequance<T> *res = new LinkedListSequance<T>(this->items->Copy());
            return res;
        }

        ~LinkedListSequance() {
            delete items;
        }
};



#endif
