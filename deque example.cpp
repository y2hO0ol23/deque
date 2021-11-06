#include <iostream>
#include "deque.h"

using namespace std;

int main() {
	stack<int> st;
	queue<int> q;
	deque<int> dq;
	for (int i = 0; i < 10; i++) {
		st.push(i);
		q.push(i);

		if (i % 2) dq.push_back(i);
		else dq.push_front(i);
	}
	cout << "stack" << endl;
	while (!st.empty()) {
		cout << st.pop() << endl;
	}
	cout << "queue" << endl;
	while (!q.empty()) {
		cout << q.pop() << endl;
	}
	cout << "deque" << endl;
	while (!dq.empty()) {
		cout << dq.pop_back() << endl;
	}
}