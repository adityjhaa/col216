## Cache Simulator
### Best Cache

<hr>

#### Build
```bash
make
```

#### Run
```bash
./cacheSim <sets> <blocks> <bytes> <allocate-policy> <write-policy> <replacement-policy> < traceFilePath
```

#### Example
```bash
./cacheSim 256 4 16 write-allocate write-back lru < example.trace
```

#### Clean
```bash
make clean
```

<hr>

#### Tests

**Process**
<p>
To find out which write and replacement policies would be the best for the simulator, I ran the simulator over different tracefiles and check their total cycles, total hits, total misses and miss penalties. I checked all the 4 possible combinations (a. *write-back* & *lru*, b. *write-through* & *lru*, c. *write-back* & *fifo*, d. *write-through* & *fifo*) for every trace. I did not check for *no-write-allocate* Vs *write-allocate* as *write-allocate* seems to always outperform *no-write-allocate*. This gives a good estimate for which combination should perform the best. For finding the optimal cache size, i ran a python script that runs the simulator for each number of sets, blocks and bytes per block, and a single trace file in the following manner.

- Sets : 1, 2, 4, ..., 16384
- Blocks : 1, 2, 4, ..., 128
- Bytes : 1, 2, 4, ..., 64

The python script now returns the cache size attributes for top 10 most performant configurations of these 840 combinations. I checked these 10 results returned and checked for the result which is the perfect balance of size and performance. A performant cache which takes up size in the magnitudes of 100 MBs is not desired. So, I searched for one that doesn't requires much size and the performance only increases by a slight amount on doubling the size.
</p>

**Results**
The best cache configuration I got on performing the above tests is :

Write-policy | Replacement-policy | Sets | Blocks | Bytes | Total Size
--- | --- | --- | --- | --- | ---
*Write-back* | *lru* | 4096 | 4 | 4 | 64 KB

<hr>
