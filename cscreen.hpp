#ifndef CSCREEN_HPP_INCLUDED
#define CSCREEN_HPP_INCLUDED
#include"header.hpp"
#include <SFML/Graphics.hpp>

class cscreen
{
public:
    virtual int run(sf::RenderWindow &app)=0;
};


#endif // CSCREEN_HPP_INCLUDED
