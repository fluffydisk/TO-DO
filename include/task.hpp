#pragma once
#include "utils.hpp"
#include <vector>


class task
{
public:
    task();
    ~task();
    static void update();
    static int s_TotalTaskNum;
    static std::vector<task*> taskList;
    sf::RectangleShape card;
    static int scrollNum;
    static bool upwardsScrollable;
    static bool downwardsScrollable;
    static void updateScrollable();
    int taskNum;
private:
    static void updateCardSize();
    static void draw();
};

