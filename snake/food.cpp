#include "food.h"


vector < pair <int, int> > food_item;
char food_character = (char) 36;
pair<int, int> make_food() {
    return{rand() % (LINES - 2) + 1, rand() % (COLS - 2) + 1};
}
void init_food() {
    food_item.clear();
    for(int i = 0; i < FOOD_COUNT; i++)
        food_item.push_back(make_food());
}

void paint_food() {
    for(int i = 0; i < food_item.size(); i++) {
        move(food_item[i].first, food_item[i].second);
        addch(food_character);
    }
}

bool try_eating_food(pair<int, int> head) {
    for(int i = 0; i < food_item.size(); i++){
        if(head.first == food_item[i].first && head.second == food_item[i].second) {
            food_item.erase(food_item.begin() + i);
            food_item.push_back(make_food());
            return true;
        }
    }
    return false;
}