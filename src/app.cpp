#include "../include/app.hpp"
#include "../include/task.hpp"
#include <iostream>

app::app()
{
    utils::init();
    /*
    for(int i=0; i < 7; i++)
    {
        task::taskList.push_back(new task());
    }
    */
}

app::~app()
{
}

void app::run()
{
    
    while (utils::window.isOpen())
    {   
        task::updateScrollable();
        while (utils::window.pollEvent(utils::event))
        {
            if (utils::event.type == sf::Event::Closed)
            {
                utils::window.close();
            }
            if (utils::event.type == sf::Event::Resized)
            {
                // Update the view to the new size of the window
                sf::FloatRect visibleArea(0, 0, utils::event.size.width, utils::event.size.height);
                utils::window.setView(sf::View(visibleArea));
                
                // Update your screen components
                utils::updateScreenSize();

            }
            
            if(utils::event.type == sf::Event::MouseWheelScrolled)
            {
                if(utils::event.mouseWheelScroll.delta > 0 && task::upwardsScrollable)
                {
                    task::scrollNum-=30;
                }
                else if(utils::event.mouseWheelScroll.delta < 0 && task::downwardsScrollable)
                {
                    task::scrollNum+=30;
                    //std::cout << task::scrollNum<<std::endl;
                }
            }
            if(utils::event.type == sf::Event::MouseButtonPressed)
            {
                if(utils::event.mouseButton.button == sf::Mouse::Button::Left)
                {
                    utils::mouseLeftClicked = true;
                }
            }
            else if(utils::event.type == sf::Event::MouseButtonReleased)
            {
                if(utils::event.mouseButton.button == sf::Mouse::Button::Left)
                {
                    utils::mouseLeftClicked = false;
                }
            }
        }
        

        utils::window.clear(sf::Color::Black);

        utils::update();

        utils::window.display();
    }
}
