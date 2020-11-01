// LR2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <conio.h>

//определение классов-объектов, класс-потомок, проверка вызова деструкторов, конструкторов

class Point{
protected:
	int x, y; //атрибуты
public:
	Point(){ //конструктор
		printf("Point()\n");
		x = 0;
		y = 0;
	}
	Point(int x, int y){ //конструктор с параметрами
		printf("Point(int x, int y)\n");
		this->x = x;
		this->y = y;
	}
	Point(const Point &p){ //копирующий конструктор
		printf("Point(const Point &p)\n");
		x = p.x;
		y = p.y;
	}
	~Point(){ //деструктор
		printf("%d, %d\n", x, y);
		printf("~Point()\n");
	}
	void move(int dx, int dy){ // метод c параметрами и реализацией
		x = x + dx;
		y = y + dy; 
	}

	void reset(); //метод без параметров и реализации
};

void Point::reset(){ //реализация метода после объявления класса
	x = 0;
	y = 0;
}

class ColoredPoint: public Point{ //класс - потомок
protected:
	int color; //добавляет свойство color
public:
	ColoredPoint() : Point() { //в конструкторе вызывается метод базового класса
		printf("ColoredPoint()\n");
		color = 0;
	}
	ColoredPoint(int x, int y, int color) : Point(x,y){ //в конструкторе с параметрами также вызван конструктор Point с параметрами
		printf("ColoredPoint(int x, int y)\n");
		this->color= color;
	}
	ColoredPoint(const ColoredPoint &p){ //копирующий конструктор 
		printf("ColoredPoint(const Point &p)\n");
		color = p.color; //копируем вручную
		x = p.x;
		y = p.y;
	}
	~ColoredPoint(){ //деструктор
		printf("%d, %d, %d\n", x, y, color);
		printf("~ColoredPoint()\n");
	}
	void change_color(int new_color){ // метод
		color = new_color;
	}
};


int _tmain(int argc, _TCHAR* argv[])
{
	
	ColoredPoint *p=new ColoredPoint(1,2, 42);

	delete p;

	_getch();
	return 0;
}


