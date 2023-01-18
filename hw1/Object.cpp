#include "Object.h"


Object::Object(){}
Object::Object(string name, string tag):name(name),tag(tag){}


void Object::setName(string name) {
	this->name = name;
}


void Object::setTag(string tag) {
	this->tag = tag;
}


string Object::getName() {
	return name;
}


string Object::getTag() {
	return tag;
}
