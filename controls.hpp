#ifndef CONTROLS_HPP_INCLUDED
#define CONTROLS_HPP_INCLUDED

class controls:public cscreen
{
public:
    virtual int run(sf::RenderWindow &app);
};

int controls::run(sf::RenderWindow &app)
{
    sf::Texture texture44;
    if (!texture44.loadFromFile("controls.png", sf::IntRect(0, 0,1360, 810)))
    {
        std::cout<<"error...";
    }

    sf::Sprite sprite(texture44);
    sprite.setColor(sf::Color(255,255,255,200));

    sf::Event event8;
    while(1)
    {
    while(app.pollEvent(event8))
        {
            if(event8.type==sf::Event::Closed)
                return (-1);
            if(event8.type==sf::Event::KeyPressed)
            {
                switch (event8.key.code)
                {
                case sf::Keyboard::Escape:
                    return 0;
                    break;
                default:
                    break;
                }
            }
        }


            app.clear();
            app.draw(sprite);
            app.display();
    }
    return -1;

}



#endif // CONTROLS_HPP_INCLUDED
