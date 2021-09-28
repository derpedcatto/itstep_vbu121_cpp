#include <windows.h>
#include <iostream>
#include <ctime>
#include <conio.h>
#include "draw.h"
#include <SFML/Audio.hpp>
#pragma comment(lib, "winmm.lib") //wav
using namespace std;

int main()
{
	//-------------------------------------------------------------------//	sounds

	sf::SoundBuffer walk_buf;
	if (!walk_buf.loadFromFile("walk.wav"))
		return -1;

	sf::SoundBuffer collision_buf;
	if (!collision_buf.loadFromFile("collision.wav"))
		return -1;

	sf::SoundBuffer coin_buf;
	if (!coin_buf.loadFromFile("coin.wav"))
		return -1;

	sf::SoundBuffer coffee_buf;
	if (!coffee_buf.loadFromFile("coffee.wav"))
		return -1;

	sf::SoundBuffer potion_buf;
	if (!potion_buf.loadFromFile("potion.wav"))
		return -1;

	sf::SoundBuffer punch_buf;
	if (!punch_buf.loadFromFile("punch.wav"))
		return -1;

	sf::SoundBuffer hit_buf;
	if (!hit_buf.loadFromFile("hit.wav"))
		return -1;

	sf::SoundBuffer win_buf;
	if (!win_buf.loadFromFile("win.wav"))
		return -1;

	sf::SoundBuffer lose_buf;
	if (!lose_buf.loadFromFile("lose.wav"))
		return -1;

	sf::Music music;
	if (!music.openFromFile("theme.wav"))
		return -1;
	

	sf::Sound walk_sound;
	sf::Sound collision_sound;
	sf::Sound coin_sound;
	sf::Sound coffee_sound;
	sf::Sound punch_sound;
	sf::Sound hit_sound;
	sf::Sound potion_sound;
	sf::Sound win_sound;
	sf::Sound lose_sound;

	//-------------------------------------------------------------------//	window

	srand(time(0));
	system("mode con cols=60 lines=36");
	//system("title Super Maze!");

	char* title = new char[200];

	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	//hide cursor
	CONSOLE_CURSOR_INFO cci;
	cci.bVisible = false;
	cci.dwSize = 100;
	SetConsoleCursorInfo(h, &cci);

	//-------------------------------------------------------------------//	variables

	enum maze_objects { HALL, WALL, GOLD, POTION, COFFEE, ENEMY, BOMB  };
	enum direction { DOWN = 80, UP = 72, LEFT = 75, RIGHT = 77 };
	enum colors { BLUE = 9, RED = 12, YELLOW = 14, DARKGREEN = 2, DARKBLUE = 1 };

	const int height = 30;
	const int width = 60;

	int maze[height][width];

	const int MAX_HEALTH = 100;
	float current_health = MAX_HEALTH;

	int gold_count = 0;
	int gold_max = 0;

	const int enemy_count = 50;
	int current_enemy_count = 0;

	const int max_energy = 500;
	int energy = max_energy;

	bool drawBackPotion = false;
	bool drawBackCoffee = false;

	bool cooldownCoffee = false;

	bool isAttack = false;

	int step_count = 0;
	int coffee_step_count = 0;

	//-------------------------------------------------------------------//	maze gen

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			//---------------------// generation
			int random = rand() % 5;
			maze[i][j] = random;

			//Wall border
			if (j == 0 || i == 0 || j == width - 1 || i == height - 1)
				maze[i][j] = WALL;

			//Spawn | Exit
			if (j == 0 && i == 2 || j == 1 && i == 2
				|| j == width - 1 && i == height - 3)
				maze[i][j] = HALL;

			//---------------------// symbols

			if (maze[i][j] == WALL)
			{
				SetConsoleTextAttribute(h, DARKGREEN);
				cout << (char)178;
			}

			else if (maze[i][j] == GOLD)
			{
				gold_max++;
				SetConsoleTextAttribute(h, YELLOW);
				cout << (char)250;
			}

			else if (maze[i][j] == POTION)
			{
				SetConsoleTextAttribute(h, BLUE);
				cout << (char)248;
			}

			else if (maze[i][j] == COFFEE)
			{
				SetConsoleTextAttribute(h, DARKBLUE);
				cout << "u";
			}

			else
			{
				cout << " ";
			}
		}

		cout << endl;
	}

	//-------------------------------------------------------------------//	enemy gen

	while (current_enemy_count < enemy_count)
	{
		//Создаём структуру координат для врага
		COORD enemy;

		//Рандомно генерируем точку, с учётом рамки
		enemy.X = rand() % width - 2 + 1;
		enemy.Y = rand() % height - 2 + 1;

		//Если в лабиринте по сгенерированным координатам не пустое место пропускаем итерацию
		if (maze[enemy.Y][enemy.X] != HALL)
			continue;

		//Записываем врага в лабиринт
		maze[enemy.Y][enemy.X] = ENEMY;

		//Устанавливаем позицию курсора на точку, 
		//которую сгенерировали, красим шрифт в красный цвет и рисуем смайлик
		SetConsoleCursorPosition(h, enemy);
		SetConsoleTextAttribute(h, RED);
		cout << char(1);

		//Увеличиваем счетчик установленных врагов
		current_enemy_count++;
	}

	//-------------------------------------------------------------------//	first time draw

	COORD hero = { 0, 2 };
	draw_hero(hero, h);

	COORD bomb;

	COORD enemy_val = { 25, 31 };
	draw_enemy_val(enemy_val, current_enemy_count, h);

	COORD gold_stat = { 45, 31 };
	draw_gold_stat(gold_stat, gold_count, h);

	COORD gold_stat_max = { 45, 32 };
	draw_gold_stat_max(gold_stat_max, gold_max, h);

	COORD health_stat = { 5, 31 };
	draw_health_stat(health_stat, current_health, h);

	COORD energy_stat = { 5,32 };
	draw_energy_stat(energy_stat, energy, h);

	COORD coffee_cooldown_stat = { 10,34 };
	draw_coffee_cooldown_stat(coffee_cooldown_stat, coffee_step_count, h);

	COORD enemy_gen_cooldown_stat = { 25, 32 };
	draw_enemy_gen_cooldown_stat(enemy_gen_cooldown_stat, step_count, h);

	_itoa_s(gold_count, title, 199, 10);
	SetConsoleTitleA(title);

	//-------------------------------------------------------------------//	movement

	music.play();
	music.setLoop(true);

	while (true)
	{
		if (_kbhit())
		{
			//-------------------------------------------------------------------// get key

			int direct = _getch();

			if (direct == 224)
				direct = _getch();

			SetConsoleCursorPosition(h, hero);
			cout << " ";

			short int offsetX = 0;
			short int offsetY = 0;

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

			case VK_SPACE:
				isAttack = true;
				break;

			default:
				continue;
			}

			//-------------------------------------------------------------------// collision | counter

			//wall
			if (maze[hero.Y + offsetY][hero.X + offsetX] != WALL)
			{
				walk_sound.setBuffer(walk_buf);
				walk_sound.play();

				hero.X += offsetX;
				hero.Y += offsetY;
			}
			
			//when against the wall
			else
			{
				drawBackPotion = false;
				drawBackCoffee = false;

				collision_sound.setBuffer(collision_buf);
				collision_sound.play();

				if (current_enemy_count != enemy_count)
					step_count--;

				if (cooldownCoffee == true)
					coffee_step_count--;

				if (energy <= max_energy)
					energy++;
			}

			if (maze[hero.Y + offsetY][hero.X + offsetX] == BOMB)
				return 0;

			energy--;

			//gold
			if (maze[hero.Y][hero.X] == GOLD)
			{
				gold_count++;
				maze[hero.Y][hero.X] = HALL;
				coin_sound.setBuffer(coin_buf);
				coin_sound.play();
			}

			//enemy
			if (maze[hero.Y][hero.X] == ENEMY)
			{
				maze[hero.Y][hero.X] = HALL;

				punch_sound.setBuffer(hit_buf);
				punch_sound.play();

				current_enemy_count--;

				current_health -= rand() % 6 + 20;

				if (current_health < 0)
					current_health = 0;
			}

			//restore potion symbol
			if (drawBackPotion == true && maze[hero.Y - offsetY][hero.X - offsetX] != WALL)
			{
				SetConsoleCursorPosition(h, { hero.X - offsetX, hero.Y - offsetY });
				SetConsoleTextAttribute(h, BLUE);
				cout << (char)248;

				drawBackPotion = false;
			}

			//restore coffee symbol
			if (drawBackCoffee == true && maze[hero.Y - offsetY][hero.X - offsetX] != WALL)
			{
				SetConsoleCursorPosition(h, { hero.X - offsetX, hero.Y - offsetY });
				SetConsoleTextAttribute(h, DARKBLUE);
				cout << "u";

				drawBackCoffee = false;
			}

			//potion
			if (maze[hero.Y][hero.X] == POTION)
			{
				if (current_health == MAX_HEALTH)
				{
					draw_hero(hero, h);
					drawBackPotion = true;
				}

				else
				{
					current_health *= 1.05;
					maze[hero.Y][hero.X] = HALL;

					potion_sound.setBuffer(potion_buf);
					potion_sound.play();

					coffee_step_count = 0;
					cooldownCoffee = true;

					if (current_health >= MAX_HEALTH)
						current_health -= (current_health - MAX_HEALTH);
				}
			}

			//coffee
			if (maze[hero.Y][hero.X] == COFFEE)
			{
				if (cooldownCoffee == true)
				{
					draw_hero(hero, h);
					drawBackCoffee = true;
				}

				else if (cooldownCoffee == false)
				{
					maze[hero.Y][hero.X] = HALL;

					coffee_sound.setBuffer(coffee_buf);
					coffee_sound.play();

					energy += 26;
					if (energy > max_energy)
						energy -= (energy - max_energy);
				}
			}

			//-------------------------------------------------------------------// hero_attack

			if (isAttack == true && energy > 10)
			{
				COORD attack;
				attack.Y = hero.Y - 1;
				attack.X = hero.X - 1;

				punch_sound.setBuffer(punch_buf);
				punch_sound.play();

				for (int i = 0; i < 3; i++)
				{
					for (int j = 0; j < 3; j++)
					{
						if (maze[attack.Y][attack.X] == ENEMY)
						{
							maze[attack.Y][attack.X] = HALL;
							SetConsoleCursorPosition(h, attack);
							cout << " ";

							current_enemy_count--;
						}

						attack.X++;
					}

					attack.Y++;
					attack.X = hero.X - 1;
				}

				energy -= 10;
				isAttack = false;
			}

			//-------------------------------------------------------------------// enemy_step_gen

			if (current_enemy_count != enemy_count)
				step_count++;

			if (step_count >= 20 && current_enemy_count < enemy_count)
			{
				while (true)
				{
					COORD enemy;

					enemy.X = rand() % width - 2 + 1;
					enemy.Y = rand() % height - 2 + 1;

					if (maze[enemy.Y][enemy.X] != HALL)
						continue;

					maze[enemy.Y][enemy.X] = ENEMY;

					SetConsoleCursorPosition(h, enemy);
					SetConsoleTextAttribute(h, RED);
					cout << char(1);

					current_enemy_count++;

					step_count = 0;

					break;
				}
			}

			//-------------------------------------------------------------------// draw

			draw_hero(hero, h);
			draw_enemy_val(enemy_val, current_enemy_count, h);
			draw_gold_stat(gold_stat, gold_count, h);
			draw_health_stat(health_stat, current_health, h);
			draw_energy_stat(energy_stat, energy, h);
			draw_coffee_cooldown_stat(coffee_cooldown_stat, coffee_step_count, h);
			draw_enemy_gen_cooldown_stat(enemy_gen_cooldown_stat, step_count, h);

			//-------------------------------------------------------------------// cooldownCoffee_check

			if (cooldownCoffee == true)
				coffee_step_count++;

			if (coffee_step_count > 9)
			{
				cooldownCoffee = false;
				coffee_step_count = 0;
			}

			//-------------------------------------------------------------------// gold count in title

			_itoa_s(gold_count, title, 199, 10);
			SetConsoleTitleA(title);

			//-------------------------------------------------------------------//	game end state

			//exit
			if (hero.X == width - 1 && hero.Y == height - 3)
			{
				music.stop();
				win_sound.setBuffer(win_buf);
				win_sound.play();

				MessageBox(NULL, TEXT("Вы выиграли!"), TEXT("Сообщение!"), MB_OK);
				return 0;
			}

			//gold
			if (gold_count == gold_max)
			{
				music.stop();
				win_sound.setBuffer(win_buf);
				win_sound.play();

				MessageBox(NULL, TEXT("Вы собрали всё золото!"), TEXT("Сообщение!"), MB_OK);
				return 0;
			}

			//energy
			if (energy < 1)
			{
				music.stop();
				lose_sound.setBuffer(lose_buf);
				lose_sound.play();

				MessageBox(NULL, TEXT("Закончилась энергия!"), TEXT("Сообщение!"), MB_OK);
				return 0;
			}

			//enemy
			if (current_enemy_count == 0)
			{
				music.stop();
				lose_sound.setBuffer(lose_buf);
				lose_sound.play();

				MessageBox(NULL, TEXT("Все враги уничтожены!"), TEXT("Сообщение!"), MB_OK);
				return 0;
			}

			//death
			if (!current_health) 
			{
				music.stop();
				lose_sound.setBuffer(lose_buf);
				lose_sound.play();

				MessageBox(NULL, TEXT("Вы проиграли, закончилось здоровье!"), TEXT("Сообщение!"), MB_OK);
				return 0;
			}
		}

		else
		{
			
		}
	}
}