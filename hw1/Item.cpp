#include "Item.h"


Item::Item():Object(){}
Item::Item(string name, int health, int attack, int defense):Object(name,"Item"){
	this->health = health;
	this->attack = attack;
	this->defense = defense;
}

bool Item::triggerEvent(Object* o) {
	Player* player = dynamic_cast<Player*>(o);
	cout << "Would you want to equip " << getName() << "(health:" << health << ",attack:" << attack << ",defense:" << defense << ") ?" << endl;
	cout << "A.YES \nB.NO" << endl;
	char answer;
	cin >> answer;
	cout << endl;
	if (answer == 'A'||answer=='a') {
		player->addItem(*this);
		player->increaseStates(health, attack, defense);
		return true;
	}
	else {
		return false;
	}
}

int Item::getHealth() {
	return health;
}
int Item::getAttack() {
	return attack;
}
int Item::getDefense() {
	return defense;
}
void Item::setHealth(int health) {
	this->health = health;
}
void Item::setAttack(int attack) {
	this->attack = attack;
}
void Item::setDefense(int defense) {
	this->defense = defense;
}