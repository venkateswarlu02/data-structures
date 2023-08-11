#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

struct HashTable {
    int keys[SIZE];
    int values[SIZE];
};
void initHashTable(struct HashTable* ht) {
    for (int i = 0; i < SIZE; ++i) {
        ht->keys[i] = -1; 
        ht->values[i] = -1;
    }
}
int hash(int key) {
    return key % SIZE;
}
void insert(struct HashTable* ht, int key, int value) {
    int index = hash(key);

    while (ht->keys[index] != -1) {
        index = (index + 1) % SIZE;
    }

    ht->keys[index] = key;
    ht->values[index] = value;
}
int search(struct HashTable* ht, int key) {
    int index = hash(key);
    while (ht->keys[index] != -1) {
        if (ht->keys[index] == key) {
            return ht->values[index];
        }
        index = (index + 1) % SIZE; 
    }
    return -1;
}

int main() {
    struct HashTable ht;
    initHashTable(&ht);

    insert(&ht, 5, 50);
    insert(&ht, 15, 150);
    insert(&ht, 25, 250);
    insert(&ht, 35, 350);

    printf("Value for key 15: %d\n", search(&ht, 15));
    printf("Value for key 25: %d\n", search(&ht, 25));
    printf("Value for key 10: %d\n", search(&ht, 10));

    return 0;
}
