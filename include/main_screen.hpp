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
private:

    int x;
    int width;
    int height;

    void drawTestButton();
    void draw();
    void drawBackground();

    sf::Color backgroundColor = sf::Color::Black;
    sf::RectangleShape background;
};



