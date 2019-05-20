#pragma once
#include<unordered_map>

class LRUCache {
public :
	LRUCache(int capacity) {
		_capacity = capacity;
	}
	int get(int key) {
		auto  item = _cache.find(key);
		//if the key doesn't exist,return -1
		if (item == _cache.end()) {
			return -1;
		}
		return item->second.first;
	}

	void set(int key, int value) {
		auto item = _cache.find(key);
		//if the key exists just set the value and update
		if (item != _cache.end()) {
			use(item);
			_cache[key] = { value,_lru.begin() };
		}
		//if the key doesn't exist,check the capacity
		if (_cache.size() == _capacity) {
			//remove lru item
			_cache.erase(_lru.back());
			_lru.pop_back();
		}
		_lru.push_front(key);
		//insert new key value pair
		_cache.insert({ key,{value,_lru.begin()} });
	}

	void use(std::unordered_map<int, std::pair<int, std::list<int>::iterator>>::iterator& it) {
		_lru.erase(it->second.second);
		_lru.push_front(it->first);
		it->second.second = _lru.begin();
	}



private:
	int _capacity;
		//<key,<value,key iterator>>
		std::unordered_map<int, std::pair<int, std::list<int>::iterator>>_cache;
		//list of keys, 1st=MSU, last=LRU
		std::list<int> _lru;
};