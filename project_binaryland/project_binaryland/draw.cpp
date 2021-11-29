#include <iostream>
#include <Windows.h>
#include "enum.h"
using namespace std;

inline void draw_board(int**& board, int& rows, int& cols, HANDLE h)
{
	/*random wall color*/
	int color = 1 + rand() % 15;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (board[i][j] == EMPTY)
			{
				cout << " ";
			}

			if (board[i][j] == WALL)
			{
				SetConsoleTextAttribute(h, color);
				cout << "O";
			}

			if (board[i][j] == EXIT)
			{
				SetConsoleTextAttribute(h, YELLOW);
				cout << "#";
			}

			if (board[i][j] == PLAYER1)
			{
				SetConsoleTextAttribute(h, PINK);
				cout << "0";
			}

			if (board[i][j] == PLAYER2)
			{
				SetConsoleTextAttribute(h, BLUE);
				cout << "1";
			}

			if (board[i][j] == WEB)
			{
				SetConsoleTextAttribute(h, GRAY);
				cout << "@";
			}

			if (board[i][j] == TREASURE_S)
			{
				SetConsoleTextAttribute(h, PINK);
				cout << "u";
			}

			if (board[i][j] == TREASURE_B)
			{
				SetConsoleTextAttribute(h, YELLOW);
				cout << "q";
			}
		}

		/*display last line properly*/
		if (i < rows - 1)
			cout << endl;
	}
}

inline void draw_start_level(int& lvl_id, HANDLE& h)
{
	system("cls");

	SetConsoleTextAttribute(h, WHITE);
	SetConsoleCursorPosition(h, {11, 5});

	cout << "Level " << lvl_id;

	SetConsoleCursorPosition(h, { 0, 0 });
}

inline void draw_end_screen(HANDLE& h, int& score)
{
	system("cls");

	SetConsoleTextAttribute(h, WHITE);
	SetConsoleCursorPosition(h, { 9, 4 });
	cout << "Game over!";

	SetConsoleTextAttribute(h, YELLOW);
	SetConsoleCursorPosition(h, { 7, 6 });
	cout << "Total score: " << score;

	Sleep(4000);
}


inline void draw_P1(bool& P1_stuck, COORD& P1, HANDLE& h)
{
	if (P1_stuck)
		SetConsoleTextAttribute(h, GRAY);
	else
		SetConsoleTextAttribute(h, PINK);

	SetConsoleCursorPosition(h, P1);
	cout << "0";
}

inline void draw_P2(bool& P2_stuck, COORD& P2, HANDLE& h)
{
	if (P2_stuck)
		SetConsoleTextAttribute(h, GRAY);
	else
		SetConsoleTextAttribute(h, BLUE);

	SetConsoleCursorPosition(h, P2);
	cout << "1";
}

inline void draw_exit(HANDLE& h)
{
	SetConsoleCursorPosition(h, { 8, 1 });
	SetConsoleTextAttribute(h, YELLOW);
	cout << "#";
}


inline void draw_level_id(HANDLE& h, int& lvl_id)
{
	SetConsoleCursorPosition(h, { 20, 0 });
	SetConsoleTextAttribute(h, WHITE);
	cout << "LEVEL " << lvl_id;
}

inline void draw_score(HANDLE& h, int& score)
{
	SetConsoleCursorPosition(h, { 20, 2 });
	SetConsoleTextAttribute(h, YELLOW);
	cout << "SCORE";

	SetConsoleCursorPosition(h, { 20, 3 });
	cout << score;
}

inline void draw_moves(HANDLE& h, int& moves)
{
	SetConsoleCursorPosition(h, { 20, 5 });
	SetConsoleTextAttribute(h, BLUE);
	cout << "MOVES";

	SetConsoleCursorPosition(h, { 20, 6 });
	cout << moves << "  ";
}

inline void draw_lives(HANDLE& h, int& lives)
{
	SetConsoleCursorPosition(h, { 20, 8 });
	SetConsoleTextAttribute(h, PINK);
	cout << "LIVES";

	SetConsoleCursorPosition(h, { 20, 9 });
	cout << lives << "  ";
}