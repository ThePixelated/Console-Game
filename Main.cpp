#include <iostream>
#include "Terrain.cpp"

//std::vector<std::vector<char>> map(int width, int height, int type);
//void print_map(std::vector<int> arr);

void oceans(std::vector<std::vector<char>> arr) {
	
	arr[0][0] = '+';

}

int main() {
	std::vector<std::vector<char>> map_grid = map(80, 20, 177);
	std::cout << "test";

	oceans(map_grid);

	std::cout << map_grid[0][0];

	//int test[2][3] = {{1,2,3}, {4,5,6}};
	//int* p_test = &test[0][0];

	//std::cout << *p_test + 1;

	//for (int i = 176; i < 179; i++) {
	//	map_grid = map(80, 20, i);
	//	print_map(map_grid);
	//}

	//std::cout << char(243);

	return 0;
}
