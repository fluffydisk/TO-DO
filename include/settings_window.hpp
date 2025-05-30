//SETTINGS_WINDOW
#pragma once
#include "utils.hpp"

class settings_window
{
public:
    enum class Screen_data{ADD_TASK, REMOVE_TASK, EDIT_TASK, SETTINGS};
    Screen_data screenData;

    settings_window();
    ~settings_window();
    
    void update();

    void update_AddTask();
    void update_RemoveTask();
    void update_EditTask();
    void update_Settings();

    bool isSettingsWindowActive;
    void setWindowActive();
    bool isMouseOnIt(sf::RectangleShape obj);
    enum class Tasks_shown{ONE, TWO, FOUR, SIX, RESIZABLE};
    static Tasks_shown tasksShown;


private:
    void handleWriting(sf::RectangleShape& rect1, sf::RectangleShape& rect2);
    bool isActive_FirstWritingBar;

    struct TaskName
    {
        std::string str_Text;
        sf::Text sf_Text;
        static bool shouldGoToUnderRow;
        static std::vector<TaskName*> list;

    private:
        size_t index;
        
    public:
        TaskName()
        {
            index = list.size();
            
            list.push_back(this);
        }
        size_t getIndex() const{return index;};
        TaskName* previousObj() const{return index>0 ? list[index-1] : nullptr;};

    };    

    sf::Font font;

    void setForeground();
    bool isLeftMouseClicked;
    sf::Cursor mouseCursor;
    sf::Vector2i mousePos;
    sf::RenderWindow window;

    sf::Event event;
    void buttonClick(sf::Text& text, sf::RectangleShape& applyButton);
};
