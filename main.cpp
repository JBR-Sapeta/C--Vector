// Projekt.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.



#include "mcoord.h"
#include "create_exception.h"
#include "interface.h"
#include "node.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>


using namespace std;

int main(int argc, char* argv[])
{
	int userInput;

	int imax = DEFAULT_VECTOR_SIZE;
	char filename[PATH] = "data.bin";

	cout << "Czy chcesz ustawic wielkosc vectora i nazwe pliku ?" << endl;
	cout << "1) TAK" << endl;
	cout << "2) NIE" << endl;
	cin >> userInput;

	switch (userInput)
	{
	case 1:
		cout << "Podaj wielkosc wektora ( Liczba calkowita !) :" << endl;
		cin >> imax;
		cout << "Podaj nazwe pliku ( Plik binarny !) :  " << endl;
		cin >> filename;
		break;
	case 2:
		cout << "Przyjeto wartosci domyslne !" << endl;
		break;
	default:
		cout << "Przyjeto wartosci domyslne !" << endl;

	};

	
	Interface window(filename, imax);


	

	try
	{
		while (window.runing)
		{
			window.menu();
			cin >> userInput;
			system("CLS");

			switch (userInput)
			{
			case 0:
				window.pushElement();
				break;
			case 1:
				window.popElement();
				break;
			case 2:
				window.clearVector();
				break;
			case 3:
				window.modifyElement();
				break;
			case 4:
				window.insertElement();
				break;
			case 5:
				window.findElement();
				break;
			case 6:
				window.saveVectoBin();
				break;
			case 7:
				window.loadVectorBin();
				break;
			case 8:
				window.displeyVector();
				break;
			case 9:
				window.closeProgram();
				break;
			
			default:
				window.defaultCase();

			};
		}
	}

	catch (CreateException exception)
	{
		exception.displayMessage();
	}



	system("pause");
	return 0;

}


// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
