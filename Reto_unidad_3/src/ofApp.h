#pragma once
#include "ofMain.h"
// Nodo de la cola
struct Node {
	float x, y;
	float radius;
	ofColor color;
	float opacity;
	Node * next;
	Node(float _x, float _y, float _radius, ofColor _color, float _opacity)
		: x(_x)
		, y(_y)
		, radius(_radius)
		, color(_color)
		, opacity(_opacity)
		, next(nullptr) { }
};
// Implementación manual de una cola (FIFO)
class BrushQueue {
public:
	Node * front;
	Node * rear;
	int size;
	int maxSize;
	BrushQueue(int _maxSize);
	~BrushQueue();
	void enqueue(float x, float y, float radius, ofColor color, float opacity);
	void dequeue();
	void clear();
	bool isEmpty();
};

// Constructor
BrushQueue::BrushQueue(int _maxSize)
	: front(nullptr)
	, rear(nullptr)
	, size(0)
	, maxSize(_maxSize) {}
// Destructor
BrushQueue::~BrushQueue() {
	clear();
}
// Implementa aquí `enqueue()`
void BrushQueue::enqueue(float x, float y, float radius, ofColor color, float opacity) {

	Node * newnode = new Node(x, y,radius,color,opacity);

	if (isEmpty) {
		front = newnode;
		rear = newnode;
	}
	else {
		rear->next = newnode;

		rear = newnode;
	}
	size++;

	if (size > maxSize) {
		dequeue();

	}



	// TODO: crear un nuevo nodo y agregarlo al final de la cola.
	// Si la cola supera `maxSize`, eliminar el nodo más antiguo con `dequeue()`.
}
// Implementa aquí `dequeue()`
void BrushQueue::dequeue() {

	if (isEmpty) {
		return;
	}
	else
	{
		Node* temp = front;

		while (temp->next != rear) {
			temp = temp->next;
		}
		delete rear;
		rear = temp;
		rear->next = nullptr;
	}
	size--;

	// TODO: eliminar el nodo más antiguo si la cola no está vacía.
}
// Implementa aquí `clear()`
void BrushQueue::clear() {
	Node* current = rear;
	while (current != nullptr) {
		Node* nextNode = current->next;
		delete current;
		current = nextNode;
	}
	front = rear = nullptr;
	size = 0;// TODO: eliminar todos los nodos de la cola.
}
// Implementa aquí `isEmpty()`
bool BrushQueue::isEmpty() {
	// TODO: retornar si la cola está vacía.
}

class ofApp : public ofBaseApp {
public:
	BrushQueue strokes; // Cola de trazos
	float backgroundHue = 0;
	ofApp()
		: strokes(50) { } // Tamaño máximo de la cola
	void setup();
	void update();
	void draw();
	void keyPressed(int key);
};
