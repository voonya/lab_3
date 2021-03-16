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
HashTable::~HashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node* start = table[i];

        while (start != NULL) {
            Node* previous = start;
            start = start->next;
            delete previous;
        }
    }
    delete[] table;
}

unsigned long HashTable::hashing(string key) {
    unsigned long int hash = 0;
    for (int i = 0; i < key.length(); i++)
        hash = (31 * hash + key[i]) % TABLE_SIZE;
    return hash;
}

void HashTable::insert(string key, string value) {
    long int hash_key = hashing(key);
    Node* previous = NULL;
    Node* start = table[hash_key];
    if (start == NULL) loads++;
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
    
    if (loads >= MAX_SIZE) resize();
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
/*int HashTable::analyze() {
    int c = 0;
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table[i] == NULL) c++;
    }
    return c;
}*/

void HashTable::resize() {
    int old_size = TABLE_SIZE;
    TABLE_SIZE *= 2;
    MAX_SIZE = TABLE_SIZE * 0.8;
    Node** old_table = table;
    Node** new_table = new Node * [TABLE_SIZE];
    table = new_table;
    loads = 0;
    for (int i = 0; i < TABLE_SIZE; i++) table[i] = NULL;
    for (int i = 0; i < old_size; i++) {
        if (old_table[i] != NULL) {
            Node* start = old_table[i];
            while (start != NULL){
                Node* previous = start;
                insert(start->key, start->value);
                start = start->next;
                delete previous;
            }
        }
    }
    delete[] old_table;
}

void HashTable::show_table() {
    for (int i = 0; i < TABLE_SIZE; i++) {
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