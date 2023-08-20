#include <iostream>
#include <list>
using namespace std;

class Hash {
    int BUCKET;
    list<int> *table;

public:
    Hash(int V);
    void insertItem(int key);
    void deleteItem(int key);
    int hashFunction(int key);
    void displayHash();
};

Hash::Hash(int b) {
    this->BUCKET = b;
    table = new list<int>[BUCKET];
}

void Hash::insertItem(int key) {
    int index = hashFunction(key);
    table[index].push_back(key);
}

void Hash::deleteItem(int key) {
    int index = hashFunction(key);
    list<int>::iterator i;
    for (i = table[index].begin(); i != table[index].end(); i++) {
        if (*i == key)
            break;
    }
    if (i != table[index].end())
        table[index].erase(i);
}

int Hash::hashFunction(int key) {
    return (key % BUCKET);
}

void Hash::displayHash() {
    for (int i = 0; i < BUCKET; i++) {
        cout << i;
        if (!table[i].empty()) {
            cout << " --> ";
            for (auto x : table[i])
                cout << x << " --> ";
        }
        cout << endl;
    }
}

int main() {
    Hash hashTable(10);

    // Inserting data
    hashTable.insertItem(20);
    hashTable.insertItem(11);
    hashTable.insertItem(12);
    hashTable.insertItem(23);
    hashTable.insertItem(5);
    hashTable.insertItem(17);
    hashTable.insertItem(8);
    hashTable.insertItem(9);

    // Displaying the hash table after inserting data
    cout << "Hash table after inserting data:" << endl;
    hashTable.displayHash();
    cout << endl;

    // Deleting item 12
    hashTable.deleteItem(12);

    // Displaying the hash table after deleting item 12
    cout << "Hash table after deleting item 12:" << endl;
    hashTable.displayHash();
    cout << endl;

    // Inserting additional data to observe collision
    hashTable.insertItem(13);
    hashTable.insertItem(57);

    // Displaying the hash table after collision
    cout << "Hash table after collision:" << endl;
    hashTable.displayHash();
    cout << endl;

    return 0;
}