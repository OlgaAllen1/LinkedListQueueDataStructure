#include <iostream>
#include <string>
using namespace std; 

struct Node {
	string data;
	Node* next;
	Node(const string& str) : data(str), next(nullptr) {}
};

class Queue {
private:
	Node* front;
	Node* back;
	int count;
public: 
	// Constructor
	Queue() : front(nullptr), back(nullptr), count(0) {}

	// Destructor
	~Queue() {
		while (!isEmpty()) {
			dequeue();
		}
	}

	void enqueue(const string& data) {
		Node* newNode = new Node(data);
		if (isEmpty()) {
			front = back = newNode;
		}
		else {
			back->next = newNode;
			back = newNode;
		}
		count++;
	}
	
	void dequeue() {
		if (isEmpty()) {
			// Error if queue is empty
			cout << "The queue is empty." << endl;
			return;
		}

		Node* temp = front;
		front = front->next;
		delete temp;
		count--;

		if (isEmpty()) {
			// If the queue is empty after dequeueing, set back to nullptr
			back = nullptr;
		}
	}


	string peek() {
		if (isEmpty()) {
			return ""; // Return an empty string if the queue is empty
		}
		return front->data;
	}

	bool isEmpty() {
		return count == 0;
	}

	int size() {
		return count;
	}

	void print() {
		if (isEmpty()) {
			cout << "The queue is empty." << endl;
		}
		else {
			Node* temp = front;
			while (temp != nullptr) {
				cout << "[ " << temp->data << " ] ";
				temp = temp->next;
			}
			cout << endl;
		}
	}
};

int main() {
	Queue queue;
	queue.print();
	// Queue with one node
	queue.enqueue("Apple");
	cout << queue.size() << " item(s): ";
	queue.print();
	// Removing one node; queue becomes empty
	queue.dequeue();
	queue.print();
	// Trying to dequeue from empty (no crash)
	queue.dequeue();
	// Trying to peek empty queue (no crash)
	cout << queue.peek();
	// Adding three nodes
	queue.enqueue("Banana");
	queue.enqueue("Cherry");
	queue.enqueue("Date");
	cout << queue.size() << " item(s): ";
	queue.print();
	// Removing one node
	queue.dequeue();
	cout << queue.size() << " item(s): ";
	queue.print();
	// Adding one additional node
	queue.enqueue("Elderberry");
	cout << queue.size() << " item(s): ";
	queue.print();
	// Peeking first node
	cout << "Peek: " << queue.peek() << endl;
}