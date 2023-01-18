#include "Player.h"


Player::Player():GameCharacter(){}
Player::Player(string name, int maxHealth, int currentHealth, int attack,int defense):GameCharacter(name,"Player",maxHealth,currentHealth,attack,defense){}

void Player::addItem(Item i) {
    inventory.push_back(i);
}
void Player::increaseStates(int currentHealth, int attack, int defense) {
    if (getMaxHealth()-(getCurrentHealth() + currentHealth)>0) {
        setCurrentHealth(getCurrentHealth() + currentHealth);
    }
    setAttack(getAttack() + attack);
    setDefense(getDefense() + defense);
}
void Player::changeRoom(Room* goal_room) {
    previousRoom = currentRoom;
    currentRoom = goal_room;
}

                         
bool Player::triggerEvent(Object* o) {
    Player* player = dynamic_cast<Player*>(o);
    cout << "Status:\n";
    cout << "[" << getName() << "]" << endl;
    cout << ">Health: " << getCurrentHealth() << "/" << getMaxHealth() << endl;
    cout << ">Attack: " << getAttack() << endl;
    cout << ">Defense: " << getDefense() << endl;
    cout << ">Current Room: " << getCurrentRoom()->getIndex() << endl;
    return true;
}


void Player::setCurrentRoom(Room* r) {
    currentRoom = r;
}
void Player::setPreviousRoom(Room* r) {
    previousRoom = r;
}
void Player::setInventory(vector<Item> i) {
    inventory = i;
}
Room* Player::getCurrentRoom() {
    return currentRoom;
}
Room* Player::getPreviousRoom() {
    return previousRoom;
}
vector<Item> Player::getInventory() {
    return inventory;
}