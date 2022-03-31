#pragma once
#include <iostream>
#include "vector.h"
#include "create_exception.h"


#define DEFAULT_VECTOR_SIZE 100


using namespace std;


template <class T> class Vector
{

protected:

	T* data;
	size_t allocatedDataSize;
	size_t usingDataSize;

public:


	Vector();												//Konstruktor domyslny - Tworzenie wektor o rozmiarze rownym DEFAULT_VECTOR_SIZE.
	Vector(size_t vectorSize);								//Konstruktor sparametryzowany - Tworzenie wektor o podanym rozmiarze.

	~Vector();												//Destruktor.

	T* getAt(size_t index) { return &data[index]; }		    // Zwraca elemet vectora o podanym indeksie. 
	T* getFront() { return data; }							// Zwraca pierwszy elemet wektora.
	T* getEnd() { return &data[usingDataSize]; }			// Zwraca ostatni elemet wektora.

	size_t size() { return usingDataSize; }					// Zwraca rozmiar uzywanej cze�ci wektora.

	void pushBack(const T& newElement);						//Dodaj nowy element na koniec wektora.
	void popBack();											//Usuwanie ostatniego elementu wektora.

	bool isEmpty() { return !bool(usingDataSize); }			//Sprawdzanie, czy wektor jest pusty.

	void clear();											//Usuwanie wszystkich elementow z wektora.
	void shrinkToFit();										//Realokowanie pamieci, aby dopasowac rozmiar zaalokowanej tablicy do uzywanej.

	void erase(size_t index);								// Usuwanie elementu pod wskazanym indeksem.
		
	void insertElement(size_t index);						// Wstawiamy danych w konkretnym miejscu.
	void reallocVector();									// Zwiekszamy wielkosc wektora 2 krotnie.
	void changeVectorSize(size_t size);								// Zwiekszenie rozmiaru wktora dwukrotnie gdy jest pelen.
	void displayVector();											// Wyswietla zawrtosc wektora.

	T& operator [] (const size_t index) { return data[index]; }		// Korzystanie z operatora [] dla naszego wektora.

};


using namespace std;

template <class T, class Key>
T* Find(const T* p_begin, const T* p_end, const Key& k)				// Szukanie wskazanego klucza w wketorze.
{

	T* tempPointer = const_cast<T*>(p_begin);
	while (tempPointer != p_end)
	{
		if (*tempPointer == k)
			return tempPointer;
		++tempPointer;
	}
	return NULL;
}



template <class T>
Vector<T>::Vector() //Konstruktor domyslny.
{
	try
	{
		allocatedDataSize = DEFAULT_VECTOR_SIZE;
		data = new T[DEFAULT_VECTOR_SIZE];
		usingDataSize = 0;
	}
	catch (bad_alloc)
	{
		CreateException exception(ERROR_ENUM::EXCEPT_MEMORY_ALOCATION_ERROR);

	}

	cout << "Utworzono wektor o rozmiarze domyslnym:" << DEFAULT_VECTOR_SIZE << endl;
}




template <class T>
Vector<T>::Vector(size_t vectorSize) //Konstruktor sparametryzowany.
{
	try
	{
		allocatedDataSize = vectorSize;
		data = new T[allocatedDataSize];
		usingDataSize = 0;
	}
	catch (bad_alloc)
	{
		CreateException exception(ERROR_ENUM::EXCEPT_MEMORY_ALOCATION_ERROR);
	}

	cout << "Utworzono wektor o rozmiarze :" << allocatedDataSize << endl;
}

template <class T>
Vector<T>::~Vector()		//Destruktor .

{
	if (data) {
		delete[] data;
	}
	data = NULL;

}


template <class T>
void Vector<T>::pushBack(const T& newElement)				//Dodawanie elementu n koniec wektora.
{
	if (usingDataSize >= allocatedDataSize) {
		CreateException exception(ERROR_ENUM::EXCEPT_VECTOR_OVERFLOW_WARNING);
		reallocVector();
	}
	data[usingDataSize] = newElement;
	usingDataSize++;
}

template <class T>
void Vector<T>::popBack()								//Usuwanie elementu z konica wektora.
{
	if (usingDataSize > 0) {
		usingDataSize--;
	}
	else
	{
		CreateException exception(ERROR_ENUM::EXCEPT_EMPTY_VECTOR_WARNING);
	}
}

template <class T>
void Vector<T>::clear()								// "Czyszczenie" wektora.
{
	
	if (usingDataSize)
		usingDataSize = 0;
}


template<class T>
void Vector<T>::shrinkToFit()	//Realokowanie pamieci, aby dopasowac rozmiar zaalokowanej tablicy do uzywanej.
{
	T* newData;

	try
	{
		T* newData = new T[usingDataSize];
	}
	catch (bad_alloc)
	{
		CreateException exception(ERROR_ENUM::EXCEPT_MEMORY_ALOCATION_ERROR);
	}

	if (newData)
	{
		copy(data, data[usingDataSize], newData);
	}


	delete[] data;

	allocatedDataSize = usingDataSize;
	data = newData;

	cout << "Zmieniono rozmiar wektor na  :" << allocatedDataSize << endl;
}

template<class T>
void Vector<T>::erase(size_t index) // Usuwanie elementu pod wskazanym indeksem.
{
	size_t i;
	for (i = index; i < usingDataSize - 1; ++i)
	{
		data[i] = data[i + 1];
	}
	usingDataSize--;
}


template<class T>
void Vector<T>::reallocVector()		// Zwiekszamy wielkosc wektora 2 krotnie.
{
	
	T* newData = new T[allocatedDataSize * 2];
	
	if (newData) {
		copy(data, data + min(allocatedDataSize, allocatedDataSize * 2), newData);
	}
	

	delete[] data;
	allocatedDataSize = allocatedDataSize * 2;
	data = newData;

	cout << "Zmieniono rozmiar wektor na  :" << allocatedDataSize << endl;
}

template<class T>
void Vector<T>::changeVectorSize(size_t size)  // Zwiekszenie rozmiaru wktora dwukrotnie gdy jest pelen.
{

	if (allocatedDataSize == size) {
		return;
	}

	if (data)
	{
		delete[] data;
	}

	try
	{
		data = new T[size];
	}
	catch (bad_alloc)
	{
		CreateException exception(ERROR_ENUM::EXCEPT_MEMORY_ALOCATION_ERROR);
	}
	allocatedDataSize = size;


	cout << "Wielkosc wektora ustawiona na:"<< allocatedDataSize <<endl;

}


template <class T>
void Vector<T>::displayVector() // Wyswietla zawrtosc wektora.
{

	cout << "Element [Index]" << " Nazwa   " <<  "Numer   " <<  "   X   "<< "   Y   " <<endl;
	for (size_t i = 0; i < usingDataSize; i++) {
		cout << "Element [" << i << "]" << "\t " << data[i] << endl;
	}
}


template<class T>
void Vector<T>::insertElement(size_t index)  // Wstawiamy danych w konkretnym miejscu.
{
	size_t i;
	if (index == usingDataSize) {
		return;
	}

	if (index == allocatedDataSize) {
		reallocVector();
	}

	for (i = usingDataSize; i > index + 1; --i)
	{
		data[i] = data[i - 1];
	}
	usingDataSize++;
}