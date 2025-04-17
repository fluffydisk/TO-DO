#include "../include/settings_window.hpp"
#include "../include/task.hpp"

settings_window::settings_window()
    :window(sf::VideoMode(480, 430), "Settings", sf::Style::Titlebar | sf::Style::Close),
    isSettingsWindowActive(false),
    isLeftMouseClicked(false)
    {
        window.setVisible(isSettingsWindowActive);
    }

settings_window::~settings_window(){}

void settings_window::draw_AddTask()
{
    static int space = 20;
    
    static sf::Font font;

    if(!font.loadFromFile("../res/Fonts/SFPRODISPLAYREGULAR.OTF"))
    {
        std::cout << "couldnt load file";
    }
    
    /*
    static sf::Text addTaskText;
    addTaskText.setFont(font);
    addTaskText.setString("Add Task");
    addTaskText.setStyle(sf::Text::Bold);
    addTaskText.setCharacterSize(24);
    
    addTaskText.setFillColor(sf::Color::White);
    addTaskText.setPosition(sf::Vector2f(window.getSize().x/3+20, 5));

    window.draw(addTaskText);
    */

    static sf::Text firstSpaceText;

    firstSpaceText.setFont(font);
    firstSpaceText.setString("Task Name");
    firstSpaceText.setStyle(sf::Text::Style::Bold);
    firstSpaceText.setCharacterSize(20);
    firstSpaceText.setPosition(sf::Vector2f(space, 30));
    window.draw(firstSpaceText);

    static sf::RectangleShape firstSpaceEntry;
    firstSpaceEntry.setFillColor(sf::Color(18,18,18));
    firstSpaceEntry.setPosition(space,firstSpaceText.getPosition().y+30);
    firstSpaceEntry.setSize(sf::Vector2f(window.getSize().x-(2*space), window.getSize().y/6));
    window.draw(firstSpaceEntry);


    static sf::Text secondSpaceText;
    
    secondSpaceText.setFont(font);
    secondSpaceText.setString("Description");
    secondSpaceText.setStyle(sf::Text::Style::Bold);
    secondSpaceText.setCharacterSize(20);
    secondSpaceText.setPosition(sf::Vector2f(space, firstSpaceEntry.getPosition().y +  firstSpaceEntry.getSize().y + 30));

    window.draw(secondSpaceText);

    static sf::RectangleShape secondSpaceEntry;
    secondSpaceEntry.setOutlineColor(sf::Color(0, 120, 212));
    secondSpaceEntry.setFillColor(sf::Color(18,18,18));
    secondSpaceEntry.setPosition(space, secondSpaceText.getPosition().y+30);
    secondSpaceEntry.setSize(sf::Vector2f(window.getSize().x-(2*space), window.getSize().y/3));
    window.draw(secondSpaceEntry);

    static sf::RectangleShape applyButton;
    applyButton.setPosition(sf::Vector2f(window.getSize().x/2-60, secondSpaceEntry.getPosition().y+secondSpaceEntry.getSize().y + 20));
    applyButton.setSize(sf::Vector2f(120, 50));
    applyButton.setFillColor(sf::Color(18,18,18));
    window.draw(applyButton);

    static sf::Text applyText;
    static sf::Font applyFont;
    applyFont.loadFromFile("../res/Fonts/SFPRODISPLAYBOLD.OTF");
    applyText.setFont(applyFont);
    applyText.setString("Apply");
    applyText.setStyle(sf::Text::Style::Bold);
    applyText.setCharacterSize(18);
    
    applyText.setFillColor(sf::Color::White);
    applyText.setPosition(sf::Vector2f(applyButton.getPosition().x+33, applyButton.getPosition().y+15));
    
    buttonClick(applyText, applyButton);

    window.draw(applyText);
    
}

