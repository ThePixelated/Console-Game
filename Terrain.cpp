#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

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

// Generating the map - kinda used
inline std::vector<std::vector<char>> generate_map(int width, int height, int type) {
	std::vector<std::vector<char>> grid (height, std::vector<char>(width));

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			grid[i][j] = char(type);
		}
	}

	return grid;
}

// Kinda used
inline void ocean_map(std::vector<std::vector<char>> &arr) {
	std::string water = "-._.";

	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr[0].size(); j++) {
			arr[i][j] = water[j % 4];
		}
		
	}
}

// Not used
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
				map_file >> ch;
				std::cout << ch;

				//std::cout << int(ch) << " ";

				/*map_file >> arr[i][j];
				if (map_file.eof())
					break;*/
			}
		}
	}

	map_file.close();
	
	return arr;
}



inline void prints(std::vector<std::string> arr) {
	for (int i = 0; i < arr.size(); i++) {
		std::cout << arr[i] << std::endl;
	}
}

inline void print_map_default(std::vector<std::vector<char>> vec_map) {
	for (int i = 0; i < vec_map.size(); i++) {
		for (int j = 0; j < vec_map[i].size(); j++) {
			std::cout << vec_map[i][j];
		} std::cout << std::endl;
	}
}

inline std::string hash_converter(std::string text_str, std::map<char, char> dict) {
	for (int i = 0; i < text_str.size(); i++) {
		text_str[i] = dict[text_str[i]];
	}

	return text_str;
}

inline std::vector<std::string> encoder(std::map<char, char> dict_en) {
	std::vector<std::string> text;
	std::string inputs;

	for (int i = 0; i < 20; i++) {
		std::cin >> inputs;
		inputs = hash_converter(inputs, dict_en);
		text.push_back(inputs);
	}

	return text;
}

inline std::vector<std::string> decoder(std::map<char, char> dict_de) {
	std::vector<std::string> text;
	std::string inputs;

	for (int i = 0; i < 20; i++) {
		std::cin >> inputs;
		inputs = hash_converter(inputs, dict_de);
		text.push_back(inputs);
	}

	return text;
}

inline void save_map(std::vector<std::string> encode_text) {
	std::fstream my_file;
	my_file.open("Map_terrain\\MA_1.txt", std::ios::out);

	for (int i = 0; i < encode_text.size(); i++) {
		my_file << encode_text[i];
		my_file << "\n";
	}

	my_file.close();
}

inline std::vector<std::vector<char>> load_map(int width, int height, std::map<char, char> dict_de) {
	std::vector<std::vector<char>> map_section(height, std::vector<char>(width));

	std::fstream my_file;
	my_file.open("Map_terrain\\MA_1.txt", std::ios::in);

	char ch;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			my_file >> ch;
			//std::cout << ch << " " << dict_de[ch] << " " << char(dict_de[ch]) << " + " << j << "\n";
			map_section[i][j] = char(dict_de[ch]);
		} /*std::cout << "\n";*/
	}
	my_file.close();

	return map_section;
}
