#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

void prints(std::vector<std::string> arr) {
	for (int i = 0; i < arr.size(); i++) {
		std::cout << arr[i] << std::endl;
	}
}

void print_Map(std::vector<std::vector<char>> vec_map) {
	for (int i = 0; i < vec_map.size(); i++) {
		for (int j = 0; j < vec_map[i].size(); j++) {
			std::cout << vec_map[i][j];
		} std::cout << std::endl;
	}
}

std::string hash_converter(std::string text_str, std::map<char, char> dict) {
	for (int i = 0; i < text_str.size(); i++) {
		text_str[i] = dict[text_str[i]];
	}

	return text_str;
}

std::vector<std::string> encoder(std::map<char, char> dict_en) {
	std::vector<std::string> text;
	std::string inputs;

	for (int i = 0; i < 20; i++) {
		std::cin >> inputs;
		inputs = hash_converter(inputs, dict_en);
		text.push_back(inputs);
	}

	return text;
}

std::vector<std::string> decoder(std::map<char, char> dict_de) {
	std::vector<std::string> text;
	std::string inputs;

	for (int i = 0; i < 20; i++) {
		std::cin >> inputs;
		inputs = hash_converter(inputs, dict_de);
		text.push_back(inputs);
	}

	return text;
}

void save_map(std::vector<std::string> encode_text) {
	std::fstream my_file;
	my_file.open("map_A1.txt", std::ios::out);
	
	for (int i = 0; i < encode_text.size(); i++) {
		my_file << encode_text[i];
		my_file << "\n";
	}

	my_file.close();
}

std::vector<std::vector<char>> load_map(int width, int height, std::map<char,char> dict_de) {
	std::vector<std::vector<char>> map_section(height, std::vector<char>(width));

	std::fstream my_file;
	my_file.open("map_A1.txt", std::ios::in);

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

int main() {
	std::vector<std::string> text_encoder;
	std::vector<std::string> text_decoder;
	std::string text_mp;

	std::map<char, char> mp_encode = {
		{45, 'A'},
		{46, 'B'},
		{95, 'C'},
		{176, 'D'},
		{124, 'E'},
		{223, 'F'},
		{218, 'G'},
		{217, 'H'},
		{192, 'I'}
	};

	std::map<char, char> mp_decode = {
		{'A', 45},
		{'B', 46},
		{'C', 95},
		{'D', 176},
		{'E', 124},
		{'F', 223},
		{'G', 218},
		{'H', 217},
		{'I', 192}
	};

	text_encoder = encoder(mp_encode);
	std::cout << std::endl;

	save_map(text_encoder);

	print_Map(load_map(80, 20, mp_decode));
	
	//prints(text_encoder);
	//std::cout << std::endl << std::endl;;

	//text_decoder = decoder(mp_decode);
	//std::cout << std::endl;

	//prints(text_decoder);
	//std::cout << std::endl;


	//for (int i = 0; i < 9; i++) {
	//	text_mp += " ";
	//	std::cin >> text_mp[i];
	//}

	//for (int i = 0; i < 9; i++) {
	//	std::cout << "{'" << char(65 + i) << "', ";
	//	if (int(text_mp[i]) < 0) {
	//		std::cout << int(char(text_mp[i])) + 256 << "},\n";
	//		//std::cout << "{" << int(char(text[i])) + 256 << ", '" << char(65 + i) << "'},\n";
	//		continue;
	//	}

	//	std::cout << int(char(text_mp[i])) << "},\n";
	//	//std::cout << "{" << int(char(text[i])) << ", '" << char(65 + i) << "'},\n";
	//}

	return 0;
}


//using namespace std;
//
//int main() {
//	fstream my_file;
//	my_file.open("my_file.txt", ios::out);
//	if (!my_file) {
//		cout << "File not created!";
//	}
//	else {
//		cout << "File created successfully!";
//		my_file << "░░░░░░░";
//		my_file.close();
//	}
//	return 0;
//}

//#include <iostream>
//#include <vector>
//
//void x_axis(int* x_coor) {
//	*x_coor = 9999;
//}
//
//void arrays(std::vector<int>* arr) {
//	/**arr;*/
//	for (int i = 0; i < 9; i++) {
//		arr -> push_back(i+1);
//	}
//
//	arr -> at(5) = 12312;
//}
//
//void print(std::vector<int> arrays) {
//
//	for (int j = 0; j < arrays.size(); j++) {
//		std::cout << arrays[j] << " ";
//	}
//}
//
//int main() {
//	std::vector<int> arr = { 5 };
//
//	int x_coordinate = 5;
//	int y_coordinate = 3;
//
//	std::cout << arr.at(0) << "\n";
//
//	x_axis(&x_coordinate);
//
//	arrays(&arr);
//
//	//std::cout << arr[0] << "\n";
//	//std::cout << arr[1] << "\n";
//
//	print(arr); std::cout << "\n";
//
//	//std::cout << x_coordinate << "\n";
//	return 0;
//}

//#include <iostream>
//#include <limits>
//
//int main() {
//	int var;
//
//	for (int i = 0; i < 10; i++) {
//		if (!(std::cin >> var)) {
//			std::cout << "valid" << std::endl;
//			std::cin.clear();
//			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//			break;
//		}
//	}
//
//	std::cin >> var;
//
//	//std::cout << var;
//
//	return 0;
//}

//#include <iostream>
//
//int main() {
//	int size = 1;
//	unsigned long long* arr = new unsigned long long[size];
//
//	long sums = 0;
//
//	for (int i = 0; i < 100; i++) {
//		std::cout << arr[i] << std::endl;
//		sums += arr[i];
//		size++;
//	}
//
//	std::cout << "\n" << sums << "\n" << /*random()*/ /*<<*/ "\n";
//
//	return 0;
//}

//#include <iostream>
//#include <conio.h>
//
//int main() {
//	int size = 0;
//	int indexs[10];
//
//	int arr[] = {10, 23, 7, 5, 23, 19, 10, 4, 23};
//	
//	for (int i = 0; i < 9; i++) {
//		std::cout << "Test " << i << std::endl;
//
//		if (arr[i] != 23) {
//			continue;
//		}
//
//		indexs[size] = i;
//		std::cout << indexs[size] << " - ";
//
//		size++;
//	}
//
//	std::cout << "\n";
//
//	return 0;
//}