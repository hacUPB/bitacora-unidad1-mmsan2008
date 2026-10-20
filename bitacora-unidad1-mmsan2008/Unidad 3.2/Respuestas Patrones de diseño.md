# ¿Cómo puedes interactuar con la aplicación? Menciona específicamente las teclas y qué efecto parecen tener sobre las partículas.
se puede interactuar con las teclas s,a,r,n 
S: para el movimiento de las particulas 
A: hace como la funcion de un iman i atrae las particulas a donde este el mause 
R: repele las particulas y estas se alejan de donde este el mouse
N: hace que vuelva a movimiento por defecto de las particulas 

# ¿Observas los diferentes tipos de “partículas”? ¿Se comportan todas igual inicialmente?
las particulas se comportan igual todas van a la misma velocidad y revotan en las paredes de igual manera la unica diferencia es su color y tamaño 
siendo rojo mas pequeño verde medianas azules mas grandes
# Toma algunas capturas de pantalla de la aplicación en diferentes momentos (estado inicial, después de presionar ‘a’, ‘r’, ‘s’, ‘n’) y añádelas a tu bitácora.
# N
<img width="1015" height="752" alt="image" src="https://github.com/user-attachments/assets/d9f8f186-0f38-4cb2-9566-748a0e75d439" />
# S 
<img width="1017" height="764" alt="image" src="https://github.com/user-attachments/assets/ab627500-2f48-4128-9add-1f25f6aa70f8" />
# A 
<img width="796" height="594" alt="image" src="https://github.com/user-attachments/assets/c98fc7e9-c328-4ad4-be41-5c806d39b92d" />
# R
<img width="1014" height="759" alt="image" src="https://github.com/user-attachments/assets/3c0383ab-463b-4ca1-aa03-9361cf72a939" />

# ¿Qué crees que está pasando “detrás de cámaras” cuando presionas las teclas? Formula una hipótesis inicial sobre cómo la aplicación cambia el comportamiento de las partículas.
yo creo que cada ves que presiono n s a o r el programa cambia de estado al estado asignado a cada tecla y estos estados son clases y sub clases


# Explica con tus propias palabras el propósito del patrón Observer. ¿Qué problema resuelve?
el patron obeserver permite mediante una subscripcion notificar a varios objetos un evento que se este llamando 

# Dibuja un diagrama que muestre la relación entre `Subject`, `Observer`, `ofApp` y `Particle` en el caso de estudio, indicando quién es el Sujeto y quiénes los Observadores.

<img width="836" height="1194" alt="diagrama" src="https://github.com/user-attachments/assets/1944ed10-5ea3-4bc1-b6e5-728c6848e938" />

# Construye un diagrama de secuencia que muestre cómo funciona el patrón Observer al presionar una tecla.

<img width="900" height="790" alt="image" src="https://github.com/user-attachments/assets/ca0b50aa-26e0-487c-8808-c99f1e151da8" />

# ¿Qué ventajas crees que ofrece usar el patrón Observer en esta aplicación en comparación con, por ejemplo, que `ofApp::update` recorriera todas las partículas y les dijera directamente que cambien su comportamiento basado en una variable global? Piensa en términos de acoplamiento y extensibilidad.
## actividad 12
<img width="1018" height="758" alt="image" src="https://github.com/user-attachments/assets/ce587a20-aadb-4862-bb56-9a0d6e8f57c6" />

