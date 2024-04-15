#pragma once

#include <vector>
#include <iostream>
#include <cmath>
#include <list>

using std::cout,
    std::cin,
    std::endl,
    std::stoull,
    std::string,
    std::pair,
    std::list;

#define ull unsigned long long

struct Line
{
    bool valid, dirty;
    ull tag;
    int bytes;

    Line();
    Line(bool v, bool d, ull t, int n);
};

class Cache
{
    Line **cache;
    // configurations of cache
    ull sets;
    ull blocks;
    int bytes;
    int config;

    // policies
    bool write_through, write_allocate, lru;

    // track lru & fifo
    ull *fifo;
    list<ull> *lru_cnt;

public:
    ull loads, stores;
    pair<ull, ull> hits, misses;
    ull cylces;

    Cache(ull sets, ull blocks, int bytes, int config);
    ~Cache();
    void set_policies(bool wt, bool wa, bool lr);

    void store(ull adr);
    void load(ull adr);
};
