#include <ncurses.h>
#include <stdio.h>

int main() {
    SCREEN* term0 = newterm(0, stdout, stdin);
    SCREEN* term1 = newterm(0, stdout, stdin);

    printw("hi term1");
    refresh();
    getch();

    set_term(term0);
    refresh();
    printw("hi term0");
    refresh();
    getch();

    set_term(term1);
    refresh();
    printw("hi term1 again");
    mvprintw(3, 0, "hi term1 from blah");
    getch();

    endwin();
    delscreen(term1);

    set_term(term0);
    endwin();
    delscreen(term0);
    return 0;
}
