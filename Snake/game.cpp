#include "game.h"


// int i = 10;
// int x = 10, y = 10;
int game_state = BEFORE_STARTED;
int direction;
int score;
void start_game() {
    init_snake();
    init_food();
    direction = UP;
    game_state = STARTED;
    score = 0;
}

void end_game() {
    game_state = END_STATE;
}

void paint_score() {
    move(0,5);
    printw("Score : %d ", score);
}

bool game_logic() {
     paint_border();
     paint_score();
    int key = getch();
    if(game_state == BEFORE_STARTED) {
        move(10, 10);
        addstr("|||||||||| Press SPACE to start ......... :) ||||||||||");
        if(key == 32) {
            start_game();
        }
    } else if(game_state == STARTED){
        if(key == UP && direction != DOWN) {
            direction = UP;
        } else if(key == DOWN && direction != UP ) {
            direction = DOWN;
        } if(key == RIGHT && direction != LEFT) {
            direction = RIGHT;
        } else if(key == LEFT && direction != RIGHT) {
            direction = LEFT;
        }
        pair <int, int> head = move_snake(direction);

        if(try_eating_food(head)) {
            score++;
            grow_snake();
        }

        if(has_collison()) {
            end_game();
        }

        paint_snake();
        paint_food();
    } else {
        move(10, 10);
        addstr("|||||||||| GAME OVER !! :( Press SPACE to restart or Q to quit ||||||||||");
        if(key == 32) {
            start_game();
        } else if(key == 'q') {
            return true;
        }
    }

    return false;

}