void settings_window::draw_Settings()
{
    static sf::Font font; font.loadFromFile("../res/Fonts/SFPRODISPLAYBOLD.OTF");
    static sf::Vector2u windowSize;
    windowSize = window.getSize();
    int xSpaceBetweenCarts = 10;
    int ySpaceBetweenCarts = 10;

    static sf::Text mainText; mainText.setFillColor(sf::Color::White);
    mainText.setFont(font); mainText.setString("Choose how tasks should be shown"); mainText.setCharacterSize(24);
    mainText.setPosition(45, 20);
    window.draw(mainText);

    static sf::RectangleShape onePerPage; onePerPage.setPosition(sf::Vector2f(xSpaceBetweenCarts*2 ,80)); onePerPage.setFillColor(sf::Color(40, 40, 40));
    onePerPage.setSize(sf::Vector2f((windowSize.x-(5*xSpaceBetweenCarts))/2, (windowSize.y-(2*ySpaceBetweenCarts))/9*2));
    window.draw(onePerPage);

    static sf::RectangleShape twoPerPage; twoPerPage.setPosition(sf::Vector2f(3*xSpaceBetweenCarts+onePerPage.getSize().x ,80)); twoPerPage.setFillColor(sf::Color(40, 40, 40));
    twoPerPage.setSize(sf::Vector2f((windowSize.x-(5*xSpaceBetweenCarts))/2, (windowSize.y-(2*ySpaceBetweenCarts))/9*2));
    window.draw(twoPerPage);

    static sf::RectangleShape fourPerPage; fourPerPage.setPosition(sf::Vector2f(xSpaceBetweenCarts*2 ,onePerPage.getPosition().y+onePerPage.getSize().y+ySpaceBetweenCarts)); fourPerPage.setFillColor(sf::Color(40, 40, 40));
    fourPerPage.setSize(sf::Vector2f((windowSize.x-(5*xSpaceBetweenCarts))/2, (windowSize.y-(2*ySpaceBetweenCarts))/9*2));
    window.draw(fourPerPage);

    static sf::RectangleShape sixPerPage; sixPerPage.setPosition(sf::Vector2f(xSpaceBetweenCarts+fourPerPage.getSize().x +fourPerPage.getPosition().x ,twoPerPage.getPosition().y+twoPerPage.getSize().y+ySpaceBetweenCarts)); sixPerPage.setFillColor(sf::Color(40, 40, 40));
    sixPerPage.setSize(sf::Vector2f((windowSize.x-(5*xSpaceBetweenCarts))/2, (windowSize.y-(2*ySpaceBetweenCarts))/9*2));
    window.draw(sixPerPage);

    static sf::RectangleShape repositionablePerPage; repositionablePerPage.setPosition(sf::Vector2f(xSpaceBetweenCarts*2, sixPerPage.getPosition().y+sixPerPage.getSize().y+ySpaceBetweenCarts)); repositionablePerPage.setFillColor(sf::Color(40, 40, 40));
    repositionablePerPage.setSize(sf::Vector2f((windowSize.x-(4*xSpaceBetweenCarts)), (windowSize.y-(2*ySpaceBetweenCarts))/9));
    window.draw(repositionablePerPage);
}

void settings_window::draw_EditTask(){}
void settings_window::draw_RemoveTask(){}

bool settings_window::isMouseOnIt(sf::RectangleShape obj)
{
    return (settings_window::mousePos.x>obj.getPosition().x &&
            settings_window::mousePos.x<obj.getPosition().x+obj.getSize().x &&
            settings_window::mousePos.y>obj.getPosition().y &&
            settings_window::mousePos.y<obj.getPosition().y+obj.getSize().y);
}

void settings_window::buttonClick(sf::Text& text, sf::RectangleShape& applyButton)
{
    sf::Cursor::Type newCursor = sf::Cursor::Arrow;
    text.setStyle(sf::Text::Style::Regular);

    if (settings_window::isMouseOnIt(applyButton)) 
    {   
        newCursor = sf::Cursor::Hand;
    }
    //std::cout <<isLeftMouseClicked;
    if(settings_window::isMouseOnIt(applyButton) && isLeftMouseClicked)
    {
        task::taskList.push_back(new task());
        isSettingsWindowActive = false;
    }
    static sf::Cursor::Type currentCursor = sf::Cursor::Arrow;
    if (newCursor != currentCursor) 
    {
        settings_window::mouseCursor.loadFromSystem(newCursor);
        settings_window::window.setMouseCursor(settings_window::mouseCursor);
        currentCursor = newCursor;
    }
}

void settings_window::update()
{
    
    window.setVisible(isSettingsWindowActive);
    if (isSettingsWindowActive)
    {
        mousePos = sf::Mouse::getPosition(window);
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                isSettingsWindowActive = false;
                utils::mouseLeftClicked = false;
            }
            isLeftMouseClicked = false;
            if(event.type == sf::Event::MouseButtonPressed)
            {
                if(event.mouseButton.button == sf::Mouse::Button::Left)
                {
                    isLeftMouseClicked = true;
                }
            }
        }
        window.clear(sf::Color(11, 11, 11));


        switch (screenData)
        {
        case Screen_data::ADD_TASK :
            draw_AddTask();
            break;
        case Screen_data::REMOVE_TASK :
            draw_RemoveTask();
            break;
        case Screen_data::EDIT_TASK :
            draw_EditTask();
            break;
        case Screen_data::SETTINGS:
            draw_Settings();
            break;
        default:
            break;
        }

        window.display();
    }
}
