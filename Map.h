#ifndef __FIELD_H__ 
#define __FIELD_H__
#include <vector>
#include <iostream>
#include <fstream>
#include "Tile.h"
class Map {
private:
	std::vector<std::vector<Tile>> tile_array;
	int size_x;
	int size_y;
public:
	Map(int size_X, int size_Y);
	Map(std::vector<std::vector<Tile>> map_data);
	void Print(std::ostream& out = std::cout);
	int Get_size_x();
	int Get_size_y();
};
#endif