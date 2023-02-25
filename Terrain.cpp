#include <iostream>
#include <string>
#include <vector>

inline void print_map(std::vector<std::vector<char>> arr) {
	std::cout << "\n";
	for (int i = 0; i < arr.size(); i++) {
		std::cout << "\t";
		for (int j = 0; j < arr[i].size(); j++) {
			std::cout << arr[i][j];
		} std::cout << "\n";
	}
}

inline std::vector<std::vector<char>> map(int width, int height, int type) {
	std::vector<std::vector<char>> grid (height, std::vector<char>(width));

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			grid[i][j] = char(type);
		}
	}

	return grid;
}

inline void ocean_map(std::vector<int>* arr) {
	std::string water = "-._.";

	//for (int i = 0; i < arr.size(); i++) {

	//}
}