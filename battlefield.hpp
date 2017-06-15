#ifndef BATTLEFIELD_HPP_INCLUDED
#define BATTLEFIELD_HPP_INCLUDED

#include"header.hpp"
#include <SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<ctime>
#include<cstdlib>

#define BOX 11
#define COLBOX 10
#define TOT 303

int nowzzx,nowzzy;
int yes=0;
int b,chk=0,small=1,ii1,ii2,jj1,jj2,axfcod1=0,axfcod2=0,axfcod3=0,axfcod4=0,axfcod5=0,axfcod6=0,ayfcod1=0,ayfcod2=0,ayfcod3=0,ayfcod4=0,ayfcod5=0,ayfcod6=0,axfocod1=0,axfocod2=0,axfocod3=0,axfocod4=0,axfocod5=0,axfocod6=0,ayfocod1=0,ayfocod2=0,ayfocod3=0,ayfocod4=0,ayfocod5=0,ayfocod6=0;
int xfcod1=0,xfcod2=0,xfcod3=0,xfcod4=0,xfcod5=0,xfcod6=0,yfcod1=0,xfocod1=0,xfocod2=0,xfocod3=0,xfocod4=0,xfocod5=0,yfocod1=0;
int coun=0;
int nnn=2;
int counter=0;
int ccounter=0;
int dcounter=0;
int cross[90],cros=0;
int cnt=1,yy=0,zzx=0,zzy=0;
int hit=0,chit=0;
int xtar[100],ytar[100];
int str=0;
int aix[100],aiy[100];
int ckx[6]={0,0,0,0,0,0},cky[6]={0,0,0,0,0,0},t=0;

class BattleField:public cscreen
{
public:
    sf::RectangleShape rectangle2[TOT];
    sf::RectangleShape rectangle5[TOT];
    sf::RectangleShape cross[90];
    BattleField();
    virtual int run(sf::RenderWindow &app);
    void airand();
    void aiblast();
    void checkh(int);
    void checkup(int);
    void checkdown(int);
    void checkleft(int);
    void checkright(int);
};

BattleField::BattleField()
{
    for(int i=0;i<COLBOX;i++)
    {
        for(int j=1;j<BOX;j++)
        {
            rectangle2[j+10*i].setOrigin(-295-(j-1)*76,-45-i*60);
            rectangle2[j+10*i].setSize(sf::Vector2f(76,60));
            rectangle2[j+10*i].setOutlineThickness(-2);
            rectangle2[j+10*i].setOutlineColor(sf::Color(128,87,37));
            rectangle2[j+10*i].setFillColor(sf::Color(255,255,255,0));
        }
    }

    for(b=1;b<=6;b++)
    {
        rectangle2[b].setOutlineThickness(-3);
        rectangle2[b].setOutlineColor(sf::Color(0,0,0));
    }
}

void BattleField::airand()
{
    srand(time(NULL));
    ii1 = rand() % 10;
    ayfcod1 = -45-ii1*60;
    jj1 = rand() %5;
    axfcod1 = -295-jj1 * 76;
    axfcod2 = -295-(jj1+1) * 76;
    axfcod3 = -295-(jj1+2) * 76;
    axfcod4 = -295-(jj1+3) * 76;
    axfcod5 = -295-(jj1+4) * 76;
    axfcod6=-295-(jj1+5)*76;
    while(1)
    {
        ii2 = rand() % 10;
        jj2 = rand() % 6;
        if(ii2==ii1)
            continue;

        ayfocod1 = -45-ii2*60;
        axfocod1 = -295-jj2*76;
        axfocod2 = -295-(jj2+1)*76;
        axfocod3 = -295-(jj2+2)*76;
        axfocod4 = -295-(jj2+3)*76;
        axfocod5 = -295-(jj2+4)*76;
        break;
    }
}

void BattleField::aiblast()
{
    while(1)
    {
        int rd1=rand()%10;
        aix[yy]=rd1;
        int rd2=rand()%10;
        aiy[yy]=rd2;
        for(int i=0;i<yy;i++)
        {
            if((aix[yy]==aix[yy-1-i] && aiy[yy]==aiy[yy-1-i]))
                yes=1;
        }

        if(yes==1)
        {
            yes=0;
            continue;
        }
        zzx=-295-rd1*76;
        zzy=-45-rd2*60;
        if((zzx==ckx[0]&&zzy==cky[0])||(zzx==ckx[1]&&zzy==cky[1])||(zzx==ckx[2]&&zzy==cky[2])||(zzx==ckx[3]&&zzy==cky[3])||(zzx==ckx[4]&&zzy==cky[4])||(zzx==ckx[5]&&zzy==cky[5]))
        {
            continue;
        }
        yy++;
        break;
    }
}

