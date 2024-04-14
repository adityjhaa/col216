#include "../include/cache.hpp"

// Required values
ull sets,
    blocks;

int bytes,
    write_allocate,
    write_through,
    lru;
int choose; // case specific

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

    Cache cache(sets, blocks, bytes, choose);
    cache.set_policies(write_through, write_allocate, lru);

    string s;
    char c;
    ull a;

    while (cin >> s)
    {
        c = s[0];
        switch (c)
        {
        case 's':
            cin >> s;
            a = stoi(s, nullptr, 16);
            cin >> s;
            cache.store(a);
            break;
        case 'l':
            cin >> s;
            a = stoi(s, nullptr, 16);
            cin >> s;
            cache.load(a);
            break;
        default:
            puts("Operation is neither store nor load! ERROR!\n");
            return 1;
        }
    }

    cout << "Total loads: " << cache.loads << "\n"
         << "Total stores: " << cache.stores << "\n"
         << "Load hits: " << cache.hits.first << "\n"
         << "Load misses: " << cache.misses.first << "\n"
         << "Store hits: " << cache.hits.second << "\n"
         << "Store misses: " << cache.misses.second << "\n"
         << "Total cycles: " << cache.cylces << "\n";

    return 0;
}
