#pragma once

#include<SFML/Graphics.hpp>
#include<string>
#include "utils.hpp"
class main_screen
{
public:
    main_screen();
    ~main_screen();
    void updateSize(); 

    void update();
    
    static bool isBarDragging;
private:

    int x;
    int width;
    int height;

    void drawTestButton();
    void drawBackground();
    void drawScrollBar();
    void updateScrollBar();
    void draw();

    float totalHeightOfPage;
    bool scrollBarVisible;
    sf::Color backgroundColor = sf::Color::Black;
    sf::RectangleShape scrollBar;
    sf::RectangleShape background;
};



