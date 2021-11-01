#include "StringList.h"

StringList::Elem::Elem(string w)
{
	word = w;
	next = nullptr;
}

StringList::StringList()
{
	first = nullptr;
	current = nullptr;
}

void StringList::onFirst()
{
	current = first;
}

void StringList::onNext()
{
	current = current->next;
}

void StringList::add(string word)
{
	Elem* insert = new Elem(word);
	insert->next = this->first;
	first = insert;
}

string StringList::getCurrent()
{
	return current->word;
}

bool StringList::currentExists()
{
	return current ? true : false;
}

bool StringList::contains(string word)
{
	for (Elem* temp = first; temp; temp = temp->next)
		if (!word.compare(temp->word))
			return true;
	return false;
}

void StringList::clear()
{
	while (first) {
		Elem* old = first;
		first = first->next;
		delete old;
	}
	first = nullptr;
	current = nullptr;
}

StringList::~StringList()
{
	clear();
}
