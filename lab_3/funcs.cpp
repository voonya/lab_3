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


void working_loop(HashTable table) {
	string res_of_search,
		sentence,
		temp_def;
	string* words;
	cout << "If you want to finish searching make empty request" << endl;

	while (true) {
		cout << "Insert the sentence: ";
		getline(cin, sentence);
		if (sentence == "")
			exit(1)
			int number_of_words = into_words(sentence, words);

		for (int i = 0; i < numbre_of_words; i++) {
			temp_def = search(words[i]);
			if (temp_def == "") {
				cout << "No matches for key " << words[i] << endl;
			}
			else {
				cout << words[i] << "definition:" << endl;
				cout << temp_def << endl;
			}
		}
	}
}