#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>
namespace fs = std::filesystem;
using namespace std;

struct list_item {
	string value;
	list_item* next;
};

class linked_list {
	list_item* start;
	list_item* end;
	int count_el = 0;
	bool empty;
public:
	linked_list() {
		start = NULL;
		end = NULL;
		count_el = 0;
		empty = true;
	}

	void push_back(string item) {
		empty = false;
		list_item* curr = new list_item;
		curr->value = item;
		curr->next = NULL;
		if (start == NULL && end == NULL) {
			start = curr;
			end = curr;
		}
		else {
			end->next = curr;
			end = curr;
		}
		count_el++;
	}

	int size() {
		return count_el;
	}

	void show_list() {
		list_item* ptr = start;
		for (int i = 0; i < count_el; i++) {
			cout << ptr->value << "\n\n";
			ptr = ptr->next;
		}
	}

	bool is_empty() {
		return empty;
	}
};

class Node {
public:
    string key;
    linked_list value;
    Node* next;
    Node(string key, linked_list value);
};

class HashTable {
private:
    int TABLE_SIZE = 20;
    int loads = 0;
    int MAX_SIZE = TABLE_SIZE * 0.8;
    Node** table;
    void resize();
public:
    HashTable();
    ~HashTable();
    unsigned long hashing(string key);
    void insert(string key, string value);
    linked_list search(string key);
    void show_table();
    int get_size() { return TABLE_SIZE; };
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


