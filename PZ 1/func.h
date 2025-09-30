#pragma once
#include "structs.h"

//�����
void PointRead(Point& P);
void PointPrint(const Point& P);

//����������
void CircleRead(Circle& C);
void CirclePrint(const Circle& C);
double CircleLength(const Circle& C);
double CircleArea(const Circle& C);

//�������
void SquareRead(Square& S);
void SquarePrint(const Square& S);
double SquareLength(const Square& S);
double SquareArea(const Square& S);

//�������� 10^-5
bool AreEqual(double a, double b, double epsilon = 1e-5);
bool IsLessOrEqual(double a, double b, double epsilon = 1e-5);
bool IsGreaterOrEqual(double a, double b, double epsilon = 1e-5);

//�������������� ����� ������
bool IsInsideCircle(const Point& P, const Circle& C);
bool IsInsideSquare(const Point& P, const Square& S);

// ���������� ����� �� �������
bool IsOnCircle(const Point& P, const Circle& C);
bool IsOnSquare(const Point& P, const Square& S);

// ����������� ����� 
bool DoCirclesIntersect(const Circle& C1, const Circle& C2);
bool DoSquaresIntersect(const Square& S1, const Square& S2);
bool DoCircleAndSquareIntersect(const Circle& C, const Square& S);

// �������������� ������
bool IsCircleInsideCircle(const Circle& C1, const Circle& C2);
bool IsSquareInsideSquare(const Square& S1, const Square& S2);
bool IsSquareInsideCircle(const Square& S, const Circle& C);
bool IsCircleInsideSquare(const Circle& C, const Square& S);