#pragma once
#include <string>
#include <fstream>
#include "creator.h"


class Save {
private:
	std::string file;
	int count_hash(std::vector<int> load_list);
public:
	Save(std::string file);
	void save(Creator* creator);
};