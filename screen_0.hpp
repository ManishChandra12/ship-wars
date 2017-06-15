#ifndef SCREEN_0_HPP_INCLUDED
#define SCREEN_0_HPP_INCLUDED

#include"header.hpp"
#include <SFML/Graphics.hpp>

class screen_0:public cscreen
{
private:
    bool playing;
public:
    screen_0(void);
    virtual int run(sf::RenderWindow &app);
};

screen_0::screen_0()
{
    playing=false;
}

int screen_0::run(sf::RenderWindow &app)
{
    bool running=true;

    sf::Texture texture;
    if (!texture.loadFromFile("url.png", sf::IntRect(0, 0,1360, 810)))
    {
        std::cout<<"error...";
    }

    sf::Sprite sprite(texture);
    sprite.setColor(sf::Color(255,255,255,200));

    sf::Font font;
    if (!font.loadFromFile("ALGER.TTF"))
    {
        std::cout<<"error...";
    }

    sf::Text text[3];

    for(int i=0;i<3;i++)
    {
        text[i].setFont(font);
        text[i].setCharacterSize(75);
        text[i].setStyle(sf::Text::Bold);
    }

    text[0].setString("PLAY");
    text[1].setString("CONTROLS");
    text[2].setString("EXIT");
    text[0].setColor(sf::Color(10,87,255));
    text[1].setColor(sf::Color(10,87,255));
    text[2].setColor(sf::Color(10,87,255));
    text[0].setOrigin(-610,-105);
    text[1].setOrigin(-520,-305);
    text[2].setOrigin(-610,-505);

    int mouse_x1,mouse_y1;

    while(running)
    {
        sf::Event event;
        while(app.pollEvent(event))
        {
            switch(event.type)
            {
                case sf::Event::Closed:
                    return (-1);
                    break;

                case sf::Event::MouseMoved:
                     mouse_x1=event.mouseMove.x;
                     mouse_y1=event.mouseMove.y;

                     if((mouse_x1>=450 && mouse_x1<=950) && (mouse_y1>=500 && mouse_y1<=600))
                     {
                        text[2].setColor(sf::Color(17,17,17));
                     }
                     else if((mouse_x1>=450 && mouse_x1<=950) && (mouse_y1>=300 && mouse_y1<=400))
                     {
                        text[1].setColor(sf::Color(17,17,17));
                     }
                     else if((mouse_x1>=450 && mouse_x1<=950) && (mouse_y1>=100 && mouse_y1<=200))
                     {
                        text[0].setColor(sf::Color(17,17,17));
                     }
                     else
                        for(int i=0;i<3;i++)
                            text[i].setColor(sf::Color(10,87,255));
                     break;

                case sf::Event::MouseButtonPressed:
                    if (event.mouseButton.button == sf::Mouse::Left)
                    {
                        int mouse_x=event.mouseButton.x;
                        int mouse_y=event.mouseButton.y;
                        if(mouse_x>=450 && mouse_x<=950 && mouse_y>=500 && mouse_y<=600)
                        {
                            text[2].setColor(sf::Color::Red);
                            playing=false;
                            return(-1);
                        }
                       else if(mouse_x>=450 && mouse_x<=950 && mouse_y>=300 && mouse_y<=400)
                        {
                            text[1].setColor(sf::Color::Red);
                            return 4;
                        }
                        else if(mouse_x>=450 && mouse_x<=950 && mouse_y>=100 && mouse_y<=200)
                        {
                            text[0].setColor(sf::Color::Red);
                            playing=true;
                            return(1);
                        }
                    }
                    break;

                case sf::Event::MouseButtonReleased:
                    text[0].setColor(sf::Color(10,87,200));
                    text[1].setColor(sf::Color(10,87,200));
                    text[2].setColor(sf::Color(10,87,200));
                    break;

                default:
                    break;

            }

        }

        app.clear();
        app.draw(sprite);

        for(int i=0;i<3;i++)
        {
           app.draw(text[i]);
        }

        app.display();

    }
return -1;
}

#endif // SCREEN_0_HPP_INCLUDED
