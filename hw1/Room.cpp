#include "Room.h"

Room::Room(){}
Room::Room(bool isExist, int index, vector<Object*> object) :isExit(isExist), index(index), objects(object) {
	upRoom = NULL;
	downRoom = NULL;
	leftRoom = NULL;
	rightRoom = NULL;
}

/*bool Room::popObject(Object* o) {

}*/

void Room::setUpRoom(Room* r) {
	upRoom = r;
}
void Room::setDownRoom(Room* r) {
	downRoom = r;
}
void Room::setLeftRoom(Room* r) {
	leftRoom = r;
}
void Room::setRightRoom(Room* r) {
	rightRoom = r;
}
void Room::setIsExit(bool isExist) {
	this->isExit = isExist;
}
void Room::setIndex(int index) {
	this->index = index;
}
void Room::setObjects(vector<Object*> o) {
	objects = o;
}
bool Room::getIsExit() {
	return isExit;
}
int Room::getIndex() {
	return index;
}
vector<Object*> Room::getObjects() {
	return objects;
}
Room* Room::getUpRoom() {
	return upRoom;
}
Room* Room::getDownRoom() {
	return downRoom;
}
Room* Room::getLeftRoom() {
	return leftRoom;
}
Room* Room::getRightRoom() {
	return rightRoom;
}