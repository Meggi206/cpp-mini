#include <iostream>
#include "LRUCache.hpp"

int main() {
    LRUCache cache(2);
    cache.put(1, 10);
    cache.put(2, 20);
    std::cout << "Get 1: " << cache.get(1) << std::endl; // 10
    cache.put(3, 30);
    std::cout << "Get 2: " << cache.get(2) << std::endl; // -1
    std::cout << "Get 3: " << cache.get(3) << std::endl; // 30
    return 0;
}
