#include <iostream>
#include <string>
#include <cstdlib>

struct Vector2f
{
    float x, y;
};

Vector2f operator+(Vector2f left, Vector2f right)
{
    Vector2f result = {left.x + right.x, left.y + right.y};
    return result;
}
Vector2f operator*(Vector2f left, float right)
{
    Vector2f result = {left.x * right, left.y * right};
    return result;
}
Vector2f operator*(float left, Vector2f right)
{
    Vector2f result = {left * right.x, left * right.y};
    return result;
}

class Monster
{
protected:
    Vector2f position;
    Vector2f velocity;

    int max_health, health;
    bool is_alive;
public:
    Monster(Vector2f position, int max_health) :
            position(position), max_health(max_health), is_alive(true)
    {
        health = max_health;
    }

    void hurt(int damage)
    {
        health -= damage;
        if (health <= 0)
            is_alive = false;
    }

    void heal(int heal_power)
    {
        if (is_alive)
            health += heal_power;
        if (health > max_health)
            health = max_health;
    }

    void resurrect()
    {
        if (is_alive == false)
        {
        health = max_health;
        is_alive = true;
        }
    }

};

class Skeleton : public Monster
{
public:

    Skeleton(Vector2f position = {0,0}, int max_health = 100) : Monster(position, max_health)
                
    {
        health = max_health;
        // Скелет может двигаться только по горизонтали:
        if (rand() % 2)
            velocity = {5, 0};
        else
            velocity = {-5, 0};
    }

    void say()
    {
        std::cout << "<Bones are creaking>" << std::endl;
    }

    void move(float dt)
    {
        position = position + velocity * dt;
    }

    void print_info()
    {
        std::cout << "Skeleton: position = {" << position.x << ", " << position.y << "}, "
                     "velocity = {" << velocity.x << ", " << velocity.y << "}, " 
                     "health = " << health << ", max_health = " << max_health << std::endl;
    }
};


class Ghost : public Monster
{
private:
    bool is_regeneratable;

public:

    Ghost(Vector2f position = {0,0}, int max_health = 100) : Monster(position, max_health)
    {
        health = max_health;
        // Призрак движется в произвольном направлении
        velocity = {(float)(rand() % 10 - 5), (float)(rand() % 10 - 5)};
    }

    void say()
    {
        std::cout << "oooOOOoooOOOoooOOOooo" << std::endl;
    }

    void move(float dt)
    {
        if (is_regeneratable)
            heal(1);
        position = position + velocity * dt;
    }

    void print_info()
    {
        std::cout << "Ghost: position = {" << position.x << ", " << position.y << "}, "
                     "velocity = {" << velocity.x << ", " << velocity.y << "}, " 
                     "health = " << health << ", max_health = " << max_health << std::endl;
    }
};


class Frog : public Monster
{
private:
    int talkativeness;

public:

    Frog(Vector2f position = {0,0}, int max_health = 100, int talkativeness = 3) :
                Monster(position, max_health), talkativeness(talkativeness)
    {
        health = max_health;
        // Лягушка прыгает вверх
        velocity = {(float)(rand() % 10 - 5), (float)(rand() % 10)};
    }

    void say()
    {
        for (int i = 0; i < talkativeness; i++)
            std::cout << "Kwaak ";
        std::cout << std::endl;
    }

    void move(float dt)
    {
        // Чтобы лягушка прыгала, нужна гравитация
        velocity.y -= 9.8 * dt;
        if (position.y <= 0)
            velocity.y = 0;
        position = position + velocity * dt;
    }

    void print_info()
    {
        std::cout << "Frog: position = {" << position.x << ", " << position.y << "}, "
                     "velocity = {" << velocity.x << ", " << velocity.y << "}, " 
                     "health = " << health << ", max_health = " << max_health << std::endl;
    }
};

class SkeletonPirate : public Skeleton
{
public:
    SkeletonPirate() : Skeleton(position, max_health)
    {
    }

    void say()
    {
        std::cout << "Aaarrrgghh!" << std::endl;
    }
    
};

int main()
{
    Skeleton a;
    a.say();
    
    Ghost b;
    b.say();

    Frog c{{0,0}, 50, 10};
    c.say();


    a.print_info();
    a.hurt(80);
    a.print_info();
    c.print_info();
    c.move (10);
    c.print_info();

    SkeletonPirate d;
    d.say();


    // Задание 1: 
    // Создайте класс-родитель Monster, такой, чтобы классы Skeleton, Ghost и Frog от него наследовались.
    // Сами определите те методы и поля, которые должны описываться в классе Monster 
    //        и которые должны описываться в классах потомках


    // Задание 2: 
    // Напишите функцию resurrect, которая будет "воскрешать" монстра

    // Задание 3:
    // Создайте класс SkeletonPirate - скелета-пирата. Этот монстр должен вести себя также как и скелет,
    // но при вызове функции say, он должен говорить  "Aaarrrgghh!"
    // Протестируте класс SkeletonPirate в main
}