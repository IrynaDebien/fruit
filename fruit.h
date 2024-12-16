#pragma once
#include <iostream>
#include <cstring>
#include <windows.h>
using namespace std;

template <typename T>
class Fruit {
private:
    int kilograms;
    char type[50];
    char name[50];

public:
    Fruit();
    Fruit(const char* t, const char* n, int kg);

    const char* getType() const;
    const char* getName() const;
    int getKilograms() const;

    void setType(const char* t);
    void setName(const char* n);
    void setKilograms(int kg);

    friend ostream& operator<<(ostream& os, const Fruit& fruit) {
        os << fruit.name << " - " << fruit.type << " (" << fruit.kilograms << " kg)";
        return os;
    }
};


template <typename T>
Fruit<T>::Fruit() : kilograms(0) {
    strcpy_s(type, "unknown");
    strcpy_s(name, "unknown");
}

template <typename T>
Fruit<T>::Fruit(const char* t, const char* n, int kg) : kilograms(kg) {
    strcpy_s(name, t);
    strcpy_s(type, n);
}

template <typename T>
const char* Fruit<T>::getType() const {
    return type;
}

template <typename T>
const char* Fruit<T>::getName() const {
    return name;
}

template <typename T>
int Fruit<T>::getKilograms() const {
    return kilograms;
}

template <typename T>
void Fruit<T>::setType(const char* t) {
    if (strlen(t) >= sizeof(type)) {
        throw out_of_range("Type is too long");
    }
    strcpy_s(type, t);
}

template <typename T>
void Fruit<T>::setName(const char* n) {
    if (strlen(n) >= sizeof(name)) {
        throw out_of_range("Name is too long");
    }
    strcpy_s(name, n);
}

template <typename T>
void Fruit<T>::setKilograms(int kg) {
    kilograms = kg;
}