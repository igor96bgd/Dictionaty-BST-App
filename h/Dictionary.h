#pragma once
#include <string>
#include <iostream>
#include "StringList.h"
#include "Stack.h"

using namespace std;

class Dictionary
{
	struct Node {
	public:
		string key;
		StringList translations;
		Node* left, * right, * parent;
		Node(string k, string t);
	};

	Node* bst;
public:
	Dictionary();
	Dictionary(StringList& keys, StringList& translations);
	bool wordExists(string& word);
	StringList* getTranslations(string& word);
	bool pairExists(string& word, string& translation);
	void addPair(string word, string translation);
	friend ostream& operator << (ostream& os, const Dictionary& d); //vidi da li treba friend
	void printWithPrefix(string prefix);
	void removeWord(string& word);
	void emptyDictionary();
	void ispis();
	~Dictionary();
};

