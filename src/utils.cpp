#include "../include/utils.hpp"
#include <iostream>
#include "../include/task.hpp"

sf::RenderWindow utils::window(sf::VideoMode(800, 600), "TO-DO APP");
sf::Vector2u utils::windowSize;
sf::Vector2i utils::mousePos;
sf::Cursor utils::mouseCursor;
bool utils::mouseLeftClicked = false;
sf::Event utils::event;

main_screen utils::mainScreen;
settings_bar utils::settingsBar;

int utils::seperationPointCurrentX;
int utils::seperationPointMaxX;
int utils::seperationPointMinX;

void utils::init()
{   
    seperationPointCurrentX = window.getSize().x/4;
    updateScreenSize();
    window.setFramerateLimit(60);
}
void utils::updateScreenSize()
{
    windowSize = window.getSize();
    
    utils::seperationPointMaxX = utils::windowSize.x/2;
    utils::seperationPointMinX = utils::windowSize.x/6;
    if(utils::seperationPointCurrentX>utils::seperationPointMaxX)
    {
        utils::seperationPointCurrentX=utils::seperationPointMaxX;
    }
    if(utils::seperationPointCurrentX<utils::seperationPointMinX)
    {
        utils::seperationPointCurrentX=utils::seperationPointMinX;
    }
    
    mainScreen.updateSize();
    settingsBar.updateSize();
}

void utils::update()
{

    updateScreenSize();


    settingsBar.update();
    mainScreen.update();
    
    mousePos = sf::Mouse::getPosition(window);
}

bool utils::isMouseOnIt(sf::RectangleShape obj)
{
    return (utils::mousePos.x>obj.getPosition().x &&
            utils::mousePos.x<obj.getPosition().x+obj.getSize().x &&
            utils::mousePos.y>obj.getPosition().y &&
            utils::mousePos.y<obj.getPosition().y+obj.getSize().y);
}

utils::utils()
{
}

utils::~utils()
{
}