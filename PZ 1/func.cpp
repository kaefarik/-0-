#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>
#include <cmath>
#include "func.h"

using namespace std;

//Точка
void PointRead(Point& P) 
{
    cout << "Введите координаты X, Y: ";
    cin >> P.X >> P.Y;
}

void PointPrint(const Point& P) 
{
    cout << "Координаты точки: (" << P.X << "; " << P.Y << ")" << endl;
}

//Окружность
void CircleRead(Circle& C) 
{
    cout << "Введите X, Y центра и радиус: ";
    cin >> C.Centre.X >> C.Centre.Y >> C.Radius;
}

void CirclePrint(const Circle& C) 
{
    cout << "Окружность с центром в точке (" << C.Centre.X << "; " << C.Centre.Y << ") и радиусом " << C.Radius << endl;
}

double CircleLength(const Circle& C)
{
    double Length = 2 * M_PI * C.Radius;
    return Length;
}

double CircleArea(const Circle& C)
{
    double Area = M_PI * C.Radius * C.Radius;
    return Area;
}

//Квадрат
void SquareRead(Square& S)
{
    cout << "Введите X, Y левого верхнего угла квадрата и длину стороны: ";
    cin >> S.UpperLeftCorner.X >> S.UpperLeftCorner.Y >> S.SideLength;
}

void SquarePrint(const Square& S)
{
    cout << "Квадрат с левым верхним углом в точке (" << S.UpperLeftCorner.X << "; " << S.UpperLeftCorner.Y << ") и стороной длины " << S.SideLength << endl;
}

double SquareLength(const Square& S)
{
    double Length = 4 * S.SideLength;
    return Length;
}

double SquareArea(const Square& S)
{
    double Area = S.SideLength * S.SideLength;
    return Area;
}

//Точность 10^-5
bool AreEqual(double a, double b, double epsilon)
{
    return fabs(a - b) < epsilon;
}

bool IsLessOrEqual(double a, double b, double epsilon)
{
    return a < b || AreEqual(a, b, epsilon);
}

bool IsGreaterOrEqual(double a, double b, double epsilon)
{
    return a > b || AreEqual(a, b, epsilon);
}

//Принадлежность точки фигуре
bool IsInsideCircle(const Point& P, const Circle& C)
{
    double a = (P.X - C.Centre.X) * (P.X - C.Centre.X) + (P.Y - C.Centre.Y) * (P.Y - C.Centre.Y);
    double b = C.Radius * C.Radius;
    return (a < b) && !AreEqual(a, b);
}

bool IsInsideSquare(const Point& P, const Square& S)
{
    double left = S.UpperLeftCorner.X;
    double right = S.UpperLeftCorner.X + S.SideLength;
    double top = S.UpperLeftCorner.Y;
    double bottom = S.UpperLeftCorner.Y - S.SideLength;
    return (P.X > left && !AreEqual(P.X, left)) && (P.X < right && !AreEqual(P.X, right)) && (P.Y < top && !AreEqual(P.Y, top)) && (P.Y > bottom && !AreEqual(P.Y, bottom));
}

//Нахождение точки на контуре
bool IsOnCircle(const Point& P, const Circle& C)
{
    double a = (P.X - C.Centre.X) * (P.X - C.Centre.X) + (P.Y - C.Centre.Y) * (P.Y - C.Centre.Y);
    double b = C.Radius * C.Radius;
    return AreEqual(a , b);
}

bool IsOnSquare(const Point& P, const Square& S)
{
    double left = S.UpperLeftCorner.X;
    double right = S.UpperLeftCorner.X + S.SideLength;
    double top = S.UpperLeftCorner.Y;
    double bottom = S.UpperLeftCorner.Y - S.SideLength;
    
    bool OnLeft = AreEqual(P.X, left) && IsLessOrEqual(P.Y, top) && IsGreaterOrEqual(P.Y, bottom);
    bool OnRight = AreEqual(P.X, right) && IsLessOrEqual(P.Y, top) && IsGreaterOrEqual(P.Y, bottom);
    bool OnTop = AreEqual(P.Y, top) && IsGreaterOrEqual(P.X, left) && IsLessOrEqual(P.X, right);
    bool OnBottom = AreEqual(P.Y, bottom) && IsGreaterOrEqual(P.X, left) && IsLessOrEqual(P.X, right);

    return OnLeft || OnRight || OnTop || OnBottom;
}

