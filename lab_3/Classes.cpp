#include "Header.h"

Node::Node(string key, string value) {
    this->key = key;
    this->value = value;
    this->next = NULL;
}

HashTable::HashTable() {
    table = new Node * [table_size];
    for (int i = 0; i < table_size; i++)
        table[i] = NULL;
}

unsigned long HashTable::hashing(string key) {
    unsigned long hash_key = 0;
    for (size_t i = 0; i < key.length(); i++) {
        hash_key += hash_key * 33 ^ key[i];
    }
    return hash_key % table_size;
}

void HashTable::insert(string key, string value) {
    unsigned long hash_key = hashing(key);

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
            load++;
            if (float(load) / table_size > 0.8)
                resize();
        }
        else {
            previous->next = start;
        }
    }
}

string HashTable::search(string key) {
    unsigned long hash_key = hashing(key);
    Node* start = table[hash_key];
    while(start != NULL) {
        if (start->key == key) {
            return start->value;
        }
        start = start->next;
    }
    return "";
}

void HashTable::show_table() {
    for (int i = 0; i < table_size; i++) {
        cout << i << " ";
        if (table[i] == NULL)
            cout << "NULL" << endl;
        else {
            Node* previous = NULL;
            Node* start = table[i];
            while (start != NULL)
            {
                previous = start;
                start = start->next;
                cout << " ---> " << previous->key;
            }
            cout << endl;
        }
    }
}


void HashTable::resize() {
    Node** new_table;
    new_table = new Node* [static_cast<long long>(table_size) * 2];
    for (int i = 0; i < table_size * 2; i++)
        new_table[i] = NULL;

    for (int i = 0; i < table_size; i++) {
        new_table[table_size + i] = table[i];
    }
    table = new_table;
    table_size *= 2;
    cout << table_size;
}