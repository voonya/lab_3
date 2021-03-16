#include "Header.h"
#include <ctime>
using namespace std;


int main() {
    HashTable table;
    parse_file(get_working_dir() + +"\\" + "dict.txt", table);
    cout << endl << table.get_size() << endl;
    //table.show_table();
    work_loop(table);

    return 0;
}

