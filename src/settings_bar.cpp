#include "../include/settings_bar.hpp"
#include <iostream>
#include <algorithm>
#include <iostream>
#include "../include/task.hpp"


//SETTINGS_BAR CLASS

settings_bar::settings_bar()
{
    testButton1 = new button(sf::Vector2f(width-20, 30),sf::Vector2f(width-20, 40), "Add Task");
    testButton2 = new button(sf::Vector2f(width-20, 30),sf::Vector2f(width-20, 80), "Edit Task");
    testButton3 = new button(sf::Vector2f(width-20, 30),sf::Vector2f(width-20, 120), "Remove Task");
    seperatingBar = new seperating_bar(sf::Vector2f(width-20, 30),sf::Vector2f(width-20, 120));
    settingsWindow = new settings_window();
}

settings_bar::~settings_bar()
{
    delete testButton1;
    delete testButton2;
    delete testButton3;
    delete seperatingBar;
    delete settingsWindow;
}

void settings_bar::updateSize()
{
    height = utils::window.getSize().y;
    width = utils::seperationPointCurrentX;
    x = 0;
}

void settings_bar::update()
{
    checkMouseInteractions();

    updateButtons();
    settingsWindow->update();

    draw();
}

void settings_bar::addTaskButton()
{
    if(!settingsWindow->isSettingsWindowActive)
    {
        if(testButton1->isClicked(seperatingBar->isDragging))
        {
            settingsWindow->isSettingsWindowActive=true;
            settingsWindow->screenData = settings_window::Screen_data::ADD_TASK;


        }
    }
}

void settings_bar::editTaskButton()
{
    if(!settingsWindow->isSettingsWindowActive)
    {
        if(testButton2->isClicked(seperatingBar->isDragging))
        {
            settingsWindow->isSettingsWindowActive=true;
            settingsWindow->screenData = settings_window::Screen_data::EDIT_TASK;
        }
    }
}

void settings_bar::removeTaskButton()
{
    if(!settingsWindow->isSettingsWindowActive)
    {
        if(testButton3->isClicked(seperatingBar->isDragging))
        {
            settingsWindow->isSettingsWindowActive=true;
            settingsWindow->screenData = settings_window::Screen_data::REMOVE_TASK;
        }
    }
}

void settings_bar::updateButtons()
{
    addTaskButton();
    editTaskButton();
    removeTaskButton();
}



void settings_bar::checkMouseInteractions()
{
    sf::Cursor::Type newCursor = sf::Cursor::Arrow;

    // Start dragging
    if (utils::isMouseOnIt(seperatingBar->rectangle) && !main_screen::isBarDragging && utils::mouseLeftClicked && utils::window.hasFocus()) 
    {
        seperatingBar->isDragging = true;
    }

    // Stop dragging
    if (!utils::mouseLeftClicked) 
    {
        seperatingBar->isDragging = false;
    }

    // Handle dragging
    if (seperatingBar->isDragging) 
    {
        newCursor = sf::Cursor::SizeHorizontal;
        utils::seperationPointCurrentX = std::clamp(utils::mousePos.x, utils::seperationPointMinX, utils::seperationPointMaxX);
    }
    // Handle test button hover
    else if ((testButton1->isMouseOnIt() || testButton2->isMouseOnIt() || testButton3->isMouseOnIt()) && !main_screen::isBarDragging) 
    {   
        newCursor = sf::Cursor::Hand;
    }
    // Handle normal hover
    else if (utils::isMouseOnIt(seperatingBar->rectangle) && utils::window.hasFocus() && !seperating_bar::isDragging && !main_screen::isBarDragging) 
    {
        newCursor = sf::Cursor::SizeHorizontal;
    }

    // Apply cursor if needed
    static sf::Cursor::Type currentCursor = sf::Cursor::Arrow;
    if (newCursor != currentCursor) 
    {
        utils::mouseCursor.loadFromSystem(newCursor);
        utils::window.setMouseCursor(utils::mouseCursor);
        currentCursor = newCursor;
    }
}

void settings_bar::drawBackground()
{
    background.setPosition(sf::Vector2f(0, 0));
    background.setSize(sf::Vector2f(width, height));
    background.setFillColor(sf::Color(13, 13, 13));
    utils::window.draw(background);
}


void settings_bar::draw()
{
    drawBackground();

    seperatingBar->draw();
    testButton1->draw(width, x+10);
    testButton2->draw(width, x+10);
    testButton3->draw(width, x+10);
}

//BUTTON CLASS

button::button(sf::Vector2f _size, sf::Vector2f _position, std::string taskString)
    :   rectangle(_size)
        {
            rectangle.setPosition(_position);

            font.loadFromFile("../res/Fonts/arial.TTF");

            taskText.setFillColor(sf::Color::White);

            taskText.setFont(font);

            taskText.setString(taskString);

            taskText.setCharacterSize(16);
            taskText.setStyle(sf::Text::Bold);
        }

button::~button(){}

void button::draw(int settingsBarWidth, int settingsBarX)
{
    buttonColor = sf::Color(13,13,13);
    if(this->isMouseOnIt())
    {
        buttonColor = sf::Color(21,21,21);
    }
    rectangle.setSize(sf::Vector2f(settingsBarWidth-20, 30));
    rectangle.setPosition(sf::Vector2f(settingsBarX, rectangle.getPosition().y));
    rectangle.setFillColor(buttonColor);
    utils::window.draw(rectangle);

    taskText.setPosition((rectangle.getPosition().x + rectangle.getSize().x/3-settingsBarWidth/5), rectangle.getPosition().y+rectangle.getSize().y/4);
    float textWidth = std::clamp(settingsBarWidth/140.0f, 0.1f, 1.0f);
    taskText.setScale(sf::Vector2f((textWidth), 1));

    utils::window.draw(taskText);
}

bool button::isMouseOnIt()
{
    return (utils::mousePos.x > this->rectangle.getPosition().x &&
    utils::mousePos.x < this->rectangle.getPosition().x + this->rectangle.getSize().x &&
    utils::mousePos.y > this->rectangle.getPosition().y &&
    utils::mousePos.y < this->rectangle.getPosition().y + this->rectangle.getSize().y);
}

bool button::isClicked(bool seperatingBarIsDragging)
{
    return isMouseOnIt() && utils::mouseLeftClicked && !seperatingBarIsDragging && !main_screen::isBarDragging;
}




//SEPERATING_BAR CLASS

bool seperating_bar::isDragging = false;

seperating_bar::seperating_bar(sf::Vector2f _size, sf::Vector2f _position)
    :   rectangle(_size)
        {
            rectangle.setPosition(_position);
        }

seperating_bar::~seperating_bar(){}


void seperating_bar::draw()
{
    this->rectangle.setSize(sf::Vector2f(4, utils::windowSize.y));
    this->rectangle.setPosition(sf::Vector2f(utils::seperationPointCurrentX - this->rectangle.getSize().x/2, 0));
    this->rectangle.setFillColor(sf::Color::White);
    utils::window.draw(this->rectangle);
}

