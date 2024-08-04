#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "cache.h"

void simulateCache(int cacheSize, ReplacementPolicy policy, const std::vector<int>& addresses, sf::RenderWindow& window) {
    Cache cache(cacheSize, policy);

    for (int address : addresses) {
        cache.access(address);
    }

    std::string policyStr = (policy == LRU ? "LRU" : "FIFO");
    std::string hitRateStr = "Hit Rate: " + std::to_string(cache.getHitRate());
    std::string missRateStr = "Miss Rate: " + std::to_string(cache.getMissRate());

    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        std::cerr << "Error loading font\n";
        return;
    }

    sf::Text policyText(policyStr, font, 20);
    policyText.setPosition(10, 10);
    sf::Text hitRateText(hitRateStr, font, 20);
    hitRateText.setPosition(10, 40);
    sf::Text missRateText(missRateStr, font, 20);
    missRateText.setPosition(10, 70);

    window.clear();
    window.draw(policyText);
    window.draw(hitRateText);
    window.draw(missRateText);
    window.display();
}

int main() {
    int cacheSize = 4;
    ReplacementPolicy policy = LRU;
    std::vector<int> addresses = { 1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5, 1, 6 };

    sf::RenderWindow window(sf::VideoMode(800, 600), "Cache Simulator");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        std::cout << "Simulating LRU Cache:" << std::endl;
        simulateCache(cacheSize, LRU, addresses, window);

        std::cout << "\nSimulating FIFO Cache:" << std::endl;
        simulateCache(cacheSize, FIFO, addresses, window);
    }

    return 0;
}
