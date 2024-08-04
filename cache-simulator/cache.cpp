#include "cache.h"

Cache::Cache(int size, ReplacementPolicy policy) : size(size), policy(policy), hits(0), misses(0) {}

bool Cache::access(int address) {
    auto it = addressMap.find(address);
    if (it != addressMap.end()) {
        // Hit
        hits++;
        if (policy == LRU) {
            cache.erase(it->second);
            cache.push_front(address);
            addressMap[address] = cache.begin();
        }
        return true;
    }
    else {
        // Miss
        misses++;
        replace(address);
        return false;
    }
}

void Cache::replace(int address) {
    if (cache.size() >= size) {
        int oldAddress;
        if (policy == LRU || policy == FIFO) {
            oldAddress = cache.back();
            cache.pop_back();
        }
        addressMap.erase(oldAddress);
    }
    if (policy == LRU) {
        cache.push_front(address);
        addressMap[address] = cache.begin();
    }
    else if (policy == FIFO) {
        cache.push_back(address);
        addressMap[address] = --cache.end();
    }
}

double Cache::getHitRate() const {
    return static_cast<double>(hits) / (hits + misses);
}

double Cache::getMissRate() const {
    return static_cast<double>(misses) / (hits + misses);
}