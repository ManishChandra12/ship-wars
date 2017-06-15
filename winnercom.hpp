#ifndef WINNERCOM_HPP_INCLUDED
#define WINNERCOM_HPP_INCLUDED

class winnercom:public cscreen
{
public:
    bool running;
    virtual int run(sf::RenderWindow &app);
};
int winnercom::run(sf::RenderWindow &app)
{
    bool running=true;
    sf::Texture t;
    if (!t.loadFromFile("url.png", sf::IntRect(0, 0,1360, 810)))
    {
        std::cout<<"error...";
    }

    sf::Sprite s(t);

    sf::Font font;
    if (!font.loadFromFile("ALGER.TTF"))
    {
        std::cout<<"error...";
    }

    sf::Text text[2];


    text[0].setFont(font);
    text[0].setCharacterSize(90);
    text[0].setStyle(sf::Text::Bold);
    text[0].setColor(sf::Color(100,87,255));


    text[1].setFont(font);
    text[1].setCharacterSize(75);
    text[1].setStyle(sf::Text::Bold);
    text[1].setColor(sf::Color(10,87,255));

    text[0].setString("COMPUTER WINS");
    text[1].setString("EXIT");

    text[0].setOrigin(-300,-105);
    text[1].setOrigin(-610,-610);

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

                     if((mouse_x1>=560 && mouse_x1<=760) && (mouse_y1>=560 && mouse_y1<=760))
                     {
                        text[1].setColor(sf::Color(17,17,17));
                     }
                     else
                            text[1].setColor(sf::Color(10,87,255));
                     break;

                case sf::Event::MouseButtonPressed:
                    if (event.mouseButton.button == sf::Mouse::Left)
                    {
                        int mouse_x=event.mouseButton.x;
                        int mouse_y=event.mouseButton.y;
                        if(mouse_x>=560 && mouse_x<=760 && mouse_y>=560 && mouse_y<=760)
                        {
                            text[1].setColor(sf::Color::Red);
                            running=false;
                            return(-1);
                        }
                    }
                    break;
                default:
                    break;
            }
        }

    app.clear();
    app.draw(s);
    app.draw(text[0]);
    app.draw(text[1]);

    app.display();

    }
    return -1;
}

#endif // WINNERCOM_HPP_INCLUDED
