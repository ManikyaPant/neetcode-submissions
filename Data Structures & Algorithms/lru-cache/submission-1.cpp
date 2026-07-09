class LRUCache {
public:
    int timer;
    int capacity;

    unordered_map<int, int> cache;

    unordered_map<int, int> key_time;

    map<int, int> time_key;


    LRUCache(int capacity) {
        this->capacity = capacity;
        timer = 0;
    }


    void updateTime(int key) {

        if (key_time.find(key) != key_time.end()) {
            int old_time = key_time[key];
            time_key.erase(old_time);
        }

        timer++;

        key_time[key] = timer;
        time_key[timer] = key;
    }


    int get(int key) {

        if (cache.find(key) == cache.end()) {
            return -1;
        }

        updateTime(key);

        return cache[key];
    }


    void put(int key, int value) {

        if (cache.find(key) != cache.end()) {

            cache[key] = value;
            updateTime(key);

            return;
        }


        if ((int)cache.size() == capacity) {

            auto it = time_key.begin();

            int removal_key = it->second;

            time_key.erase(it);
            key_time.erase(removal_key);
            cache.erase(removal_key);
        }


        cache[key] = value;
        updateTime(key);
    }
};