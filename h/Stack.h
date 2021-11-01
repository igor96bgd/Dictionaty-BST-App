#pragma once
template <typename T>
class Stack
{
	struct Elem {
	public:
		T data;
		Elem* next;
		Elem(T d) {
			data = d;
			next = nullptr;
		}
	};
	Elem* first;
public:
	Stack() :first(nullptr) {}
	void push(T data) {
		Elem* temp = new Elem(data);
		temp->next = first;
		first = temp;
	}
	T pop() {
		Elem* temp = first;
		first = first->next;
		T data = temp->data;
		delete temp;
		return data;
	}
	bool empty() {
		return first ? false : true;
	}
	~Stack() {
		while (first) {
			Elem* old = first;
			first = first->next;
			delete old;
		}
		first = nullptr;
	}
};



