#include <iostream>
#include <Windows.h>
#include "enum.h"
using namespace std;


inline void player_input_value(int& input, bool& isAttack, int& moves, COORD& player_offset)
{
	enum direction { DOWN = 80, UP = 72, LEFT = 75, RIGHT = 77 };

	while (true)
	{
		switch (input)
		{
			case UP:
				player_offset.Y = -1;
				break;

			case DOWN:
				player_offset.Y = 1;
				break;

			case RIGHT:
				player_offset.X = 1;
				break;

			case LEFT:
				player_offset.X = -1;
				break;

			case VK_SPACE:
				isAttack = true;
				break;

			default:
				continue;
		}

		moves--;
		break;
	}
}

inline int player_movement(int**& board, bool& P1_stuck, bool&P2_stuck, int& score, int& moves,
							COORD& player_offset, COORD& P1, COORD& P2, HANDLE& h)
{
	if (board[P1.Y + player_offset.Y][P1.X + player_offset.X] != WALL && !P1_stuck)
	{
		if (board[P1.Y + player_offset.Y][P1.X + player_offset.X] == PLAYER2 && P2_stuck)
			moves++;

		else
		{
			SetConsoleCursorPosition(h, P1);
			cout << " ";
			board[P1.Y][P1.X] = EMPTY;

			P1.Y += player_offset.Y;
			P1.X += player_offset.X;

			if (board[P1.Y][P1.X] == WEB)
				P1_stuck = true;
			if (board[P1.Y][P1.X] == TREASURE_S)
				score += 500;
			if (board[P1.Y][P1.X] == TREASURE_B)
				score += 1000;

			board[P1.Y][P1.X] = PLAYER1;
		}
	}

	if (board[P2.Y + player_offset.Y][P2.X - player_offset.X] != WALL && !P2_stuck)
	{
		if (board[P2.Y + player_offset.Y][P2.X - player_offset.X] == PLAYER1 && P1_stuck)
			moves++;

		else
		{
			SetConsoleCursorPosition(h, P2);
			cout << " ";
			board[P2.Y][P2.X] = EMPTY;

			P2.Y += player_offset.Y;
			P2.X -= player_offset.X;

			if (board[P2.Y][P2.X] == WEB)
				P2_stuck = true;
			if (board[P2.Y][P2.X] == TREASURE_S)
				score += 500;
			if (board[P2.Y][P2.X] == TREASURE_B)
				score += 1000;

			board[P2.Y][P2.X] = PLAYER2;
		}
	}

	return 0;
}

inline void player_attack(int**& board, bool& isAttack, bool& P1_stuck, bool& P2_stuck, int& score, int& moves,
							COORD& P1, COORD& P2, HANDLE& h)
{
	COORD attack1;
	attack1.Y = P1.Y - 1;
	attack1.X = P1.X - 1;

	COORD attack2;
	attack2.Y = P2.Y - 1;
	attack2.X = P2.X - 1;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			/*web*/
			if (board[attack1.Y][attack1.X] == WEB && !P1_stuck)
			{
				board[attack1.Y][attack1.X] = EMPTY;
				SetConsoleCursorPosition(h, attack1);
				cout << " ";

				score += 100;
			}

			if (board[attack2.Y][attack2.X] == WEB && !P2_stuck)
			{
				board[attack2.Y][attack2.X] = EMPTY;
				SetConsoleCursorPosition(h, attack2);
				cout << " ";

				score += 100;
			}


			/*player in web*/
			if (board[attack1.Y][attack1.X] == PLAYER2 && P2_stuck)
				P2_stuck = false;

			if (board[attack2.Y][attack2.X] == PLAYER1 && P1_stuck)
				P1_stuck = false;

			attack1.X++;
			attack2.X++;
		}

		attack1.Y++;
		attack2.Y++;
		attack1.X = P1.X - 1;
		attack2.X = P2.X - 1;
	}

	isAttack = false;
}