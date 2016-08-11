//Autor: Paweł Roszatycki

//załączanie bibliotek
#include <iostream>
#include <cstdlib>
#include <string>

//załączanie własnych plików
#include "menu.h"
#include "zapis_odczyt.h"
#include "obiekty.h"

int main ()
{
	szablon *glowa_szablon = NULL;

	//zmiana kodowania znaków, w celu poprawnego wyświetlania wszystkich liter używanych w polskim alfabecie
	setlocale(LC_ALL, "polish");

	//odczyt danych z pliku lista.txt
	glowa_szablon = odczyt (glowa_szablon);
	
	//wywoływanie menu
	menu (glowa_szablon);

	system ("pause");
	return 0;
};