void BattleField::checkh(int cnnt)
{
    if(cnnt!=3 && b>=7 && b<=11&& (chk!=12&&chk!=22 && chk!=32 && chk!=42 && chk!=52 && chk!=62 && chk!=72 && chk!=82 && chk!=92 && chk!=102))
    {
        rectangle2[100+cnnt].setOrigin(-295-(b-7)*76,-45);
        if(cnnt==1) {xfcod1=-295-(b-7)*76;yfcod1=-45;}
        else if(cnnt==2){xfocod1=-295-(b-7)*76;yfocod1=-45;}
    }
    else if(cnnt!=3 && b>=17 && b<=21&& (chk!=12&&chk!=22 && chk!=32 && chk!=42 && chk!=52 && chk!=62 && chk!=72 && chk!=82 && chk!=92 && chk!=102))
    {
        rectangle2[100+cnnt].setOrigin(-295-(b-17)*76,-45-60);
        if(cnnt==1) {xfcod1=-295-(b-17)*76;yfcod1=-45-60;}
        else if(cnnt==2){xfocod1=-295-(b-17)*76;yfocod1=-45-60;}
    }
    else if(cnnt!=3 && b>=27 && b<=31&& (chk!=12&&chk!=22 && chk!=32 && chk!=42 && chk!=52 && chk!=62 && chk!=72 && chk!=82 && chk!=92 && chk!=102))
    {
        rectangle2[100+cnnt].setOrigin(-295-(b-27)*76,-45-60*2);
        if(cnnt==1) {xfcod1=-295-(b-27)*76;yfcod1=-45-60*2;}
        else if(cnnt==2){xfocod1=-295-(b-27)*76;yfocod1=-45-60*2;}
    }
    else if(cnnt!=3 && b>=37 && b<=41&& (chk!=12&&chk!=22 && chk!=32 && chk!=42 && chk!=52 && chk!=62 && chk!=72 && chk!=82 && chk!=92 && chk!=102))
    {
        rectangle2[100+cnnt].setOrigin(-295-(b-37)*76,-45-60*3);
        if(cnnt==1) {xfcod1=-295-(b-37)*76;yfcod1=-45-60*3;}
        else if(cnnt==2){xfocod1=-295-(b-37)*76;yfocod1=-45-60*3;}
    }
    else if(cnnt!=3 && b>=47 && b<=51&& (chk!=12&&chk!=22 && chk!=32 && chk!=42 && chk!=52 && chk!=62 && chk!=72 && chk!=82 && chk!=92 && chk!=102))
    {
        rectangle2[100+cnnt].setOrigin(-295-(b-47)*76,-45-60*4);
        if(cnnt==1) {xfcod1=-295-(b-47)*76;yfcod1=-45-60*4;}
        else if(cnnt==2){xfocod1=-295-(b-47)*76;yfocod1=-45-60*4;}
    }
    else if(cnnt!=3 && b>=57 && b<=61&& (chk!=12&&chk!=22 && chk!=32 && chk!=42 && chk!=52 && chk!=62 && chk!=72 && chk!=82 && chk!=92 && chk!=102))
    {
        rectangle2[100+cnnt].setOrigin(-295-(b-57)*76,-45-60*5);
        if(cnnt==1) {xfcod1=-295-(b-57)*76;yfcod1=-45-60*5;}
        else if(cnnt==2){xfocod1=-295-(b-57)*76;yfocod1=-45-60*5;}
    }
    else if(cnnt!=3 && b>=67 && b<=71&& (chk!=12&&chk!=22 && chk!=32 && chk!=42 && chk!=52 && chk!=62 && chk!=72 && chk!=82 && chk!=92 && chk!=102))
    {
        rectangle2[100+cnnt].setOrigin(-295-(b-67)*76,-45-60*6);
        if(cnnt==1) {xfcod1=-295-(b-67)*76;yfcod1=-45-60*6;}
        else if(cnnt==2){xfocod1=-295-(b-67)*76;yfocod1=-45-60*6;}
    }
    else if(cnnt!=3 && b>=77 && b<=81&& (chk!=12&&chk!=22 && chk!=32 && chk!=42 && chk!=52 && chk!=62 && chk!=72 && chk!=82 && chk!=92 && chk!=102))
    {
        rectangle2[100+cnnt].setOrigin(-295-(b-77)*76,-45-60*7);
        if(cnnt==1) {xfcod1=-295-(b-77)*76;yfcod1=-45-60*7;}
        else if(cnnt==2){xfocod1=-295-(b-77)*76;yfocod1=-45-60*7;}
    }
    else if(cnnt!=3 && b>=87 && b<=91&& (chk!=12&&chk!=22 && chk!=32 && chk!=42 && chk!=52 && chk!=62 && chk!=72 && chk!=82 && chk!=92 && chk!=102))
    {
        rectangle2[100+cnnt].setOrigin(-295-(b-87)*76,-45-60*8);
        if(cnnt==1) {xfcod1=-295-(b-87)*76;yfcod1=-45-60*8;}
        else if(cnnt==2){xfocod1=-295-(b-87)*76;yfocod1=-45-60*8;}
    }
    else if(cnnt!=3 && b>=97 && b<=101&& (chk!=12&&chk!=22 && chk!=32 && chk!=42 && chk!=52 && chk!=62 && chk!=72 && chk!=82 && chk!=92 && chk!=102))
    {
        rectangle2[100+cnnt].setOrigin(-295-(b-97)*76,-45-60*9);
        if(cnnt==1) {xfcod1=-295-(b-97)*76;yfcod1=-45-60*9;}
        else if(cnnt==2){xfocod1=-295-(b-97)*76;yfocod1=-45-60*9;}
    }
    else if(chk==12)
    {
        rectangle2[100+cnnt].setOrigin(-295-(chk-7)*76,-45);
        xfocod1=-295-(chk-7)*76;yfocod1=-45;
    }
    else if(chk==22)
    {
        rectangle2[100+cnnt].setOrigin(-295-(chk-17)*76,-45-60*1);
        xfocod1=-295-(chk-17)*76;yfocod1=-45-60*1;
    }
    else if(chk==32)
    {
        rectangle2[100+cnnt].setOrigin(-295-(chk-27)*76,-45-60*2);
        xfocod1=-295-(chk-27)*76;yfocod1=-45-60*2;
    }
    else if(chk==42)
    {
        rectangle2[100+cnnt].setOrigin(-295-(chk-37)*76,-45-60*3);
        xfocod1=-295-(chk-37)*76;yfocod1=-45-60*3;
    }
    else if(chk==52)
    {
        rectangle2[100+cnnt].setOrigin(-295-(chk-47)*76,-45-60*4);
        xfocod1=-295-(chk-47)*76;yfocod1=-45-60*4;
    }
    else if(chk==62)
    {
        rectangle2[100+cnnt].setOrigin(-295-(chk-57)*76,-45-60*5);
        xfocod1=-295-(chk-57)*76;yfocod1=-45-60*5;
    }
    else if(chk==72)
    {
        rectangle2[100+cnnt].setOrigin(-295-(chk-67)*76,-45-60*6);
        xfocod1=-295-(chk-67)*76;yfocod1=-45-60*6;
    }
    else if(chk==82)
    {
        rectangle2[100+cnnt].setOrigin(-295-(chk-77)*76,-45-60*7);
        xfocod1=-295-(chk-77)*76;yfocod1=-45-60*7;
    }
    else if(chk==92)
    {
        rectangle2[100+cnnt].setOrigin(-295-(chk-87)*76,-45-60*8);
        xfocod1=-295-(chk-87)*76;yfocod1=-45-60*8;
    }
    else if(chk==102)
    {
        rectangle2[100+cnnt].setOrigin(-295-(chk-97)*76,-45-60*9);
        xfocod1=-295-(chk-97)*76;yfocod1=-45-60*9;
    }

    if(cnnt==1)
    {
        xfcod2=xfcod1-76;xfcod3=xfcod2-76;xfcod4=xfcod3-76;xfcod5=xfcod4-76;xfcod6=xfcod5-76;
    }
    else if(cnnt==2)
    {
        xfocod2=xfocod1-76;xfocod3=xfocod2-76;xfocod4=xfocod3-76;xfocod5=xfocod4-76;
    }
}


void BattleField::checkup(int cnnt)
{
    if(b!=7 && b!=8 && b!=9 && b!=10 && b!=11 && (chk!=12&&chk!=22 && chk!=32 && chk!=42 && chk!=52 && chk!=62 && chk!=72 && chk!=82 && chk!=92 && chk!=102))
    {
        for(int z=11;z<=17-cnnt;z++)
        {
            rectangle2[b-z-cnt+1].setOutlineColor(sf::Color(0,0,0));
            rectangle2[b-z-cnt+1].setOutlineThickness(-3);
            rectangle2[b-z+10-cnt+1].setOutlineColor(sf::Color(128,87,37));
        }
        b-=10;
    }
    else if(cnnt==2 && (chk==22 || chk==32 || chk==42 || chk==52 || chk==62 || chk==72 || chk==82 || chk==92 || chk==102))
    {
        for(int z=11;z<=17-cnnt;z++)
        {
            rectangle2[chk-z-cnt+1].setOutlineColor(sf::Color(0,0,0));
            rectangle2[chk-z-cnt+1].setOutlineThickness(-3);
            rectangle2[chk-z+10-cnt+1].setOutlineColor(sf::Color(128,87,37));
        }
        chk-=10;
        b-=10;
    }
}

