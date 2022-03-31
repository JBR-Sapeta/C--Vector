#pragma once

#include "interface.h"
#include "create_exception.h"
#include "node.h"
#include "vector_file.h"
#include <iostream>
#include <fstream>

using namespace std;


const char* Interface::interfaceArray[] = 
{
	"0) Dodaj nowy element na koniec wektora.",
	"1) Usun ostatni element z wektora.",
	"2) Wyczysc wektor z obiektow.",
	"3) Modyfikuj element wektora.",
	"4) Wstaw wektor w okreslone miejsce.",
	"5) Znajdz wierzcholki o wskazanym numerze.",
	"6) Zapisz wektor do pliku.",
	"7) Wczytaj wektor z pliku.",
	"8) Wyswietl elementy wektora na ekranie.",
	"9) Zakoncz Program.",

};





Interface::Interface(char* binFileName) {

	//Node newObject(100,(char*)"DEFAULT", 0.0, 0.0);
	//object = newObject;
	//ptr = &newObject;
	runing = true;
	vector.initFile(binFileName);
}

Interface::Interface(char* binFileName, size_t size) {
	
	//Node newObject(100, (char*)"DEFAULT", 0.0, 0.0);
	//object = newObject;
	//ptr = &newObject;
	runing = true;
	vector.initFile(binFileName);
	vector.changeVectorSize(size);
}

void Interface::menu() {

	cout << endl << "Menu: " << endl;
	for (int i = 0; i < INTERFACE_TOT; i++)
		cout  << interfaceArray[i] << endl;
	cout << "Wprowadz numer polecenia: " << endl;
}

void Interface::pushElement()
{
	cout << "Wprowadz dane obiektu:" << endl;
	
	cin >> object;
	vector.pushBack(object);
}

void Interface::popElement()
{
	if (vector.isEmpty())
	{
		CreateException exception(ERROR_ENUM::EXCEPT_EMPTY_VECTOR_WARNING);
		return;
	}
	vector.popBack();
	cout << "Usunieto ostatni element z wektora !" << endl;

}

void Interface::clearVector()
{
	if (vector.isEmpty()) {
		CreateException exception(ERROR_ENUM::EXCEPT_EMPTY_VECTOR_WARNING);
		return;
	}
	vector.clear();
	cout << "Wektor zostal wyczyszczony" << endl;

}

void Interface::modifyElement()
{
	size_t index;

	if (vector.isEmpty()) {
		CreateException exception(ERROR_ENUM::EXCEPT_EMPTY_VECTOR_WARNING);
		return;
	}

	cout << "Edytuj:" << endl;
	vector.displayVector();

	cout << "Podaj Index Elementu do modyfikacji: ";
	cin >> index;

	if (index > vector.size() || index < 0)
	{
		CreateException exception(ERROR_ENUM::EXCEPT_WRONG_INDEX_WARNING);
		return;
	}
	cout << "Wprowadz nowe dane obiektu:" << endl;
	cin >> vector[index];

}

void Interface::insertElement()
{
	size_t index;
	bool indexIsValid = false;

	cout << "Wektor zawiera " << vector.size() << " elementy." << endl;
	cout << "Pod ktory index wstawic element ? ( index od 0 do " << vector.size() << " )" << endl;
	vector.displayVector();

	do {

		cin >> index;
		if (index <= vector.size()) {
			indexIsValid = true;
		}
		else {
			cout << " Index musi byc <= " << vector.size() << "!" << endl;
		}
	} while (!indexIsValid);


	if (index == vector.size()) {
		cout << "Wprowadz dane obiektu:" << endl;
		cin >> object;
		vector.pushBack(object);
		return;
	}

	vector.insertElement(index);
	cout << "Wprowadz dane obiektu:" << endl;
	cin >> vector[index];

}





void Interface::findElement()
{
	if (vector.isEmpty()) {
		CreateException exception(ERROR_ENUM::EXCEPT_EMPTY_VECTOR_WARNING);
		return;
	}

	int numbToFind, found = 0;
	cout << "Szukaj elementow." << endl;
	cout << "Podaj numer wierzcholka szukanego: ";
	cin >> numbToFind;

	Node* ptr = vector.getFront();
	cout << "Wynik:" << endl;
	cout << "Nazwa    " << "Numer    " << "  X   " << "  Y   " << endl;
	do
	{
		ptr = Find(ptr, vector.getEnd(), numbToFind);
		if (ptr)
		{
			cout << *ptr << endl;
			ptr++;
			found++;
		}
		else
			cout << endl << "Ilosc znalezionych elementow: " << found << endl;
	} while (ptr);

}



void Interface::saveVectoBin()
{
	cout << "Poprawny zapis do pliku binarnego" << endl;
	vector.getBinFileStream() << vector;
}

void Interface::loadVectorBin()
{
	cout << "Poprawny odczyt z pliku binarnego" << endl;
	vector.getBinFileStream() >> vector;
}


void Interface::displeyVector()
{
	if (vector.isEmpty()) {
		CreateException exception(ERROR_ENUM::EXCEPT_EMPTY_VECTOR_WARNING);
		return;
	}
	cout << "Lista elementow vectora: " << endl;
	vector.displayVector();
}




void Interface::closeProgram()
{
	cout << "Program zostanie zakonczony." << endl;
	runing = false;
}

void Interface::defaultCase()
{
	CreateException exception(ERROR_ENUM::EXCEPT_UNKNOWN_COMAND_WARNING);
}