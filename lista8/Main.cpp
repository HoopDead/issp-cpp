#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>


//Const and init variables
const int HEIGHT = 1920;
const int WIDTH = 1080;
int playerScale = 1;
int playerLevel = 1;
int RADIUS = 10;
int x = 960;
int y = 540;
int randomX_dot_array[100], randomY_dot_array[100], randomX_enemy_array[8], randomY_enemy_array[8];

//
//Generate SFML objects
sf::CircleShape player(RADIUS); //Generate player object
sf::View followPlayer;
sf::RectangleShape background;
std::vector <sf::CircleShape> dots(100);
std::vector <sf::CircleShape> enemies(8);

//Get dot function
//Get x and y cooridantes, and random color - red, green blue,
//Return x and y coords for next dot, and color for it.
void getDot(int *x, int *y, int *randomR, int *randomG, int *randomB)
{
    *x = rand() % ((3400 + 30) - 30);
    *y = rand() % ((1800 + 250) - 250);
    *randomR = rand() % ((256 + 1) - 1);
    *randomG = rand() % ((256 + 1) - 1);
    *randomB = rand() % ((256 + 1) - 1);
}


//fillDots function
//Get - getDot function, and generate coords for dots to fill, when game starts
//Return - fullfiled vector with objects (dots), with color, and coords
void fillDots()
{
    for(int i = 0; i < dots.size(); i++)
    {
        int randomX_dot, randomY_dot, rr, rg, rb;
        getDot(&randomX_dot, &randomY_dot, &rr, &rg, &rb);
        randomX_dot_array[i] = randomX_dot;
        randomY_dot_array[i] = randomY_dot;
        sf::CircleShape dot(3);
        dots[i] = dot;
        dots[i].setFillColor(sf::Color(rr, rg, rb));
    }
}

void fillEnemies()
{
    for(int i = 0; i < enemies.size(); i++)
    {
        int randomX_enemy, randomY_enemy, rr, rg, rb;
        getDot(&randomX_enemy, &randomY_enemy, &rr, &rg, &rb);
        randomX_enemy_array[i] = randomX_enemy;
        randomY_enemy_array[i] = randomY_enemy;
        sf::CircleShape enemy(RADIUS + 15);
        enemies[i] = enemy;
        enemies[i].setFillColor(sf::Color(rr, rg, rb));
    }
}

//Get level function
//Get - playerLevel,
//Return - it counts every playerLevel mod 5, if 0 = player Scale gets bigger by 1, if playerScale greater than 15 - it stops, because player object is too big, and it's to easy to win.
void getLevel(int playerLevel)
{
    if(playerLevel % 5 == 0)
    {
        playerScale++;
        std::cout << playerScale << std::endl;
        std::cout << player.getRadius() << std::endl;
    }
    if(playerLevel % 75 == 0)
    {
        followPlayer.zoom(1.5);
    }
}

//checkCollisionEnemy
//Check if player collided with enemy
//TODO - check whos bigger, and pass score to bigger one.
void checkCollisionEnemy()
{
	// if (player.getGlobalBounds().intersects(enemy.getGlobalBounds())) //Check colision between player and enemy
    {
    }
}


//checkCollision dot
//Get - nothing
//Return - check collision with player and dot, then it gets getDot function to generate new dot on map, and getLevel function to check is player going to get bigger, then push new dot to vector, and change player Scale.
void checkCollisionDot()
{
    for(int i = 0; i < dots.size(); i++)
    {
        if(player.getGlobalBounds().intersects(dots[i].getGlobalBounds()))
        {
            int randomX_dot, randomY_dot, rr, rg, rb;
            getDot(&randomX_dot, &randomY_dot, &rr, &rg, &rb);
            getLevel(playerLevel);
            playerLevel++;
            randomX_dot_array[i] = randomX_dot;
            randomY_dot_array[i] = randomY_dot;
            dots[i].setFillColor(sf::Color(rr, rg, rb));
            dots[i].setPosition(randomX_dot_array[i], randomY_dot_array[i]);
            player.setScale(playerScale, playerScale);
        }
    }
}


//TODO EnemyMove
void enemyMove()
{
}

//PlayerMove function
//Clicking arrows changes player position,
//If player position is greater than map, it's going to stop him by collision.
//TODO - Change getRadius to getScale - radius is const, scale changes.
void checkPlayerMove()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        y = y-3;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
         y = y+3;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        x = x-3;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        x = x+3;
    }
    if(x + player.getRadius() >= 3599 - player.getRadius() * player.getRadius())
    {
        x = x-3;
    }
    if(x + player.getRadius() <= 0 + player.getRadius() * player.getRadius())
    {
        x = x+3;
    }
    if(y + player.getRadius() >= 2200 + player.getRadius() * player.getRadius())
    {
        y = y-3;
    }
    if(y + player.getRadius() <= -100 + player.getRadius() * player.getRadius())
    {
        y = y+3;
    }
}

int main()
{
    srand(time(NULL));
    fillDots();
    fillEnemies();
    sf::RenderWindow window(sf::VideoMode(HEIGHT, WIDTH), "Gra");
    followPlayer.setSize(1920, 1080);
    background.setSize(sf::Vector2f(4000, 2700));
    background.setFillColor(sf::Color(59, 10, 69));
    background.setPosition(0, 0);
    player.setFillColor(sf::Color::Green);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {   
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                window.close();
            }
        }
        checkPlayerMove();
        followPlayer.setCenter(x, y);
        window.clear();
        window.setView(followPlayer);
        window.draw(background);
        window.draw(player);
        player.setPosition(x, y);
        for(int i = 0; i < dots.size(); i++)
        {
            window.draw(dots[i]);
            dots[i].setPosition(randomX_dot_array[i], randomY_dot_array[i]);
            checkCollisionDot();
        }
        for(int i = 0; i < enemies.size(); i++)
        {
            window.draw(enemies[i]);
            enemies[i].setPosition(randomX_enemy_array[i], randomY_enemy_array[i]);
        }
        window.display();
    }
    return 0;
}