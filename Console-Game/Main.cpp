#include <conio.h>
#include "Terrain.cpp"

//std::vector<std::vector<char>> map(int width, int height, int type);
//void print_map(std::vector<int> arr);
//void ocean_map(std::vector<std::vector<char>>& arr);

int main() {
	//std::vector<std::string> text_encoder;
	//std::vector<std::string> text_decoder;
	//std::string text_mp;

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

	/*text_encoder = encoder(mp_encode);
	std::cout << std::endl;

	save_map(text_encoder);*/

	print_map(load_map(80, 20, mp_decode));


	//std::vector<std::vector<char>> map_grid1 = f_load_map(80, 20);
	//std::vector<std::vector<char>> map_grid2 = generate_map(80, 20, 176);

	//print_map(map_grid);
	//ocean_map(map_grid);
	//print_map(map_grid1);
	//print_map(map_grid2);

	//std::cout << "test";

	//std::cout << map_grid[0][0];

	//int test[2][3] = {{1,2,3}, {4,5,6}};
	//int* p_test = &test[0][0];

	//std::cout << *p_test + 1;

	//for (int i = 176; i < 179; i++) {
	//	map_grid = map(80, 20, i);
	//	print_map(map_grid);
	//}

	//std::cout << char(243);

	_getch();

	return 0;
}
