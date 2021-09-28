#include <windows.h>
#include <iostream>
#include <ctime>
#include <conio.h>
using namespace std;

int main()
{
	srand(time(0));
	system("mode con cols=80 lines=40");
	system("title Super Maze!");

	// hide standard console cursor
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	cci.bVisible = false;
	cci.dwSize = 100;
	SetConsoleCursorInfo(h, &cci);

	const int height = 30;
	const int width = 60;
	int maze[height][width];

	const int MAX_HEALTH = 100;
	int current_health = MAX_HEALTH;

	int gold_count = 0; //Тут будет храниться количество биткоинов

	// http://www.quizful.net/post/enum-types-c

	enum maze_objects { HALL, WALL, GOLD, VRAG };
	enum direction { DOWN = 80, UP = 72, LEFT = 75, RIGHT = 77 };
	enum colors { BLUE = 9, RED = 12, YELLOW = 14, DARKGREEN = 2 };

	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			int random = rand() % 3;
			maze[y][x] = random;

			if (x == 0 || y == 0 || x == width - 1 || y == height - 1)
				maze[y][x] = WALL;

			// enter and exit
			if (x == 0 && y == 2 || x == 1 && y == 2
				|| x == width - 1 && y == height - 3)
				maze[y][x] = HALL;

			/////////////////////////////////////////////////////////

			if (maze[y][x] == WALL)
			{
				SetConsoleTextAttribute(h, DARKGREEN);
				cout << (char)178;
			}
			else if (maze[y][x] == GOLD)
			{
				SetConsoleTextAttribute(h, YELLOW);
				cout << (char)250;
			}
			else
			{
				cout << " ";
			}
		}
		cout << "\n";
	}

	const int enemy_count = 25;
	int current_enemy_count = 0;

	while (true)
	{
		//Создаём структуру координат для врага
		COORD enemy = { 0 };

		//Рандомно генерируем точку, с учётом рамки
		enemy.X = rand() % width - 2 + 1;
		enemy.Y = rand() % height - 2 + 1;

		//Если в лабиринте по сгенерированным координатам не пустое место пропускаем итерацию
		if (maze[enemy.Y][enemy.X] != HALL)
			continue;

		//Записываем врага в лабиринт
		maze[enemy.Y][enemy.X] = VRAG;

		//Устанавливаем позицию курсора на точку, 
		//которую сгенерировали, красим шрифт в красный цвет и рисуем смайлик
		SetConsoleCursorPosition(h, enemy);
		SetConsoleTextAttribute(h, RED);
		cout << char(1);

		//Увеличиваем счетчик установленных врагов
		current_enemy_count++;

		//Если счётчик установленных врагов >= макс количеству врагов, выходим из цикла
		if (current_enemy_count >= enemy_count)
			break;
	}

	COORD pers = { 0, 2 };
	SetConsoleCursorPosition(h, pers);
	SetConsoleTextAttribute(h, BLUE);
	cout << (char)1;

	// Statistics
	COORD stat = {63, 1};
	SetConsoleCursorPosition(h, stat);
	SetConsoleTextAttribute(h, YELLOW);
	cout << "Gold: " << gold_count << endl;

	SetConsoleCursorPosition(h, { stat.X, stat.Y + 2} );
	SetConsoleTextAttribute(h, DARKGREEN);
	cout << "Health: " << current_health << " ";

	while (true)
	{
		if (_kbhit())
		{
			int direct = _getch();
			if (direct == 224)
				direct = _getch();

			SetConsoleCursorPosition(h, pers);
			cout << " ";

			int offsetX = 0;
			int offsetY = 0;

			switch (direct)
			{
			case UP:
				offsetY = -1;
				break;
			case DOWN:
				offsetY = 1;
				break;
			case RIGHT:
				offsetX = 1;
				break;
			case LEFT:
				offsetX = -1;
				break;
			}

			if (maze[pers.Y + offsetY][pers.X + offsetX] != WALL)
			{
				pers.X += offsetX;
				pers.Y += offsetY;
			}

			if (maze[pers.Y][pers.X] == GOLD)
			{
				gold_count++;
				maze[pers.Y][pers.X] = HALL;
			}

			if (maze[pers.Y][pers.X] == VRAG)
			{
				maze[pers.Y][pers.X] = HALL;

				current_health -= rand() % 6 + 20;

				if (current_health < 0)
					current_health = 0;	
			}

			SetConsoleCursorPosition(h, pers);
			SetConsoleTextAttribute(h, BLUE);
			cout << (char)1;	

			SetConsoleCursorPosition(h, stat);
			SetConsoleTextAttribute(h, YELLOW);
			cout << "Gold: " << gold_count << endl;

			SetConsoleCursorPosition(h, { stat.X, stat.Y + 2 });
			SetConsoleTextAttribute(h, DARKGREEN);
			cout << "Health: " << current_health << " ";

			if (pers.X == width - 1 && pers.Y == height - 3)
			{
				system("cls");
				MessageBox(NULL, TEXT("Вы выйграли!"), TEXT("Сообщение!"), MB_OK);
				break;
			}

			if (!current_health) {
				MessageBox(NULL, TEXT("Вы проиграли, закончилось здоровье!"), TEXT("Сообщение!"), MB_OK);
				break;
			}
		}
		else 
		{
			
		}
	}
}

////////////////////////////////////////////////////////////////////
// как отправить значение интовой переменной в заголовок консоли: //
////////////////////////////////////////////////////////////////////

/*
#include <windows.h>
#include <iostream>
using namespace std;

void main()
{
	int coins = 25;

	// string representation of coins variable
	char* title = new char[200];
	_itoa_s(coins, title, 199, 10);

	SetConsoleTitleA(title);

	system("pause");
}
*/

