#pragma once
#include "main_screen.hpp"
#include "settings_window.hpp"
#include "utils.hpp"
#include <iostream>

class button;
class seperating_bar;
class settings_window;

class settings_bar
{
public:
    settings_bar();
    ~settings_bar();
    void updateSize(); 

    void update();


private:
    int x;
    int width;
    int height;

    void updateButtons();
    void addTaskButton();
    void editTaskButton();
    void removeTaskButton();

    sf::Color backgroundColor = sf::Color::Black;
    sf::RectangleShape background;

    void draw();
    void drawBackground();

    void checkMouseInteractions();

    button* testButton1;
    button* testButton2;
    button* testButton3;
    seperating_bar* seperatingBar;
    settings_window* settingsWindow;
};

class seperating_bar
{
public:
    seperating_bar(sf::Vector2f _size, sf::Vector2f _position);
    ~seperating_bar();
    static bool isDragging;
    void draw();
    sf::RectangleShape rectangle;
private:
};


class button
{
public:
    button(sf::Vector2f _size, sf::Vector2f _position, std::string taskString);
    ~button();

    void draw(int settingsBarWidth, int settingsBarX);
    bool isMouseOnIt();
    bool isClicked(bool seperatingBarIsDragging);
    
private:   

    sf::Color buttonColor;
    sf::Font font;
    sf::Text taskText;

    int savedWidth;
    sf::RectangleShape rectangle;
};


