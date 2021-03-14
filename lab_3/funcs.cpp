#include "Header.h"


definition parse_line(string line) {
	definition curr;
	string word = line.substr(0, line.find(";"));
	string def = line.substr(line.find(";") + 1, string::npos);
	curr.key = word;
	curr.value = def;
	return curr;
}