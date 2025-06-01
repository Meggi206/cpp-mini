#ifndef LRUCACHE_HPP
#define LRUCACHE_HPP

#include <unordered_map>
#include <list>

class LRUCache {
private:
    int capacity;
    std::list<std::pair<int, int>> itemList;
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> itemMap;

public:
    LRUCache(int cap);
    int get(int key);
    void put(int key, int value);
};

#endif
