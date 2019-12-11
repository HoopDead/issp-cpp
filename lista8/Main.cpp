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
int playerX = 960;
int playerY = 540;
int RADIUS = 10;
int randomX_dot_array[100], randomY_dot_array[100], randomX_enemy_array[10], randomY_enemy_array[10];
std::vector <int> enemyGoingX(10);
std::vector <int> enemyGoingY(10);
std::vector <int> enemiesVelocity(10);
std::vector <int> enemyScale(10);
std::vector <int> enemyLevel(10);

//Generate SFML objects
sf::CircleShape player(RADIUS); //Generate player object
sf::View followPlayer;
sf::RectangleShape background;
std::vector <sf::CircleShape> dots(100);
std::vector <sf::CircleShape> enemies(10);

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


//Function get no argument, and returns enemy object, with random color, and random position on player. Enemy is always smaller 1 unit than player.
void fillEnemies()
{
    for(int i = 0; i < enemies.size(); i++)
    {
        int randomX_enemy, randomY_enemy, rr, rg, rb;
        getDot(&randomX_enemy, &randomY_enemy, &rr, &rg, &rb);
        randomX_enemy_array[i] = randomX_enemy;
        randomY_enemy_array[i] = randomY_enemy;
        sf::CircleShape enemy(15);
        enemies[i] = enemy;
        enemies[i].setFillColor(sf::Color(rr, rg, rb));
        enemiesVelocity[i] = 2;
    }
}



//Function loop every enemey object, and returns random dots to follow by enemy. The function is called only once - at begging of main function,
//because points to follow don't have to change - collision with dot leads to change position.
void enemyScan()
{
    for(int i = 0; i < enemyGoingX.size(); i++)
    {
        int randomIndex = rand() % ((dots.size() + 0) - 1);
        std::cout << "Kropka: " << std::endl;
        std::cout << "X: " << randomX_dot_array[randomIndex] << " Y: " << randomY_dot_array[randomIndex] << std::endl;
        std::cout << "Przeciwnik: " << std::endl;
        std::cout << "X: " <<  randomX_enemy_array[i] << " Y: " << randomY_enemy_array[i] << std::endl;
    }
}


//Function is called every time, that any object collide with dot.
//It returns new dot position, and new color of dot.
void changeDotPosition(int i)
{
    int randomX_dot, randomY_dot, rr, rg, rb;
    getDot(&randomX_dot, &randomY_dot, &rr, &rg, &rb);
    randomX_dot_array[i] = randomX_dot;
    randomY_dot_array[i] = randomY_dot;
    dots[i].setFillColor(sf::Color(rr, rg, rb));
    dots[i].setPosition(randomX_dot_array[i], randomY_dot_array[i]);
}


//Function get index of enemy object in enemyLevel and enemyScale vector, if indicated element is % 5 it gets bigger by 1 scale unit.
void getEnemyLevel(int i)
{
    if(enemyLevel[i] % 5 == 0)
    {
        enemyScale[i]++;
        enemies[i].setScale(enemyScale[i], enemyScale[i]);
    }
}

//checkCollisionEnemyDot
//Function get argument - circleShape enemy, and check if player collided with ANY dot on map, if statement is true, changeDotPosition function is called,
//and enemy is going to follow new coordinates.
void checkCollisionEnemyDot(sf::CircleShape enemy, int index)
{
    for(int i = 0; i < dots.size(); i++)
    {
        if(enemy.getGlobalBounds().intersects(dots[i].getGlobalBounds()))
        {
            changeDotPosition(i);
            enemyLevel[index]++;
            getEnemyLevel(index);
        }
    }
}


