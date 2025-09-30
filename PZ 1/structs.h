#pragma once

struct Point 
{
	double X;
	double Y;
};

struct Circle
{
	double Radius;
	Point Centre;
};

struct Square
{
	double SideLength;
	Point UpperLeftCorner;
};