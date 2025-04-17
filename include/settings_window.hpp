//SETTINGS_WINDOW
#pragma once
#include "utils.hpp"

class settings_window
{
public:
    enum class Screen_data : char{ADD_TASK, REMOVE_TASK, EDIT_TASK, SETTINGS};
    Screen_data screenData;

    settings_window();
    ~settings_window();
    
    void update();

    void draw_AddTask();
    void draw_RemoveTask();
    void draw_EditTask();
    void draw_Settings();

    bool isSettingsWindowActive;
    bool isMouseOnIt(sf::RectangleShape obj);
private:
    bool isLeftMouseClicked;
    sf::Cursor mouseCursor;
    sf::Vector2i mousePos;

    sf::RenderWindow window;
    sf::Event event;
    void buttonClick(sf::Text& text, sf::RectangleShape& applyButton);
};
