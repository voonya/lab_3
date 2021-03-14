#include "Header.h"


definition parse_line(string line) {
	definition curr;
	string word = line.substr(0, line.find(";"));
	string def = line.substr(line.find(";") + 1, string::npos);
	curr.key = word;
	curr.value = def;
	return curr;
}

string get_working_dir() {
	return fs::current_path().string();
}

void parse_file(string path, HashTable& table) {
	ifstream dict(path);
	if (dict.is_open()) {
		while (!dict.eof()) {
			string line;
			getline(dict, line);
			definition item_table = parse_line(line);
			table.insert(item_table.key, item_table.value);
		}
	}
	dict.close();
}