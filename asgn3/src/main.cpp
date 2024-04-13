#include <iostream>

// Required values
int sets,
    blocks,
    bytes,
    write_allocate,
    write_through,
    lru;

int main(int argc, const char *argv[])
{
    if (argc != 7)
    {
        std::cout << argc << "\n";
        puts("Invalid input arguments");

        return 1;
    }

    sets = atoi(argv[1]);
    blocks = atoi(argv[2]);
    bytes = atoi(argv[3]);

    ((std::string)(argv[4]) == "write-allocate") ? write_allocate = 1 : write_allocate = 0;
    ((std::string)argv[5] == "write-through") ? write_through = 1 : write_through = 0;
    ((std::string)argv[6] == "lru") ? lru = 1 : lru = 0;

    return 0;
}