#include "download.h"

Download::Download(std::string file) : file(file) {}

void Download::download(Creator* creator) {
	std::vector<int> load_list;
	std::ifstream file(this->file);

	if (!file.is_open()) {
		throw FileDecorator(new FileExc(this->file));
	}

	std::string h, w, x_player, y_player, coins, hearts;

	std::getline(file, h);
	std::getline(file, w);
	load_list.push_back(std::stoi(h));
	load_list.push_back(std::stoi(w));

	if (std::stoi(h) < 3 || std::stoi(w) < 3) {
		throw FieldDecorator(new FieldExc(std::stoi(h), std::stoi(w)));
	}

	std::string cur;
	for (int i = 0; i < std::stoi(h); i++) {
		for (int j = 0; j < std::stoi(w); j++) {
			std::getline(file, cur);
			load_list.push_back(std::stoi(cur));
		}
	}
	std::getline(file, y_player);
	load_list.push_back(std::stoi(y_player));
	std::getline(file, x_player);
	load_list.push_back(std::stoi(x_player));
	std::getline(file, coins);
	load_list.push_back(std::stoi(coins));
	std::getline(file, hearts);
	load_list.push_back(std::stoi(hearts));

	int hash = count_hash(load_list);
	if (*creator->getHash() != hash) {
		throw HashDecorator(new HashExc(hash));
	}

	file.close();
	accept_download(creator, load_list);
}

void Download::accept_download(Creator* creator, std::vector<int> load_list){
	creator->getField()->resizeField(load_list.at(0), load_list.at(1));
	int cur = 2;
	for (int i = 0; i < load_list.at(0); i++) {
		for (int j = 0; j < load_list.at(1); j++) {
			if (creator->getField()->getCell(i, j)->getState() != static_cast<Cell::STATES>(load_list.at(cur))) {
				creator->getField()->makeCell(static_cast<Cell::STATES>(load_list.at(cur)), i, j);
			}
			cur++;
		}
	}
	int y = load_list.at(cur);
	cur++;
	int x = load_list.at(cur); 
	cur++;

	creator->getField()->setPlayerCoords(y, x);
	creator->getField()->getPlayer()->setCoins(load_list.at(cur)); 
	cur++;
	creator->getField()->getPlayer()->setHealth(load_list.at(cur));
	cur++;

}

int Download::count_hash(std::vector<int> load_list){
	int hash = 0;
	int x = X_HASH;
	for (int i = 0; i < load_list.size(); i++) {
		hash = (hash + x * load_list.at(i)) % P_HASH;
		x = x * X_HASH % P_HASH;
	}
	return hash;
}


// После исключения не загружать
// Информативные ошибки
// Под каждую ошибку свой класс