#ifndef GRAPHIC_H_DEFINED
#define GRAPHIC_H_DEFINED

#include <ncurses.h>

#include <vector>
#include <string>
#include <utility>
#include <functional>

enum WINDOWS {
    MAIN_WINDOW,
    LOGIN_WINDOW,
    STUDENT_WINDOW,
    LECTURER_WINDOW,
    STAFF_WINDOW
};

enum MAINWINDOW {
    FRAMES,
    TITLE,
    LOGIN_BUTTON,
    ABOUT_BUTTON
};

enum LOGINWINDOW {
    USERNAME,
    PASSWORD,
    LOGIN,
    CANCEL
};

enum STUDENTWINDOW {
    STUDENT_PROFILE_BUTTON,
    CHECKIN_BUTTON,
    SCHEDULE_BUTTON,
    SCOREBOARD_BUTTON
};

enum LECTURERWINDOW {
    LECTURER_PROFILE_BUTTON,
    COURSE_WINDOW
};

enum STAFFWINDOW {
    CLASS_MANAGER_BUTTON,
    COURSE_MANAGER_BUTTON,
    STAFF_SCOREBOARD_BUTTON
};

enum LECTURER_COURSE_WINDOW {
    COURSE_INFO_BUTTON,
    ATTENDANCE_BUTTON,
    LECTURER_SCOREBOARD_BUTTON
};

struct rectangle {
    int x, y, w, h;
    void set(int _x, int _y, int _h, int _w) {
        x = _x; y = _y; h = _h; w = _w;
    }
    int top() { return x; }
    int bottom() { return x + h - 1; }
    int left() { return y; }
    int right() { return y + w - 1; }

    int width() { return w; }
    int height() { return h; }

    void drawEdges() {
        attron(A_BOLD);
        for (int i = top(); i <= bottom(); ++i) {
            int x = i - top();
            mvaddch(i, left(), ACS_VLINE);
            mvaddch(i, right(), ACS_VLINE);
        }
        for (int i = left(); i <= right(); ++i) {
            int x = i - left();
            mvaddch(top(), i, ACS_HLINE);
            mvaddch(bottom(), i, ACS_HLINE);
        }
        mvaddch(top(), left(), ACS_ULCORNER);
        mvaddch(top(), right(), ACS_URCORNER);
        mvaddch(bottom(), left(), ACS_LLCORNER);
        mvaddch(bottom(), right(), ACS_LRCORNER);
    }
    void drawTable() {
        attron(A_BOLD);
        for (int x = top(); x <= bottom(); ++x)
            for (int y = left(); y <= right(); ++y) {
                int h = x - top(), w = y - left();
                if (h % 2 && w % 2) continue;
                if (h % 2) {
                    mvaddch(x, y, ACS_VLINE);
                } else {
                    mvaddch(x, y, (w % 2) ? ACS_HLINE : ACS_DIAMOND);
                }
            }
        attroff(A_BOLD);
    }
};

namespace Graphic {
    namespace Windows {
        extern rectangle subcomps[11][11];
        
        void init();
        
        void load();

        void clear(int, int, int, int);

        void updateptr(int, int, int, int);

        void MainWindow();
        void LoginWindow();
        void AboutWindow();

        void StudentWindow();

        void LecturerWindow();

        void StaffWindow();
        void StaffClassManager();
        void StaffCourseManager();
        void StaffScoreboardManager();
    };

    namespace Color {
        extern int currentBackgroundColor;
        extern int colors[2][5];

        void init();
        
        void setCurrentBackgroundColor(int x);
        
        void colorOn(int x);
        
        void colorOff(int x);
        
        void reverseColorOn(int x);
        
        void reverseColorOff(int x);
        
        void reverseOn();
        
        void reverseOff();
    }

    void init();

    void load();
};

#endif