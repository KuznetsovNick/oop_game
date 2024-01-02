#pragma once
#include <string>
#include <fstream>
#include "creator.h"
#include "fileExc.h"
#include "fieldExc.h"
#include "hashExc.h"
#include "fileDec.h"
#include "fieldDec.h"
#include "hashDec.h"


class Download {
private:
	std::string file;
	void accept_download(Creator* creator, std::vector<int> load_list);
	int count_hash(std::vector<int> load_list);
public:
	Download(std::string file);
	void download(Creator* creator);
};