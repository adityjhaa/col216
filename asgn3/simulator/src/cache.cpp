#include "../include/cache.hpp"

Line::Line() {}

Line::Line(bool v, bool d, ull t, int n)
{
    this->valid = v;
    this->dirty = d;
    this->tag = t;
    this->bytes = n;
}

Cache::Cache(ull sets, ull blocks, int bytes)
{
    this->sets = sets;
    this->blocks = blocks;
    this->bytes = bytes;

    loads = stores = 0;
    hits = misses = {0, 0};
    cylces = 0;

    cache = new Line *[sets];
    fifo = new ull[sets];
    lru_cnt = new list<ull>[sets];
    for (ull i = 0; i < sets; ++i)
    {
        cache[i] = new Line[blocks];
        fifo[i] = 0;
        lru_cnt[i] = {};
        for (ull j = 0; j < blocks; ++j)
        {
            cache[i][j] = Line(false, false, 0, bytes);
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
    delete[] fifo;
    delete[] lru_cnt;
}

void Cache::set_policies(bool wt, bool wa, bool lr)
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
            if (write_through)
                cylces += 100 * bytes / 4;
            else
                cache[index][i].dirty = true;

            if (lru)
            {
                lru_cnt[index].remove(i);
                lru_cnt[index].push_front(i);
            }
            return;
        }
    }

    misses.second++;

    if (write_allocate)
    {
        cylces += 100 * (bytes / 4);
        for (ull i = 0; i < blocks; ++i)
        {
            if (!cache[index][i].valid)
            {
                cache[index][i].valid = true;
                cache[index][i].tag = tag;
                if (write_through)
                    cylces += 100 * (bytes / 4);
                else
                    cache[index][i].dirty = true;
                return;
            }
        }

        ull e;
        if (lru)
        {
            ull a = e = lru_cnt[index].back();
            lru_cnt[index].push_front(a);
            lru_cnt[index].pop_back();
            cache[index][a].tag = tag;
        }
        else
        {
            e = fifo[index];
            cache[index][fifo[index]].tag = tag;
            fifo[index] = (1 + fifo[index]) % blocks;
        }
        if (write_through)
        {
            cylces += 100 * (bytes / 4);
            return;
        }

        if (cache[index][e].dirty and (!write_through))
        {
            cylces += 100 * (bytes / 4);
        }
    }
    else
    {
        cylces += 100 * bytes / 4;
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
            if (lru)
            {
                lru_cnt[index].remove(i);
                lru_cnt[index].push_front(i);
            }
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
            if (lru)
            {
                lru_cnt[index].remove(i);
                lru_cnt[index].push_front(i);
            }
            return;
        }
    }

    ull e;
    if (lru)
    {
        ull a = e = lru_cnt[index].back();
        lru_cnt[index].push_front(a);
        lru_cnt[index].pop_back();
        cache[index][a].tag = tag;
    }
    else
    {
        e = fifo[index];
        cache[index][fifo[index]].tag = tag;
        fifo[index] = (1 + fifo[index]) % blocks;
    }

    if (cache[index][e].dirty and (!write_through))
    {
        cylces += 100 * (bytes / 4);
        cache[index][e].dirty = false;
    }
}
