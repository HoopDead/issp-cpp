#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>


//Const and init variables
const int HEIGHT = 1920;
const int WIDTH = 1080;
int playerLevel = 10;
const int N = 125;
int randomX_dot_array[N], randomY_dot_array[N], randomX_enemy_array[25], randomY_enemy_array[25];
int playerPosition[2] = {960, 540};
int playerVelocity = 3;
std::vector <int> enemyGoingX(25);
std::vector <int> enemyGoingY(25);
std::vector <int> enemiesVelocity(25);
std::vector <int> enemyLevel(25);

//Generate SFML objects
sf::CircleShape player(playerLevel); //Generate player object
sf::View followPlayer;
sf::RectangleShape background;
std::vector <sf::CircleShape> dots(125);
std::vector <sf::CircleShape> enemies(25);

//Get dot function
//Get x and y cooridantes, and random color - red, green blue,
//Return x and y coords for next dot, and color for it.
void getDot(int *x, int *y, int *randomR, int *randomG, int *randomB)
{
    *x = rand() % ((4000+playerLevel+10 + 30) - 30);
    *y = rand() % ((2600+playerLevel+10 + 250) - 250);
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
        sf::CircleShape dot(5);
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
        sf::CircleShape enemy(playerLevel);
        enemies[i] = enemy;
        enemies[i].setFillColor(sf::Color(rr, rg, rb));
        enemiesVelocity[i] = 3;
        enemyLevel[i] = 10;
    }
}


//Test function, used in teleport random - actually left for TODO
int getRandomValue(int size)
{
    return rand() % size + 1;
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


//Function get index of enemy object in enemyLevel and increase radius of it by 1.
void getEnemyLevel(int i)
{
    enemyLevel[i]++;
    enemies[i].setRadius(enemyLevel[i]);
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
            getEnemyLevel(index);
        }
    }
}


//enemyMove function is looping every enemy object, and then if enemy is smaller than player, it's going to get some level and get bigger, else it will follow player till collision, and win.
void enemyMove()
{
    for(int i = 0; i < enemies.size(); i++)
    {
        if((enemies[i].getRadius() <= player.getRadius()) || (playerVelocity == 0))
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
            if (randomX_enemy_array[i] > playerPosition[0])
            {
                randomX_enemy_array[i] -= enemiesVelocity[i];
            }   
            if (randomX_enemy_array[i] < playerPosition[0])
            {
                randomX_enemy_array[i] += enemiesVelocity[i];
            }
            if (randomY_enemy_array[i] > playerPosition[1])
            {
                randomY_enemy_array[i] -= enemiesVelocity[i];
            }
            if (randomY_enemy_array[i] < playerPosition[1])
            {
                randomY_enemy_array[i] += enemiesVelocity[i];
            }
        }
    }
}

//Get level function
//Get - playerLevel,
//Return - increase player radius by 1.
void getLevel(int playerLevel)
{
    player.setRadius(playerLevel);
}


//Iteration map function
//Get - no args
//Return - bigger map by 10 units
void mapIteration()
{
    background.setSize(sf::Vector2f(4000+playerLevel+10, 2700+playerLevel+10));
    background.setFillColor(sf::Color(59, 10, 69));
    background.setPosition(0, 0);
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
            mapIteration();
            followPlayer.zoom(1.003f);
        }
    }
}


//checkCollisionPlayerEnemy function, it get's two arguments - enemy object, and index - indicated enemy object in vector, then check whois bigger, and
//return - who's bigger - the bigger object is going to eat enemy.
void checkCollisionPlayerEnemy(sf::CircleShape enemy, int index)
{
    if(player.getGlobalBounds().intersects(enemy.getGlobalBounds()))
    {
        sf::Vector2f enemyScale = enemy.getScale();
        sf::Vector2f playerScale = player.getScale();
        if(enemy.getRadius()> player.getRadius())
        {
            player.setRadius(0);
            playerVelocity = 0;
        }
        else
        {
            playerLevel += enemies[index].getRadius()/2;
            player.setRadius(playerLevel);
            enemies[index].setRadius(0);
            enemiesVelocity[index] = 0;
        }
    }
}

//TODO Function - Speciall spell, to teleport player on random coordinates.
bool TimeListener(sf::Clock clock)
{
    sf::Time elapsed1 = clock.getElapsedTime();
    std::cout << elapsed1.asSeconds() << std::endl;
    return false;
}

//PlayerMove function
//Clicking arrows changes player position,
//If player position is greater than map, it's going to stop him by collision.
//Get - clock object, TODO spell to teleport
//Return - player collision with border, or player move.
void checkPlayerMove(sf::Clock clock)
{
    sf::Vector2f borderSize = background.getSize();
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        playerPosition[1] -= playerVelocity;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
         playerPosition[1] += playerVelocity;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        playerPosition[0] -= playerVelocity;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        playerPosition[0] += playerVelocity;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        if(TimeListener(clock))
        {
            playerPosition[0] = getRandomValue(borderSize.x) + 1;
            playerPosition[1] = getRandomValue(borderSize.y) + 1;
        }
    }
    if(playerPosition[0] + player.getRadius() >= borderSize.x)
    {
        playerPosition[0] -= playerVelocity;
    }
    if(playerPosition[0] + player.getRadius() <= 0)
    {
        playerPosition[0] += playerVelocity;
    }
    if(playerPosition[1] + player.getRadius() >= borderSize.y)
    {
        playerPosition[1] -= playerVelocity;
    }
    if(playerPosition[1] + player.getRadius() <= 0)
    {
        playerPosition[1] += playerVelocity;
    }
}

int main()
{
    srand(time(NULL));
    fillDots();
    fillEnemies();
    enemyScan();
    sf::Clock clock;
    sf::RenderWindow window(sf::VideoMode(HEIGHT, WIDTH), "Gra");
    followPlayer.setSize(1920.f, 1080.f);
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
        checkPlayerMove(clock);
        followPlayer.setCenter(playerPosition[0]+player.getRadius(), playerPosition[1]+player.getRadius());
        window.clear();
        window.setView(followPlayer);
        window.draw(background);
        window.draw(player);
        player.setPosition(playerPosition[0], playerPosition[1]);
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
        if(TimeListener(clock))
        {
            clock.restart();
        }
        window.display();
    }
    return 0;
}