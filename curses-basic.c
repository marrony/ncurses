#include <ncurses.h>

int main(int argc, char* argv[]) {
    initscr();                 /* Initialize ncurses  */
    curs_set(0);               /* Makes the cursor invisible */
    printw("Hello World !!!"); /* Print a message */
    refresh();                 /* Print it on to the screen */
    getch();                   /* Wait user press a key */
    endwin();                  /* Finish curses */
    return 0;
}