void BattleField::checkdown(int cnnt)
{
    if(b!=97 && b!=98 && b!=99 && b!=100 && b!=101 && (chk!=12 && chk!=22 && chk!=32 && chk!=42 && chk!=52 && chk!=62 && chk!=72 && chk!=82 && chk!=92&&chk!=102))
    {
        for(int z=4;z<=10-cnnt;z++)
        {
            rectangle2[b+z].setOutlineColor(sf::Color(0,0,0));
            rectangle2[b+z].setOutlineThickness(-3);
            rectangle2[b-z+3-cnt+1].setOutlineColor(sf::Color(128,87,37));
        }
        b+=10;
    }
    else if(cnnt==2 && (chk==12 || chk==22 || chk==32 || chk==42 || chk==52 || chk==62 || chk==72 || chk==82 || chk==92))
    {
        for(int z=4;z<=10-cnnt;z++)
        {
            rectangle2[chk+z].setOutlineColor(sf::Color(0,0,0));
            rectangle2[chk+z].setOutlineThickness(-3);
            rectangle2[chk-z+3-cnt+1].setOutlineColor(sf::Color(128,87,37));
        }
        chk+=10;
        b+=10;
    }
}

void BattleField::checkleft(int cnnt)
{
    if(b!=7 && b!=17 && b!=27 && b!=37 && b!=47 && b!=57 && b!=67 && b!=77 && b!=87 && b!=97 && (chk!=12 && chk!=22 && chk!=32 && chk!=42 && chk!=52 && chk!=62 && chk!=72 && chk!=82 && chk!=92 && chk!=102))
    {
        for(int z=7;z>=1+cnnt;z--)
        {
            rectangle2[b-z].setOutlineColor(sf::Color(0,0,0));
            rectangle2[b-z].setOutlineThickness(-3);
            rectangle2[b-cnt].setOutlineColor(sf::Color(128,87,37));
        }
        b-=1;
    }
    else if(cnnt==2 && (chk==12 || chk==22 || chk==32 || chk==42 || chk==52 || chk==62 || chk==72 || chk==82 || chk==92 || chk==102))
    {
        for(int z=7;z>=1+cnnt;z--)
        {
            rectangle2[chk-z].setOutlineColor(sf::Color(0,0,0));
            rectangle2[chk-z].setOutlineThickness(-3);
            rectangle2[chk-cnt].setOutlineColor(sf::Color(128,87,37));
        }
        chk=0;
    }
}

void BattleField::checkright(int cnnt)
{
    if(b!=11 && b!=21 && b!=31 && b!=41 && b!=51 && b!=61 && b!=71 && b!=81 && b!=91 && b!=101 && (chk!=12 && chk!=22 && chk!=32 && chk!=42 && chk!=52 && chk!=62 && chk!=72 && chk!=82 && chk!=92&&chk!=102))
    {
        for(int z=5;z>=-1+cnnt;z--)
        {
            rectangle2[b-z].setOutlineColor(sf::Color(0,0,0));
            rectangle2[b-z].setOutlineThickness(-3);
            rectangle2[b-6].setOutlineColor(sf::Color(128,87,37));
        }
        b+=1;
    }
    if(cnnt==2 && (b==11 || b==21 || b==31 || b==41 || b==51 || b==61 || b==71 || b==81 || b==91 || b==101)&&chk==0)
    {
        chk=b;
        for(int z=5;z>=1;z--)
        {
            rectangle2[chk-z].setOutlineColor(sf::Color(0,0,0));
            rectangle2[chk-z].setOutlineThickness(-3);
            rectangle2[chk-6].setOutlineColor(sf::Color(128,87,37));
        }
        chk+=1;
    }
}

