#pragma once

template <class T> class deque;
template <class T> class node;

template <class T>
class node {
	friend class deque<T>;
private:
	T data;
	node<T>* next; // 다음
	node<T>* prev; // 이전
};

template <class T>
class deque {
private:
	node<T>* head = nullptr; // 시작
	node<T>* tail = nullptr; // 끝
	int deque_size = 0;
	node<T>* make_new_node(T value);
public:
	deque() {}
	~deque();
	void push_back(T value);
	void push_front(T value);
	T front();
	T back();
	T pop_back();
	T pop_front();
	int size();
	bool empty();
};

template <class T>
class stack {
private:
	deque<T> data;
public:
	void push(T value) {
		return data.push_back(value);
	}
	T pop() {
		return data.pop_back();
	}
	int size() {
		return data.size();
	}
	bool empty() {
		return data.empty();
	}
	int top() {
		return data.back();
	}
};

template <class T>
class queue {
private:
	deque<T> data;
public:
	void push(T value) {
		return data.push_back(value);
	}
	T pop() {
		return data.pop_front();
	}
	int size() {
		return data.size();
	}
	bool empty() {
		return data.empty();
	}
	int front() {
		return data.front();
	}
};

template <class T> deque<T>::~deque() {
	while (!this->empty()) this->pop_back();
}
template <class T> node<T>* deque<T>::make_new_node(T value) {
	node<T>* new_node = (node<T>*)calloc(1, sizeof(node<T>));
	new_node->data = value;
	new_node->next = nullptr;
	new_node->prev = nullptr;
	this->deque_size++;

	return new_node;
}
template <class T> void deque<T>::push_back(T value) {
	node<T>* new_node = this->make_new_node(value);
	new_node->prev = this->tail;
	if (this->tail != nullptr) this->tail->next = new_node;
	this->tail = new_node;
	if (this->head == nullptr) this->head = new_node;
}
template <class T> void deque<T>::push_front(T value) {
	node<T>* new_node = this->make_new_node(value);
	new_node->next = this->head;
	if(this->head != nullptr) this->head->prev = new_node;
	this->head = new_node;
	if (this->tail == nullptr) this->tail = new_node;
}

template <class T> T deque<T>::back() {
	if (this->empty()) throw "no data in deque";
	return this->tail->data;
}
template <class T> T deque<T>::front() {
	if (this->empty()) throw "no data in deque";
	return this->head->data;
}

template <class T> T deque<T>::pop_back() {
	if (this->empty()) throw "no data in deque";
	int ret = this->tail->data;
	node<T>* temp = this->tail->prev;
	free(this->tail);
	this->tail = temp;
	this->deque_size--;
	if(this->deque_size > 0) this->tail->next = nullptr;
	return ret;
}
template <class T> T deque<T>::pop_front() {
	if (this->empty()) throw "no data in deque";
	int ret = this->head->data;
	node<T>* temp = this->head->next;
	free(this->head);
	this->head = temp;
	this->deque_size--;
	if (this->deque_size > 0) this->tail->next = nullptr;
	return ret;
}

template <class T> int deque<T>::size() {
	return this->deque_size;
}
template <class T> bool deque<T>::empty() {
	return (this->deque_size == 0);
}

