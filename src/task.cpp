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
    
    if (s_TotalTaskNum < 6)
    {
        upwardsScrollable = false;
        downwardsScrollable = false;
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



    int index = 0;
    for (auto& task : taskList)
    {
        float x = utils::seperationPointCurrentX + 10;
        float y = 10;
    
        /*
        float width = mainScreenWidth / 2 - 20;
        float height = mainScreenHeight / 3 - 20;
        task->card.setSize(sf::Vector2f(width, height));
        float xpos = x + (index % 2) * (width + 10);
        float ypos = y + (index / 2) * (height + 10);
        task->card.setPosition(sf::Vector2f(xpos, ypos - scrollNum));
        */
       
       //Optional version of drawing new created tasks 
       if (s_TotalTaskNum == 1)
       {
           // Full width, full height
            task->card.setSize(sf::Vector2f(mainScreenWidth - 20, mainScreenHeight - 20));
            task->card.setPosition(sf::Vector2f(x, y - scrollNum));
        }
        else if (s_TotalTaskNum == 2)
        {
            // Two vertical cards
            float height = mainScreenHeight - 20;
            float width = mainScreenWidth / 2 - 20;
            task->card.setSize(sf::Vector2f(width, height));
            task->card.setPosition(sf::Vector2f(x + index * (width + 10), y - scrollNum));
        }
        else if (s_TotalTaskNum <= 4)
        {
            // 2x2 grid
            float width = mainScreenWidth / 2 - 20;
            float height = mainScreenHeight / 2 - 20;
            task->card.setSize(sf::Vector2f(width, height));
            float xpos = x + (index % 2) * (width + 10);
            float ypos = y + (index / 2) * (height + 10);
            task->card.setPosition(sf::Vector2f(xpos, ypos - scrollNum));
        }
        else
        {
            // 2x3 grid
            float width = mainScreenWidth / 2 - 20;
            float height = mainScreenHeight / 3 - 20;
            task->card.setSize(sf::Vector2f(width, height));
            float xpos = x + (index % 2) * (width + 10);
            float ypos = y + (index / 2) * (height + 10);
            task->card.setPosition(sf::Vector2f(xpos, ypos- scrollNum));
        }
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