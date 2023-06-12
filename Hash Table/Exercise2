#include <iostream>
#include <list>
#include <vector>
using namespace std;

class HashTable {
private:
    vector<list<string>> table;
    int size;

public:
    HashTable(int tableSize) : size(tableSize) {
        table.resize(size);
    }

    int hashFunction(const string& key) {
        int sum = 0;
        for (char c : key) {
            sum += c;
        }
        return sum % size;
    }

    void insert(const string& key) {
        int index = hashFunction(key);
        table[index].push_back(key);
    }

    void remove(const string& key) {
        int index = hashFunction(key);
        table[index].remove(key);
    }

    bool contains(const string& key) {
        int index = hashFunction(key);
        for (const string& item : table[index]) {
            if (item == key) {
                return true;
            }
        }
        return false;
    }

    void printTable() {
        for (int i = 0; i < size; ++i) {
            cout << "Index " << i << ": ";
            for (const string& item : table[i]) {
                cout << item << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    HashTable hashTable(10);

    hashTable.insert("apple");
    hashTable.insert("banana");
    hashTable.insert("cherry");
    hashTable.insert("date");
    hashTable.insert("elderberry");
    hashTable.insert("fig");

    cout << "HashTable contents:" << endl;
    hashTable.printTable();

    cout << boolalpha;
    cout << "Contains 'banana': " << hashTable.contains("banana") << endl;
    cout << "Contains 'grape': " << hashTable.contains("grape") << endl;

    hashTable.remove("cherry");

    cout << "HashTable contents after removing 'cherry':" << endl;
    hashTable.printTable();

    return 0;
}
