#include "Dungeon.h"


Dungeon::Dungeon() {};

void Dungeon::createPlayer() {
	cout << "Please enter player's name:\n";
	string name;
	cin >> name;
	cout << endl;
	cout << "Choose your character:\n";
	cout << "A.清新小口愛(health:100/100,attack:10,defense:0)\nB.黑化白蓮花(health:200/200,attack:50,defense:20)\nC.頂配高級綠茶(health:300/300,attack:80,defense:50)\n";
	char answer;
	cin >> answer;
	cout << endl;
	/*switch (answer) {
	case 'A':case 'a':
		player = Player(name, 100, 100, 10, 0); break;
	case 'B':case 'b':
		player = Player(name, 200, 200, 50, 20); break;
	case 'C':case 'c':
		player = Player(name, 300, 300, 80, 50); break;
	}*/
	if (answer == 'A' || answer == 'a') {
		player = Player(name, 100, 100, 10, 0);
		//this->player = player;
	}
	else if (answer == 'B' || answer == 'b') {
		player = Player(name, 200, 200, 50, 20);
		//this->player = player;
	}
	else if (answer == 'C' || answer == 'c') {
		player = Player(name, 300, 300, 80, 50);
		//this->player = player;
	}

}

void Dungeon::createMap() {
	//r.reserve(7);
	vector<Object*> o0, o1, o2, o3, o4, o5, o6, o7;

	Item* a = new Item("green tea bag", 10, 20, 10);
	Item* b = new Item("black tea bag", 20, 30, 0);
	Item* j = new Item("oolong tea bag", 30, 10, 20);
	Item* k = new Item("oriental Beauty tea bag", 40, 0, 20);
	o1.push_back(a);
	o1.push_back(b);
	o1.push_back(j);
	o1.push_back(k);
	Monster* c = new Monster("鑒婊達人", 200, 200, 10, 0);
	o2.push_back(c);
	vector<Item> commodity1;
	commodity1.push_back(*a);
	commodity1.push_back(*b);
	NPC* d = new NPC("waiter", "Do I have the pleasure to make tea for you?", commodity1);
	o3.push_back(d);
	Monster* e = new Monster("楚楚口憐小綠茶", 100, 100, 30, 0);
	o4.push_back(e);
	Monster* f = new Monster("盛世農夫山泉水", 200, 200, 40, 20);
	o6.push_back(f);
	vector<Item> fish;
	Item* h = new Item("安康魚", 50, 20, 0);
	Item* i = new Item("沉魚", 70, 20, 10);
	fish.push_back(*h);
	fish.push_back(*i);
	NPC* g = new NPC("魚塘管理員", "歡迎來這裡釣魚以提升您的綠茶功力，請問您想釣魚嗎？", fish);
	o5.push_back(g);

	r.push_back(Room(true, 0, o0));
	r.push_back(Room(true, 1, o1));
	r.push_back(Room(true, 3, o2));
	r.push_back(Room(true, 2, o3));
	r.push_back(Room(true, 4, o4));
	r.push_back(Room(true, 5, o5));
	r.push_back(Room(false, 6, o6));
	r.push_back(Room(true, 7, o7));
	
	r[0].setUpRoom(r[1].getDownRoom());
	r[1].setDownRoom(r[0].getUpRoom());
	//r[1].setRightRoom(r[2].getLeftRoom());
	//r[2].setLeftRoom(r[1].getRightRoom());
	r[2].setRightRoom(r[1].getLeftRoom());
	r[2].setLeftRoom(r[3].getRightRoom());
	r[1].setLeftRoom(r[2].getRightRoom());
	r[3].setLeftRoom(r[2].getRightRoom());
	r[1].setUpRoom(r[4].getDownRoom());
	r[4].setDownRoom(r[1].getUpRoom());
	r[4].setRightRoom(r[5].getLeftRoom());
	r[5].setLeftRoom(r[4].getRightRoom());
	r[6].setUpRoom(r[7].getDownRoom());
	r[7].setDownRoom(r[6].getUpRoom());
	r[5].setUpRoom(r[6].getDownRoom());
	r[6].setDownRoom(r[5].getUpRoom());

	player.setCurrentRoom(&r[0]);
	
}

