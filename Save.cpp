#include "Save.h"
Save::Save(std::string save_n, std::string save_loc) {
	std::ifstream read;
	read.open(save_loc + save_n + ".txt");
	if (!read.is_open()) {
		std::ofstream write;
		write.open(save_loc + save_n + ".txt");
		write.close();
	}
	read.close();
	save_file.open(save_loc + save_n + ".txt", std::fstream::in | std::fstream::out);
	save_location = save_loc;
	save_name = save_n;
}
void Save::Save_Map(Map Data) {
	std::ofstream write;
	write.open(save_location + save_name + ".txt");
	write << Data.Get_size_x() << "\n";
	write << Data.Get_size_y() << "\n";
	Data.Print(write);
	write.close();
}
std::vector<std::vector<Tile>> Save::Load_Map() {
	int size_x = save_file.get() - 48;
	save_file.get();
	int size_y = save_file.get() - 48;
	save_file.get();
	std::vector<std::vector<Tile>> map_data;
	map_data.resize(size_x);
	for (int i = 1; i != size_x + 1; i++) {
		std::vector<Tile> v;
		v.resize(size_y);
		for (int j = 1; j != size_y + 1; j++) {
			v[j - 1] = Tile(i, j, tile_type(save_file.get() - 48));
			save_file.get();
		}
		map_data[i - 1] = v;
	}
	save_file.seekg(0);
	return map_data;
}
void Save::Save_Delete() {
	std::string str = save_location + save_name + ".txt";
	save_file.close();
	const char * c = str.c_str();
	remove(c);
}
Save::~Save() {
	if (save_file.is_open()) save_file.close();
}