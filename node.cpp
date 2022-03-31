#pragma once

#include <iostream>
#include <fstream>
#include "node.h"
#include "mcoord.h"
#include "create_exception.h"


using namespace std;


Node::Node( ):MCoord()
{
	numb = -777;
	strcpy_s(str, "DEFAULT");

}


Node::Node(int nb, char* st, double xx, double yy) :MCoord(xx, yy)
{
	numb = nb;
	if (strlen(st) > 511) {
		CreateException exception(ERROR_ENUM::EXCEPT_TO_LONG_NODE_NAME_WARNING);
	}
	strcpy_s(str, st);

}

Node::Node(const Node& object)
{
	numb = object.numb;
	strcpy_s(str, object.str);
	if(object.pcoord) {
		try
		{
			pcoord = new double[2];
		}
		catch (bad_alloc)
		{
			CreateException exception(ERROR_ENUM::EXCEPT_MEMORY_ALOCATION_ERROR);
		}
		pcoord[0] = object.pcoord[0];
		pcoord[1] = object.pcoord[1];
	}
	else
	{
	pcoord = NULL;
	}
}

Node& Node::operator = (const Node& object)
{
	numb = object.numb;
	strcpy_s(str, object.str);
	if (object.pcoord) {
		try
		{
			pcoord = new double[2];
		}
		catch (bad_alloc)
		{
			CreateException exception(ERROR_ENUM::EXCEPT_MEMORY_ALOCATION_ERROR);
		}
		pcoord[0] = object.pcoord[0];
		pcoord[1] = object.pcoord[1];
	}
	else
	{
		pcoord = NULL;
	}


	return *this;
}

bool Node::operator == (const Node& object)
{
	return ((pcoord[0] == object.pcoord[0]) && (pcoord[1] == object.pcoord[1]) && (numb == object.numb));
}

bool Node::operator == (const int number)
{
	return (numb == number);
}

ostream& operator << (ostream& out, const Node& object)
{
	out << object.str << "\t " << object.numb << "\t " << object.pcoord[0] << "\t" << object.pcoord[1];
	return out;
}



istream& operator >> (istream& in, Node& object)
{
	cout << "Nazwa wiercholka: ";
	in >> object.str;
	cout << "Numer:";
	in >> object.numb;
	cout << "Wartosc x:";
	in >> object.pcoord[0];
	cout << "Wartosc y:";
	in >> object.pcoord[1];
	return in;
}

fstream& operator >> (fstream& strm, const Node* object)
{
	strm.read((char*)&object->str, sizeof(object->str));
	strm.read((char*)&object->numb, sizeof(int));
	strm.read((char*)&object->pcoord[0], sizeof(double));
	strm.read((char*)&object->pcoord[1], sizeof(double));
	return strm;
}

fstream& operator << (fstream& strm, const Node* object)
{
	strm.write((char*)&object->str, sizeof(object->str));
	strm.write((char*)&object->numb, sizeof(int));
	strm.write((char*)&object->pcoord[0], sizeof(double));
	strm.write((char*)&object->pcoord[1], sizeof(double));
	return strm;
}

fstream& operator >> (fstream& strm, const Node& object)
{
	strm.read((char*)&object.str, sizeof(object.str));
	strm.read((char*)&object.numb, sizeof(int));
	strm.read((char*)&object.pcoord[0], sizeof(double));
	strm.read((char*)&object.pcoord[1], sizeof(double));
	return strm;
}

fstream& operator << (fstream& strm, const Node& object)
{
	strm.write((char*)&object.str, sizeof(object.str));
	strm.write((char*)&object.numb, sizeof(int));
	strm.write((char*)&object.pcoord[0], sizeof(double));
	strm.write((char*)&object.pcoord[1], sizeof(double));
	return strm;
}