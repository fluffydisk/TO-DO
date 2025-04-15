#include "../include/main_screen.hpp"
#include "../include/task.hpp"
#include <iostream>

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
    draw();
}

void main_screen::drawBackground()
{
    background.setPosition(sf::Vector2f(x, 0));
    background.setSize(sf::Vector2f(width, height));
    background.setFillColor(sf::Color(33, 33, 33));
    
    utils::window.draw(background);
}

void main_screen::drawTestButton()
{
    static sf::RectangleShape textButton;
    textButton.setPosition(sf::Vector2f(x+width/3, height/3));
    textButton.setSize(sf::Vector2f(width/3, height/3));
    textButton.setFillColor(sf::Color::White);
    utils::window.draw(textButton);
}

void main_screen::draw()
{
    drawBackground();
    task::update();

    //drawTestButton();
}

