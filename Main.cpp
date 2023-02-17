#include <conio.h>
#include <iostream>

void printArr(char** arr, int size) {
	for (int i = 0; i < size; i++) {
		std::cout << " [";
		for (int j = 0; j < size; j++) {
			std::cout << "'" << arr[i][j] << "'";
			if (j < size - 1) std::cout << " ";
		} std::cout << "] " << std::endl;
	}
}

char** arr(int size) {
	char** arrs = new char*[size];

	for (int i = 0; i < size; i++) {
		arrs[i] = new char[size];
		for (int j = 0; j < size; j++) {
			arrs[i][j] = '-';
		}
	}

	return arrs;
}

bool in(int command_list[], int user_input) {
	bool state = false;
	int i = 0;

	while (command_list[i] != -1) {
		//if () break;

		if (user_input == command_list[i]) {
			state = true;
			break;
		}

		i++;
	}

	return state;
}

int main() {
	int map_size = 11;
	int player_x_coor = map_size / 2;
	int player_y_coor = map_size / 2;

	int command_key[] = {87, 65, 83, 68, 119, 97, 115, 100, -1};

	char** Arr = arr(map_size);
	Arr[player_y_coor][player_x_coor] = 'X';

	printArr(Arr, map_size); std::cout << std::endl;

	while (1) {
		int usr_input = _getch();

		if (usr_input == 27) break;

		Arr[player_y_coor][player_x_coor] = '-';

		if ((usr_input == 87 || usr_input == 119) && player_y_coor > 0) {			// Upwards
			Arr[player_y_coor - 1][player_x_coor] = 'X';
			
			player_y_coor--;
		} 

		else if ((usr_input == 65 || usr_input == 97) && player_x_coor > 0) {		// Left
			Arr[player_y_coor][player_x_coor - 1] = 'X';

			player_x_coor--;
		}

		else if ((usr_input == 83 || usr_input == 115) && player_y_coor < map_size - 1) {		// Downwards
			Arr[player_y_coor + 1][player_x_coor] = 'X';

			player_y_coor++;
		}

		else if ((usr_input == 68 || usr_input == 100) && player_x_coor < map_size - 1) {		// Right
			Arr[player_y_coor][player_x_coor + 1] = 'X';

			player_x_coor++;
		}

		if (in(command_key, usr_input)) {
			printArr(Arr, map_size);
			std::cout << " Player coor (X,Y): (" << player_x_coor << ", " << player_y_coor << ") \n" << std::endl;
		}
	}

	//std::cout << "\n";
	//printArr(Arr, N);

	return 0;
}