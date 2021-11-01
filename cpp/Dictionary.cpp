#include "Dictionary.h"

Dictionary::Dictionary()
{
	bst = nullptr;
}

Dictionary::Dictionary(StringList& keys, StringList& translations)
{
	bst = nullptr;
	keys.onFirst();
	translations.onFirst();
	while (keys.currentExists() && translations.currentExists()) {
		addPair(keys.getCurrent(), translations.getCurrent());
		keys.onNext();
		translations.onNext();
	}
}

bool Dictionary::wordExists(string& word)
{
	Node* temp = (Node*)bst;
	while (temp) {
		if (!word.compare(temp->key))
			return true;
		else if (word.compare(temp->key) > 0)
			temp = temp->right;
		else
			temp = temp->left;
	}
	return false;
}

StringList* Dictionary::getTranslations(string& word)
{
	if (!wordExists(word)) {
		cout << "There is no word " << word << " in dictionary" << endl;
		return nullptr;
	}
	Node* temp = (Node*)bst;
	while (temp) {
		if (!word.compare(temp->key))
			return &(temp->translations);
		else if (word.compare(temp->key) > 0)
			temp = temp->right;
		else
			temp = temp->left;
	}
	return nullptr;
}

bool Dictionary::pairExists(string& word, string& translation)
{
	if (!wordExists(word))
		return false;
	Node* temp = (Node*)bst;
	while (temp) {
		if (!word.compare(temp->key)) {
			return temp->translations.contains(translation);
		}
		else if (word.compare(temp->key) > 0)
			temp = temp->right;
		else
			temp = temp->left;
	}
	return false;
}

void Dictionary::addPair(string word, string translation)
{
	if (wordExists(word)) {
		if (pairExists(word, translation)) {
			cout << "Pair " << word << " " << translation << " is already in dictionary" << endl;
			return;
		}
		else {
			Node* temp = (Node*)bst;
			while (true) {
				if (!word.compare(temp->key))
					break;
				else if (word.compare(temp->key) > 0)
					temp = temp->right;
				else
					temp = temp->left;
			}
			temp->translations.add(translation);
		}
	}
	else {
		Node* insert = new Node(word, translation);
		Node* cur = (Node*)bst;
		Node* prev = nullptr;
		while (cur) {
			prev = cur;
			if (word.compare(cur->key) > 0)
				cur = cur->right;
			else
				cur = cur->left;
		}
		if (prev) {
			insert->parent = prev;
			if (word.compare(prev->key) > 0)
				prev->right = insert;
			else
				prev->left = insert;
		}
		else {
			bst = (Node*)insert;
		}
	}
}

void Dictionary::printWithPrefix(string prefix)
{
	bool found = false;
	if (bst == nullptr) {
		cout << "Dictionary is empty." << endl;
		return;
	}
	cout << "Words with prefix " << prefix << ":" << endl;
	Stack<Dictionary::Node*> stack;
	Dictionary::Node* next = (Node*)bst;
	while (true) {
		while (next) {
			stack.push(next);
			next = next->left;
		}
		if (!stack.empty()) {
			next = (Node*)stack.pop();
			size_t pos = next->key.find(prefix);
			if (pos == 0) {
				found = true;
				cout << "Word: " << next->key << " Translations:";
				next->translations.onFirst();
				while (next->translations.currentExists()) {
					cout << " " << next->translations.getCurrent();
					next->translations.onNext();
				}
				cout << endl;
			}
			next = next->right;
		}
		else {
			if (!found)
				cout << "Nothing found" << endl;
			return;
		}
	}
}

void Dictionary::removeWord(string& word)
{
	if (wordExists(word)) {
		Node* p = bst;
		while (p->key.compare(word)) {
			if (word.compare(p->key) > 0)
				p = p->right;
			else
				p = p->left;
		}
		Node* q = p->parent;
		Node* rp;
		if (p->left == nullptr)
			rp = p->right;
		else if (p->right == nullptr)
			rp = p->left;
		else {
			Node* f = p;
			rp = p->right;
			Node* s = rp->left;
			while (s) {
				f = rp;
				rp = s;
				s = rp->left;
			}
			if (f != p) {
				f->left = rp->right;
				rp->right = p->right;
			}
			rp->left = p->left;
			p->left->parent = rp;
		}
		if (q == nullptr) {
			bst = rp;
		}
		else if (p == q->left) {
			q->left = rp;

		}
		else {
			q->right = rp;
		}
		if (rp) rp->parent = q;
		delete p;
	}
}

void Dictionary::emptyDictionary()
{
	while (bst) {
		removeWord(bst->key);
	}
	bst = nullptr;
}

void Dictionary::ispis()
{
	if (bst == nullptr) {
		cout << "Dictionary is empty." << endl;
		return;
	}
	cout << "Dictionary:" << endl;
	Stack<Dictionary::Node*> stack;
	Dictionary::Node* next = (Node*)bst;
	while (true) {
		while (next) {
			stack.push(next);
			next = next->left;
		}
		if (!stack.empty()) {
			next = (Node*)stack.pop();
			cout << "Word: " << next->key << " Translations:";
			next->translations.onFirst();
			while (next->translations.currentExists()) {
				cout << " " << next->translations.getCurrent();
				next->translations.onNext();
			}
			cout << endl;
			next = next->right;
		}
		else {
			return;
		}
	}
}

Dictionary::~Dictionary()
{
	emptyDictionary();
}

ostream& operator<<(ostream& os, const Dictionary& d)
{
	if (d.bst == nullptr) {
		os << "Dictionary is empty." << endl;
		return os;
	}
	os << "Dictionary:" << endl;
	Stack<Dictionary::Node*> stack;
	Dictionary::Node* next = (Dictionary::Node*)(d.bst);
	while (true) {
		while (next) {
			stack.push(next);
			next = next->left;
		}
		if (!stack.empty()) {
			next = (Dictionary::Node*)(stack.pop());
			os << "Word: " << next->key << " Translations:";
			next->translations.onFirst();
			while (next->translations.currentExists()) {
				os << " " << next->translations.getCurrent();
				next->translations.onNext();
			}
			cout << endl;
			next = next->right;
		}
		else {
			return os;
		}
	}
	return os;
}

Dictionary::Node::Node(string k, string t)
{
	key = k;
	translations.add(t);
	left = nullptr;
	right = nullptr;
	parent = nullptr;
}


