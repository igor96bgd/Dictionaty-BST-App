#include <iostream>
#include <string>

#include "StringList.h"
#include "Dictionary.h"

using namespace std;



void zadatak1() {


	Dictionary* dic = nullptr;
	int option;
	int done;
	string word, translation;
	StringList keys;
	StringList translations;
	StringList* translations1 = nullptr;
	do {
		cout << "MENU" << endl;
		cout << "1 - Create dictionary" << endl;
		cout << "2 - Get translations for word" << endl;
		cout << "3 - Insert new pair" << endl;
		cout << "4 - Print dictionary" << endl;
		cout << "5 - Print dictionary(with prefix)" << endl;
		cout << "6 - Delete key" << endl;
		cout << "7 - Delete dictionary" << endl;
		cout << "0 - Close program" << endl;
		cout << "Your choice: ";
		cin >> option;
		switch (option) {
		case 1:
			if (dic)
				cout << "Error: Dictionary is already created!" << endl;
			else {
				while (true) {
					cout << "Enter word(key): ";
					cin >> word;
					cout << "Enter translation: ";
					cin >> translation;
					keys.add(word);
					translations.add(translation);
					cout << "Enter 0 if you are finnished: ";
					cin >> done;
					if (!done) break;
				}
				dic = new Dictionary(keys, translations);
				keys.clear();
				translations.clear();
			}
			break;
		case 2:
			if (!dic) {
				cout << "Dictionary doesnt exist" << endl;
				break;
			}
			cout << "Enter word(key): ";
			cin >> word;
			translations1 = dic->getTranslations(word);
			if (!translations1) {
				cout << "There are no translations available" << endl;
				break;
			}
			translations1->onFirst();
			if (dic->wordExists(word)) {
				cout << "Translations for word " << word << ":" << endl;
				while (translations1->currentExists()) {
					cout << translations1->getCurrent() << " ";
					translations1->onNext();
				}
				cout << endl;
			}
			break;
		case 3:
			if (!dic) {
				cout << "Dictionary doesnt exist" << endl;
				break;
			}
			cout << "Enter word: ";
			cin >> word;
			cout << "Enter translation: ";
			cin >> translation;
			dic->addPair(word, translation);
			break;
		case 4:
			if (dic)
				cout << (*dic);
			else
				cout << "Dictionary doesnt exist" << endl;
			break;
		case 5:
			if (!dic) {
				cout << "Dictionary doesnt exist" << endl;
				break;
			}
			cout << "Enter prefix: ";
			cin >> word;
			dic->printWithPrefix(word);
			break;
		case 6:
			if (!dic) {
				cout << "Dictionary doesnt exist" << endl;
				break;
			}
			cout << "Enter word(key) you want to delete: ";
			cin >> word;
			dic->removeWord(word);
			break;
		case 7:
			if (!dic) {
				cout << "Dictionary doesnt exist" << endl;
				break;
			}
			delete dic;
			dic = nullptr;
			break;
		case 0:
			break;
		default:
			cout << "Invalid command!" << endl;
			break;
		}
	} while (option != 0);

	if (dic) {
		delete dic;
		dic = nullptr;
	}
	if (translations1) {
		delete translations1;
		translations1 = nullptr;
	}
}