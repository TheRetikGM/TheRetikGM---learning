#include <ncurses.h>
#include <stdlib.h>
#include "menu.h"

int main()
{
	int maxx,maxy;
	int x = 20;
	int y = 10;
	char items[3][1024] = {"Calculator", "Ascii art", "item3"};	
	int focused = 1;

	initscr();
	start_color();

	init_pair(1, COLOR_WHITE, COLOR_BLUE);

	bkgd(COLOR_PAIR(1));
	getmaxyx(stdscr, maxy, maxx);
	menu(10, 40, items);
	bkgd(COLOR_PAIR(1));
	printw("%s", items[menu_out - 1]);
	refresh();
	getch();
	endwin();
	return 0;
}
