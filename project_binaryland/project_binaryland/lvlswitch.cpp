#include <iostream>
#include "Windows.h"
#include "enum.h"
using namespace std;

inline void lvl_switch(int& lvl_id, int**& board, int& cols, int& rows)
{
	int** tmp_arr = new int* [rows];

	switch (lvl_id)
	{
		case 1:
		{
			tmp_arr[0] = new int[cols] {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
			tmp_arr[1] = new int[cols] {1, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 1};
			tmp_arr[2] = new int[cols] {1, 6, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1};
			tmp_arr[3] = new int[cols] {1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 6, 1};
			tmp_arr[4] = new int[cols] {1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1};
			tmp_arr[5] = new int[cols] {1, 7, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1};
			tmp_arr[6] = new int[cols] {1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1};
			tmp_arr[7] = new int[cols] {1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1};
			tmp_arr[8] = new int[cols] {1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1};
			tmp_arr[9] = new int[cols] {1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1};
			tmp_arr[10]= new int[cols] {1, 0, 0, 0, 0, 0, 0, 3, 1, 4, 0, 0, 0, 0, 0, 0, 1};
			tmp_arr[11]= new int[cols] {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
			break;
		}

		case 2:
		{
			tmp_arr[0] = new int[cols] {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
			tmp_arr[1] = new int[cols] {1, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 1};
			tmp_arr[2] = new int[cols] {1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 6, 1, 0, 1};
			tmp_arr[3] = new int[cols] {1, 0, 1, 0, 1, 0, 1, 7, 1, 7, 1, 1, 1, 1, 1, 0, 1};
			tmp_arr[4] = new int[cols] {1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1};
			tmp_arr[5] = new int[cols] {1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1};
			tmp_arr[6] = new int[cols] {1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1};
			tmp_arr[7] = new int[cols] {1, 1, 1, 0, 1, 1, 1, 0, 1, 7, 1, 1, 1, 1, 1, 0, 1};
			tmp_arr[8] = new int[cols] {1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1};
			tmp_arr[9] = new int[cols] {1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1};
			tmp_arr[10]= new int[cols] {1, 6, 0, 0, 0, 0, 1, 3, 1, 4, 0, 0, 0, 0, 0, 6, 1};
			tmp_arr[11]= new int[cols] {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
			break;
		}

		case 3:
		{
			tmp_arr[0] = new int[cols] {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
			tmp_arr[1] = new int[cols] {1, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 1};
			tmp_arr[2] = new int[cols] {1, 7, 1, 6, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1};
			tmp_arr[3] = new int[cols] {1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 6, 1, 0, 1, 7, 1};
			tmp_arr[4] = new int[cols] {1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1};
			tmp_arr[5] = new int[cols] {1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1};
			tmp_arr[6] = new int[cols] {1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1};
			tmp_arr[7] = new int[cols] {1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1};
			tmp_arr[8] = new int[cols] {1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1};
			tmp_arr[9] = new int[cols] {1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1};
			tmp_arr[10]= new int[cols] {1, 0, 0, 0, 0, 0, 0, 3, 1, 4, 0, 0, 0, 0, 1, 7, 1};
			tmp_arr[11]= new int[cols] {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
			break;
		}

		case 4:
		{
			tmp_arr[0] = new int[cols] {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
			tmp_arr[1] = new int[cols] {1, 0, 0, 0, 1, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 1};
			tmp_arr[2] = new int[cols] {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1};
			tmp_arr[3] = new int[cols] {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 7, 1};
			tmp_arr[4] = new int[cols] {1, 0, 1, 0, 6, 0, 1, 0, 1, 0, 6, 0, 1, 0, 0, 0, 1};
			tmp_arr[5] = new int[cols] {1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1};
			tmp_arr[6] = new int[cols] {1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1};
			tmp_arr[7] = new int[cols] {1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1};
			tmp_arr[8] = new int[cols] {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1};
			tmp_arr[9] = new int[cols] {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1};
			tmp_arr[10]= new int[cols] {1, 6, 1, 0, 0, 0, 1, 3, 1, 4, 0, 0, 0, 0, 1, 6, 1};
			tmp_arr[11]= new int[cols] {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
			break;
		}

		case 5:
		{
			tmp_arr[0] = new int[cols] {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
			tmp_arr[1] = new int[cols] {1, 0, 0, 0, 1, 0, 0, 0, 2, 0, 0, 0, 0, 0, 1, 7, 1};
			tmp_arr[2] = new int[cols] {1, 7, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1};
			tmp_arr[3] = new int[cols] {1, 1, 1, 6, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1};
			tmp_arr[4] = new int[cols] {1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1};
			tmp_arr[5] = new int[cols] {1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1};
			tmp_arr[6] = new int[cols] {1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1};
			tmp_arr[7] = new int[cols] {1, 0, 1, 6, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1};
			tmp_arr[8] = new int[cols] {1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1};
			tmp_arr[9] = new int[cols] {1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1};
			tmp_arr[10]= new int[cols] {1, 7, 0, 0, 0, 0, 0, 3, 1, 4, 1, 0, 0, 0, 0, 6, 1};
			tmp_arr[11]= new int[cols] {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
			break;
		}

		case 6:
		{
			tmp_arr[0] = new int[cols] {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
			tmp_arr[1] = new int[cols] {1, 7, 0, 0, 1, 0, 1, 0, 2, 0, 0, 0, 0, 0, 0, 0, 1};
			tmp_arr[2] = new int[cols] {1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 6, 1, 0, 1};
			tmp_arr[3] = new int[cols] {1, 6, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1};
			tmp_arr[4] = new int[cols] {1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1};
			tmp_arr[5] = new int[cols] {1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 6, 1, 1, 1};
			tmp_arr[6] = new int[cols] {1, 7, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1};
			tmp_arr[7] = new int[cols] {1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1};
			tmp_arr[8] = new int[cols] {1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1};
			tmp_arr[9] = new int[cols] {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1};
			tmp_arr[10]= new int[cols] {1, 6, 1, 0, 0, 0, 0, 3, 1, 4, 0, 0, 0, 0, 0, 6, 1};
			tmp_arr[11]= new int[cols] {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
			break;
		}

		case 7:
		{
			tmp_arr[0] = new int[cols] {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
			tmp_arr[1] = new int[cols] {1, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 1};
			tmp_arr[2] = new int[cols] {1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 6, 1};
			tmp_arr[3] = new int[cols] {1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1};
			tmp_arr[4] = new int[cols] {1, 0, 7, 0, 1, 0, 0, 0, 1, 6, 0, 0, 0, 0, 0, 0, 1};
			tmp_arr[5] = new int[cols] {1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 6, 1};
			tmp_arr[6] = new int[cols] {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1};
			tmp_arr[7] = new int[cols] {1, 0, 1, 0, 1, 0, 1, 0, 1, 6, 1, 1, 1, 0, 1, 1, 1};
			tmp_arr[8] = new int[cols] {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1};
			tmp_arr[9] = new int[cols] {1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 6, 1};
			tmp_arr[10]= new int[cols] {1, 7, 1, 0, 6, 0, 1, 3, 1, 4, 0, 0, 0, 0, 0, 0, 1};
			tmp_arr[11]= new int[cols] {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
			break;
		}
	}
    

	/*random web*/
	int count = 4 + rand() % 12;
	COORD point;
	
	for (int i = 0; i < count; i++)
	{
		while (true)
		{
			point.Y = rand() % rows;
			point.X = rand() % cols;
	
			if (tmp_arr[point.Y][point.X] == EMPTY)
			{
				tmp_arr[point.Y][point.X] = WEB;
				break;
			}
		}
	}


	for (int i = 0; i < rows; i++)
	{
		delete[] board[i];
	}
	delete[] board;

	board = tmp_arr;
}