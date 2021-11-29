#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "header.h"

using namespace std;

int main()
{
	srand(time(NULL));
	system("title Binary Land");
	system("mode con cols=29 lines=12");

	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	/*hide_cursor*/
	CONSOLE_CURSOR_INFO cci;
	cci.bVisible = false;
	cci.dwSize = 100;
	SetConsoleCursorInfo(h, &cci);

	//------------------------------------------------------// variables

	int rows = 12;
	int cols = 17;

	int** board = new int* [rows];
	for (int i = 0; i < rows; i++)
		board[i] = new int[cols];

	int score = 0;
	int lives = 3;
	int count = 0;

	//------------------------------------------------------// loop

	for (int lvl_id = 1; lvl_id < 8; lvl_id++)
	{
		if (lives == 0)
		{
			draw_end_screen(h, score);
			return 0;
		}
		count++;
		if (count == 4)
		{
			lives++;
			count = 0;
		}


		COORD P1 = { 7, 10 };
		COORD P2 = { 9, 10 };

		bool P1_stuck = false;
		bool P2_stuck = false;

		int moves = 75 + rand() % 100;


		draw_start_level(lvl_id, h);
		lvl_switch(lvl_id, board, cols, rows);
		Sleep(2000);
		system("cls");

		draw_board(board, rows, cols, h);
		draw_level_id(h, lvl_id);
		draw_score(h, score);
		draw_moves(h, moves);
		draw_lives(h, lives);


		while (true)
		{
			if (_kbhit)
			{
				bool isAttack = false;
				int input = _getch();
				if (input == 224)
					input = _getch();

				COORD player_offset = { 0,0 };

				player_input_value(input, isAttack, moves, player_offset);
				player_movement(board, P1_stuck, P2_stuck, score, moves,
								player_offset, P1, P2, h);
				
				if (isAttack)
					player_attack(board, isAttack, P1_stuck, P2_stuck, score, moves, P1, P2, h);

				draw_P1(P1_stuck, P1, h);
				draw_P2(P2_stuck, P2, h);

				//------------------------------------------------------// end condition

				/*win*/
				if ((P1.X == 7 && P1.Y == 1 && P2.X == 9 && P2.Y == 1) ||
					(P1.X == 9 && P1.Y == 1 && P2.X == 7 && P2.Y == 1))
				{
					score += 600;
					Sleep(2000);
					break;
				}

				/*moves*/
				if (moves < 1)
				{
					lives--;
					lvl_id--;
					Sleep(2000);
					break;
				}

				/*both players in web*/
				if (P1_stuck && P2_stuck)
				{
					lives--;
					lvl_id--;
					Sleep(2000);
					break;
				}
			}

			draw_score(h, score);
			draw_moves(h, moves);
			draw_exit(h);
		}
	}

	draw_end_screen;
}