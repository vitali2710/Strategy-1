#include "Tile.h"
Tile::Tile(int pos_x, int pos_y, tile_type pos_type) {
	x = pos_x;
	y = pos_y;
	type = pos_type;
}
void Tile::Print(std::ostream& out) {
	out << type;
}