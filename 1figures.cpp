#include <iostream>
#include <cmath>
#define M_PI 3.14159265

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

Vector2f& operator+=(Vector2f& left, Vector2f right)
{
    left.x += right.x;
    left.y += right.y;
    return left;
}

class Figure
{
protected:
	Vector2f position;
	float angle;
public:
	Figure(Vector2f position, float angle) : position({0, 0}), angle(0)
	{
	}

	Vector2f get_position()
	{
		return position;
	}

	void set_position(const Vector2f& new_position)
	{
		position = new_position;
	}

	void move(Vector2f change)
	{
		position += change;
	}

	float get_angle()
	{
		return angle;
	}

	void set_angle(float new_angle)
	{
		angle = new_angle;
	}


};

class Circle : public Figure
{
private:
	float radius;

public:


	Circle(float radius) : radius(radius), Figure(position, angle)
	{
	}


	float calculate_perimeter()
	{
		return 2 * M_PI * radius;
	}

	float calculate_area()
	{
		return M_PI * radius * radius;
	}
};



class Triangle : public Figure
{
private:


	Vector2f point_a;
	Vector2f point_b;
	Vector2f point_c;

	float get_distance(Vector2f a, Vector2f b)
	{
		return sqrtf((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
	}

public:

	Triangle(Vector2f point_a, Vector2f point_b, Vector2f point_c) : 
			 point_a(point_a), point_b(point_b), point_c(point_c), Figure(position, angle)
	{
	}

	float calculate_perimeter()
	{
		return get_distance(point_a, point_b) + get_distance(point_b, point_c) + get_distance(point_c, point_a);
	}

	float calculate_area()
	{
		float a = get_distance(point_a, point_b);
		float b = get_distance(point_b, point_c);
		float c = get_distance(point_c, point_a);

		float p = (a + b + c) / 2;
		return sqrtf(p * (p - a) * (p - b) * (p - c));
	}
};

class Rectangle : public Figure
{
private:
	Vector2f position;
	float angle;

	float a;
	float b;

public:

	Rectangle(float a, float b) : 
			 a(a), b(b), Figure(position, angle)
	{
	}


	float calculate_perimeter()
	{
		return 2 * (a + b);
	}

	float calculate_area()
	{
		return a * b;
	}
};

int main()
{
	Circle a(7);
	std::cout << a.calculate_perimeter() << " " << a.calculate_area() << std::endl;

	Triangle b({5, 2}, {-7, 5}, {4, 4});
	std::cout << b.calculate_perimeter() << " " << b.calculate_area() << std::endl;


	// Задание 1: Создайте свой класс Rectangle
	 Rectangle c(12, 8);
	 std::cout << c.calculate_perimeter() << " " << c.calculate_area() << std::endl;


	// Задание 2: Создайте свой основной класс Figure и проведите наследование от него к класам Circle, Triangle и Rectangle


	// Задание 3: Добавьте метод void move(Vector2f change) в класс Figure. Этот метод должен изменять поле position
	// Так как остальные классы наследуются от Figure, то этот метод можно будет вызвать
	
	a.set_position({100, 200});
	a.move({200, -100});
	std::cout << a.get_position().x << " " << a.get_position().y << std::endl;
	
}