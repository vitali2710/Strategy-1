#include "Map.h"
Map::Map(std::vector<std::vector<Tile>> map_data) {
	size_x = map_data.size();
	size_y = map_data[0].size();
	tile_array = map_data;
}
Map::Map(int size_X, int size_Y) {
	size_x = size_X;
	size_y = size_Y;
	std::vector<std::vector<Tile>> map_data;
	map_data.resize(size_x);
	for (int i = 1; i != size_x + 1; i++) {
		std::vector<Tile> v;
		v.resize(size_y);
		for (int j = 1; j != size_y + 1; j++) {
			v[j - 1] = Tile(i, j, plain);
		}
		map_data[i - 1] = v;
	}
	tile_array = map_data;
}
void Map::Print(std::ostream& out) {
	for (auto i = tile_array.begin(); i != tile_array.end(); i++) {
		for (auto j = (*i).begin(); j != (*i).end(); j++) {
			(*j).Print(out);
			if ((j + 1) != (*i).end()) out << " ";
		}
		out << "\n";
	}
}
int Map::Get_size_x() {
	return size_x;
}
int Map::Get_size_y() {
	return size_y;
}