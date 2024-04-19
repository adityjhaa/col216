#include "../include/cache.hpp"

// Configuration of cache
ull sets,
    blocks;
int bytes;

bool write_allocate, // write-allocate -> 1, no-write-allocate -> 0
    write_through,   // write-through -> 1, write-back -> 0
    lru;             // lru -> 1, fifo -> 0

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

    ((string)(argv[4]) == "write-allocate") ? write_allocate = true : write_allocate = false;
    ((string)argv[5] == "write-through") ? write_through = true : write_through = false;
    ((string)argv[6] == "lru") ? lru = true : lru = false;

    Cache cache(sets, blocks, bytes);
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
            a = stoull(s, nullptr, 16);
            cin >> s;
            cache.store(a);
            break;
        case 'l':
            cin >> s;
            a = stoull(s, nullptr, 16);
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
