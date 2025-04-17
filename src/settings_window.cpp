#include "../include/settings_window.hpp"
#include "../include/task.hpp"

settings_window::Tasks_shown settings_window::tasksShown = Tasks_shown::SIX;

settings_window::settings_window()
    :window(sf::VideoMode(480, 430), "Settings", sf::Style::Titlebar | sf::Style::Close),
    isSettingsWindowActive(false),
    isLeftMouseClicked(false)
    {
        window.setVisible(isSettingsWindowActive);
    }

settings_window::~settings_window(){}

void settings_window::update_AddTask()
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

void settings_window::update_Settings()
{
    static sf::Vector2u windowSize;
    
    static sf::Font font;

    static sf::RectangleShape onePerPage;
    static sf::Text oneText;

    static sf::RectangleShape twoPerPage;
    static sf::Text twoText;

    static sf::RectangleShape fourPerPage;
    static sf::Text fourText;

    static sf::RectangleShape sixPerPage;
    static sf::Text sixText;

    static sf::RectangleShape resizablePerPage;
    static sf::Text resizableText;

    static bool isHoveringAny;
    isHoveringAny = isMouseOnIt(onePerPage) || isMouseOnIt(twoPerPage) || isMouseOnIt(fourPerPage) || isMouseOnIt(sixPerPage) || isMouseOnIt(resizablePerPage);
    mouseCursor.loadFromSystem(isHoveringAny ? sf::Cursor::Type::Hand : sf::Cursor::Type::Arrow);
    window.setMouseCursor(mouseCursor);


    if(isLeftMouseClicked)
    {
        if(isMouseOnIt(onePerPage))
        {
            tasksShown=Tasks_shown::ONE;
            isSettingsWindowActive=false;
            task::scrollNum = 0;
        }
        else if(isMouseOnIt(twoPerPage))
        {
            tasksShown=Tasks_shown::TWO;
            isSettingsWindowActive=false;
            task::scrollNum = 0;
        }
        else if(isMouseOnIt(fourPerPage))
        {
            tasksShown=Tasks_shown::FOUR;
            isSettingsWindowActive=false;
            task::scrollNum = 0;
        }
        else if(isMouseOnIt(sixPerPage))
        {
            tasksShown=Tasks_shown::SIX;
            isSettingsWindowActive=false;
            task::scrollNum = 0;
        }
        else if(isMouseOnIt(resizablePerPage))
        {
            tasksShown=Tasks_shown::RESIZABLE;
            isSettingsWindowActive=false;
            task::scrollNum = 0;
        }
    }

    //Draw
    font.loadFromFile("../res/Fonts/SFPRODISPLAYBOLD.OTF");
    
    windowSize = window.getSize();
    int xSpaceBetweenCarts = 10;
    int ySpaceBetweenCarts = 10;

    static sf::Text mainText; mainText.setFillColor(sf::Color::White);
    mainText.setFont(font); mainText.setString("Choose how tasks should be shown"); mainText.setCharacterSize(24);
    mainText.setPosition(45, 20);
    window.draw(mainText);

    onePerPage.setPosition(sf::Vector2f(xSpaceBetweenCarts*2 ,80)); onePerPage.setFillColor(isMouseOnIt(onePerPage) ? sf::Color(40, 40, 40)   : sf::Color(20, 20, 20));
    onePerPage.setSize(sf::Vector2f((windowSize.x-(5*xSpaceBetweenCarts))/2, (windowSize.y-(2*ySpaceBetweenCarts))/9*2));
    window.draw(onePerPage);
    oneText.setFillColor(sf::Color::White); oneText.setFont(font); 
    oneText.setString("One Task Per Page"); oneText.setCharacterSize(18);
    oneText.setPosition(onePerPage.getPosition().x+25, onePerPage.getPosition().y+30);
    window.draw(oneText);


    twoPerPage.setPosition(sf::Vector2f(3*xSpaceBetweenCarts+onePerPage.getSize().x ,80)); twoPerPage.setFillColor(isMouseOnIt(twoPerPage) ? sf::Color(40, 40, 40)   : sf::Color(20, 20, 20));
    twoPerPage.setSize(sf::Vector2f((windowSize.x-(5*xSpaceBetweenCarts))/2, (windowSize.y-(2*ySpaceBetweenCarts))/9*2));
    window.draw(twoPerPage);
    twoText.setFillColor(sf::Color::White); twoText.setFont(font); 
    twoText.setString("Two Task Per Page"); twoText.setCharacterSize(18);
    twoText.setPosition(twoPerPage.getPosition().x+25, twoPerPage.getPosition().y+30);
    window.draw(twoText);

    fourPerPage.setPosition(sf::Vector2f(xSpaceBetweenCarts*2 ,onePerPage.getPosition().y+onePerPage.getSize().y+ySpaceBetweenCarts)); fourPerPage.setFillColor(isMouseOnIt(fourPerPage) ? sf::Color(40, 40, 40)   : sf::Color(20, 20, 20));
    fourPerPage.setSize(sf::Vector2f((windowSize.x-(5*xSpaceBetweenCarts))/2, (windowSize.y-(2*ySpaceBetweenCarts))/9*2));
    window.draw(fourPerPage);
    fourText.setFillColor(sf::Color::White); fourText.setFont(font); 
    fourText.setString("Four Task Per Page"); fourText.setCharacterSize(18);
    fourText.setPosition(fourPerPage.getPosition().x+25, fourPerPage.getPosition().y+30);
    window.draw(fourText);

    sixPerPage.setPosition(sf::Vector2f(xSpaceBetweenCarts+fourPerPage.getSize().x +fourPerPage.getPosition().x ,twoPerPage.getPosition().y+twoPerPage.getSize().y+ySpaceBetweenCarts)); sixPerPage.setFillColor((isMouseOnIt(sixPerPage) ? sf::Color(40, 40, 40)   : sf::Color(20, 20, 20)));
    sixPerPage.setSize(sf::Vector2f((windowSize.x-(5*xSpaceBetweenCarts))/2, (windowSize.y-(2*ySpaceBetweenCarts))/9*2));
    window.draw(sixPerPage);
    sixText.setFillColor(sf::Color::White); sixText.setFont(font); 
    sixText.setString("Six Task Per Page"); sixText.setCharacterSize(18);
    sixText.setPosition(sixPerPage.getPosition().x+25, sixPerPage.getPosition().y+30);
    window.draw(sixText);

    resizablePerPage.setPosition(sf::Vector2f(xSpaceBetweenCarts*2, sixPerPage.getPosition().y+sixPerPage.getSize().y+ySpaceBetweenCarts)); resizablePerPage.setFillColor(isMouseOnIt(resizablePerPage) ? sf::Color(40, 40, 40)   : sf::Color(20, 20, 20));
    resizablePerPage.setSize(sf::Vector2f((windowSize.x-(4*xSpaceBetweenCarts)), (windowSize.y-(2*ySpaceBetweenCarts))/9));
    window.draw(resizablePerPage);
    resizableText.setFillColor(sf::Color::White); resizableText.setFont(font); 
    resizableText.setString("Resize as number of tasks"); resizableText.setCharacterSize(18);
    resizableText.setPosition(resizablePerPage.getPosition().x+100, resizablePerPage.getPosition().y+12);
    window.draw(resizableText);
}

void settings_window::update_EditTask(){}
void settings_window::update_RemoveTask(){}

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
            update_AddTask();
            break;
        case Screen_data::REMOVE_TASK :
            update_RemoveTask();
            break;
        case Screen_data::EDIT_TASK :
            update_EditTask();
            break;
        case Screen_data::SETTINGS:
            update_Settings();
            break;
        default:
            break;
        }

        window.display();
    }
}
