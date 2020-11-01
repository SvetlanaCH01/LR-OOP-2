// LR2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <conio.h>

//создание динамических объектов, создание объектов с помощью различных конструкторов
//удаление динамических объектов


class Point{
public:
	int x, y; //атрибуты
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
};



int _tmain(int argc, _TCHAR* argv[])
{
	Point *p=new Point;
	Point *p2= new Point(10, 20);
	Point *p3=new Point(*p2);
	
	delete p;
	delete p2;
	delete p3;

	_getch();
	return 0;
}


