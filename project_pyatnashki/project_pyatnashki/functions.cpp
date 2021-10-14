#include <iostream>
#include <windows.h>
#include <conio.h>		//При нажатии кнопки
#include <time.h>
#include "functions.h"
using namespace std;

//Глобальные переменные

enum dir { DOWN = 80, UP = 72, LEFT = 75, RIGHT = 77 };
int emptyY = 3;
int emptyX = 3;
int offsetX;
int offsetY;
int direct;
int rand_num = 0;


void cursor_coord(short x, short y)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(h, { x, y });
}

void hide_cursor()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(h, &info);
}


void fill_board(int board[4][4])
{
	int num = 1;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			board[i][j] = num;
			num++;
		}
	}

	board[3][3] = 0;
}

void draw_board(int board[4][4])
{
	COORD first_draw;
	first_draw.X = 0;
	first_draw.Y = 0;
	int y_default = -1;		//новое default значение при спуске на след. ряд
	int y_offset = -1;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			first_draw.X = 5 * j;
			y_offset = y_default;

			first_draw.Y = ++y_offset;
			cursor_coord(first_draw.X, first_draw.Y);
			if (board[i][j] == 0)
				cout << "     ";
			else
				cout << "+ - +";

			first_draw.Y = ++y_offset;
			cursor_coord(first_draw.X, first_draw.Y);
			if (board[i][j] == 0)
				cout << "     ";
			else if (board[i][j] < 10)
				cout << "|" << board[i][j] << "  |";
			else
				cout << "|" << board[i][j] << " |";

			first_draw.Y = ++y_offset;
			cursor_coord(first_draw.X, first_draw.Y);
			if (board[i][j] == 0)
				cout << "     ";
			else
				cout << "+ - +";
		}

		y_default = y_offset;
	}
}


int get_input()
{
	direct = _getch();
	if (direct == 224)
		direct = _getch();

	return direct;
}

int random_input()
{
	//Рандом
	srand(time(0));
	rand();
	int arr[4];

	Sleep(100);
	for (int i = 0; i < 4; i++)
		arr[i] = rand() % 4;

	direct = arr[rand_num];
	rand_num++;

	if (rand_num > 4)
		rand_num = 0;

	//Возвращение значения клавиши
	switch (direct)
	{
		case 0:
		{
			direct = DOWN;
			return direct;
		}

		case 1:
		{
			direct = UP;
			return direct;
		}

		case 2:
		{
			direct = LEFT;
			return direct;
		}

		case 3:
		{
			direct = RIGHT;
			return direct;
		}
	}
}


int movement(int board[4][4])
{
	offsetX = 0;
	offsetY = 0;

	//Направление
	switch (direct)
	{
		case DOWN:
		{
			offsetY = -1;
			break;
		}
		case UP:
		{
			offsetY = 1;
			break;
		}
		case LEFT:
		{
			offsetX = 1;
			break;
		}
		case RIGHT:
		{
			offsetX = -1;
			break;
		}
	}

	//Проверка на выход за пределы
	if ((board[emptyY][emptyX] == board[emptyY][3] && offsetX == 1) ||
		(board[emptyY][emptyX] == board[emptyY][0] && offsetX == -1) ||
		(board[emptyY][emptyX] == board[3][emptyX] && offsetY == 1) ||
		(board[emptyY][emptyX] == board[0][emptyX] && offsetY == -1))
		return 0;


	if (offsetX)
	{
		//Замена значений
		int temp = board[emptyY][emptyX];
		board[emptyY][emptyX] = board[emptyY][emptyX + offsetX];
		board[emptyY][emptyX + offsetX] = temp;
		emptyX += offsetX;

		return offsetX;
	}

	if (offsetY)
	{
		//Замена значений
		int temp = board[emptyY][emptyX];
		board[emptyY][emptyX] = board[emptyY + offsetY][emptyX];
		board[emptyY + offsetY][emptyX] = temp;
		emptyY += offsetY;

		return offsetY;
	}
}

