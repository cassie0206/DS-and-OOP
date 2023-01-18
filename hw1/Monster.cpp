#include "Monster.h"


Monster::Monster():GameCharacter(){}
Monster::Monster(string name, int maxHealth, int currentHealth, int attack,int defense):GameCharacter(name,"Monster",maxHealth,currentHealth,attack,defense){}


bool Monster::triggerEvent(Object* o) {
	Player* player = dynamic_cast<Player*>(o);
	cout << "What do you want to do?" << endl;
	cout << "A.Fight with " << getName() << "(health:" << getCurrentHealth() << "/" << getMaxHealth() << ",attack:" << getAttack() << ",defense:" << getDefense() << ")" << endl;
	cout << "B.Retreat\nC.Check status\n";
	char answer;
	cin >> answer;
	cout << endl;
	
	if (answer == 'A' || answer == 'a') {
		while (getCurrentHealth() > 0 && player->getCurrentHealth() > 0) {
			cout << "Choose Action:\n";
			cout << "A.Attack " << getName() << endl;
			cout << "B.Retreat\n";
			cin >> answer;
			if (answer == 'A' || answer == 'a') {
				cout << "You choose to attack!\n";
				cout << "Your attack does " << player->getAttack() << " damage.\n";
				player->takeDamage(getAttack());
				if (checkIsDead()) {
					cout << "You beat " << getName() << endl;
					return true;
				}
				else {
					cout << "The" << getName() << "'s attack does " << getAttack() << " damage.\n";
					takeDamage(player->getAttack());
					if (player->checkIsDead()) {
						cout << "You are DEAD! " ;
						exit(1);
					}
					else {
						cout << "You now have " << player->getCurrentHealth() << " health." << endl;
						cout << endl;
					}
					
				}
			}
			else if (answer == 'B' || answer == 'b') {
				player->changeRoom(player->getPreviousRoom());
				break;
			}
		}		
	}
	else if (answer == 'B' || answer == 'b') {
		player->changeRoom(player->getPreviousRoom());
	}
	else {
		player->triggerEvent(player);
		cout << endl;
		cout << "What do you want to do?" << endl;
		cout << "A.Fight  B.Retreat" << endl;
		if (answer == 'A' || answer == 'a') {
			while (getCurrentHealth() > 0 && player->getCurrentHealth() > 0) {
				cout << "Choose Action:\n";
				cout << "A.Attack " << getName() << endl;
				cout << "B.Retreat\n";
				cin >> answer;
				if (answer == 'A' || answer == 'a') {
					cout << "You choose to attack!\n";
					cout << "Your attack does " << player->getAttack() << " damage.\n";
					player->takeDamage(getAttack());
					if (checkIsDead()) {
						cout << "You beat " << getName() << endl;
						return true;
					}
					else {
						cout << "The" << getName() << "'s attack does " << getAttack() << " damage.\n";
						takeDamage(player->getAttack());
						if (player->checkIsDead()) {
							cout << "You are DEAD! ";
							exit(1);
						}
						else {
							cout << "You now have " << player->getCurrentHealth() << " health." << endl;
							cout << endl;
						}

					}
				}
				else {
					player->changeRoom(player->getPreviousRoom());
				}
			}
		}
		else if (answer == 'B' || answer == 'b') {
			player->changeRoom(player->getPreviousRoom());
		}
	}

}
