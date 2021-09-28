#include <windows.h>
#include <iostream>
using namespace std;

enum colors { BLUE = 9, RED = 12, YELLOW = 14, DARKGREEN = 2, DARKBLUE = 1 };

//------------------------------------------------------------// stats

void draw_hero(COORD hero, HANDLE h)
{
	SetConsoleCursorPosition(h, hero);
	SetConsoleTextAttribute(h, BLUE);
	cout << (char)1;
}

void draw_gold_stat(COORD gold_stat, int gold_count, HANDLE h)
{
	SetConsoleCursorPosition(h, gold_stat);
	SetConsoleTextAttribute(h, YELLOW);
	cout << "Gold: " << gold_count;
}

void draw_gold_stat_max(COORD gold_stat_max, int gold_max, HANDLE h)
{
	SetConsoleCursorPosition(h, gold_stat_max);
	SetConsoleTextAttribute(h, YELLOW);
	cout << "Total: " << gold_max;
}

void draw_enemy_val(COORD enemy_val, int current_enemy_count, HANDLE h)
{
	SetConsoleCursorPosition(h, enemy_val);
	SetConsoleTextAttribute(h, RED);
	cout << "Enemies: " << current_enemy_count << " ";
}

void draw_health_stat(COORD health_stat, float current_health, HANDLE h)
{
	SetConsoleCursorPosition(h, health_stat);
	SetConsoleTextAttribute(h, BLUE);
	cout << "Health: " << (int)current_health << " ";
}

void draw_energy_stat(COORD energy_stat, int energy, HANDLE h)
{
	SetConsoleCursorPosition(h, energy_stat);
	SetConsoleTextAttribute(h, DARKBLUE);
	cout << "Energy: " << energy << "  ";
}

void draw_coffee_cooldown_stat(COORD coffee_cooldown_stat, int coffee_step_count, HANDLE h)
{
	SetConsoleCursorPosition(h, coffee_cooldown_stat);
	SetConsoleTextAttribute(h, DARKBLUE);
	cout << "Coffee cooldown: " << coffee_step_count << "  ";
}

void draw_enemy_gen_cooldown_stat(COORD enemy_gen_cooldown_stat, int step_count, HANDLE h)
{
	SetConsoleCursorPosition(h, enemy_gen_cooldown_stat);
	SetConsoleTextAttribute(h, RED);
	cout << "Spawn cooldown: " << step_count << " ";
}