//enemyMove function is looping every enemy object, and then if enemy is smaller than player, it's going to get some level and get bigger, else it will follow player till collision, and win.
void enemyMove()
{
    for(int i = 0; i < enemies.size(); i++)
    {
        sf::Vector2f enemyScale = enemies[i].getScale();
        sf::Vector2f playerScale = player.getScale();
        if(enemies[i].getRadius() * enemyScale.x < player.getRadius() * playerScale.x)
        {
            if (randomX_enemy_array[i] > randomX_dot_array[i])
            {
                randomX_enemy_array[i] -= enemiesVelocity[i];
            }
            if (randomX_enemy_array[i] < randomX_dot_array[i])
            {
                randomX_enemy_array[i] += enemiesVelocity[i];
            }
            if (randomY_enemy_array[i] > randomY_dot_array[i])
            {
                randomY_enemy_array[i] -= enemiesVelocity[i];
            }
            if (randomY_enemy_array[i] < randomY_dot_array[i])
            {
                randomY_enemy_array[i] += enemiesVelocity[i];
            }
        }
        else
        {
            if (randomX_enemy_array[i] > playerX)
            {
                randomX_enemy_array[i] -= enemiesVelocity[i];
            }
            if (randomX_enemy_array[i] < playerX)
            {
                randomX_enemy_array[i] += enemiesVelocity[i];
            }
            if (randomY_enemy_array[i] > playerY)
            {
                randomY_enemy_array[i] -= enemiesVelocity[i];
            }
            if (randomY_enemy_array[i] < playerY)
            {
                randomY_enemy_array[i] += enemiesVelocity[i];
            }
        }
    }
}

//Get level function
//Get - playerLevel,
//Return - it counts every playerLevel mod 5, if 0 = player Scale gets bigger by 1, if playerScale greater than 15 - it stops, because player object is too big, and it's to easy to win.
void getLevel(int playerLevel)
{
    if(playerLevel % 7 == 0)
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



//checkCollision dot
//Get - nothing
//Return - check collision with player and dot, then it gets getDot function to generate new dot on map, and getLevel function to check is player going to get bigger, then push new dot to vector, and change player Scale.
void checkCollisionDot()
{
    for(int i = 0; i < dots.size(); i++)
    {
        if(player.getGlobalBounds().intersects(dots[i].getGlobalBounds()))
        {
            getLevel(playerLevel);
            playerLevel++;
            changeDotPosition(i);
            player.setScale(playerScale, playerScale);
        }
    }
}


//checkCollisionPlayerEnemy function, it get's two arguments - enemy object, and index - indicated enemy object in vector, then check whois bigger, and
//return print with information
//TODO - get level from smaller one, to bigger one
void checkCollisionPlayerEnemy(sf::CircleShape enemy, int index)
{
    if(player.getGlobalBounds().intersects(enemy.getGlobalBounds()))
    {
        sf::Vector2f enemyScale = enemy.getScale();
        sf::Vector2f playerScale = player.getScale();
        if(enemy.getRadius() * enemyScale.x > player.getRadius() * playerScale.x)
        {
            std::cout << "COLLSION: Enemy Bigger! \n";
        }
        else
        {
            std::cout << "COLLISION: Player Bigger! \n";
        }
    }
}


//PlayerMove function
//Clicking arrows changes player position,
//If player position is greater than map, it's going to stop him by collision.
//TODO - Change getRadius to getScale - radius is const, scale changes.
void checkPlayerMove()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        playerY = playerY-3;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
         playerY = playerY+3;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        playerX = playerX-3;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        playerX = playerX+3;
    }
    if(playerX + player.getRadius() >= 3599 - player.getRadius() * player.getRadius())
    {
        playerX = playerX-3;
    }
    if(playerX + player.getRadius() <= 0 + player.getRadius() * player.getRadius())
    {
        playerX = playerX+3;
    }
    if(playerY + player.getRadius() >= 2200 + player.getRadius() * player.getRadius())
    {
        playerY = playerY-3;
    }
    if(playerY + player.getRadius() <= -100 + player.getRadius() * player.getRadius())
    {
        playerY = playerY+3;
    }
}

int main()
{
    srand(time(NULL));
    fillDots();
    fillEnemies();
    enemyScan();
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
        enemyMove();
        checkPlayerMove();
        followPlayer.setCenter(playerX, playerY);
        window.clear();
        window.setView(followPlayer);
        window.draw(background);
        window.draw(player);
        player.setPosition(playerX, playerY);
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
            checkCollisionEnemyDot(enemies[i], i);
            checkCollisionPlayerEnemy(enemies[i], i);
        }
        window.display();
    }
    return 0;
}