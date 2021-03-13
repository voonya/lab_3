#include "Header.h"

Node::Node(string key, string value) {
    this->key = key;
    this->value = value;
    this->next = NULL;
}

HashTable::HashTable() {
    table = new Node * [TABLE_SIZE];
    for (int i = 0; i < TABLE_SIZE; i++)
        table[i] = NULL;
}

long int HashTable::hashing(string key) {
    long int hash_key = 0;
    for (size_t i = 0; i < key.length(); i++) {
        hash_key += i * key[i];
    }
    return hash_key % TABLE_SIZE;
}