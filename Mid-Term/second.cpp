#include <iostream>
#include <list>
#include <vector>

class Hash {
    int numBuckets;
    std::list<int> *table;
    std::vector<bool> isOccupied;

public:
    Hash(int v);
    void insertItem(int value);
    void deleteItem(int key);
    int hashFunction(int value) {
        return (value % numBuckets);
    }
    void displayHash();
};

Hash::Hash(int b) {
    this->numBuckets = b;
    table = new std::list<int>[numBuckets];
    isOccupied.resize(numBuckets);
}

void Hash::insertItem(int key) {
    int index = hashFunction(key);
    int originalIndex = index;
    int i = 1;

    while (isOccupied[index]) {
        index = (index + i * i) % numBuckets;
        i++;
    }
    table[index].push_back(key);
    isOccupied[index] = true;
}

void Hash::displayHash() {
    for (int i = 0; i < numBuckets; i++) {
        std::cout << i;
        for (auto x : table[i])
            std::cout << " ==> " << x;
        std::cout << std::endl;
    }
}

int main() {
    Hash hash = Hash(10);
    int elements[] = {4371, 1323, 6173, 4199, 4344, 9679, 1989};
    for (int i = 0; i < 7; i++) {
        hash.insertItem(elements[i]);
    }
    hash.displayHash();
    std::cout << std::endl;

    return 0;
}
