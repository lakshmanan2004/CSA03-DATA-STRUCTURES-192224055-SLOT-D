#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

// Structure to represent a hash table entry
typedef struct {
    int key;
    int value;
} Entry;

// Hash table array
Entry hashTable[TABLE_SIZE];

// Initialize the hash table
void initHashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i].key = -1; // -1 indicates an empty slot
    }
}

// Hash function
int hash(int key) {
    return key % TABLE_SIZE;
}

// Insert a key-value pair into the hash table
void insert(int key, int value) {
    int index = hash(key);

    while (hashTable[index].key != -1) {
        index = (index + 1) % TABLE_SIZE; // Linear probing
    }

    hashTable[index].key = key;
    hashTable[index].value = value;
}

// Search for a key in the hash table
int search(int key) {
    int index = hash(key);

    while (hashTable[index].key != -1) {
        if (hashTable[index].key == key) {
            return hashTable[index].value;
        }
        index = (index + 1) % TABLE_SIZE; // Linear probing
    }

    return -1; // Key not found
}

int main() {
    initHashTable();

    insert(5, 100);
    insert(15, 200);
    insert(25, 300);

    printf("Value for key 15: %d\n", search(15));
    printf("Value for key 5: %d\n", search(5));
    printf("Value for key 10: %d\n", search(10));

    return 0;
}
