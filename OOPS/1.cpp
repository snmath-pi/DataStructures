// class: (user defined data type);
// object: instance of class
// include "Hero.cpp" // can also create new cpp
#include<iostream>
using namespace std;

class Hero {
public:
	// some properties of class Hero
	char name[100];
	static int time;
// private:
	int health;
	// constructor 
	Hero() {
		cout << "Constructor called\n";
	} 

	// Parameterized Constructor
	Hero(int health) {
		// this -> a pointer that points to current object
		cout << this << ' ';
		this->health = health;
	}
	Hero(int health, int level) {
		this->health = health;
		this->level = level;
	}
	// Hero(Hero &temp) {
	// 	this->health = temp.health;
	// 	this->level = temp.level;
	// }
private:
	int level;
public:
	void print() {
		cout << this->level << ' ' << this->health << '\n'; // no error here even it's private
	}

	int getHealth() {
		return health;
	}
	int getlevel() {
		return level;
	}

	void setHealth(int h) {
		health = h;
	}

	void setlevel(int l) {
		level = l;
	}
	~Hero() {
		cout << "Destroy" << '\n';
	}
};


class Test {
public:
	int a; int b;
	// Test(int i, int j) : a(i), b(j) {
	// 	cout << "Constructor executed\n";
	// }
	// Test(int i, int j) : a(i), b(i+j) {
	// 	cout << a << ' ' << b << '\n';
	// 	cout << "Constructor executed\n";
	// }
	Test(int i, int j) : a(i), b(a*j) {
		cout << a << ' ' << b << '\n';

		cout << "Constructor executed\n";
	}
};
int Hero::time = 5;

int main() {

	// Hero hero;
	// 1.
	// cout << sizeof(hero) << '\n'; 
	// 100 + 4(int)  + 4(int)
	// for empty class object gets 1 byte of memory allocated for its identification
	// to keep it's track


	// 2.
	// access is through '.' operator
	// cout << hero.health  << '\n'; // garbage value
	// 3. access modifiers
	// public, private, protected
	// By default it's private
	// i. Public: can be accessed anywhere in the code inside the class or outside the class too.
	// ii. Private: can *only* be accessed inside the class itself!
	// cout << hero.level << '\n'; -> Error


	// hero.health = 10, hero.level = 20;
	// cout << hero.health << ' ' << hero.level << '\n';

	// *** Getter and Setters 
	// if I make health as private I won't be able to set it to 10

	// To set and Get
	// hero.setHealth(5);
	// cout << hero.getHealth() << '\n';
	// hero.setlevel(10);
	// cout << hero.getlevel() << '\n';
	// cout << hero.getHealth() << ' ' << hero.getlevel() << '\n'; // no issue with it being private


	// static vs dynamic allocation
	// static allocation
	// Hero a;
	// a.setlevel(5);
	// a.health = 10;
	// cout << a.getlevel() << '\n';
	// cout << a.health << '\n';
	// // dynmically alloction;
	// Hero *b = new Hero();
	// (*b).health = 12;
	// (*b).setlevel(10);
	// cout << (*b).getlevel() << '\n';
	// cout << (*b).health << '\n';
	// b->setlevel(10);
	// cout << b->getlevel() << '\n';
	// b->health = 20;
	// cout << b->health << '\n';

	// Constructor
	// Whenever an object is created it's invoked
	// it has no return type
	// created by default hero.Hero() -> default constructor

	// cout << "Hi "; Hero u;
	// Hero *y = new Hero();



	// Parametirized constructor
	// Hero some(5);
	// cout << &some << '\n';


	// copy constructor

	// Hero suresh(10, 20);
	// Hero ritesh(suresh);
	// suresh.print();
	// ritesh.print();


	// Shallow and Deep Copy
	// Default copy constructor does shallow copy



	//Destructor -> memory deallocaiton
	// // no parameter, no return type same as class name
	// Hero a;
	// Hero *b = new Hero();

	// only static location -> destructor called automatically
	// but dynamic allocation -> destructor has to be called manually
	// delete b;


	// Test t(5, 10);

	// Static Keyword
	cout << Hero::time << '\n';

	return 0;
}
