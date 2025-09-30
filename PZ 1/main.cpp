#include <iostream>
#include "structs.h"
#include "func.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");	

	Point p1;
	PointRead(p1);
	PointPrint(p1);

	Circle c1;
	CircleRead(c1);
	CirclePrint(c1);
	cout << "Длина окружности = " << CircleLength(c1) << endl;
	cout << "Площадь круга = " << CircleArea(c1) << endl;

	Square s1;
	SquareRead(s1);
	SquarePrint(s1);
	cout << "Периметр квадрата = " << SquareLength(s1) << endl;
	cout << "Площадь квадрата = " << SquareArea(s1) << endl;

    cout << "Точка внутри круга: " << (IsInsideCircle(p1, c1)) << endl;
    cout << "Точка на окружности: " << (IsOnCircle(p1, c1)) << endl;
    cout << "Точка внутри квадрата: " << (IsInsideSquare(p1, s1)) << endl;
    cout << "Точка на квадрате: " << (IsOnSquare(p1, s1)) << endl;
   
    cout << "Введите данные для второго круга:" << endl;
    Circle c2;
    CircleRead(c2);
    cout << "Круги пересекаются: " << (DoCirclesIntersect(c1, c2)) << endl;

    cout << "Введите данные для второго квадрата:" << endl;
    Square s2;
    SquareRead(s2);
    cout << "Квадраты пересекаются: " << (DoSquaresIntersect(s1, s2)) << endl;

    cout << "Круг и квадрат пересекаются: " << (DoCircleAndSquareIntersect(c1, s1)) << endl;

    cout << "Круг 1 внутри круга 2: " << (IsCircleInsideCircle(c1, c2)) << endl;
    cout << "Квадрат 1 внутри квадрата 2: " << (IsSquareInsideSquare(s1, s2)) << endl;
    cout << "Квадрат внутри круга: " << (IsSquareInsideCircle(s1, c1)) << endl;
    cout << "Круг внутри квадрата: " << (IsCircleInsideSquare(c1, s1)) << endl;
}