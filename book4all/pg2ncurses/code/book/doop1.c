#include <curses.h>

int main()
{
	WINDOW *alpha;
	char text1[] = "Lorem ipsum dolor sit amet, consectetuer adipiscing elit, sed diam nonummy nibh euismod tincidunt ut laoreet dolore magna aliquam erat volutpat. Ut wisi enim ad minim veniam, quis nostrud exerci tation ullamcorper suscipit lobortis nisl ut aliquip ex ea commodo consequat.";
	char text2[]= "Four score and seven years ago our fathers brought forth on this continent, a new nation, conceived in Liberty, and dedicated to the proposition that all men are created equal.";

	initscr();

        start_color();                 /* Remember to check for errors! */
        init_pair(1, COLOR_RED, COLOR_BLACK);
        init_pair(2, COLOR_WHITE,  COLOR_BLACK);


/* Build windows */
	alpha = newwin(0,0,0,0);		/* Remember to check for errors! */


        attron(COLOR_PAIR(1));                  /* Add color to text           */
	addstr(text1);		        	/* Add text to stdscr and wait */
	refresh();
	getch();

        wattron(alpha, COLOR_PAIR(2));          /* Add color to text       */
	waddstr(alpha,text2);			/* Show win alpha and wait */
	wrefresh(alpha);
	getch();

/* Copy text from one window to the other, non-destructively */
	overlay(stdscr,alpha);
	wrefresh(alpha);
	getch();

	endwin();
	return(0);
}
