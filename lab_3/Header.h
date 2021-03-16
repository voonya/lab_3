#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>
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
    int loads = 0;
    int MAX_SIZE = TABLE_SIZE * 0.8;
    Node** table;
    void resize();
public:
    HashTable();
    ~HashTable();
    unsigned long hashing(string key);
    void insert(string key, string value);
    string search(string key);
    void show_table();
    int get_size() { return TABLE_SIZE; };
    //int analyze();
};

struct definition {
    string key;
    string value;
};

void work_loop(HashTable);
string get_working_dir();
void parse_file(string path, HashTable& table);
definition parse_line(string line);
int input_sentence(string words[]);
string str_to_upper(string str);