// Пересечение фигур
bool DoCirclesIntersect(const Circle& C1, const Circle& C2)
{
    double CentreDistance = sqrt((C1.Centre.X - C2.Centre.X) * (C1.Centre.X - C2.Centre.X) + (C1.Centre.Y - C2.Centre.Y) * (C1.Centre.Y - C2.Centre.Y));
    return IsLessOrEqual(CentreDistance, C1.Radius + C2.Radius) && IsGreaterOrEqual(CentreDistance, fabs(C1.Radius - C2.Radius));
}

bool DoSquaresIntersect(const Square& S1, const Square& S2)
{
    double left1 = S1.UpperLeftCorner.X;
    double right1 = S1.UpperLeftCorner.X + S1.SideLength;
    double top1 = S1.UpperLeftCorner.Y;
    double bottom1 = S1.UpperLeftCorner.Y - S1.SideLength;

    double left2 = S2.UpperLeftCorner.X;
    double right2 = S2.UpperLeftCorner.X + S2.SideLength;
    double top2 = S2.UpperLeftCorner.Y;
    double bottom2 = S2.UpperLeftCorner.Y - S2.SideLength;

    return !(right1 < left2 || left1 > right2 ||
        bottom1 > top2 || top1 < bottom2);
}

bool DoCircleAndSquareIntersect(const Circle& C, const Square& S)
{
    double left = S.UpperLeftCorner.X;
    double right = S.UpperLeftCorner.X + S.SideLength;
    double top = S.UpperLeftCorner.Y;
    double bottom = S.UpperLeftCorner.Y - S.SideLength;

    double closestX = max(left, min(C.Centre.X, right));
    double closestY = min(top, max(C.Centre.Y, bottom));

    double dx = C.Centre.X - closestX;
    double dy = C.Centre.Y - closestY;
    double distanceSquared = dx * dx + dy * dy;

    return IsLessOrEqual(distanceSquared, C.Radius * C.Radius);
}

// Принадлежность фигуры
bool IsCircleInsideCircle(const Circle& C1, const Circle& C2)
{
    double dx = C1.Centre.X - C2.Centre.X;
    double dy = C1.Centre.Y - C2.Centre.Y;
    double distance = sqrt(dx * dx + dy * dy);

    return IsLessOrEqual(distance + C1.Radius, C2.Radius);
}

bool IsSquareInsideSquare(const Square& S1, const Square& S2)
{
    double left1 = S1.UpperLeftCorner.X;
    double right1 = S1.UpperLeftCorner.X + S1.SideLength;
    double top1 = S1.UpperLeftCorner.Y;
    double bottom1 = S1.UpperLeftCorner.Y - S1.SideLength;

    double left2 = S2.UpperLeftCorner.X;
    double right2 = S2.UpperLeftCorner.X + S2.SideLength;
    double top2 = S2.UpperLeftCorner.Y;
    double bottom2 = S2.UpperLeftCorner.Y - S2.SideLength;

    return (left1 >= left2 && right1 <= right2 &&
        top1 <= top2 && bottom1 >= bottom2);
}

bool IsSquareInsideCircle(const Square& S, const Circle& C)
{
    Point corners[4] = {
        {S.UpperLeftCorner.X, S.UpperLeftCorner.Y},
        {S.UpperLeftCorner.X + S.SideLength, S.UpperLeftCorner.Y}, 
        {S.UpperLeftCorner.X, S.UpperLeftCorner.Y - S.SideLength}, 
        {S.UpperLeftCorner.X + S.SideLength, S.UpperLeftCorner.Y - S.SideLength} 
    };

    for (int i = 0; i < 4; i++) {
        double dx = corners[i].X - C.Centre.X;
        double dy = corners[i].Y - C.Centre.Y;
        double distanceSquared = dx * dx + dy * dy;
        double radiusSquared = C.Radius * C.Radius;

        if (distanceSquared >= radiusSquared ||
            AreEqual(distanceSquared, radiusSquared)) {
            return false;
        }
    }
    return true;
}


bool IsCircleInsideSquare(const Circle& C, const Square& S)
{
    double left = S.UpperLeftCorner.X;
    double right = S.UpperLeftCorner.X + S.SideLength;
    double top = S.UpperLeftCorner.Y;
    double bottom = S.UpperLeftCorner.Y - S.SideLength;
    
    return (C.Centre.X - C.Radius > left || AreEqual(C.Centre.X - C.Radius, left)) &&
        (C.Centre.X + C.Radius < right || AreEqual(C.Centre.X + C.Radius, right)) &&
        (C.Centre.Y + C.Radius < top || AreEqual(C.Centre.Y + C.Radius, top)) &&
        (C.Centre.Y - C.Radius > bottom || AreEqual(C.Centre.Y - C.Radius, bottom));
}