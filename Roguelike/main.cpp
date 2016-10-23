#include <curses.h>

#include "utils.h"
#include "map.h"
#include "units.h"
#include "level.h"

int main()
{
	init();
	
	WINDOW *field = newwin(25, 70, 5, 2);
	WINDOW *player_info = newwin(10, 25, 0, 72);
	
	for (char i = COLOR_BLACK; i <= COLOR_WHITE; ++i)
		for (char j = COLOR_BLACK; j <= COLOR_WHITE; ++j)
			init_pair(1 + 8 * i + j, i, j);

	Level level(LT_RANDOM, 100, 100, field, "name", player_info);

	while (level.Iterate()) {
		;
	}

	getch();
	endwin();
	return 0;
}