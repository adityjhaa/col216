#pragma once

#include <vector>
#include <iostream>
#include <cmath>

using std::cout,
    std::cin,
    std::endl,
    std::stoi,
    std::string,
    std::vector,
    std::pair;

#define ull unsigned long long int

struct Block
{
    bool valid;
    ull tag;
    int nbytes;

    vector<int> data;

    Block();
    Block(bool v, ull t, int n);
};

class Cache
{
    Block **cache;
    // configurations of cache
    ull sets;
    ull blocks;
    int bytes;
    int config;

    // policies
    int write_through, write_allocate, lru;

public:
    ull loads, stores;
    pair<ull, ull> hits, misses;
    ull cylces;

    Cache(ull sets, ull blocks, int bytes, int config);
    ~Cache();
    void set_policies(int wt, int wa, int lr);

    void store(ull adr, int data);
    void load(ull adr);
};
