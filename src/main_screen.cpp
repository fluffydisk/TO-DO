#include "../include/main_screen.hpp"
#include "../include/task.hpp"
#include <iostream>

bool main_screen::isBarDragging = false;
bool main_screen::scrollBarVisible = false;

main_screen::main_screen()
{

}

main_screen::~main_screen()
{
}

void main_screen::updateSize()
{
    width = utils::windowSize.x - utils::seperationPointCurrentX;
    height = utils::window.getSize().y;
    x = utils::seperationPointCurrentX;
}  

void main_screen::update()
{
    updateScrollBar();
    draw();
    task::update();
}

void main_screen::drawBackground()
{
    background.setPosition(sf::Vector2f(x, 0));
    background.setSize(sf::Vector2f(width, height));
    background.setFillColor(sf::Color(33, 33, 33));
    
    utils::window.draw(background);
}

//CHATGPT
///---
void main_screen::updateScrollBar()
{
    totalHeightOfPage = 10;
    const auto taskCount = static_cast<int>(task::taskList.size());

    int rows = 1;
    int tasksPerRow = 1;
    float taskHeight = 0;

    switch (settings_window::tasksShown)
    {
        case settings_window::Tasks_shown::ONE:
            rows = taskCount;
            tasksPerRow = 1;
            taskHeight = utils::windowSize.y - 20;
            break;
        case settings_window::Tasks_shown::TWO:
            tasksPerRow = 2;
            taskHeight = utils::windowSize.y - 20;
            rows = (taskCount + 1) / 2;
            break;
        case settings_window::Tasks_shown::FOUR:
            tasksPerRow = 2;
            taskHeight = utils::windowSize.y / 2 - 20;
            rows = (taskCount + 1) / 2;
            break;
        case settings_window::Tasks_shown::SIX:
            tasksPerRow = 2;
            taskHeight = utils::windowSize.y / 3 - 20;
            rows = (taskCount + 1) / 2;
            break;
        case settings_window::Tasks_shown::RESIZABLE:
        {
            if (taskCount == 1)
            {
                rows = 1;
                taskHeight = utils::windowSize.y - 20;
            }
            else if (taskCount == 2)
            {
                tasksPerRow = 2;
                rows = 1;
                taskHeight = utils::windowSize.y - 20;
            }
            else if (taskCount <= 4)
            {
                tasksPerRow = 2;
                rows = (taskCount + 1) / 2;
                taskHeight = utils::windowSize.y / 2 - 20;
            }
            else
            {
                tasksPerRow = 2;
                rows = (taskCount + 1) / 2;
                taskHeight = utils::windowSize.y / 3 - 20;
            }
            break;
        }
    }

    totalHeightOfPage += rows * (taskHeight + 10);

    // --- ScrollBar Dragging Logic ---
    static float dragOffset = 0.f;
    static bool dragOffsetFirstIteration = true;

    if (utils::isMouseOnIt(scrollBar) && !seperating_bar::isDragging && utils::mouseLeftClicked && utils::window.hasFocus())
    {
        isBarDragging = true;
        if (dragOffsetFirstIteration)
        {
            dragOffset = utils::mousePos.y - scrollBar.getPosition().y;
            dragOffsetFirstIteration = false;
        }
    }

    if (!utils::mouseLeftClicked)
    {
        dragOffsetFirstIteration = true;
        isBarDragging = false;
    }

    if (isBarDragging)
    {
        float newY = utils::mousePos.y - dragOffset;
        newY = std::clamp(newY, 0.f, utils::windowSize.y - scrollBar.getSize().y);
        scrollBar.setPosition(scrollBar.getPosition().x, newY);
        task::scrollNum = (newY / (utils::windowSize.y - scrollBar.getSize().y)) * (totalHeightOfPage - utils::windowSize.y);
    }

    task::scrollNum = std::clamp(task::scrollNum, 0, INT_MAX); // Clamp to non-negative
}


void main_screen::drawScrollBar()
{
    if(scrollBarVisible)
    {
        static int width = 7;

        static sf::Color scrollBarColor;
        scrollBarColor = sf::Color(79,79,79);
        if(utils::isMouseOnIt(scrollBar) || isBarDragging)
        {
            scrollBarColor = sf::Color(122,122,122);
        }
        scrollBar.setFillColor(scrollBarColor);
        scrollBar.setPosition(utils::windowSize.x-width*2, utils::windowSize.y*task::scrollNum/totalHeightOfPage);
        scrollBar.setSize(sf::Vector2f(width, utils::windowSize.y*(utils::windowSize.y/totalHeightOfPage)));
        utils::window.draw(scrollBar);
    }
}

void main_screen::draw()
{
    drawBackground();
    drawScrollBar();

    //drawTestButton();
}

