//Zadanie semestralne nr. 7
//Autor: Pawe³ Roszatycki

//za³¹czanie bibliotek
#include <iostream>
#include <cstdlib>
#include <string>

//za³¹czanie w³asnych plików
#include "menu.h"
#include "zapis_odczyt.h"
#include "obiekty.h"

int main ()
{
	szablon *glowa_szablon = NULL;

	//zmiana kodowania znaków, w celu poprawnego wyœwietlania wszystkich liter u¿ywanych w polskim alfabecie
	setlocale(LC_ALL, "polish");

	//odczyt danych z pliku lista.txt
	glowa_szablon = odczyt (glowa_szablon);
	
	//wywo³ywanie menu
	menu (glowa_szablon);

	system ("pause");
	return 0;
};