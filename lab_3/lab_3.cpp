#include "Header.h"

using namespace std;

int main() {
    HashTable table;

    parse_file(get_working_dir() + +"\\" + "dict.txt", table);

    work_loop(table);

    return 0;
}

