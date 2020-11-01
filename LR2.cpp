// LR2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <conio.h>

//проверка доступности атрибутов и методов

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

int _tmain(int argc, _TCHAR* argv[])
{
	
	Point *p=new Point(1,2);
	p->reset(); //Вывод (10,10)
	p->move(10,10);  //обратиться к свойству мы не можем, но вызвать метод можем. Вывод (11,12)

	delete p;

	_getch();
	return 0;
}


