#pragma once


#include <iostream>
#include "create_exception.h"

using namespace std;


  const char* CreateException::exceptionArray[] = 
{
	"Error - Blad alokacji pamieci!",				// EXCEPT_MEMORY_ALOCATION_ERROR
	"Error - Blad podczas otwierania pliku!",		// EXCEPT_OPEN_FILE_ERROR	
	"Error - Blad zapisu do pliku!",				// EXCEPT_WRITE_TO_FILE_ERROR
	"Error - Blad czytania z pliku!",				// EXCEPT_READ_FROM_FILE_ERROR
	"Warning - Nazwa wierzcholka zbyt dluga!",		// EXCEPT_TO_LONG_NODE_NAME_WARNING	
	"Warning - Tablica jest przepelniona!",			// EXCEPT_VECTOR_OVERFLOW_WARNING
	"Warning - Tablica jest pusta!",				// EXCEPT_EMPTY_VECTOR_WARNING
	"Warning - Element o zlym indeksie!",			// EXCEPT_WRONG_INDEX_WARNING
	"Warning - Nieznane polecenie!"				    // EXCEPT_UNKNOWN_COMAND_WARNING

};


 
 



CreateException::CreateException(enum  ERROR_ENUM::EXCEPTIONS newExceptions)
{
	position = newExceptions;

	if (exceptionArray[position][0] == 'E')
		throw* this;
	else
		displayMessage();
}
void CreateException::displayMessage()
{
	cout << exceptionArray[position] << endl;
}