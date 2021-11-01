#pragma once
#include <string>

using namespace std;

class StringList
{
	struct Elem {
	public:
		string word;
		Elem* next;
		Elem(string w);
	};
	Elem* first;
	Elem* current;
public:
	StringList();
	void onFirst();
	void onNext();
	void add(string word);
	string getCurrent();
	bool currentExists();
	bool contains(string word);
	void clear();
	~StringList();
};

