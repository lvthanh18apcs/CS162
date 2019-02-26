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

};

rectangle Graphic::Windows::windows[11];
rectangle Graphic::Windows::subcomps[11][11];

void Graphic::Windows::init() {
    // main window
    windows[MAIN_WINDOW][]
}

void Graphic::Windows::load() {
    refresh();
}

void Graphic::Windows::clear(int x, int y, int h, int w) {
    for (int i = 0; i < h; ++i) for (int j = 0; j < w; ++j)
        mvaddch(x + i, y + j, ' ');
    refresh();
}

void Graphic::Windows::LoginWindow() {

}

void Graphic::Windows::StudentWindow() {

}

void Graphic::Windows::LecturerWindow() {

}

void Graphic::Windows::StaffWindow() {

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