#include <ncurses.h>
#include <stdlib.h>
#include "menu.h"
#include <string.h>

char items[4][1024];

void menucal()
{
	strcpy(items[0], "Decimal");
	strcpy(items[1], "Hexdecimal");
	strcpy(items[2], "Binary");
	strcpy(items[3], "<Back>");
}

void mainmenu()
{
	strcpy(items[0], "Calculator");
	strcpy(items[1], "Ascii art");
	strcpy(items[2], "item3");
	strcpy(items[3], "<Exit>");
}

int main()
{
	int maxx,maxy;
	int x = 40;
	int y = 10;
	int focused = 1;
	int menus = 1;
	
	while (1)
	{
		initscr();
		start_color();

		init_pair(1, COLOR_WHITE, COLOR_BLUE);

		bkgd(COLOR_PAIR(1));
		getmaxyx(stdscr, maxy, maxx);
		if (menus == 1) mainmenu();
		else if(menus == 2) menucal();
		menu(y, x, items);
		bkgd(COLOR_PAIR(1));
		
		switch(menu_out)
		{
			case 1:
			{
				menus = 2;
				menucal();
				menu(y, x, items);
			}	
			
		}
		if (strcmp(items[menu_out - 1], "<Exit>") == 0)
		{
			refresh();
			endwin();
			break;
		}
		else if (strcmp(items[menu_out - 1], "<Back>") == 0)
		{
			menus--;
		}
	}
	return 0;
}
