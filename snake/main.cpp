#include <bits/stdc++.h>
#include <curses.h>
#include "ui.h"
#include "game.h"
#include <chrono>
#include "settings_constant.h"
using namespace std;

/*
    TO DO 
    1) Add color to things
    2) HIGH SCORE - database, file where you can store
    3) Multiple no of lives of snake |
    4) One big food point It some period]
    5) Multiple levels, multiple snakes
    6) Change the structure of border
    7) Increase the speed gradually
*/

void event_loop() {
    int dt;
    while (true) {
        bool game_over;
        game_over = game_logic();
        if(game_over)
            break;
        auto last_time = chrono::system_clock::now();
        erase();
        game_logic();
        refresh();
        do {
            auto current_time = chrono::system_clock::now();
            dt = chrono::duration_cast<std::chrono::microseconds>(current_time - last_time).count();
        }
        while(dt < TIME_DELAY_BETWEEN_FRAMES);
    }    
}

int main() {
   init_ui();
   event_loop();
   tear_down_ui();
    return 0;
}