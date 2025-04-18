#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "main_screen.hpp"
#include "settings_bar.hpp"
#include "app.hpp"

class main_screen;
class settings_bar;

class utils
{
public:
    utils();
    ~utils();
    static void init();
    static void update();

    static sf::Event event;
    
    static bool mouseLeftClicked;
    static sf::Cursor mouseCursor;
    static sf::Vector2i mousePos;
    static bool isMouseOnIt(sf::RectangleShape obj);

    static sf::RenderWindow window;
    static sf::Vector2u windowSize;
    
    static void updateScreenSize();

    static main_screen mainScreen;
    static settings_bar settingsBar;

    static int seperationPointCurrentX;
    static int seperationPointMaxX;
    static int seperationPointMinX;
};

