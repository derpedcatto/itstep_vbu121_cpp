#include <iostream>
#include <windows.h>
#include "functions.h"
using namespace std;

int main()
{
	system("mode con cols=20 lines=12");

	int board[4][4];
	int random_count;
	extern int offsetX;
	extern int offsetY;

	cout << "    Randomize num\n    -> ";
	cin >> random_count;

	//Меню загрузки
	system("cls");
	cursor_coord(3, 5);
	hide_cursor();
	cout << "Please wait...";


	fill_board(board);

	while (random_count > 0)
	{
		random_input();
		movement(board);
		//draw_board(board);
		random_count--;
	}

	draw_board(board);

	while (true)
	{
		get_input();
		movement(board);
		board_anim(offsetX, offsetY, board);

		win_check(board);
		if (win_check(board) == true)
		{
			MessageBox(NULL, (LPCWSTR)L"You win!", (LPCWSTR)L"Congratulations!", MB_OK);
			return 0;
		}
	}
} 