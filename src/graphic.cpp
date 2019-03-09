#include <graphic.hpp>

/*      *       *       *       *       Overall       *       *       *       *       */

void Graphic::init() {
    initscr(); //Initialises all implementation data structure and enviroment variable specifics.
    cbreak(); //Disable line buffering
    noecho(); //switches off echoing
    clear(); //clear terminal
    refresh();
    
    curs_set(0); //set appearance of the cursor to invisible
    keypad(stdscr, true); //turn on keypad translation
    nodelay(stdscr, true); //set stdscr to No Delay Mode

    start_color(); //start color functionalitsy
    if (!has_colors()) {
        printf("ERROR: Terminal does not support color!\n");
        exit(0);
    }

    int cnt = 0;
    for (int i = 0; i < 2; ++i) for (int j = 0; j < 5; ++j) if (i != j)
        Color::colors[i][j] = ++cnt;
    
    init_pair(Color::colors[0][1], COLOR_WHITE, COLOR_BLACK);
    init_pair(Color::colors[0][2], COLOR_YELLOW, COLOR_BLACK);
    init_pair(Color::colors[0][3], COLOR_RED, COLOR_BLACK);
    init_pair(Color::colors[0][4], COLOR_BLUE, COLOR_BLACK);
    init_pair(Color::colors[1][0], COLOR_BLACK, COLOR_WHITE);
    init_pair(Color::colors[1][2], COLOR_YELLOW, COLOR_WHITE);
    init_pair(Color::colors[1][3], COLOR_RED, COLOR_WHITE);
    init_pair(Color::colors[1][4], COLOR_BLUE, COLOR_WHITE);
}


void Graphic::load() {
    init();
    Color::init();
    Windows::init(); // initialises variables
    Windows::load(); // load beginning window
}

/*      *       *       *       *       Windows       *       *       *       *       */

const std::vector < std::string > title = {
    "student managerment"
};

std::vector < std::vector < std::string> > comps {
    { //main window
        "          LOGIN          ",
        "          ABOUT          "
    },
    { // login window

    },
    { // student window
        
    },
    { // lecturer window

    },
    { // staff main window
        "      Class Manager      ",
        "      Course Manager     ",
        "    Scoreboard Manager   "
    },
    { //staff class manager window
    },
    { //staff course manager window
    }
};

rectangle Graphic::Windows::subcomps[11][11];

void Graphic::Windows::init() {
    // main window
    subcomps[MAIN_WINDOW][FRAMES].set(0, 0, LINES, COLS);
    subcomps[MAIN_WINDOW][TITLE].set(subcomps[MAIN_WINDOW][FRAMES].bottom() / 4.5, 
                                    subcomps[MAIN_WINDOW][FRAMES].right() / 2 - title[0].size() / 2,
                                    title.size() + 1, title[0].size());
    subcomps[MAIN_WINDOW][LOGIN_BUTTON].set(subcomps[MAIN_WINDOW][TITLE].bottom() + 3, 
                                            subcomps[MAIN_WINDOW][FRAMES].right() / 2 - 15,
                                            3, 27);
    subcomps[MAIN_WINDOW][ABOUT_BUTTON].set(subcomps[MAIN_WINDOW][LOGIN_BUTTON].bottom() + 1,
                                            subcomps[MAIN_WINDOW][LOGIN_BUTTON].left(),
                                            3, 27);
    //login window
    
    //student main window

    //lecturer main window

    //staff main window
    subcomps[STAFF_WINDOW][CLASS_MANAGER_BUTTON].set(subcomps[MAIN_WINDOW][TITLE].bottom() + 3,
                                                    subcomps[MAIN_WINDOW][FRAMES].right() / 2 - 15,
                                                    3, 27);
    subcomps[STAFF_WINDOW][COURSE_MANAGER_BUTTON].set(subcomps[STAFF_WINDOW][CLASS_MANAGER_BUTTON].bottom() + 1,
                                                    subcomps[STAFF_WINDOW][CLASS_MANAGER_BUTTON].left(),
                                                    3, 27);
    subcomps[STAFF_WINDOW][STAFF_SCOREBOARD_BUTTON].set(subcomps[STAFF_WINDOW][COURSE_MANAGER_BUTTON].bottom() + 1,
                                                    subcomps[STAFF_WINDOW][COURSE_MANAGER_BUTTON].left(),
                                                    3, 27);
    subcomps[STAFF_WINDOW][STAFF_CLASS_WINDOW].set(subcomps[MAIN_WINDOW][TITLE].bottom() + 3,
                                                    subcomps[MAIN_WINDOW][FRAMES].right() / 2 - 21,
                                                    30, 43);
                                                    
}

void Graphic::Windows::load() {
    StaffWindow();
}

void Graphic::Windows::clear(int x, int y, int h, int w) {
    for (int i = 0; i < h; ++i) for (int j = 0; j < w; ++j)
        mvaddch(x + i, y + j, ' ');
    refresh();
}

