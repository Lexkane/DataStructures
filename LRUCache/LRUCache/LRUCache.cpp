// LRUCache.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "LRUCache.h"

int main()
{

	LRUCache *cache = new LRUCache(2);
	cache->set(1, 2);
	cache->set(2, 2);
	std::cout << cache->get(1) << std::endl;
	cache->set(3, 3);
	std::cout << cache->get(2) << std::endl;

	system("pause");
    std::cout << "Hello World!\n"; 
}
