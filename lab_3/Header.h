#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>
#include <math.h>
namespace fs = std::filesystem;
using namespace std;

class Node {
public:
    string key;
    string value;
    Node* next;

    Node(string key, string value);
};

class HashTable {
private:
    int TABLE_SIZE = 1000;
    Node** table;

public:
    HashTable();
    ~HashTable();
    long int hashing(string key);
    void insert(string key, string value);
    string search(string key);
};

struct definition {
    string key;
    string value;
};

void work_loop(HashTable table, string key);
string get_working_dir();
void parse_file(string path, HashTable& table);
definition parse_line(string line);
int input_sentence(string words[]);