void Graphic::Windows::updateptr(int curWin, int curPtr, int stat, int end) {
    for (int i = stat; i < end; ++i) {
        subcomps[curWin][i].drawEdges();
        
        if (curPtr == i - stat) Color::reverseOn();
        mvprintw(subcomps[curWin][i].top() + 1, subcomps[curWin][i].left() + 1, "%s", comps[curWin][i - stat].c_str());
        if (curPtr == i - stat) Color::reverseOff();
    }
    refresh();
}

void Graphic::Windows::MainWindow() {
    clear(subcomps[MAIN_WINDOW][FRAMES].top() + 1, 
        subcomps[MAIN_WINDOW][FRAMES].left() + 1, 
        subcomps[MAIN_WINDOW][FRAMES].height() - 2, 
        subcomps[MAIN_WINDOW][FRAMES].width() - 2);

    subcomps[MAIN_WINDOW][FRAMES].drawEdges();

    for (int i = 0; i < title.size(); ++i)
        for (int j = 0; j < title[i].size(); ++j)
            mvaddch(subcomps[MAIN_WINDOW][TITLE].top() + i, subcomps[MAIN_WINDOW][TITLE].left() + j, title[i][j]);

    int currentPtr = 0;

    while (true) {
        int input = getch();
        if (input == 'q' || input == 'Q') {
            break;
        }
        if (input == KEY_UP || input == KEY_DOWN) {
            currentPtr = (currentPtr + 1) % 2;
        } else if (input == '\n' || input == ' ') {
            if (currentPtr == 0) LoginWindow();
            else AboutWindow();
        }
        updateptr(MAIN_WINDOW, currentPtr, LOGIN_BUTTON, sizeof(MAINWINDOW));
    }
}

void Graphic::Windows::LoginWindow() {

}

void Graphic::Windows::AboutWindow() {

}

void Graphic::Windows::StudentWindow() {

}

void Graphic::Windows::LecturerWindow() {

}

void Graphic::Windows::StaffWindow() {
    clear(subcomps[MAIN_WINDOW][TITLE].top() + 1, 
        subcomps[MAIN_WINDOW][FRAMES].left() + 1, 
        subcomps[MAIN_WINDOW][FRAMES].bottom() - subcomps[MAIN_WINDOW][TITLE].bottom() - 1, 
        subcomps[MAIN_WINDOW][FRAMES].width() - 2);

    int currentPtr = 0;
    while (true) {
        int input = getch();
        if (input == 'b' || input == 'B') { // back to main window
            break;
        }
        if (input == KEY_DOWN) {
            currentPtr = (currentPtr + 1) % 3;
        } else if (input == KEY_UP) {
            currentPtr = (currentPtr - 1 + 3) % 3;
        } else if (input == '\n' || input == ' ') {
            if (currentPtr == 0) StaffClassManager();
            else if (currentPtr == 1) StaffCourseManager();
            else StaffScoreboardManager();
        }
        updateptr(STAFF_WINDOW, currentPtr, 0, 3);
    }
}

void Graphic::Windows::StaffClassManager() {
    clear(subcomps[MAIN_WINDOW][TITLE].top() + 1, 
        subcomps[MAIN_WINDOW][FRAMES].left() + 1, 
        subcomps[MAIN_WINDOW][FRAMES].bottom() - subcomps[MAIN_WINDOW][TITLE].bottom() - 1, 
        subcomps[MAIN_WINDOW][FRAMES].width() - 2);

    
    subcomps[STAFF_WINDOW][STAFF_CLASS_WINDOW].drawEdges();
    refresh();
    std::vector < std::string>  &cur = comps[STAFF_CLASS_WINDOW];
    cur = Staff::Classes::getClassList();

}

void Graphic::Windows::StaffCourseManager() {

}

void Graphic::Windows::StaffScoreboardManager() {

}

/*      *       *       *       *       Color       *       *       *       *       */

int Graphic::Color::currentBackgroundColor;
int Graphic::Color::colors[2][5];

void Graphic::Color::init() {
    currentBackgroundColor = 0;
}

void Graphic::Color::reverseColorOn(int x) {
    attron(COLOR_PAIR(colors[1 - currentBackgroundColor][x]));
}

void Graphic::Color::reverseColorOff(int x) {
    attroff(COLOR_PAIR(colors[1 - currentBackgroundColor][x]));
}

void Graphic::Color::colorOn(int x) {
    attron(COLOR_PAIR(colors[currentBackgroundColor][x]));
}

void Graphic::Color::colorOff(int x) {
    attroff(COLOR_PAIR(colors[currentBackgroundColor][x]));
}

void Graphic::Color::reverseOn() {
    attron(COLOR_PAIR(colors[1 - currentBackgroundColor][currentBackgroundColor]));
}

void Graphic::Color::reverseOff() {
    attroff(COLOR_PAIR(colors[1 - currentBackgroundColor][currentBackgroundColor]));
}

void Graphic::Color::setCurrentBackgroundColor(int x) { currentBackgroundColor = x; }