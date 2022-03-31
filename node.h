#pragma once


#include <iostream>
#include "mcoord.h"

using namespace std;


class Node :public MCoord
{
	int numb;       //numer wierzcholka
	char str[512];  //nazwa wierzcholka

public:
	Node();													//Konstruktor domyslny
	Node(int nb, char* st, double xx, double yy);			//Konstruktor sparametryzowany
	Node(const Node& object);								//Konstruktor kopiujacy


	Node& operator = (const Node& object);				//Operator porównania
	bool  operator == (const Node& object);				//Operator porównania
	bool operator == (const int number);				//Operator porównania


	friend ostream& operator << (ostream& out, const Node& object);		//Operator wyprowadzenia na ekran obiektu Node
	friend istream& operator >> (istream& in, Node& object);			//Operator odczytu  obiektu Node z ekranu

	friend fstream& operator >> (fstream& strm, const Node* object);		//Operator odczytu danych  typu Node ze strumienia - wskażnik
	friend fstream& operator << (fstream& strm, const Node* object);		//Operator zapisu danych  typu Node do strumienia - wskażnik
	friend fstream& operator >> (fstream& strm, const Node& object);		//Operator odczytu danych  typu Node ze strumienia - referencja
	friend fstream& operator << (fstream& strm, const Node& object);		//Operator zapisu danych  typu Node do strumienia - referencja

};