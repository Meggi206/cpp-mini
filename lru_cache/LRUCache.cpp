#include "LRUCache.hpp"

LRUCache::LRUCache(int cap) : capacity(cap) {}

int LRUCache::get(int key) {
    auto it = itemMap.find(key);
    if (it == itemMap.end()) return -1;

    // Move the accessed item to the front
    itemList.splice(itemList.begin(), itemList, it->second);
    return it->second->second;
}

void LRUCache::put(int key, int value) {
    auto it = itemMap.find(key);
    if (it != itemMap.end()) {
        // Update value and move to front
        it->second->second = value;
        itemList.splice(itemList.begin(), itemList, it->second);
        return;
    }

    // If cache is full, remove least recently used item
    if (itemList.size() == capacity) {
        int oldKey = itemList.back().first;
        itemList.pop_back();
        itemMap.erase(oldKey);
    }

    // Insert new item at front
    itemList.emplace_front(key, value);
    itemMap[key] = itemList.begin();
}