void Dungeon::handleMovement() {
	char answer;
	switch (player.getCurrentRoom()->getIndex()) {
	case 0:
		cout << "Where do you want to go?" << endl;
		cout << "A.Go up \nB.save game progress and logout" << endl;
		cin >> answer;
		cout << endl;
		if (answer == 'A' || answer == 'a') {
			player.setCurrentRoom(&r[1]);
			player.setPreviousRoom(&r[0]);
		}
		break;
	case 1:
		cout << "Where do you want to go?" << endl;
		cout << "A.Go up \nB.Go down \nC.Go left \nD.save game progress and logout" << endl;
		cin >> answer;
		cout << endl;
		if (answer == 'A'||answer=='a') {
			player.setCurrentRoom(&r[4]);
			player.setPreviousRoom(&r[1]);
		}
		else if (answer == 'B' || answer == 'b') {
			player.setCurrentRoom(&r[0]);
			player.setPreviousRoom(&r[1]);
		}
		else if (answer == 'C' || answer == 'c') {
			player.setCurrentRoom(&r[3]);
			player.setPreviousRoom(&r[1]);
		}
		else if (answer == 'D' || answer == 'd') {
			Record record;
			record.saveToFile(&player, r);
			exit(1);
		}
		break;
	case 2:
		cout << "Where do you want to go?" << endl;
		cout << "A.Go left\nB.Go right \nC.save game progress and logout\n" << endl;
		cin >> answer;
		cout << endl;
		if (answer == 'A' || answer == 'a') {
			player.setCurrentRoom(&r[2]);
			player.setPreviousRoom(&r[3]);
		}
		else if (answer == 'B' || answer == 'b') {
			player.setCurrentRoom(&r[1]);
			player.setPreviousRoom(&r[3]);
		}
		else if (answer == 'C' || answer == 'c') {
			Record record;
			record.saveToFile(&player, r);
			exit(1);
		}
		break;
	case 3:
		cout << "Where do you want to go?" << endl;
		cout << "A.Go right \nB.save game progress and logout" << endl;
		cin >> answer;
		cout << endl;
		if (answer == 'A' || answer == 'a') {
			player.setCurrentRoom(&r[3]);
			player.setPreviousRoom(&r[2]);
		}
		else if (answer == 'B' || answer == 'b') {
			Record record;
			record.saveToFile(&player, r);
			exit(1);
		}
		break;
	case 4:
		cout << "Where do you want to go?" << endl;
		cout << "A.Go down \nB.Go right \nC.save game progress and logout" << endl;
		cin >> answer;
		cout << endl;
		if (answer == 'A' || answer == 'a') {
			player.setCurrentRoom(&r[1]);
			player.setPreviousRoom(&r[4]);
		}
		else if (answer == 'B' || answer == 'b') {
			player.setCurrentRoom(&r[5]);
			player.setPreviousRoom(&r[4]);
		}
		else if (answer == 'C' || answer == 'c') {
			Record record;
			record.saveToFile(&player, r);
			exit(1);
		}
		break;
	case 5:
		cout << "Where do you want to go?" << endl;
		cout << "A.Go up\nB.save game progress and logout" << endl;
		cin >> answer;
		cout << endl;
		if (answer == 'A' || answer == 'a') {
			player.setCurrentRoom(&r[6]);
			player.setPreviousRoom(&r[5]);
		}
		else if (answer == 'B' || answer == 'b') {
			Record record;
			record.saveToFile(&player, r);
			exit(1);
		}
		break;
	case 6:
		cout << "Where do you want to go?" << endl;
		cout << "A.Go up\nB.save game progress and logout" << endl;
		cin >> answer;
		cout << endl;
		if (answer == 'A' || answer == 'a') {
			player.setCurrentRoom(&r[7]);
			player.setPreviousRoom(&r[6]);
		}
		else if (answer == 'B' || answer == 'b') {
			Record record;
			record.saveToFile(&player, r);
			exit(1);
		}
		break;
	case 7:
		cout << "恭喜妳成為地表最強綠茶！" << endl;
		exit(1);

	}
}
/*void Dungeon::handleMovement() {
	Room* first = &r[0];
	Room* current = first;
	cout << "Where do you want to go?" << endl;
	
	char answer;
	cin >> answer;
	switch (answer) {
	case 'A':case 'a':
		current = current->getUpRoom(); break;
	case 'B':case 'b':
		current = current->getDownRoom(); break;
	case 'C':case 'c':
		current = current->getLeftRoom(); break;
	case 'D':case 'd':
		current = current->getRightRoom(); break;
	}

	int u = 0, d = 0, r = 0, l = 0, sum = 0;
	if (current->getUpRoom() == NULL) {
		u = -1;
	}
	else {
		u = 1;
	}
	if (current->getDownRoom() == NULL) {
		d = -1;
	}
	else {
		d = 1;
	}
	if (current->getLeftRoom() == NULL) {
		l = -1;
	}
	else {
		l = 1;
	}
	if (current->getRightRoom() == NULL) {
		r = -1;
	}
	else {
		r = 1;
	}
	


	if (current->getUpRoom() != NULL) {
		cout << "A.Go up\n";
	}
	if (current->getDownRoom() != NULL && current->getUpRoom() != NULL) {
		cout << "B.Go down\n";
	}
	if (current->getDownRoom() != NULL && current->getUpRoom() == NULL) {
		cout << "A.Go down\n";
	}
	sum = u * d;
	if (current->getLeftRoom() != NULL && current->getDownRoom() != NULL && current->getUpRoom() != NULL) {
		cout << "C.Go left\n";
	}
	if (current->getLeftRoom() != NULL && sum == 1) {
		cout << "A.Go left\n";
	}
	if (current->getLeftRoom() != NULL && sum == -1) {
		cout << "B.Go left\n";
	}
	sum = u * d * l;
	if (current->getRightRoom() != NULL && current->getLeftRoom() != NULL && current->getDownRoom() != NULL && current->getUpRoom() != NULL) {
		cout << "D.Go left\n";
	}
	if (current->getRightRoom() != NULL && current->getLeftRoom() == NULL && current->getDownRoom() == NULL && current->getUpRoom() == NULL) {
		cout << "A.Go left\n";
	}
	if (current->getLeftRoom() != NULL && sum == 1) {
		cout << "B.Go left\n";
	}
	if (current->getLeftRoom() != NULL && sum == -1) {
		cout << "C.Go left\n";
	}

	char answer;
	cin >> answer;




}*/



