#pragma once

void cursor_coord(short x, short y);
void hide_cursor();

void fill_board(int board[4][4]);
void draw_board(int board[4][4]);

int get_input();
int random_input();

int movement(int board[4][4]);
void board_anim(int offsetX, int offsetY, int board[4][4]);

bool win_check(int board[4][4]);