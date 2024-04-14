#include "../include/cache.hpp"

Block::Block() {}

Block::Block(bool v, ull t, int n)
{
    this->valid = v;
    this->tag = t;
    this->nbytes = n;
}

Cache::Cache(ull sets, ull blocks, int bytes, int config)
{
    this->sets = sets;
    this->blocks = blocks;
    this->bytes = bytes;
    this->config = config;

    loads = stores = 0;
    hits = misses = {0, 0};
    cylces = 0;

    nbytes = log2(bytes);

    cache = new Block *[sets];
    for (ull i = 0; i < sets; ++i)
    {
        cache[i] = new Block[blocks];
        for (ull j = 0; j < blocks; ++j)
        {
            cache[i][j] = Block(false, 0, nbytes);
        }
    }
}

Cache::~Cache()
{
    for (ull i = 0; i < sets; ++i)
    {
        delete[] cache[i];
    }

    delete[] cache;
    cache = nullptr;
}

void Cache::set_policies(int wt, int wa, int lr)
{
    this->write_through = wt;
    this->write_allocate = wa;
    this->lru = lr;
}

void Cache::store(ull adr)
{
    stores++;
    cylces++;

    ull tag = adr / (sets * bytes);
    ull index = (adr / bytes) % sets;

    for (ull i = 0; i < blocks; ++i)
    {
        if (cache[index][i].tag == tag and cache[index][i].valid)
        {
            hits.second++;
            return;
        }
    }

    misses.second++;
    cylces += 100 * (bytes / 4);

    for (ull i = 0; i < blocks; ++i)
    {
        if (!cache[index][i].valid)
        {
            cache[index][i].valid = true;
            cache[index][i].tag = tag;
            return;
        }
    }
}

void Cache::load(ull adr)
{
    loads++;
    cylces++;

    ull tag = adr / (sets * bytes);
    ull index = (adr / bytes) % sets;

    for (ull i = 0; i < blocks; ++i)
    {
        if (cache[index][i].tag == tag and cache[index][i].valid)
        {
            hits.first++;
            return;
        }
    }

    misses.first++;
    cylces += 100 * (bytes / 4);

    for (ull i = 0; i < blocks; ++i)
    {
        if (!cache[index][i].valid)
        {
            cache[index][i].valid = true;
            cache[index][i].tag = tag;
            return;
        }
    }
}
