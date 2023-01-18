#include "Record.h"
#include<stdio.h>
using namespace std;
Record::Record() {};

//int Record::count = 0;
void Record::savePlayer(Player* player, ofstream& fplayer) {
	fplayer << player->getName() << endl;
	fplayer << player->getMaxHealth() << endl;
	fplayer << player->getCurrentHealth() << endl;
	fplayer << player->getAttack() << endl;
	fplayer << player->getDefense() << endl;
	fplayer << player->getCurrentRoom()->getIndex() << endl;
	fplayer << player->getPreviousRoom()->getIndex() << endl;
	//fplayer << player->getDefense() << endl;
	int size;
	size = player->getInventory().size();
	fplayer << size << endl;
	if (!player->getInventory().empty()) {
		for (int i = 0; i < size; i++) {
			fplayer << player->getInventory()[i].getName() << endl;
			fplayer << player->getInventory()[i].getHealth() << endl;
			fplayer << player->getInventory()[i].getAttack() << endl;
			fplayer << player->getInventory()[i].getDefense() << endl;
			//count++;
		}
	}
}

void Record::saveRooms(vector<Room>& r, ofstream& fr) {
	Monster* monster2 = dynamic_cast<Monster*>(r[2].getObjects()[0]);
	Monster* monster4 = dynamic_cast<Monster*>(r[4].getObjects()[0]);
	Monster* monster6 = dynamic_cast<Monster*>(r[6].getObjects()[0]);
	fr << monster2->getCurrentHealth() << endl;
	fr << monster4->getCurrentHealth() << endl;
	fr << monster6->getCurrentHealth() << endl;
}

void Record::loadPlayer(Player* player, ifstream& fplayer) {
	string name, commodity_name;
	vector<Item> commodity;
	Item commodity_item;
	int size,maxhealth,currenthealth, attack, defense, index, commodity_health, commodity_attack, commodity_defense;
	fplayer >> name;
	fplayer >> maxhealth;
	fplayer >> currenthealth;
	fplayer >> attack;
	fplayer >> defense;
	fplayer >> index;
	/*for (int i = 0; i < count; i++) {
		fplayer >> commodity_name;
		fplayer >> commodity_health;
		fplayer >> commodity_attack;
		fplayer >> commodity_defense;
		commodity_item.setName(commodity_name);
		commodity_item.setHealth(commodity_health);
		commodity_item.setAttack(commodity_attack);
		commodity_item.setDefense(commodity_defense);
		commodity.push_back(commodity_item);
	}*/
	player->setName(name);
	player->setCurrentHealth(currenthealth);
	player->setAttack(attack);
	player->setDefense(defense);
	player->setInventory(commodity);
}

void Record::loadRooms(vector<Room>& r, ifstream& fr) {
	int monster2_currentHealth, monster4_currentHealth, monster6_currentHealth;
	fr >> monster2_currentHealth;
	fr >> monster4_currentHealth;
	fr >> monster6_currentHealth;
	Monster* monster2 = dynamic_cast<Monster*>(r[2].getObjects()[0]);
	Monster* monster4 = dynamic_cast<Monster*>(r[4].getObjects()[0]);
	Monster* monster6 = dynamic_cast<Monster*>(r[6].getObjects()[0]);
	monster2->setCurrentHealth(monster2_currentHealth);
	monster4->setCurrentHealth(monster4_currentHealth);
	monster6->setCurrentHealth(monster6_currentHealth);
}


void Record::saveToFile(Player* player, vector<Room>& r) {
	ofstream fplayer("record_player.txt");
	ofstream fr("record_rooms.txt");
	Record::savePlayer(player, fplayer);
	Record::saveRooms(r, fr);
}

void Record::loadFromFile(Player* player, vector<Room>& r) {
	ifstream fplayer("record_player.txt");
	ifstream fr("record_rooms.txt");
	string name, commodity_name;
	int index_1,size,currentHealth, attack, defense, index, maxHealth, commodity_health, commodity_attack, commodity_defense;
	Item commodity_item;
	vector<Item> commodity;
	fplayer >> name;
	fplayer >> maxHealth;
	fplayer >> currentHealth;
	fplayer >> attack;
	fplayer >> defense;
	fplayer >> index;
	fplayer >> index_1;
	fplayer >> size;
	Record::loadRooms(r, fr);
	//Record::loadPlayer(player, fplayer);
	player->setName(name);
	player->setCurrentHealth(currentHealth);
	player->setMaxHealth(maxHealth);
	player->setAttack(attack);
	player->setDefense(defense);
	player->setCurrentRoom(&r[index]);
	player->setPreviousRoom(&r[index_1]);
	for (int i = 0; i < size; i++) {
		fplayer >> commodity_name;
		fplayer >> commodity_health;
		fplayer >> commodity_attack;
		fplayer >> commodity_defense;
		commodity_item.setName(commodity_name);
		commodity_item.setHealth(commodity_health);
		commodity_item.setAttack(commodity_attack);
		commodity_item.setDefense(commodity_defense);
		commodity.push_back(commodity_item);
	}
	player->setInventory(commodity);
}