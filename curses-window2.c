#include <stdlib.h>
#include <stdio.h>
#include <curses.h>


int main(void) {

    WINDOW* mainwin;
    WINDOW* childwin;
    WINDOW* childwin2;

    int      ch;


    /*  Set the dimensions and initial
     *      position for our child window   */

    int      width = 50, height = 17;
    int      rows  = 25, cols   = 80;
    int      x = (cols - width)  / 2;
    int      y = (rows - height) / 2;


    /*  Initialize ncurses  */

    if ( (mainwin = initscr()) == NULL ) {
        fprintf(stderr, "Error initialising ncurses.\n");
        exit(EXIT_FAILURE);
    }

    start_color();
    init_pair(1, COLOR_CYAN, COLOR_BLACK);

    /*  Switch of echoing and enable keypad (for arrow keys)  */

    noecho();
    keypad(mainwin, TRUE);

    //scrollok(mainwin, TRUE);

    /*  Make our child window, and add
     *      a border and some text to it.   */

    childwin = newwin(height, width, y, x);
    box(childwin, 0, 0);

    childwin2 = derwin(childwin, 10, 15, 0, 0);
    box(childwin2, 0, 0);

    werase(childwin2);
    mvderwin(childwin2, 1, 5);
    box(childwin2, 0, 0);
    //wrefresh(childwin2);
    
    touchwin(childwin);

    mvwaddstr(childwin2, 1, 1, "Move the window");
    //mvwaddstr(childwin, 2, 2, "with the arrow keys");
    //mvwaddstr(childwin, 3, 6, "or HOME/END");
    //mvwaddstr(childwin, 5, 3, "Press 'q' to quit");

    refresh();

    mvwchgat(childwin2, 1, 1, -1, A_UNDERLINE | A_BOLD | A_BLINK, 1, NULL);

    /*  Loop until user hits 'q' to quit  */

    while ( (ch = getch()) != 'q' ) {

        switch ( ch ) {

            case KEY_UP:
                if ( y > 0 )
                    --y;
                break;

            case KEY_DOWN:
                //if ( y < (rows - height) )
                    ++y;
                break;

            case KEY_LEFT:
                if ( x > 0 )
                    --x;
                break;

            case KEY_RIGHT:
                if ( x < (cols - width) )
                    ++x;
                break;

            case KEY_HOME:
                x = 0;
                y = 0;
                break;

            case KEY_END:
                x = (cols - width);
                y = (rows - height);
                break;

        }

#if 0
        werase(childwin);
        wnoutrefresh(childwin);
        mvwin(childwin, y, x);
        box(childwin, 0, 0);

        wnoutrefresh(childwin);
        doupdate();
#else
        touchwin(mainwin);
        wrefresh(mainwin);
        
        mvwin(childwin, y, x);
        wrefresh(childwin);

        //wrefresh(childwin2);
#endif
        int prefresh(WINDOW *pad, int pminrow, int pmincol,
                     int sminrow, int smincol, int smaxrow, int smaxcol);
    }


    /*  Clean up after ourselves  */

    delwin(childwin2);
    delwin(childwin);
    delwin(mainwin);
    endwin();
    refresh();

    return EXIT_SUCCESS;
}
