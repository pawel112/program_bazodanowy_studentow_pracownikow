//Zadanie semestralne nr. 7
//Autor: Pawe� Roszatycki

//za��czanie bibliotek
#include <iostream>
#include <cstdlib>
#include <string>

//za��czanie w�asnych plik�w
#include "menu.h"
#include "zapis_odczyt.h"
#include "obiekty.h"

int main ()
{
	szablon *glowa_szablon = NULL;

	//zmiana kodowania znak�w, w celu poprawnego wy�wietlania wszystkich liter u�ywanych w polskim alfabecie
	setlocale(LC_ALL, "polish");

	//odczyt danych z pliku lista.txt
	glowa_szablon = odczyt (glowa_szablon);
	
	//wywo�ywanie menu
	menu (glowa_szablon);

	system ("pause");
	return 0;
};