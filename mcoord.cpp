#pragma once

#include <iostream>
#include "mcoord.h"
#include "create_exception.h"

using namespace std;

MCoord::MCoord(double newX, double newY)
{
	try
	{
		pcoord = new double[2];
	}
	catch (bad_alloc)
	{
		CreateException exception(ERROR_ENUM::EXCEPT_MEMORY_ALOCATION_ERROR);
	}
	pcoord[0] = newX;
	pcoord[1] = newY;
}



MCoord::MCoord()
{	
	//pcoord = NULL;
	
	try
	{
		pcoord = new double[2];
	}
	catch (bad_alloc)
	{
		CreateException exception(ERROR_ENUM::EXCEPT_MEMORY_ALOCATION_ERROR);
	}
	pcoord[0] = 0;
	pcoord[1] = 0;
	
}


MCoord::~MCoord()
{
	if (pcoord) {
		delete[] pcoord;
	}
	pcoord = NULL;

}