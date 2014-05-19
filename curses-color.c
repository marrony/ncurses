#include <ncurses.h>

int main() {
    initscr();
    start_color(); /* Enable colors */
    init_pair(1, COLOR_RED, COLOR_CYAN);
    init_pair(2, COLOR_YELLOW, COLOR_GREEN);
    attron(A_UNDERLINE | COLOR_PAIR(1));
    printw("underlined red text with cyan background\n");
    attroff(A_UNDERLINE | COLOR_PAIR(1));
    attron(A_BOLD | COLOR_PAIR(2));
    printw("bold yellow text with green background");
    attroff(A_BOLD | COLOR_PAIR(2));
    refresh();            
    getch();          
    endwin();     
    return 0;
}


