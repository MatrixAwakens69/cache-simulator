#include <iostream>
#include <vector>
#include "cache.h"

void simulateCache(int cacheSize, ReplacementPolicy policy, const std::vector<int>& addresses) {
    Cache cache(cacheSize, policy);

    for (int address : addresses) {
        cache.access(address);
    }

    std::cout << "Policy: " << (policy == LRU ? "LRU" : "FIFO") << std::endl;
    std::cout << "Hit Rate: " << cache.getHitRate() << std::endl;
    std::cout << "Miss Rate: " << cache.getMissRate() << std::endl;
}

int main() {
    int cacheSize = 4;
    ReplacementPolicy policy = LRU;
    Cache cache(cacheSize, policy);

    std::vector<int> addresses = { 1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5, 1, 6 };

    std::cout << "Simulating LRU Cache:" << std::endl;
    simulateCache(cacheSize, LRU, addresses);

    std::cout << "\nSimulating FIFO Cache:" << std::endl;
    simulateCache(cacheSize, FIFO, addresses);

    return 0;
}