void board_anim(int offsetX, int offsetY, int board[4][4])
{
	COORD def;

	if (offsetX)
	{
		//Влево
		if (offsetX == 1)
			{
				int def_offset_x = 0;
				int def_offset_y = 0;
				int empty = -1;

				for (int i = 0; i < 5; i++)
				{
					Sleep(50);

					def_offset_y = 0;
					def_offset_x--;
					empty++;

					//-------------------------------------------------------------------//

					def.Y = emptyY * 3 + def_offset_y;
					def.X = emptyX * 5 + def_offset_x;

					cursor_coord(def.X, def.Y);

					cout << "+ - +";

					for (int i = empty; i >= 0; i--)
						cout << " ";

					//-------------------------------------------------------------------//

					def_offset_y++;
					def.Y = emptyY * 3 + def_offset_y;
					def.X = emptyX * 5 + def_offset_x;

					cursor_coord(def.X, def.Y);

					if (board[emptyY][emptyX - offsetX] < 10)
						cout << "|" << board[emptyY][emptyX - offsetX] << "  |";
					else
						cout << "|" << board[emptyY][emptyX - offsetX] << " |";

					for (int i = empty; i >= 0; i--)
						cout << " ";

					//-------------------------------------------------------------------//

					def_offset_y++;
					def.Y = emptyY * 3 + def_offset_y;
					def.X = emptyX * 5 + def_offset_x;

					cursor_coord(def.X, def.Y);

					cout << "+ - +";

					for (int i = empty; i >= 0; i--)
						cout << " ";
				}
			}

		//Вправо
		if (offsetX == -1)
			{
				int def_offset_x = -1;
				int def_offset_y = 0;

				for (int i = 0; i < 5; i++)
				{
					Sleep(50);

					def_offset_y = 0;
					def_offset_x++;

					//-------------------------------------------------------------------//

					def.Y = emptyY * 3 + def_offset_y;
					def.X = emptyX * 5 + def_offset_x;

					cursor_coord(def.X, def.Y);

					cout << " ";
					cout << "+ - +";

					//-------------------------------------------------------------------//

					def_offset_y++;
					def.Y = emptyY * 3 + def_offset_y;
					def.X = emptyX * 5 + def_offset_x;

					cursor_coord(def.X, def.Y);

					cout << " ";

					if (board[emptyY][emptyX - offsetX] < 10)
						cout << "|" << board[emptyY][emptyX - offsetX] << "  |";
					else
						cout << "|" << board[emptyY][emptyX - offsetX] << " |";

					//-------------------------------------------------------------------//

					def_offset_y++;
					def.Y = emptyY * 3 + def_offset_y;
					def.X = emptyX * 5 + def_offset_x;

					cursor_coord(def.X, def.Y);

					cout << " ";
					cout << "+ - +";
				}
			}
	}

	if (offsetY)
	{
		//Вверх
		if (offsetY == 1)
			{
				int def_offset_x = 0;
				int def_offset_y = 0;
				int temp_offset_y = 0;
				int empty = 0;

				for (int i = 0; i < 3; i++)
				{
					Sleep(75);

					def_offset_y--;
					def_offset_x = 0;
					temp_offset_y = def_offset_y;

					//-------------------------------------------------------------------//

					def.Y = emptyY * 3 + temp_offset_y;
					def.X = emptyX * 5 + def_offset_x;

					cursor_coord(def.X, def.Y);

					cout << "+ - +";

					//-------------------------------------------------------------------//

					temp_offset_y++;
					def.Y = emptyY * 3 + temp_offset_y;

					cursor_coord(def.X, def.Y);

					if (board[emptyY - offsetY][emptyX] < 10)
						cout << "|" << board[emptyY - offsetY][emptyX] << "  |";
					else
						cout << "|" << board[emptyY - offsetY][emptyX] << " |";

					//-------------------------------------------------------------------//

					temp_offset_y++;
					def.Y = emptyY * 3 + temp_offset_y;

					cursor_coord(def.X, def.Y);

					cout << "+ - +";

					//-------------------------------------------------------------------//

					temp_offset_y++;
					def.Y = emptyY * 3 + temp_offset_y;

					cursor_coord(def.X, def.Y);

					cout << "     ";
				}
			}

		//Вниз
		if (offsetY == -1)
			{
				int def_offset_x = 0;
				int def_offset_y = -1;
				int temp_offset_y = 0;
				int empty = 0;

				for (int i = 0; i < 3; i++)
				{
					Sleep(75);

					def_offset_y++;
					def_offset_x = 0;
					temp_offset_y = def_offset_y;

					//-------------------------------------------------------------------//

					def.Y = emptyY * 3 + temp_offset_y;
					def.X = emptyX * 5 + def_offset_x;

					cursor_coord(def.X, def.Y);

					cout << "     ";

					//-------------------------------------------------------------------//

					temp_offset_y++;
					def.Y = emptyY * 3 + temp_offset_y;

					cursor_coord(def.X, def.Y);

					cout << "+ - +";

					//-------------------------------------------------------------------//

					temp_offset_y++;
					def.Y = emptyY * 3 + temp_offset_y;

					cursor_coord(def.X, def.Y);

					if (board[emptyY - offsetY][emptyX] < 10)
						cout << "|" << board[emptyY - offsetY][emptyX] << "  |";
					else
						cout << "|" << board[emptyY - offsetY][emptyX] << " |";

					//-------------------------------------------------------------------//

					temp_offset_y++;
					def.Y = emptyY * 3 + temp_offset_y;

					cursor_coord(def.X, def.Y);

					cout << "+ - +";
				}
			}
	}
}


bool win_check(int board[4][4])
{
	int win_board[4][4] = { 1, 2, 3, 4,
							5, 6, 7, 8,
							9, 10, 11, 12,
							13, 14, 15, 0 };

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (board[i][j] != win_board[i][j])
				return false;
		}
	}

	return true;
}
