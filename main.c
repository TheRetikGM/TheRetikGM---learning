#include <ncurses.h>
#include <stdlib.h>
#include "menu.h"
#include <string.h>
#include <unistd.h>

char items[4][1024];

void menu_cal()
{
	strcpy(items[0], "Next..");
	strcpy(items[1], "Number system");
	strcpy(items[2], "Angle unit");
	strcpy(items[3], "<Back>");
}

void menu_main()
{
	strcpy(items[0], "Calculator");
	strcpy(items[1], "Ascii art");
	strcpy(items[2], "item3");
	strcpy(items[3], "<Exit>");
}
void menu_cal_numsys()
{
	strcpy(items[0], "Decimal");
	strcpy(items[1], "Hexdecimal");
	strcpy(items[2], "Binary");
}

int main()
{
	int maxx,maxy;
	int x = 40;
	int y = 10;
	int focused = 1;
	int menus = 0;
	
	while (1)
	{
		initscr();
		start_color();

		init_pair(1, COLOR_WHITE, COLOR_BLUE);

		bkgd(COLOR_PAIR(1));
		getmaxyx(stdscr, maxy, maxx);

		if (menus == 0) menu_main();
		else if (menus == 1) menu_cal();
		else if (menus == 12) menu_cal_numsys(); 
		menu(y, x, items);
		bkgd(COLOR_PAIR(1));
		refresh();

		if (menu_out == 1 && menus == 0) menus = 1;
		else if (menu_out == 2 && menus == 0);
		else if (menu_out == 3 && menus == 0);
		else if (menu_out == 1 && menus == 1);
		else if (menu_out == 2 && menus == 1) menus = 12;
		else if (menu_out == 3 && menus == 1);
		else if (menu_out == 1 && menus == 12) {/* sets numeral system to decimal */ menus = 1;}
		else if (menu_out == 2 && menus == 12) {/* sets numeral system to Hexdecimal */ menus = 1;}
		else if (menu_out == 3 && menus == 12) {/* sets numeral system to Binary */ menus = 1;}

		if (strcmp(items[menu_out - 1], "<Exit>") == 0)
		{
			refresh();
			endwin();
			break;
		}
		else if (strcmp(items[menu_out - 1], "<Back>") == 0)
		{
			if (menus < 11) menus--;
			else if (menus == 11) menus = 1;
			else if (menus == 12) menus = 1;
		}
	}
	return 0;
}
