#include "GameCharacter.h"

GameCharacter::GameCharacter():Object(){}

GameCharacter::GameCharacter(string name, string tag, int maxHealth,int currentHealth, int attack, int defense) :Object(name, tag),maxHealth(maxHealth), currentHealth(currentHealth),attack(attack),defense(defense){}
bool GameCharacter::checkIsDead() {
	if (currentHealth<=0) {
		return true;
	}
	else{
		return false;
	}
}

int GameCharacter::takeDamage(int damage) {
	if ((damage - defense) > 0) {
		currentHealth = currentHealth - (damage - defense);
	}
	return currentHealth;
}

void GameCharacter::setMaxHealth(int max_health) {
	maxHealth = max_health;
}

void GameCharacter::setCurrentHealth(int current_health) {
	currentHealth = current_health;
}

void GameCharacter::setAttack(int attack) {
	this->attack = attack;
}

void GameCharacter::setDefense(int defense) {
	this->defense = defense;
}

int GameCharacter::getMaxHealth() {
	return maxHealth;
}

int GameCharacter::getCurrentHealth() {
	return currentHealth;
}

int GameCharacter::getAttack() {
	return attack;
}
int GameCharacter::getDefense() {
	return defense;
}