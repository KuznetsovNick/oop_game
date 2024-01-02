#include "save.h"

Save::Save(std::string file) : file(file) {}

void Save::save(Creator* creator) {
	std::vector<int> safe_list;
	std::ofstream file(this->file);

	file << creator->getField()->getHeight() << "\n";
	file << creator->getField()->getWidth() << "\n";
	
	safe_list.push_back(creator->getField()->getHeight());
	safe_list.push_back(creator->getField()->getWidth());

	for (int i = 0; i < creator->getField()->getHeight(); i++) {
		for (int j = 0; j < creator->getField()->getWidth(); j++) {
			file << creator->getField()->getCell(i, j)->getState() << "\n";
			safe_list.push_back(creator->getField()->getCell(i, j)->getState());
		}
	}
	std::pair pair = creator->getField()->getPlayerCoords();
	file << pair.first << "\n";
	safe_list.push_back(int(pair.first));
	file << pair.second << "\n";
	safe_list.push_back(int(pair.second));
	file << creator->getField()->getPlayer()->getCoins() << "\n";
	safe_list.push_back(creator->getField()->getPlayer()->getCoins());
	file << creator->getField()->getPlayer()->getHealth() << "\n";
	safe_list.push_back(creator->getField()->getPlayer()->getHealth());
	int hash = count_hash(safe_list);
	*creator->getHash() = hash;
	std::ofstream f ("hash.txt");
	f << hash;
	file.close();
}

int Save::count_hash(std::vector<int> safe_list) {
	int hash = 0;
	int x = X_HASH;
	for (int i = 0; i < safe_list.size(); i++) {
		hash = (hash + x * safe_list.at(i)) % P_HASH;
		x = x * X_HASH % P_HASH;
	}
	return hash;
}