#ifndef __SAVE_H__
#define __SAVE_H__
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include "Map.h"
class Save {
private:
	std::fstream save_file;
	std::string save_location;
	std::string save_name;
public:
	Save(std::string save_name, std::string save_location = "");
	void Save_Map(Map Data);
	std::vector<std::vector<Tile>> Load_Map();
	void Save_Delete();
	~Save();
};
#endif