void Dungeon::handleEvent(Object* o) {
	Item* item = dynamic_cast<Item*>(o);
	Monster* monster = dynamic_cast<Monster*>(o);
	NPC* npc = dynamic_cast<NPC*>(o);

	if (item) {
		item->triggerEvent(&player);

	}
	if (monster) {
		if (monster->getCurrentHealth() <= 0) {
			cout << monster->getName() << "被妳打敗了！妳的綠茶功力更上一層了！\n" << endl;
			return handleMovement();
		}
		else{
			!monster->triggerEvent(&player);
		}
	}
	if (npc) {
		npc->triggerEvent(&player);
	}
	return chooseAction(player.getCurrentRoom()->getObjects());

}

void Dungeon::startGame() {
	cout << "Do you want to load previous data?\n";
	cout << "A.Yes\nB.No. Start new game.\n";
	char answer;
	cin >> answer;
	cout << endl;
	switch (answer) {
	case 'B':case 'b':
		createPlayer();
		createMap();
		break;
	case 'A':case 'a':
		createMap();
		Record record;
		//Player player;
		record.loadFromFile(&player, r);
		//cout << player.getName();
		break;
	}
	
}

void Dungeon::chooseAction(vector<Object*> o) {
	if (o.empty()) {
		cout << "What do you want to do?\n";
		cout << "A.Move\nB.Check Status\nC.Save to File\n";
		char answer;
		cin >> answer;
		cout << endl;
		switch (answer) {
		case 'A':case 'a':
			handleMovement(); break;
		case 'B':case 'b':
			player.triggerEvent(&player); break;
		case 'C':case 'c':
			Record record;
			record.saveToFile(&player, r); break;
		}

	}
	else if (!o.empty()) {
		Monster* monster = dynamic_cast<Monster*>(o[0]);
		NPC* npc = dynamic_cast<NPC*>(o[0]);
		if (o.size() == 4) {
			Item* item_0 = dynamic_cast<Item*>(o[0]);
			Item* item_1 = dynamic_cast<Item*>(o[1]);
			Item* item_2 = dynamic_cast<Item*>(o[2]);
			Item* item_3 = dynamic_cast<Item*>(o[3]);
			if (item_3 && item_2 && item_1 && item_0) {
				cout << "What do you want to do?\n";
				cout << "A.Move\nB.Check Status\nC.Open the chest\nD.Save to File\n";
				char answer;
				cin >> answer;
				cout << endl;
				int min, max, x;
				switch (answer) {
				case 'A':case 'a':
					handleMovement(); break;
				case 'B':case 'b':
					player.triggerEvent(&player); break;
				case 'C':case 'c':
					min = 0;
					max = 3;
					x = rand() % (max - min + 1) + min;
					switch (x) {
					case 0:
						handleEvent(player.getCurrentRoom()->getObjects()[0]); break;
					case 1:
						handleEvent(player.getCurrentRoom()->getObjects()[1]); break;
					case 2:
						handleEvent(player.getCurrentRoom()->getObjects()[2]); break;
					case 3:
						handleEvent(player.getCurrentRoom()->getObjects()[3]); break;
					}
				case 'D':case 'd':
					Record record;
					record.saveToFile(&player, r); break;
				}
			}
		}


		
		if (monster) {
			handleEvent(player.getCurrentRoom()->getObjects()[0]);
		}
		if (npc) {
			cout << "What do you want to do?\n";
			cout << "A.Move\nB.Check Status\n";
			cout<<"C.Talk to " << npc->getName() << endl;
			cout<<"D.Save to File\n";
			char answer;
			cin >> answer;
			cout << endl; 
			switch (answer) {
			case 'A':case 'a':
				handleMovement(); break;
			case 'B':case 'b':
				player.triggerEvent(&player); break;
			case 'C':case 'c':
				handleEvent(player.getCurrentRoom()->getObjects()[0]);
			case 'D':case 'd':
				Record record;
				record.saveToFile(&player, r); break;
			}
		}



		cout << endl;
	}
	
}

bool Dungeon::checkGameLogic() {
	//Monster* monster = dynamic_cast<Monster*>(player.getCurrentRoom()->getObjects()[0]);
	if (player.checkIsDead()) {
		return false;
	}
	else {
		return true;
	}
}


void Dungeon::runDungeon() {
	startGame();
	while (checkGameLogic()) {
		chooseAction(player.getCurrentRoom()->getObjects());
	}
}
