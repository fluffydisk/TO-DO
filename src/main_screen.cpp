#include "../include/main_screen.hpp"
#include "../include/task.hpp"
#include <iostream>

bool main_screen::isBarDragging = false;

main_screen::main_screen()
    :scrollBarVisible(false)

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


void main_screen::updateScrollBar()
{
    totalHeightOfPage = 10;
    static float dragOffset;
    for(auto &task : task::taskList)
    {
        if(task->taskNum%2!=0)
        {
            totalHeightOfPage += utils::windowSize.y / 3 - 20 + 10;
        }
    }
    if(task::s_TotalTaskNum>6)
    {
        scrollBarVisible = true;
    }
    static bool dragOffsetFirstIteration = true;
    if(utils::isMouseOnIt(scrollBar) && !seperating_bar::isDragging && utils::mouseLeftClicked && utils::window.hasFocus())
    {
        isBarDragging = true;
        if(dragOffsetFirstIteration)
        {
            dragOffset = utils::mousePos.y - scrollBar.getPosition().y;
            dragOffsetFirstIteration = false;
        }
    }
    if(!utils::mouseLeftClicked)
    {
        dragOffsetFirstIteration = true;
        isBarDragging = false;
    }
    // std::cout << isBarDragging << std::endl;
    if(isBarDragging)
    {
        static float newY;
        newY = utils::mousePos.y - dragOffset;
        newY = std::clamp(newY, 0.f, utils::windowSize.y - scrollBar.getSize().y);
        scrollBar.setPosition(scrollBar.getPosition().x, newY);
        task::scrollNum = newY * totalHeightOfPage/utils::windowSize.y;
    }
    if(task::scrollNum<0)
    {
        task::scrollNum=0;
    } 
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

