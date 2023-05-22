#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;


class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        auto it = map.find(key);
        if (it == map.end()) {
            return -1;
        } else {
            int val = it->second->second;
            lru.erase(it->second);
            lru.push_front(make_pair(key, val));
            it->second = lru.begin(); // 更新 map 中的迭代器，十分重要
            return val;
        }
    }
    
    void put(int key, int value) {
        auto it = map.find(key);
        if (it != map.end()) {
            lru.erase(it->second);
        }
        lru.push_front(make_pair(key, value));
        map[key] = lru.begin();
        
        if (map.size() > cap) {
            map.erase(lru.back().first);
            lru.pop_back();
        }
    }

private:
    int cap;
    list<pair<int, int>> lru;
    unordered_map<int, list<pair<int, int>>::iterator> map;
};

int main() {
    // LRUCache cache(3);
    // for (int i = 0; i < 5; i++)
    // {
    //     cache.put(i , i * 2);
    // }

    // for (int i = 4; i >= 0; i--)
    // {
    //     std::cout << i << ":" << cache.get(i) << std::endl;
    // }

// ["LRUCache","put","put","get","put","get","get"]
// [[2],[2,1],[1,1],[2],[4,1],[1],[2]]
    LRUCache cache(2);
    cache.put(2, 1);
    cache.put(1, 1);
    std::cout << cache.get(2) << std::endl;
    cache.put(4, 1);
    std::cout << cache.get(1) << std::endl;
    std::cout << cache.get(2) << std::endl;
    
    
    std::cout << "Hello " << std::endl;
    return 0;
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */