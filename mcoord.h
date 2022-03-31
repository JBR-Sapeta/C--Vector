#pragma once


#include <iostream>

using namespace std;

class MCoord
{
protected:

	double* pcoord;

public:
	MCoord(double newX, double newY);
	MCoord();
	~MCoord();
};