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

	if (isEmpty()) {
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

	if (isEmpty()) {
		return;
	}

	Node* temp = front;

	front = front->next;

	delete temp;

	size--;

	if (front == nullptr) {
		rear = nullptr;
	}
}
// Implementa aquí `clear()`
void BrushQueue::clear() {
	Node* current = front;

	while (current != nullptr) {

		Node* nextNode = current->next;

		delete current;

		current = nextNode;
	}

	front = nullptr;
	rear = nullptr;
	size = 0;// TODO: eliminar todos los nodos de la cola.
}
// Implementa aquí `isEmpty()`
bool BrushQueue::isEmpty() {
		return front == nullptr;
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



#include "ofApp.h"
//--------------------------------------------------------------
void ofApp::setup() {
	ofBackground(0);
}
//--------------------------------------------------------------
void ofApp::update() {
	backgroundHue += 0.2;
	if (backgroundHue > 255)
		backgroundHue = 0;
	if (ofGetMousePressed()) {
		float x = ofGetMouseX();
		float y = ofGetMouseY();
		ofColor color;
		color.setHsb(ofRandom(255), 200, 255);

		strokes.enqueue(
			ofGetMouseX(),
			ofGetMouseY(),
			10,
			color,
			255);

	}
	// TODO: agregar un nuevo trazo si el mouse está presionado.
	// Usa strokes.enqueue(x, y, radius, color, opacity);
}
//--------------------------------------------------------------
void ofApp::draw() {
	// Fondo con gradiente dinámico
	ofColor color1, color2;
	color1.setHsb(backgroundHue, 150, 240);
	color2.setHsb(fmod(backgroundHue + 128, 255), 150, 240);
	ofBackgroundGradient(color1, color2, OF_GRADIENT_LINEAR);
	// TODO: dibujar los trazos almacenados en la cola.
	
	Node* current = strokes.front;

	while (current != nullptr) {

		ofSetColor(
			current->color.r,
			current->color.g,
			current->color.b,
			current->opacity
		);

		ofDrawCircle(
			current->x,
			current->y,
			current->radius
		);

		current = current->next;
	}
	// Recorre los nodos desde strokes.front hasta nullptr y usa ofDrawCircle().
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	if (key == 'c') {
		strokes.clear();
		// TODO: limpiar la cola de trazos.
	}
	if (key == 'a') {
		if (strokes.maxSize == 50)
			strokes.maxSize = 100;
		else
			strokes.maxSize = 50;

		while (strokes.size > strokes.maxSize) {
			strokes.dequeue();
		}
	} else if (key == 's') {
		ofSaveScreen("captura.png");
	}
}
