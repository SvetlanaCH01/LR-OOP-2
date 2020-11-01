// LR2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <conio.h>

//композиция объектов

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

class Section{ //класс не наследуется от другого класса
protected:
	Point *p1; //два указателя на первую и вторую точки отрезка
	Point *p2;
public:
	Section(){ //конструктор
		printf("Section()\n");
		p1 = new Point; //создание двух точек с нулевыми координатами по умолчанию
		p2 = new Point;
	}
	Section(int x1, int y1, int x2, int y2){ //конструктор с параметрами
		printf("Section(int x1, int y1, int x2, int y2)\n");
		p1 = new Point(x1, y1); 
		p2 = new Point(x2, y2);
	}
	Section(const Section &s){ //копирующий конструктор 
		printf("Section(const Section &p)\n");
		p1 = new Point(*(s.p1)); //глубокое копирование
		p2 = new Point(*(s.p2));
	}
	~Section(){ //деструктор
		//printf("%d, %d\n", x, y);
		delete p1; //удаление двух точек
		delete p2;

		printf("~Section()\n");
	}
};


int _tmain(int argc, _TCHAR* argv[])
{
	
	Section *s1 = new Section;
	Section *s2 = new Section(*s1);
	
	delete s1;
	delete s2;

	_getch();
	return 0;
}


