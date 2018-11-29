#include <ncurses.h>
#include <string.h>



int menu_out;

int menu(int y, int x, char (*items) [1024])
{
	int maxx, maxy;
	int focused = 1;

	init_pair(2, COLOR_BLACK, COLOR_WHITE);
    	init_pair(3, COLOR_RED, COLOR_WHITE);
	init_pair(4, COLOR_WHITE, COLOR_RED);
    
    	getmaxyx(stdscr, maxy, maxx);
    	WINDOW *shadow = newwin(y, x, maxy/2 - y/2.5, maxx/2 - x/2.3);
	WINDOW *win = newwin(y, x, maxy/2 - y/2, maxx/2 - x/2);
	refresh();
	wbkgd(win, COLOR_PAIR(2));
	box(win, 0, 0);
	mvwprintw(win, 0, x/2 - 4, "| ");
	wattron(win, COLOR_PAIR(3));
	mvwprintw(win, 0, x/2 - 2, "DSCC");
	wattroff(win, COLOR_PAIR(3));
	mvwprintw(win, 0, x / 2 + 2, " |");
	wrefresh(shadow);
	wrefresh(win);
	keypad(win, true);
	int k = 1;

	while(k == 1)
	{
		for(int i = 1; i <= 4; i++)
		{
			if (i == focused)
			{
				wattron(win, COLOR_PAIR(4));
			}
			if ((i - 1) != 3)
			{
				mvwprintw(win, i + 1, 1, items[i - 1]);
			} else {
				mvwprintw(win, y - 2, x/2 - strlen(items[3])/2, items[i - 1]);	
			}
			wattroff(win, COLOR_PAIR(4));
			wrefresh(win);
		}
		int choice = mvwgetch(win, y - 2, 1);

		switch(choice)
		{
			case KEY_UP:
			{
				focused--;
				if (focused == 0) focused = 1;
				break;
			}
			case KEY_DOWN:
			{
				focused++;
				if (focused == 5) focused = 4;
				break;
			}
		}
		if (choice == 10) k = 0;
	}
    menu_out = focused;
    return 0;
}