int BattleField::run(sf::RenderWindow &app)
{
    sf::Texture texture5;
    if (!texture5.loadFromFile("Ship.png", sf::IntRect(0, 0,456, 60)))
    {
        std::cout<<"error...";
    }

    sf::Texture texture15;
    if (!texture15.loadFromFile("fire.png", sf::IntRect(0, 0,76, 60)))
    {
        std::cout<<"error...";
    }

    sf::Texture texture7;
    if (!texture7.loadFromFile("Ship2.png", sf::IntRect(0, 0,456, 60)))
    {
        std::cout<<"error...";
    }
/*
    sf::Texture texture8;
    if (!texture8.loadFromFile("Vship.png", sf::IntRect(0, 0,76,360)))
    {
        std::cout<<"error...";
    }
*/
    sf::Texture texture28;
    if (!texture28.loadFromFile("cross.png", sf::IntRect(0, 0,76,60)))
    {
        std::cout<<"error...";
    }
/*
    sf::Texture texture98;
    if (!texture98.loadFromFile("Vship2.png", sf::IntRect(0, 0,76,360)))
    {
        std::cout<<"error...";
    }
*/
    sf::Texture texture2;
    if (!texture2.loadFromFile("water.png", sf::IntRect(0, 0,760, 600)))
    {
        std::cout<<"error...";
    }

    sf::Font font;
    if (!font.loadFromFile("ALGER.TTF"))
    {
        std::cout<<"error...";
    }

    sf::Text hits[4];

    for(int i=0;i<4;i++)
    {
        hits[i].setFont(font);
        hits[i].setStyle(sf::Text::Bold);
        hits[i].setColor(sf::Color(10,87,255));
    }

    hits[0].setCharacterSize(45);
    hits[1].setCharacterSize(45);
    hits[2].setCharacterSize(25);
    hits[3].setCharacterSize(25);

    hits[0].setString("YOUR");
    hits[1].setString("COMPUTER");
    hits[0].setOrigin(-30,0);
    hits[1].setOrigin(-1100,0);
    hits[2].setOrigin(-100,-200);
    hits[3].setOrigin(-1150,-200);

    rectangle2[0].setOrigin(-295,-45);
    rectangle2[0].setSize(sf::Vector2f(760,600));
    rectangle2[0].setTexture(&texture2);
    rectangle2[0].setTextureRect(sf::IntRect(0,0,760,600));
    rectangle2[0].setFillColor(sf::Color(255, 255, 255, 130));

    sf::Event event;

    bool running=true;

    while(running)
    {
        while(app.pollEvent(event))
        {

            if(event.type==sf::Event::Closed)
                return (-1);
            if(event.type==sf::Event::KeyPressed)
            {
                switch (event.key.code)
                {
                case sf::Keyboard::Escape:
                    return 0;
                    break;

                case sf::Keyboard::Up:

                    if(cnt!=3)
                    {
                        checkup(cnt);

                    }
                    else if(cnt==3 && !(small>=1 && small<=10))
                    {
                        if((small!=20 && small!=30 && small!=40 && small!=50 && small!=60 && small!=70 && small!=80 && small!=90 && small!=100))
                        {
                            rectangle2[103].setOrigin(-295-(small%10-1)*76,-45-(small/10-1)*60);
                        }
                        else
                        {
                            rectangle2[103].setOrigin(-295-(small%10+9)*76,-45-(small/10-2)*60);
                        }
                        rectangle2[103].setSize(sf::Vector2f(76,60));
                        rectangle2[103].setOutlineThickness(-3);
                        rectangle2[103].setOutlineColor(sf::Color(0,0,0));
                        rectangle2[103].setFillColor(sf::Color(255,255,255,0));
                        small-=10;
                    }
                    break;

                case sf::Keyboard::Down:
                    if(cnt!=3)
                    {
                        checkdown(cnt);

                    }
                    else if(cnt==3 && !(small>=91 && small<=100))
                    {
                        if((small!=10 && small!=20 && small!=30 && small!=40 && small!=50 && small!=60 && small!=70 && small!=80 && small!=90 && small!=100))
                        {
                            rectangle2[103].setOrigin(-295-(small%10-1)*76,-45-(small/10+1)*60);
                        }
                        else
                        {
                            rectangle2[103].setOrigin(-295-(small%10+9)*76,-45-(small/10)*60);
                        }
                        rectangle2[103].setSize(sf::Vector2f(76,60));
                        rectangle2[103].setOutlineThickness(-3);
                        rectangle2[103].setOutlineColor(sf::Color(0,0,0));
                        rectangle2[103].setFillColor(sf::Color(255,255,255,0));
                        small+=10;
                    }
                    break;

                case sf::Keyboard::Left:
                    if(cnt!=3)
                    {
                        checkleft(cnt);

                    }
                    else if(cnt==3 && (small!=1 && small!=11 && small!=21 && small!=31 && small!=41 && small!=51 && small!=61 && small!=71 && small!=81 && small!=91))
                    {
                        if((small!=10 && small!=20 && small!=30 && small!=40 && small!=50 && small!=60 && small!=70 && small!=80 && small!=90 && small!=100))
                        {
                            rectangle2[103].setOrigin(-295-(small%10-2)*76,-45-(small/10)*60);
                        }
                        else
                        {
                            rectangle2[103].setOrigin(-295-(small%10+8)*76,-45-(small/10-1)*60);
                        }
                        rectangle2[103].setSize(sf::Vector2f(76,60));
                        rectangle2[103].setOutlineThickness(-3);
                        rectangle2[103].setOutlineColor(sf::Color(0,0,0));
                        rectangle2[103].setFillColor(sf::Color(255,255,255,0));
                        small-=1;
                    }
                    break;

                case sf::Keyboard::Right:
                    if(cnt!=3)
                    {
                        checkright(cnt);

                    }
                    else if(cnt==3 && (small!=10 && small!=20 && small!=30 && small!=40 && small!=50 && small!=60 && small!=70 && small!=80 && small!=90 && small!=100))
                    {
                        rectangle2[103].setOrigin(-295-(small%10)*76,-45-(small/10)*60);
                        rectangle2[103].setSize(sf::Vector2f(76,60));
                        rectangle2[103].setOutlineThickness(-3);
                        rectangle2[103].setOutlineColor(sf::Color(0,0,0));
                        rectangle2[103].setFillColor(sf::Color(255,255,255,0));
                        small+=1;
                    }
                    break;

                    case sf::Keyboard::Space:
                        {
                        for(int i=0;i<cros;i++)
                        {
                            cross[i].setFillColor(sf::Color(255,255,255,130));
                            app.draw(cross[i]);
                           // app.display();
                        }
                        app.display();
                        }
                        sf::sleep(sf::seconds(1));
                        {
                        if(coun==1)
                        {
                            rectangle2[104].setFillColor(sf::Color(255,255,255,130));
                            app.draw(rectangle2[104]);
                            app.display();

                        }
                        else if(coun==2)
                        {
                            rectangle2[104].setFillColor(sf::Color(255,255,255,130));
                            app.draw(rectangle2[104]);
                            rectangle2[105].setFillColor(sf::Color(255,255,255,130));
                            app.draw(rectangle2[105]);
                            app.display();

                        }
                        else if(coun==3)
                        {
                            rectangle2[104].setFillColor(sf::Color(255,255,255,130));
                            app.draw(rectangle2[104]);
                            rectangle2[105].setFillColor(sf::Color(255,255,255,130));
                            app.draw(rectangle2[105]);
                            rectangle2[106].setFillColor(sf::Color(255,255,255,130));
                            app.draw(rectangle2[106]);
                            app.display();

                        }
                        else if(coun==4)
                        {
                            rectangle2[104].setFillColor(sf::Color(255,255,255,130));
                            app.draw(rectangle2[104]);
                            rectangle2[105].setFillColor(sf::Color(255,255,255,130));
                            app.draw(rectangle2[105]);
                            rectangle2[106].setFillColor(sf::Color(255,255,255,130));
                            app.draw(rectangle2[106]);
                            rectangle2[107].setFillColor(sf::Color(255,255,255,130));
                            app.draw(rectangle2[107]);
                            app.display();

                        }
                        else if(coun==5)
                        {
                            rectangle2[104].setFillColor(sf::Color(255,255,255,130));
                            app.draw(rectangle2[104]);
                            rectangle2[105].setFillColor(sf::Color(255,255,255,130));
                            app.draw(rectangle2[105]);
                            rectangle2[106].setFillColor(sf::Color(255,255,255,130));
                            app.draw(rectangle2[106]);
                            rectangle2[107].setFillColor(sf::Color(255,255,255,130));
                            app.draw(rectangle2[107]);
                            rectangle2[108].setFillColor(sf::Color(255,255,255,130));
                            app.draw(rectangle2[108]);
                            app.display();

                        }
                        else if(coun==6)
                        {
                            rectangle2[104].setFillColor(sf::Color(255,255,255,130));
                            app.draw(rectangle2[104]);
                            rectangle2[105].setFillColor(sf::Color(255,255,255,130));
                            app.draw(rectangle2[105]);
                            rectangle2[106].setFillColor(sf::Color(255,255,255,130));
                            app.draw(rectangle2[106]);
                            rectangle2[107].setFillColor(sf::Color(255,255,255,130));
                            app.draw(rectangle2[107]);
                            rectangle2[108].setFillColor(sf::Color(255,255,255,130));
                            app.draw(rectangle2[108]);
                            rectangle2[109].setFillColor(sf::Color(255,255,255,130));
                            app.draw(rectangle2[109]);
                            app.display();

                        }
                        else if(coun==7)
                        {
                            rectangle2[104].setFillColor(sf::Color(255,255,255,130));
                            app.draw(rectangle2[104]);
                            rectangle2[105].setFillColor(sf::Color(255,255,255,130));
                            app.draw(rectangle2[105]);
                            rectangle2[106].setFillColor(sf::Color(255,255,255,130));
                            app.draw(rectangle2[106]);
                            rectangle2[107].setFillColor(sf::Color(255,255,255,130));
                            app.draw(rectangle2[107]);
                            rectangle2[108].setFillColor(sf::Color(255,255,255,130));
                            app.draw(rectangle2[108]);
                            rectangle2[109].setFillColor(sf::Color(255,255,255,130));
                            app.draw(rectangle2[109]);
                            rectangle2[110].setFillColor(sf::Color(255,255,255,130));
                            app.draw(rectangle2[110]);
                            app.display();

                        }
                        else if(coun==8)
                        {
                            rectangle2[104].setFillColor(sf::Color(255,255,255,130));
                            app.draw(rectangle2[104]);
                            rectangle2[105].setFillColor(sf::Color(255,255,255,130));
                            app.draw(rectangle2[105]);
                            rectangle2[106].setFillColor(sf::Color(255,255,255,130));
                            app.draw(rectangle2[106]);
                            rectangle2[107].setFillColor(sf::Color(255,255,255,130));
                            app.draw(rectangle2[107]);
                            rectangle2[108].setFillColor(sf::Color(255,255,255,130));
                            app.draw(rectangle2[108]);
                            rectangle2[109].setFillColor(sf::Color(255,255,255,130));
                            app.draw(rectangle2[109]);
                            rectangle2[110].setFillColor(sf::Color(255,255,255,130));
                            app.draw(rectangle2[110]);
                            rectangle2[111].setFillColor(sf::Color(255,255,255,130));
                            app.draw(rectangle2[111]);
                            app.display();

                        }
                        else if(coun==9)
                        {
                             rectangle2[104].setFillColor(sf::Color(255,255,255,130));
                            app.draw(rectangle2[104]);
                            rectangle2[105].setFillColor(sf::Color(255,255,255,130));
                            app.draw(rectangle2[105]);
                            rectangle2[106].setFillColor(sf::Color(255,255,255,130));
                            app.draw(rectangle2[106]);
                            rectangle2[107].setFillColor(sf::Color(255,255,255,130));
                            app.draw(rectangle2[107]);
                            rectangle2[108].setFillColor(sf::Color(255,255,255,130));
                            app.draw(rectangle2[108]);
                            rectangle2[109].setFillColor(sf::Color(255,255,255,130));
                            app.draw(rectangle2[109]);
                            rectangle2[110].setFillColor(sf::Color(255,255,255,130));
                            app.draw(rectangle2[110]);
                            rectangle2[111].setFillColor(sf::Color(255,255,255,130));
                            app.draw(rectangle2[111]);
                            rectangle2[112].setFillColor(sf::Color(255,255,255,130));
                            app.draw(rectangle2[112]);
                            app.display();

                        }
                        else if(coun==10)
                        {
                            rectangle2[104].setFillColor(sf::Color(255,255,255,130));
                            app.draw(rectangle2[104]);
                            rectangle2[105].setFillColor(sf::Color(255,255,255,130));
                            app.draw(rectangle2[105]);
                            rectangle2[106].setFillColor(sf::Color(255,255,255,130));
                            app.draw(rectangle2[106]);
                            rectangle2[107].setFillColor(sf::Color(255,255,255,130));
                            app.draw(rectangle2[107]);
                            rectangle2[108].setFillColor(sf::Color(255,255,255,130));
                            app.draw(rectangle2[108]);
                            rectangle2[109].setFillColor(sf::Color(255,255,255,130));
                            app.draw(rectangle2[109]);
                            rectangle2[110].setFillColor(sf::Color(255,255,255,130));
                            app.draw(rectangle2[110]);
                            rectangle2[111].setFillColor(sf::Color(255,255,255,130));
                            app.draw(rectangle2[111]);
                            rectangle2[112].setFillColor(sf::Color(255,255,255,130));
                            app.draw(rectangle2[112]);
                            rectangle2[113].setFillColor(sf::Color(255,255,255,130));
                            app.draw(rectangle2[113]);
                            app.display();

                        }
                        else if(coun==11)
                        {
                            rectangle2[104].setFillColor(sf::Color(255,255,255,130));
                            app.draw(rectangle2[104]);
                            rectangle2[105].setFillColor(sf::Color(255,255,255,130));
                            app.draw(rectangle2[105]);
                            rectangle2[106].setFillColor(sf::Color(255,255,255,130));
                            app.draw(rectangle2[106]);
                            rectangle2[107].setFillColor(sf::Color(255,255,255,130));
                            app.draw(rectangle2[107]);
                            rectangle2[108].setFillColor(sf::Color(255,255,255,130));
                            app.draw(rectangle2[108]);
                            rectangle2[109].setFillColor(sf::Color(255,255,255,130));
                            app.draw(rectangle2[109]);
                            rectangle2[110].setFillColor(sf::Color(255,255,255,130));
                            app.draw(rectangle2[110]);
                            rectangle2[111].setFillColor(sf::Color(255,255,255,130));
                            app.draw(rectangle2[111]);
                            rectangle2[112].setFillColor(sf::Color(255,255,255,130));
                            app.draw(rectangle2[112]);
                            rectangle2[113].setFillColor(sf::Color(255,255,255,130));
                            app.draw(rectangle2[113]);
                            rectangle2[114].setFillColor(sf::Color(255,255,255,130));
                            app.draw(rectangle2[114]);
                            app.display();
                        }
                        sf::sleep(sf::seconds(1));
                        }

                        break;

                    case sf::Keyboard::Return:

                        if(cnt==1)
                        {
                            checkh(cnt);
                            rectangle2[100+cnt].setSize(sf::Vector2f(456,60));
                            rectangle2[100+cnt].setTexture(&texture5);
                            rectangle2[100+cnt].setTextureRect(sf::IntRect(0,0,456,60));
                            rectangle2[100+cnt].setFillColor(sf::Color(255, 255, 255, 130));
                            cnt++;
                        }
                        else if(cnt==2)
                        {
                            checkh(cnt);
                            if(((xfocod1==xfcod1||xfocod1==xfcod2||xfocod1==xfcod3||xfocod1==xfcod4||xfocod1==xfcod5||xfocod1==xfcod6)&& yfocod1==yfcod1)||((xfocod2==xfcod1||xfocod2==xfcod2||xfocod2==xfcod3||xfocod2==xfcod4||xfocod2==xfcod5||xfocod2==xfcod6)&& yfocod1==yfcod1)||((xfocod3==xfcod1||xfocod3==xfcod2||xfocod3==xfcod3||xfocod3==xfcod4||xfocod3==xfcod5||xfocod3==xfcod6)&& yfocod1==yfcod1)||((xfocod4==xfcod1||xfocod4==xfcod2||xfocod4==xfcod3||xfocod4==xfcod4||xfocod4==xfcod5||xfocod4==xfcod6)&& yfocod1==yfcod1)||((xfocod5==xfcod1||xfocod5==xfcod2||xfocod5==xfcod3||xfocod5==xfcod4||xfocod5==xfcod5||xfocod5==xfcod6)&& yfocod1==yfcod1))
                                break;
                            rectangle2[102].setSize(sf::Vector2f(380,60));
                            rectangle2[102].setTexture(&texture7);
                            rectangle2[102].setTextureRect(sf::IntRect(0,0,380,60));
                            rectangle2[102].setFillColor(sf::Color(255, 255, 255, 130));
                            cnt++;
                            airand();
                            app.draw(rectangle2[102]);
                            app.display();
                            sf::sleep(sf::seconds(2));
                            rectangle2[101].setFillColor(sf::Color(255,255,255,0));
                            rectangle2[102].setFillColor(sf::Color(255,255,255,0));
                            for(int i=0;i<COLBOX;i++)
                            {
                                for(int j=1;j<BOX;j++)
                                {
                                    rectangle2[j+10*i].setOrigin(-295-(j-1)*76,-45-i*60);
                                    rectangle2[j+10*i].setSize(sf::Vector2f(76,60));
                                    rectangle2[j+10*i].setOutlineThickness(-2);
                                    rectangle2[j+10*i].setOutlineColor(sf::Color(128,87,37));
                                    rectangle2[j+10*i].setFillColor(sf::Color(255,255,255,0));
                                }
                            }
                            rectangle2[103].setOrigin(-295,-45);
                            rectangle2[103].setSize(sf::Vector2f(76,60));
                            rectangle2[103].setOutlineThickness(-3);
                            rectangle2[103].setOutlineColor(sf::Color(0,0,0));
                            rectangle2[103].setFillColor(sf::Color(255,255,255,0));
                        }
                        else if(cnt==3)
                        {
                            if((small!=10 && small!=20 && small!=30 && small!=40 && small!=50 && small!=60 && small!=70 && small!=80 && small!=90 && small!=100))
                            {
                                xtar[str]=-295-(small%10-1)*76;
                                ytar[str]=-45-(small/10)*60;
                            }
                            else
                            {
                                xtar[str]=-295-(small%10+9)*76;
                                ytar[str]=-45-(small/10-1)*60;
                            }

                            if(((xtar[str]==axfcod1||xtar[str]==axfcod2||xtar[str]==axfcod3||xtar[str]==axfcod4||xtar[str]==axfcod5||xtar[str]==axfcod6)&&(ytar[str]==ayfcod1||ytar[str]==ayfcod2||ytar[str]==ayfcod3||ytar[str]==ayfcod4||ytar[str]==ayfcod5||ytar[str]==ayfcod6))||((xtar[str]==axfocod1||xtar[str]==axfocod2||xtar[str]==axfocod3||xtar[str]==axfocod4||xtar[str]==axfocod5)&&(ytar[str]==ayfocod1||ytar[str]==ayfocod2||ytar[str]==ayfocod3||ytar[str]==ayfocod4||ytar[str]==ayfocod5)))
                            {
                                rectangle2[101].setFillColor(sf::Color(255,255,255,0));
                                rectangle2[102].setFillColor(sf::Color(255,255,255,0));
                                app.draw(rectangle2[101]);
                                app.draw(rectangle2[102]);
                                rectangle2[104+coun].setSize(sf::Vector2f(76,60));
                                rectangle2[104+coun].setOrigin(xtar[str],ytar[str]);
                                rectangle2[104+coun].setTexture(&texture15);
                                rectangle2[104+coun].setTextureRect(sf::IntRect(0,0,76,60));
                                rectangle2[104+coun].setFillColor(sf::Color(255, 255, 255, 130));
                                app.draw(rectangle2[104+coun]);
                                coun+=1;
                                for(int i=0;i<str;i++)
                                {
                                    if((xtar[str]==xtar[str-1-i] && ytar[str]!=ytar[str-1-i])||(xtar[str]!=xtar[str-1-i] && ytar[str]==ytar[str-1-i])||(xtar[str]!=xtar[str-1-i] && ytar[str]!=ytar[str-1-i]))
                                    {
                                        if(i!=str-1)
                                            continue;
                                        if(i==str-1)
                                        {
                                            hit+=1;
                                        }
                                    }
                                    else
                                        break;
                                }

                                if(str==0)
                                    hit+=1;
                                str++;
                                if(hit==1){ hits[2].setString("1");}
                                else if(hit==2){ hits[2].setString("2");}
                                else if(hit==3){ hits[2].setString("3");}
                                else if(hit==4){ hits[2].setString("4");}
                                else if(hit==5){ hits[2].setString("5");}
                                else if(hit==6){ hits[2].setString("6");}
                                else if(hit==7){ hits[2].setString("7");}
                                else if(hit==8){ hits[2].setString("8");}
                                else if(hit==9){ hits[2].setString("9");}
                                else if(hit==10){ hits[2].setString("10");}
                                else if(hit==11){ hits[2].setString("11");}

                                app.draw(hits[2]);
                                app.display();
                                if(hit==11) return 2;
                            }

                            else
                            {
                                cross[cros].setOrigin(xtar[str],ytar[str]);
                                cross[cros].setSize(sf::Vector2f(76,60));
                                cross[cros].setTexture(&texture28);
                                cross[cros].setTextureRect(sf::IntRect(0,0,76,60));
                                cross[cros].setFillColor(sf::Color(255, 255, 255, 130));
                                app.draw(cross[cros]);
                                app.display();
                                cros++;
                            }

                            sf::sleep(sf::seconds(1));
                            rectangle2[101].setFillColor(sf::Color(255,255,255,130));
                            rectangle2[102].setFillColor(sf::Color(255,255,255,130));
                            app.draw(rectangle2[101]);
                            app.draw(rectangle2[102]);
                            app.draw(hits[2]);
                            app.display();
                            rectangle2[103+coun].setFillColor(sf::Color(255,255,255,0));app.display();
                            sf::sleep(sf::seconds(1));

                            if(nnn==1)
                            {
                                zzx=nowzzx+(counter+1)*76;
                                if(zzx<=-295)
                                {
                                    aix[yy]=zzx;
                                    aiy[yy]=zzy;

                                    yy++;
                                    if(((zzx==xfcod1||zzx==xfcod2||zzx==xfcod3||zzx==xfcod4||zzx==xfcod5||zzx==xfcod6)&&(zzy==yfcod1))||((zzx==xfocod1||zzx==xfocod2||zzx==xfocod3||zzx==xfocod4||zzx==xfocod5)&&(zzy==yfocod1)))
                                    {
                                        if(t<=5)
                                        {
                                        ckx[t]=zzx;
                                        cky[t]=zzy;
                                        t++;
                                        }
                                        rectangle2[115].setOrigin(zzx,zzy);
                                        rectangle2[115].setSize(sf::Vector2f(76,60));
                                        rectangle2[115].setFillColor(sf::Color(255, 255, 255, 130));
                                        rectangle2[115].setTexture(&texture15);
                                        rectangle2[115].setTextureRect(sf::IntRect(0,0,76,60));
                                        app.draw(rectangle2[115]);
                                        chit+=1;
                                        counter++;
                                        if(chit==1){ hits[3].setString("1");}
                                        else if(chit==2){  hits[3].setString("2");}
                                        else if(chit==3){ hits[3].setString("3");}
                                        else if(chit==4){ hits[3].setString("4");}
                                        else if(chit==5){ hits[3].setString("5");}
                                        else if(chit==6){ hits[3].setString("6");}
                                        else if(chit==7){ hits[3].setString("7");}
                                        else if(chit==8){ hits[3].setString("8");}
                                        else if(chit==9){ hits[3].setString("9");}
                                        else if(chit==10){hits[3].setString("10");}
                                        else if(chit==11){hits[3].setString("11");}
                                        app.draw(hits[2]);
                                        app.draw(hits[3]);
                                        app.display();
                                        if(chit==11) return 3;
                                        sf::sleep(sf::seconds(2));
                                        rectangle2[115].setFillColor(sf::Color(255, 255, 255, 0));
                                        app.draw(hits[2]);
                                        app.draw(rectangle2[115]);
                                        app.display();
                                        break;
                                    }
                                    else
                                    {
                                        nnn=0;
                                        cross[89].setOrigin(zzx,zzy);
                                        cross[89].setSize(sf::Vector2f(76,60));
                                        cross[89].setTexture(&texture28);
                                        cross[89].setTextureRect(sf::IntRect(0,0,76,60));
                                        cross[89].setFillColor(sf::Color(255, 255, 255, 130));
                                        app.draw(cross[89]);
                                        app.draw(hits[2]);
                                        app.display();
                                        sf::sleep(sf::seconds(2));
                                        cross[89].setFillColor(sf::Color(255, 255, 255, 0));
                                        app.draw(cross[89]);
                                        app.draw(hits[2]);
                                        app.display();
                                        break;
                                    }
                                }
                                else if(zzx>-295)
                                {
                                    zzx=nowzzx-(ccounter+1)*76;
                                    if(zzx>=-295-9*76)
                                    {
                                        aix[yy]=zzx;
                                        aiy[yy]=zzy;
                                        yy++;
                                        if(((zzx==xfcod1||zzx==xfcod2||zzx==xfcod3||zzx==xfcod4||zzx==xfcod5||zzx==xfcod6)&&(zzy==yfcod1))||((zzx==xfocod1||zzx==xfocod2||zzx==xfocod3||zzx==xfocod4||zzx==xfocod5)&&(zzy==yfocod1)))
                                        {
                                            if(t<=5)
                                            {
                                            ckx[t]=zzx;
                                            cky[t]=zzy;
                                            t++;
                                            }
                                            rectangle2[115].setOrigin(zzx,zzy);
                                            rectangle2[115].setSize(sf::Vector2f(76,60));
                                            rectangle2[115].setFillColor(sf::Color(255, 255, 255, 130));
                                            rectangle2[115].setTexture(&texture15);
                                            rectangle2[115].setTextureRect(sf::IntRect(0,0,76,60));
                                            app.draw(rectangle2[115]);
                                            chit+=1;
                                            nnn=0;
                                            ccounter++;
                                            if(chit==1){ hits[3].setString("1");}
                                            else if(chit==2){  hits[3].setString("2");}
                                            else if(chit==3){ hits[3].setString("3");}
                                            else if(chit==4){ hits[3].setString("4");}
                                            else if(chit==5){ hits[3].setString("5");}
                                            else if(chit==6){ hits[3].setString("6");}
                                            else if(chit==7){ hits[3].setString("7");}
                                            else if(chit==8){ hits[3].setString("8");}
                                            else if(chit==9){ hits[3].setString("9");}
                                            else if(chit==10){hits[3].setString("10");}
                                            else if(chit==11){hits[3].setString("11");}
                                            app.draw(hits[2]);
                                            app.draw(hits[3]);
                                            app.display();
                                            if(chit==11) return 3;
                                            sf::sleep(sf::seconds(2));
                                            rectangle2[115].setFillColor(sf::Color(255, 255, 255, 0));
                                            app.draw(hits[2]);
                                            app.draw(rectangle2[115]);
                                            app.display();
                                            break;
                                        }
                                        else
                                        {
                                            cross[89].setOrigin(zzx,zzy);
                                            cross[89].setSize(sf::Vector2f(76,60));
                                            cross[89].setTexture(&texture28);
                                            cross[89].setTextureRect(sf::IntRect(0,0,76,60));
                                            cross[89].setFillColor(sf::Color(255, 255, 255, 130));
                                            app.draw(cross[89]);
                                            app.draw(hits[2]);
                                            app.display();
                                            sf::sleep(sf::seconds(2));
                                            cross[89].setFillColor(sf::Color(255, 255, 255, 0));
                                            app.draw(cross[89]);
                                            app.draw(hits[2]);
                                            app.display();
                                            nnn=2;
                                            break;
                                        }
                                    }
                                }
                            }

                            else if(nnn==0)
                            {
                                zzx=nowzzx-(dcounter+1)*76;
                                if(zzx>=-295-9*76)
                                {
                                    aix[yy]=zzx;
                                    aiy[yy]=zzy;
                                    yy++;
                                    if(((zzx==xfcod1||zzx==xfcod2||zzx==xfcod3||zzx==xfcod4||zzx==xfcod5||zzx==xfcod6)&&(zzy==yfcod1))||((zzx==xfocod1||zzx==xfocod2||zzx==xfocod3||zzx==xfocod4||zzx==xfocod5)&&(zzy==yfocod1)))
                                    {
                                        if(t<=5)
                                        {
                                        ckx[t]=zzx;
                                        cky[t]=zzy;
                                        t++;
                                        }
                                        rectangle2[115].setOrigin(zzx,zzy);
                                        rectangle2[115].setSize(sf::Vector2f(76,60));
                                        rectangle2[115].setFillColor(sf::Color(255, 255, 255, 130));
                                        rectangle2[115].setTexture(&texture15);
                                        rectangle2[115].setTextureRect(sf::IntRect(0,0,76,60));
                                        app.draw(rectangle2[115]);
                                        chit+=1;
                                        dcounter++;
                                        if(chit==1){ hits[3].setString("1");}
                                        else if(chit==2){  hits[3].setString("2");}
                                        else if(chit==3){ hits[3].setString("3");}
                                        else if(chit==4){ hits[3].setString("4");}
                                        else if(chit==5){ hits[3].setString("5");}
                                        else if(chit==6){ hits[3].setString("6");}
                                        else if(chit==7){ hits[3].setString("7");}
                                        else if(chit==8){ hits[3].setString("8");}
                                        else if(chit==9){ hits[3].setString("9");}
                                        else if(chit==10){hits[3].setString("10");}
                                        else if(chit==11){hits[3].setString("11");}
                                        app.draw(hits[2]);
                                        app.draw(hits[3]);
                                        app.display();
                                        if(chit==11) return 3;
                                        sf::sleep(sf::seconds(2));
                                        rectangle2[115].setFillColor(sf::Color(255, 255, 255, 0));
                                        app.draw(hits[2]);
                                        app.draw(rectangle2[115]);
                                        app.display();
                                        break;
                                    }
                                    else
                                    {
                                        cross[89].setOrigin(zzx,zzy);
                                        cross[89].setSize(sf::Vector2f(76,60));
                                        cross[89].setTexture(&texture28);
                                        cross[89].setTextureRect(sf::IntRect(0,0,76,60));
                                        cross[89].setFillColor(sf::Color(255, 255, 255, 130));
                                        app.draw(cross[89]);
                                        app.draw(hits[2]);
                                        app.display();
                                        sf::sleep(sf::seconds(2));
                                        cross[89].setFillColor(sf::Color(255, 255, 255, 0));
                                        app.draw(cross[89]);
                                        app.draw(hits[2]);
                                        app.display();
                                        nnn=2;
                                        break;
                                    }
                                }
                                if(zzx<-295-9*76)
                                {
                                    yes=0;
                                    aiblast();
                                    counter=0;
                                    ccounter=0;
                                    dcounter=0;
                                    if(((zzx==xfcod1||zzx==xfcod2||zzx==xfcod3||zzx==xfcod4||zzx==xfcod5||zzx==xfcod6)&&(zzy==yfcod1))||((zzx==xfocod1||zzx==xfocod2||zzx==xfocod3||zzx==xfocod4||zzx==xfocod5)&&(zzy==yfocod1)))
                                    {
                                        nowzzx=zzx;
                                        nowzzy=zzy;
                                        rectangle2[115].setOrigin(zzx,zzy);
                                        rectangle2[115].setSize(sf::Vector2f(76,60));
                                        rectangle2[115].setFillColor(sf::Color(255, 255, 255, 130));
                                        rectangle2[115].setTexture(&texture15);
                                        rectangle2[115].setTextureRect(sf::IntRect(0,0,76,60));
                                        app.draw(rectangle2[115]);
                                        chit+=1;
                                        nnn=1;
                                        if(chit==1){ hits[3].setString("1");}
                                        else if(chit==2){  hits[3].setString("2");}
                                        else if(chit==3){ hits[3].setString("3");}
                                        else if(chit==4){ hits[3].setString("4");}
                                        else if(chit==5){ hits[3].setString("5");}
                                        else if(chit==6){ hits[3].setString("6");}
                                        else if(chit==7){ hits[3].setString("7");}
                                        else if(chit==8){ hits[3].setString("8");}
                                        else if(chit==9){ hits[3].setString("9");}
                                        else if(chit==10){hits[3].setString("10");}
                                        else if(chit==11){hits[3].setString("11");}
                                        app.draw(hits[2]);
                                        app.draw(hits[3]);
                                        app.display();
                                        if(chit==11) return 3;
                                        sf::sleep(sf::seconds(2));
                                        rectangle2[115].setFillColor(sf::Color(255, 255, 255, 0));
                                        app.draw(hits[2]);
                                        app.draw(rectangle2[115]);
                                        app.display();
                                    }
                                    else
                                    {
                                        nnn=2;
                                        cross[89].setOrigin(zzx,zzy);
                                        cross[89].setSize(sf::Vector2f(76,60));
                                        cross[89].setTexture(&texture28);
                                        cross[89].setTextureRect(sf::IntRect(0,0,76,60));
                                        cross[89].setFillColor(sf::Color(255, 255, 255, 130));
                                        app.draw(cross[89]);
                                        app.draw(hits[2]);
                                        app.display();
                                        sf::sleep(sf::seconds(2));
                                        cross[89].setFillColor(sf::Color(255, 255, 255, 0));
                                        app.draw(cross[89]);
                                        app.draw(hits[2]);
                                        app.display();
                                    }
                                }
                            }
                            else if(nnn==2)
                            {
                                yes=0;
                                aiblast();
                                counter=0;
                                ccounter=0;
                                dcounter=0;
                                if(((zzx==xfcod1||zzx==xfcod2||zzx==xfcod3||zzx==xfcod4||zzx==xfcod5||zzx==xfcod6)&&(zzy==yfcod1))||((zzx==xfocod1||zzx==xfocod2||zzx==xfocod3||zzx==xfocod4||zzx==xfocod5)&&(zzy==yfocod1)))
                                {
                                    nowzzx=zzx;
                                    nowzzy=zzy;
                                    rectangle2[115].setOrigin(zzx,zzy);
                                    rectangle2[115].setSize(sf::Vector2f(76,60));
                                    rectangle2[115].setFillColor(sf::Color(255, 255, 255, 130));
                                    rectangle2[115].setTexture(&texture15);
                                    rectangle2[115].setTextureRect(sf::IntRect(0,0,76,60));
                                    app.draw(rectangle2[115]);
                                    chit+=1;
                                    nnn=1;
                                    if(chit==1){ hits[3].setString("1");}
                                    else if(chit==2){ hits[3].setString("2");}
                                    else if(chit==3){hits[3].setString("3");}
                                    else if(chit==4){hits[3].setString("4");}
                                    else if(chit==5){hits[3].setString("5");}
                                    else if(chit==6){hits[3].setString("6");}
                                    else if(chit==7){hits[3].setString("7");}
                                    else if(chit==8){hits[3].setString("8");}
                                    else if(chit==9){hits[3].setString("9");}
                                    else if(chit==10){hits[3].setString("10");}
                                    else if(chit==11){hits[3].setString("11");}
                                    app.draw(hits[2]);
                                    app.draw(hits[3]);
                       //////////             app.display();
                                    if(chit==11) return 3;
                                    sf::sleep(sf::seconds(2));
                                    rectangle2[115].setFillColor(sf::Color(255, 255, 255, 0));
                                    app.draw(hits[2]);
                                    app.draw(rectangle2[115]);
                                    app.display();
                                }
                                else
                                {
                                    cross[89].setOrigin(zzx,zzy);
                                    cross[89].setSize(sf::Vector2f(76,60));
                                    cross[89].setTexture(&texture28);
                                    cross[89].setTextureRect(sf::IntRect(0,0,76,60));
                                    cross[89].setFillColor(sf::Color(255, 255, 255, 130));
                                    app.draw(cross[89]);
                                    app.draw(hits[2]);
                                    app.display();
                                    sf::sleep(sf::seconds(2));
                                    cross[89].setFillColor(sf::Color(255, 255, 255, 0));
                                    app.draw(cross[89]);
                                    app.draw(hits[2]);
                                    app.display();
                                }
                            }
                        }
                    break;

                default:
                    break;
                }
            }

            app.clear();

            app.draw(hits[3]);

            app.draw(hits[2]);

            for(int i=0;i<3;i++)
            {
                app.draw(hits[i]);
            }

            for(int k=0;k<101;k++)
            {
                app.draw(rectangle2[k]);
            }

            if(cnt==1 || cnt==2)
            {
                app.draw(rectangle2[101]);
                app.draw(rectangle2[102]);
            }

            app.draw(rectangle2[103]);

            app.display();
        }
    }
return -1;
}

#endif // BATTLEFIELD_HPP_INCLUDED
