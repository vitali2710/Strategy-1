#ifndef __TILE_H__ 
#define __TILE_H__
#include <iostream>
#include <fstream>
enum tile_type { plain, forest, mountain, lake, river_horizontal, river_vertical, river_bridge_horizontal, river_bridge_vertical };
class Tile {
private:
	int x;
	int y;
	tile_type type;
public:
	Tile(int pos_x = 0, int pos_y = 0, tile_type pos_type = plain);
	void Print(std::ostream& out = std::cout);
};
#endif