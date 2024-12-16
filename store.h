#pragma once
#include <iostream>
#include <windows.h>
using namespace std;

template <typename T>
class Store {
private:
    T* array;
    int size;

public:
    Store();
    ~Store();
    Store(const Store& other);
    Store& operator=(const Store& other);
    Store(Store&& other) noexcept;
    Store& operator=(Store&& other) noexcept;

    void AddLast(const T& element);
    void RemoveLast();
    void Add(const T& element, int index);
    void Remove(int index);

    friend ostream& operator<<(ostream& os, const Store& store) {
        if (store.size == 0) {
            os << "Array is empty";
        }
        else {
            for (int i = 0; i < store.size; ++i) {
                os << "Index: " << i << ", Element: " << store.array[i] << endl;
            }
        }
        return os;
    }

    friend istream& operator>>(istream& is, Store& store) {
        cout << "Enter the number of elements: ";
        is >> store.size;
        store.array = new T[store.size];
        for (int i = 0; i < store.size; ++i) {
            cout << "Enter element " << i << ": ";
            is >> store.array[i];
        }
        return is;
    }

    int GetSize() const;
    void Output() const;
    T operator[](int index) const;
};




template <typename T>
Store<T>::Store() : array(nullptr), size(0) {}

template <typename T>
Store<T>::~Store() {
    delete[] array;
}

template <typename T>
Store<T>::Store(const Store& other) {
    size = other.size;
    array = new T[size];
    for (int i = 0; i < size; ++i) {
        array[i] = other.array[i];
    }
}

template <typename T>
Store<T>& Store<T>::operator=(const Store& other) {
    if (this == &other) return *this;
    delete[] array;
    size = other.size;
    array = new T[size];
    for (int i = 0; i < size; ++i) {
        array[i] = other.array[i];
    }
    return *this;
}

template <typename T>
Store<T>::Store(Store&& other) noexcept : array(nullptr), size(0) {
    *this = std::move(other);
}

template <typename T>
Store<T>& Store<T>::operator=(Store&& other) noexcept {
    if (this == &other) return *this;
    delete[] array;
    array = other.array;
    size = other.size;
    other.array = nullptr;
    other.size = 0;
    return *this;
}

template <typename T>
void Store<T>::AddLast(const T& element) {
    T* temp = new T[size + 1];
    for (int i = 0; i < size; ++i) {
        temp[i] = array[i];
    }
    temp[size] = element;
    delete[] array;
    array = temp;
    ++size;
}

template <typename T>
void Store<T>::RemoveLast() {
    if (size > 0) {
        T* temp = new T[size - 1];
        for (int i = 0; i < size - 1; ++i) {
            temp[i] = array[i];
        }
        delete[] array;
        array = temp;
        --size;
    }
    else {
        throw out_of_range("Array is empty, removal is impossible");
    }
}

template <typename T>
void Store<T>::Add(const T& element, int index) {
    if (index < 0 || index > size) {
        throw out_of_range("Index out of range");
    }
    T* temp = new T[size + 1];
    for (int i = 0; i < index; ++i) {
        temp[i] = array[i];
    }
    temp[index] = element;
    for (int i = index; i < size; ++i) {
        temp[i + 1] = array[i];
    }
    delete[] array;
    array = temp;
    ++size;
}

template <typename T>
void Store<T>::Remove(int index) {
    if (index < 0 || index >= size) {
        throw out_of_range("Index out of range");
    }
    T* temp = new T[size - 1];
    for (int i = 0, j = 0; i < size; ++i) {
        if (i != index) {
            temp[j++] = array[i];
        }
    }
    delete[] array;
    array = temp;
    --size;
}

template <typename T>
int Store<T>::GetSize() const {
    return size;
}

template <typename T>
void Store<T>::Output() const {
    if (size == 0) {
        cout << "Array is empty";
    }
    else {
        for (int i = 0; i < size; ++i) {
            cout << array[i] << "\t";
        }
    }
    cout << endl << endl;
}

template <typename T>
T Store<T>::operator[](int index) const {
    if (index < 0 || index >= size) {
        throw out_of_range("Index out of range");
    }
    return array[index];
}