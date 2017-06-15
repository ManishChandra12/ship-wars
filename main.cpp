#include"header.hpp"
#include <SFML/Graphics.hpp>

int main()
{
    std::vector<cscreen*>screens;
    int screen=0;
    sf::RenderWindow app(sf::VideoMode(1350, 720), "SHIP WAR",sf::Style::Fullscreen);
    screen_0 s0;
    screens.push_back(&s0);
    BattleField b;
    screens.push_back(&b);
    winner w;
    screens.push_back(&w);
    winnercom wc;
    screens.push_back(&wc);
    controls cs;
    screens.push_back(&cs);
    while(screen >= 0)
    {
        screen=screens[screen]->run(app);
    }

    return 0;
}