```
## codigo 

#include "ofApp.h"
#include <algorithm>
void Subject::addObserver(Observer* observer) {
	if (!observer) return;
	if (std::find(observers.begin(), observers.end(), observer) == observers.end()) {
		observers.push_back(observer);
	}
}

void Subject::removeObserver(Observer* observer) {
	if (!observer) return;
	observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}
void Subject::notify(const std::string& event) {
	for (Observer* observer : observers) {
		observer->onNotify(event);
	}
}
Particle::Particle() : state(nullptr) {
	position = ofVec2f(ofRandomWidth(), ofRandomHeight());
	velocity = ofVec2f(ofRandom(-0.5f, 0.5f), ofRandom(-0.5f, 0.5f));
	size = ofRandom(2.0f, 5.0f);
	color = ofColor(255);
	state = new NormalState();
	state->onEnter(this);
}

Particle::~Particle() {
	if (state) {
		state->onExit(this);
		delete state;
		state = nullptr;
	}
}
void Particle::setState(State* newState) {
	if (state) {
		state->onExit(this);
		delete state;
	}
	state = newState;
	if (state) {
		state->onEnter(this);
	}
}
void Particle::update() {
	if (state) {
		state->update(this);
	}
	keepInsideWindow();
}
void Particle::draw() {
	ofPushStyle();
	ofSetColor(color);
	ofDrawCircle(position, size);
	ofPopStyle();
}
void Particle::onNotify(const std::string& event) {
	if (event == "attract") {
		setState(new AttractState());
	}
	else if (event == "repel") {
		setState(new RepelState());
	}
	else if (event == "stop") {
		setState(new StopState());
	}
	else if (event == "normal") {
		setState(new NormalState());
	}
}
void Particle::keepInsideWindow() {
	const float W = static_cast<float>(ofGetWidth());
	const float H = static_cast<float>(ofGetHeight());
	if (position.x < 0.0f) {
		position.x = 0.0f;
		velocity.x *= -1.0f;
	}
	else if (position.x > W) {
		position.x = W;
		velocity.x *= -1.0f;
	}
	if (position.y < 0.0f) {
		position.y = 0.0f;
		velocity.y *= -1.0f;
	}
	else if (position.y > H) {
		position.y = H;
		velocity.y *= -1.0f;
	}
}
void NormalState::onEnter(Particle* particle) {
	particle->velocity.set(ofRandom(-0.5f, 0.5f), ofRandom(-0.5f, 0.5f));
}
void NormalState::update(Particle* particle) {
	particle->position += particle->velocity;
}
static void steer(Particle* particle, const ofVec2f& toward, float accel, float vmax, float posScale) {
	ofVec2f dir = toward - particle->position;
	float len = dir.length();
	if (len > 1e-6f) {
		dir /= len;
		particle->velocity += dir * accel;
	}
	particle->velocity.limit(vmax);
	particle->position += particle->velocity * posScale;
}
void AttractState::update(Particle* particle) {
	ofVec2f mouse(ofGetMouseX(), ofGetMouseY());
	steer(particle, mouse, /*accel*/ 0.05f, /*vmax*/ 3.0f, /*posScale*/ 0.2f);
}
void RepelState::update(Particle* particle) {
	ofVec2f mouse(ofGetMouseX(), ofGetMouseY());
	ofVec2f away = particle->position - mouse;
	float len = away.length();
	if (len > 1e-6f) {
		away /= len;
		particle->velocity += away * 0.05f;
	}
	particle->velocity.limit(3.0f);
	particle->position += particle->velocity * 0.2f;
}
void StopState::update(Particle* particle) {
	particle->velocity *= 0.80f;
	if (particle->velocity.lengthSquared() < 1e-4f) {
		particle->velocity.set(0.0f, 0.0f);
	}
	particle->position += particle->velocity;
}
Particle* ParticleFactory::createParticle(const std::string& type) {
	Particle* particle = new Particle();
	if (type == "star") {
		particle->size = ofRandom(2.0f, 4.0f);
		particle->color = ofColor(255, 0, 0);
	}
	else if (type == "shooting_star") {
		particle->size = ofRandom(3.0f, 6.0f);
		particle->color = ofColor(0, 255, 0);
		particle->velocity *= 3.0f;
	}
	else if (type == "planet") {
		particle->size = ofRandom(5.0f, 8.0f);
		particle->color = ofColor(0, 0, 255);
	}
	else if (type == "ball") {
		particle->size = ofRandom(5.0f, 6.0f);
		particle->color = ofColor(255, 255, 255);
		particle->velocity *= 20.0f;
	}
	return particle;
}
ofApp::~ofApp() {
	for (Particle* p : particles) {
		removeObserver(p);
		delete p;
	}
	particles.clear();
}
void ofApp::setup() {
	ofBackground(0);
	particles.reserve(100 + 5 + 10);
	for (int i = 0; i < 100; ++i) {
		Particle* p = ParticleFactory::createParticle("star");
		particles.push_back(p);
		//addObserver(p);
	}
	for (int i = 0; i < 5; ++i) {
		Particle* p = ParticleFactory::createParticle("shooting_star");
		particles.push_back(p);
		addObserver(p);
	}
	for (int i = 0; i < 10; ++i) {
		Particle* p = ParticleFactory::createParticle("planet");
		particles.push_back(p);
		addObserver(p);
	}
	for (int i = 0; i < 20; ++i) {
		Particle* p = ParticleFactory::createParticle("ball");
		particles.push_back(p);
		addObserver(p);
	}
}
void ofApp::update() {
	for (Particle* p : particles) {
		p->update();
	}
}
void ofApp::draw() {
	for (Particle* p : particles) {
		p->draw();
	}
}
void ofApp::keyPressed(int key) {
	switch (key) {
	case 's':
		notify("stop");
		break;
	case 'a':
		notify("attract");
		break;
	case 'r':
		notify("repel");
		break;
	case 'n':
		notify("normal");
		break;
	default:
		break;
	}
}
```

2. en el particle factory cree una nueva particula llamada ball con atributtos diferentes
3. el patron observers se  implementa de igual manera que en las otras particulas al crearla esta notifica al observer y la llama
4. se crea el nuevo estado en este caso se llaman todos al mismo tiempo que empieza la ejecucion
