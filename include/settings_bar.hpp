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
    void settingsButton();
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
    sf::RectangleShape* settingsButtonRect;
    seperating_bar* seperatingBar;
    settings_window* settingsWindow;

    void updateSettingsButton();
};

class seperating_bar
{
public:
    seperating_bar(sf::Vector2f _size, sf::Vector2f _position);
    ~seperating_bar();
    static bool isDragging;
    void draw();
    sf::RectangleShape rectangle;
    static int width;
private:
};


class button
{
public:
    button(sf::Vector2f _size, sf::Vector2f _position, std::string taskString);
    ~button();

    void draw(int settingsBarWidth, int settingsBarX);
    bool isClicked(bool seperatingBarIsDragging);
    sf::RectangleShape rectangle;
    
private:   

    sf::Color buttonColor;
    sf::Font font;
    sf::Text taskText;

    int savedWidth;
};


