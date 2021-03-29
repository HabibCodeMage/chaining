#pragma once
#ifndef HASHTABLE_H
#define HASHTABLE_H
#include<vector>
#include<list>
#include<iostream>
#include<functional>
using namespace std;
template <typename K,typename V >
class hashtable
{
private:
	struct element
	{
		K Key;
		V value;
	};
	vector<vector<element>> values{ {},{},{},{},{},{},{},{},{},{} };
	hash<string> tohash;
public:
	hashtable()
	{
	}
	void insert(const K& key, const V& value)
	{

		values[tohash(key)%10].push_back(element{ key,value});
	}
	V get(const K& key)
	{
		for (auto it= values[tohash(key) % 10].begin();it!= values[tohash(key) % 10].end();it++)
		{
			if (it->Key == key)
				return it->value;
		}
		throw "not found";		
	}
	void erase(const K& key)
	{
		for (auto it = values[tohash(key) % 10].begin(); it != values[tohash(key) % 10].end(); it++)
		{
			if (it->Key == key)
			{
				values[tohash(key) % 10].erase(it);
				return;
			}
			
		}
		throw "not found";

	}
};
#endif
