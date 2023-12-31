#include <iostream>
using namespace std;

const int HASH_TABLE_SIZE = 10;

class HashTable {
private:
    int hashTable[HASH_TABLE_SIZE];

public:
    HashTable() {
        // Initialize all elements of the hash table to -1 (indicating empty)
        for (int i = 0; i < HASH_TABLE_SIZE; i++) {
            hashTable[i] = -1;
        }
    }

    // Hash function to calculate the index for the given key
    int hash(int key) {
        return key % HASH_TABLE_SIZE;
    }

    // Function to insert an element into the hash table
    void insert(int data) {
        int index = hash(data);
        if (hashTable[index] == -1) {
            // If the slot is empty, insert the data
            hashTable[index] = data;
        } else {
            // If there is a collision, find the next available slot
            int i = 1;
            while (hashTable[(index + i) % HASH_TABLE_SIZE] != -1) {
                i++;
            }
            // Insert the data into the next available slot
            hashTable[(index + i) % HASH_TABLE_SIZE] = data;
        }
    }

    // Function to delete an element from the hash table
    void remove(int data) {
        int index = hash(data);
        if (hashTable[index] == data) {
            // If the data is found at the hashed index, remove it
            hashTable[index] = -1;
        } else {
            // If there is a collision or the data is not found at the hashed index,
            // search for the data in the subsequent slots
            int i = 1;
            while (hashTable[(index + i) % HASH_TABLE_SIZE] != data) {
                i++;
                // If we have checked all slots and didn't find the data, it is not present in the hash table
                if (i == HASH_TABLE_SIZE) {
                    cout << "Element " << data << " not found in the hash table." << endl;
                    return;
                }
            }
            // Remove the data if found
            hashTable[(index + i) % HASH_TABLE_SIZE] = -1;
        }
    }

    // Function to display the contents of the hash table
    void display() {
        for (int i = 0; i < HASH_TABLE_SIZE; i++) {
            if (hashTable[i] != -1) {
                cout << "Index " << i << "--> " << hashTable[i] << endl;
            } else {
                cout << "Index " << i << "--> Empty" << endl;
            }
        }
    }
};

int main() {
    HashTable hashTable;

    //Inserting elements into the hash table
    hashTable.insert(20);
    hashTable.insert(11);
    hashTable.insert(12);
    hashTable.insert(23);
    hashTable.insert(5);
    hashTable.insert(17);
    hashTable.insert(8);
    hashTable.insert(9);
    

    // Displaying the hash table after inserting data
    cout << "Hash Table after inserting data:" << endl;
    hashTable.display();

    // Deleting an element from the hash table
    hashTable.remove(12);

    // Displaying the hash table after deleting 12
    cout << "Hash Table after deleting 12:" << endl;
    hashTable.display();

    return 0;
}