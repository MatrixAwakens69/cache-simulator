#ifndef CACHE_H
#define CACHE_H

#include <vector>
#include <list>
#include <unordered_map>

enum ReplacementPolicy {
    LRU,
    FIFO
};

class Cache {
public:
    Cache(int size, ReplacementPolicy policy);
    bool access(int address);
    double getHitRate() const;
    double getMissRate() const;

private:
    int size;
    ReplacementPolicy policy;
    int hits;
    int misses;
    std::list<int> cache;
    std::unordered_map<int, std::list<int>::iterator> addressMap;

    void replace(int address);
};

#endif // CACHE_H