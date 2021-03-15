#define _CRT_SECURE_NO_WARNINGS
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




int input_sentence(string words[]) {
	char line[150];
	cout << "Input your sentence or word: ";
	cin.getline(line,150);

	char sep[] = ".,;!?- ";

	int count_words = 0;
	char* pos = strtok(line, sep);

	while (pos != NULL) {
		char word_c[100];
		words[count_words++] = pos;
		pos = strtok(NULL, sep);
	}
	return count_words;
}