#pragma once

#include <iostream>
#include <fstream>
#include "windows.h"
#include "vector.h"
#include "vector_file.h"
#include "create_exception.h"
#include "node.h"


#define PATH 128
#define DEFAULT_BIN_FILE "data.bin"

using namespace std;


template <class T>
class  VectorFile :public  Vector<T>
{
protected:
	fstream binFile;
	char binFileName[PATH];

public:
	VectorFile();							//Konstruktor domyslny.
	VectorFile(size_t vectorSize);			//Konstruktor sparametryzowany.
	~VectorFile();							//Destruktor.

	
	
	void initFile(char* fileName);						// Ustawiamy nazwe pliku  i tworzymy / otwieramy go.
	fstream& getBinFileStream() { return binFile; };	// Zwracamy strumien do pliku binFile. 

	
	friend fstream& operator << <>(fstream& binFile, const VectorFile<T>& object);	// Zapisz danych do pliku.
	friend fstream& operator >> <>(fstream& binFile, VectorFile<T>& object);		// Odczyt danych z pliku.

	


};


template<class T>
inline VectorFile<T>::VectorFile()
{	
	strcpy_s(binFileName, DEFAULT_BIN_FILE);
}

template<class T>
inline VectorFile<T>::VectorFile(size_t vectorSize) : Vector(vectorSize)
{
	strcpy_s(binFileName, DEFAULT_BIN_FILE);
}


template<class T>
inline VectorFile<T>::~VectorFile()
{
	if (binFile.is_open()) {
		binFile.close();
	}

}




template<class T>
void VectorFile<T>::initFile(char* fileName)
{	
	strcpy_s(binFileName, fileName);
	
	char pathbuffer[PATH];
	_searchenv_s(binFileName, "PATH", pathbuffer);
	if (pathbuffer[0] == '\0') {
		ofstream fileHandler(binFileName);
		fileHandler.close();
	}

	binFile.open(binFileName, ios_base::in | ios_base::out | ios_base::binary);
	if (!binFile.is_open()) {
		CreateException exception(ERROR_ENUM::EXCEPT_OPEN_FILE_ERROR);
	}

	cout << "Otwarto plik:" << binFileName << endl;

}


template <class T>
fstream& operator << <>(fstream& binFile, const VectorFile<T>& object) {
	size_t i;
	binFile.clear();
	binFile.close();
	binFile.open(object.binFileName, ios_base::in | ios_base::out | ios_base::trunc | ios_base::binary);
	if (!binFile.is_open())
		CreateException exception(ERROR_ENUM::EXCEPT_OPEN_FILE_ERROR);

	for (i = 0; i < object.usingDataSize; i++) {
		binFile << &object.data[i];
		if (binFile.bad() || binFile.fail())
			CreateException exception(ERROR_ENUM::EXCEPT_WRITE_TO_FILE_ERROR);
	}
	return binFile;
}






template <class T>
fstream& operator >> <>(fstream& binFile, VectorFile<T>& object) {
	object.usingDataSize = 0;
	binFile.clear();
	binFile.seekg(0);

	while (!binFile.eof()) {
		if (object.usingDataSize >= object.allocatedDataSize)
			object.reallocVector();

		binFile >> &object.data[object.usingDataSize];


		if (binFile.eof())
			break;
		if (binFile.bad())
			CreateException exception(ERROR_ENUM::EXCEPT_READ_FROM_FILE_ERROR);
		object.usingDataSize++;
	}
	return binFile;
}
