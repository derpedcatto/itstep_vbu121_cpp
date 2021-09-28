#pragma once

void draw_hero(COORD hero, HANDLE h);
void draw_enemy_val(COORD enemy_val, int current_enemy_count, HANDLE h);
void draw_gold_stat(COORD gold_stat, int gold_count, HANDLE h);
void draw_gold_stat_max(COORD gold_stat_max, int gold_max, HANDLE h);
void draw_health_stat(COORD health_stat, float current_health, HANDLE h);
void draw_energy_stat(COORD energy_stat, int energy, HANDLE h);
void draw_coffee_cooldown_stat(COORD coffee_cooldown_stat, int coffee_step_count, HANDLE h);
void draw_enemy_gen_cooldown_stat(COORD enemy_gen_cooldown_stat, int step_count, HANDLE h);