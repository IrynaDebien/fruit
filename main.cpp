#include "fruit.h"
#include "store.h"
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251); 

    Store<Fruit<char>> store;
    store.AddLast(Fruit<char>("Apple", "Antonovka", 5));
    store.AddLast(Fruit<char>("Apple", "Golden", 4));
    store.AddLast(Fruit<char>("Pear", "Bartlett", 3));
    store.AddLast(Fruit<char>("Pear", "Anjou", 4));

    cout << "Store after adding fruits:" << endl;
    cout << store;

    store.RemoveLast();
    cout << "Store after removing the last fruit:" << endl;
    cout << store;

    store.Add(Fruit<char>("Apple", "Fuji", 6), 1);
    cout << "Store after adding Fuji apple at index 1:" << endl;
    cout << store;

    store.Remove(2);
    cout << "Store after removing the fruit at index 2:" << endl;
    cout << store;

    Store<Fruit<char>> store2 = store; 
    store2.AddLast(Fruit<char>("Apple", "Calville", 7));
    cout << "Store2 after adding Calville apple:" << endl;
    cout << store2;

    Store<Fruit<char>> store3;
    store3 = store2; 
    store3.AddLast(Fruit<char>("Pear", "Conference", 5));
    cout << "Store3 after copy assignment and adding Conference pear:" << endl;
    cout << store3;

    Store<Fruit<char>> store4 = std::move(store); 
    cout << "Store4 after moving from store:" << endl;
    cout << store4;
    cout << "Store after moving (should be empty):" << endl;
    cout << store;

    Store<Fruit<char>> store5;
    store5 = std::move(store4); 
    cout << "Store5 after moving from store4:" << endl;
    cout << store5;
    cout << "Store4 after moving (should be empty):" << endl;
    cout << store4;

    return 0;
}
