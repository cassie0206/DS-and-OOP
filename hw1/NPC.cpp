#include "NPC.h"

NPC::NPC():GameCharacter(){}
NPC::NPC(string name, string script, vector<Item> commodity) :GameCharacter(name, "NPC",0,0,0,0) {
	this->script = script;
	this->commodity = commodity;
}

void NPC::listCommodity() {
	for (int i = 0; i < commodity.size(); i++) {
		cout << commodity[i].getName() << " ";
	}
}

bool NPC::triggerEvent(Object* o) {
	Player* player = dynamic_cast<Player*>(o);
	/*for (int i = 0; i < commodity.size(); i++) {
		cout << getScript() << endl;
		cout << "A." << commodity[i].getName() << "(health:" << commodity[i].getHealth() << ",attack:" << commodity[i].getAttack() << ",defense:" << commodity[i].getDefense() << ") " << endl;
		cout << "B.No,thanks." << endl;
		char answer;
		cin >> answer;
		cout << endl;
		if (answer == 'A' || answer == 'a') {
			player->addItem(commodity[i]);
			player->increaseStates(commodity[i].getHealth(), commodity[i].getAttack(), commodity[i].getDefense());
		}
		else {
			return false;
		}
	}*/
	cout << getScript() << endl;
	cout << "A.YES\nB.NO\n";
	char answer;
	cin >> answer;
	cout << endl;
	char low;
	low = 'a';
	char c;
	c = 'A';
	switch (answer) {
	case 'A':case'a':
		cout << "We have:";
		for (int i = 0; i < getCommodity().size(); i++) {
			c = c + i;
			cout <<c<< "."<<getCommodity()[i].getName()<< "(health:" << getCommodity()[i].getHealth() << ",attack:" << getCommodity()[i].getAttack() << ",defense:" << getCommodity()[i].getDefense() << ") "  << " ";
		}cout << endl;
		c = 'A';
		cout << "Which one do you want?" << endl;
		cin >> answer;
		cout << endl;
		for (int i = 0; i < getCommodity().size(); i++) {
			c += i;
			low += i;
			if (c == answer||low==answer) {
				player->addItem(commodity[i]);
				player->increaseStates(commodity[i].getHealth(), commodity[i].getAttack(), commodity[i].getDefense());
			}
		}
	case 'B':case 'b':
		return false;
	}

	
	return true;
}

void NPC::setScript(string script) {
	this->script = script;
}

void NPC::setCommodity(vector<Item> commodity) {
	this->commodity = commodity;
}

string NPC::getScript() {
	return script;
}

vector<Item> NPC:: getCommodity() {
	return commodity;
}