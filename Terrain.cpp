#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// Print out the map
inline void print_map(std::vector<std::vector<char>> arr) {
	std::cout << "\n\t.--------------------------------------------------------------------------------.\n";
	for (int i = 0; i < arr.size(); i++) {
		std::cout << "\t|";
		for (int j = 0; j < arr[i].size(); j++) {
			std::cout << arr[i][j];
		} std::cout << "|\n";
	} std::cout << "\t'--------------------------------------------------------------------------------'\n";
}

// Generating the map
inline std::vector<std::vector<char>> map(int width, int height, int type) {
	std::vector<std::vector<char>> grid (height, std::vector<char>(width));

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			grid[i][j] = char(type);
		}
	}

	return grid;
}

inline void ocean_map(std::vector<std::vector<char>> &arr) {
	std::string water = "-._.";

	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr[0].size(); j++) {
			arr[i][j] = water[j % 4];
		}
		
	}
}

inline std::vector<std::vector<char>> f_load_map(unsigned short width, unsigned short height) {
	std::vector<std::vector<char>> arr(height, std::vector<char>(width));

	std::fstream map_file;
	std::string file_direct = "MA_1.txt";

	map_file.open("Map_terrain\\MA_1.txt");
	if (!map_file) {
		std::cout << "No such file";
	}
	else {
		char ch;

		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				//map_file >> ch;

				//std::cout << int(ch) << " ";

				map_file >> arr[i][j];
				if (map_file.eof())
					break;
			}
		}
	}

	map_file.close();
	
	return arr;
}
