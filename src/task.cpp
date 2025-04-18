#include "../include/task.hpp"

int task::s_TotalTaskNum = 0;
std::vector<task*> task::taskList;
int task::scrollNum = 0;
bool task::upwardsScrollable = false;
bool task::downwardsScrollable= false;

task::task()
{
    this->taskNum = taskList.size()+1;
    s_TotalTaskNum = taskList.size()+1;
    card.setFillColor(sf::Color(18,18,18));
}

task::~task()
{
    for(auto& task : taskList)
    {
        delete task;
    }
}

void task::updateScrollable()
{
    static int mainScreenWidth;
    static int mainScreenHeight;

    mainScreenHeight = utils::windowSize.y;
    mainScreenWidth=utils::windowSize.x - utils::seperationPointCurrentX;

    upwardsScrollable = true;
    downwardsScrollable = true;
    main_screen::scrollBarVisible = true;

    static int totalHeight = 0;
    if(taskList.size() != 0)
    {
        totalHeight = s_TotalTaskNum*(taskList.back()->card.getSize().y + 10) + 10;
    }
    else
    {
        totalHeight = 0;    
    }

    if (totalHeight<mainScreenHeight)
    {
        upwardsScrollable = false;
        downwardsScrollable = false;
        main_screen::scrollBarVisible = false;
    }
    else if (taskList[0]->card.getPosition().y >= 10)
    {
        upwardsScrollable = false;
        taskList[0]->card.setPosition(utils::seperationPointCurrentX + 10, 10);
    }
    else if (taskList.back()->card.getPosition().y + taskList.back()->card.getSize().y  <= mainScreenHeight - 10)
    {
        downwardsScrollable = false;
        taskList.back()->card.setPosition(utils::seperationPointCurrentX + 10 + mainScreenWidth / 2 - 20, taskList.back()->card.getPosition().y);
    }
}

void task::updateCardSize()
{
    static int mainScreenWidth;
    static int mainScreenHeight;

    mainScreenHeight = utils::windowSize.y;
    mainScreenWidth=utils::windowSize.x - utils::seperationPointCurrentX;


    //CHATGPT
    ///---
    int index = 0;
    int columns = 1;
    int rows = 1;
    float width = mainScreenWidth - 20;
    float height = mainScreenHeight - 20;
    
    if (settings_window::tasksShown == settings_window::Tasks_shown::TWO || 
        (settings_window::tasksShown == settings_window::Tasks_shown::RESIZABLE && s_TotalTaskNum == 2)) {
        columns = 2; rows = 1;
        width = mainScreenWidth / 2 - 20;
        height = mainScreenHeight - 20;
    }
    else if (settings_window::tasksShown == settings_window::Tasks_shown::FOUR || 
            (settings_window::tasksShown == settings_window::Tasks_shown::RESIZABLE && s_TotalTaskNum <= 4)) {
        columns = 2; rows = 2;
        width = mainScreenWidth / 2 - 20;
        height = mainScreenHeight / 2 - 20;
    }
    else if (settings_window::tasksShown == settings_window::Tasks_shown::SIX || 
            (settings_window::tasksShown == settings_window::Tasks_shown::RESIZABLE && s_TotalTaskNum > 4)) {
        columns = 2; rows = 3;
        width = mainScreenWidth / 2 - 20;
        height = mainScreenHeight / 3 - 20;
    }
    // ONE and RESIZABLE with 1 task (fallback/default)
    else {
        columns = 1; rows = 1;
        width = mainScreenWidth - 30;
        height = mainScreenHeight - 20;
    }
    
    float x = utils::seperationPointCurrentX + 10;
    float y = 10;
    
    for (auto& task : taskList) {
        int col = index % columns;
        int row = index / columns;
    
        float xpos = x + col * (width + 10);
        float ypos = y + row * (height + 10) - scrollNum;
    
        task->card.setSize(sf::Vector2f(width, height));
        task->card.setPosition(sf::Vector2f(xpos, ypos));
    
        ++index;
    }
}

void task::draw()
{
    for(auto& task : taskList)
    {
        utils::window.draw(task->card);
    }
}

void task::update()
{
    updateCardSize();
    draw();
}