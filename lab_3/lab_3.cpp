﻿#include "Header.h"

using namespace std;


int main() {
    HashTable table;
    parse_file(get_working_dir() + +"\\" + "dict2.txt", table);
    
    //table.show_table();
    work_loop(table);

    return 0;
}

