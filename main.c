#include <ncurses.h>
#include <stdlib.h>
#include "menu.h"
#include <string.h>

int main()
{
	int maxx,maxy;
	int x = 40;
	int y = 10;
	char items[3][1024];
		strcpy(items[0], "Calculator");
		strcpy(items[1], "Ascii art");
		strcpy(items[2], "item3");
		strcpy(items[3], "<Exit>");
	int focused = 1;

	initscr();
	start_color();

	init_pair(1, COLOR_WHITE, COLOR_BLUE);

	bkgd(COLOR_PAIR(1));
	getmaxyx(stdscr, maxy, maxx);
	menu(y, x, items);
	bkgd(COLOR_PAIR(1));
	
	switch(menu_out)
	{
		case 1:
		{
			strcpy(items[0], "Decimal");
			strcpy(items[1], "Hexdecimal");
			strcpy(items[2], "Binary");
			strcpy(items[3], "<Back>");
			menu(y, x, items);
		}	
		
	}
	if (strcmp(items[focused - 1], "<Exit>") == 0) return 0;
	refresh();
	getch();
	endwin();
	return 0;
}
