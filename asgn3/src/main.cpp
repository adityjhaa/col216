#include <iostream>
#include "../include/cache.hpp"

using std::cout, std::string, std::cin;

// Required values
int sets,
    blocks,
    bytes,
    write_allocate,
    write_through,
    lru;

// case specific
int choose;

int main(int argc, const char *argv[])
{
    if (argc != 7)
    {
        cout << argc << "\n";
        puts("Invalid input arguments");

        return 1;
    }

    sets = atoi(argv[1]);
    blocks = atoi(argv[2]);
    bytes = atoi(argv[3]);

    ((string)(argv[4]) == "write-allocate") ? write_allocate = 1 : write_allocate = 0;
    ((string)argv[5] == "write-through") ? write_through = 1 : write_through = 0;
    ((string)argv[6] == "lru") ? lru = 1 : lru = 0;

    if (blocks == 1)
        choose = 0; // direct mapping
    else if (sets == 1)
        choose = 2; // fully associative
    else
        choose = 1; // m-way set-associative

    string s;

    while (cin >> s)
    {
        cout << s <<" ";
        cin >> s;
        cout << s << "\n";
        cin >>s;
    }

    return 0;
}
