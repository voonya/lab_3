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

void HashTable::insert(string key, string value) {
    long int hash_key = hashing(key);

    Node* previous = NULL;
    Node* start = table[hash_key];
    while(start != NULL) {
        previous = start;
        start = start->next;
    }
    if (start == NULL) {
        start = new Node(key, value);
        if (previous == NULL) {
            table[hash_key] = start;
        }
        else {
            previous->next = start;
        }
    }
}

string HashTable::search(string key) {
    long int hash_key = hashing(key);
    Node* start = table[hash_key];
    while(start != NULL) {
        if (start->key == key) {
            return start->value;
        }
        start = start->next;
    }
    return "";
}
