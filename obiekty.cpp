#include "obiekty.h"
#include <iostream>
#include <string>

//metody klasy szablon
void szablon::set_ocena (float ocena_temp = 0.0, bool komunikat = true)
{
	if ((ocena_temp != 2) && (ocena_temp != 3) && (ocena_temp != 3.5) && (ocena_temp != 4) && (ocena_temp != 4.5) && (ocena_temp != 5))
	{
		if (komunikat == true)
		{
			std::cout << "Podana ocena koñcowa jest nieprawid³owa, poniewa¿ nie jest ona 2, 3, 3.5, 4, 4.5 lub 5.\n";
		}
		ocena = 0;
	}
	else
	{
		ocena = ocena_temp;
	}
};

//metody klasy student
void student::set_numer (int numer_temp = 0)
{
	if ((numer_temp > 99999) || (numer_temp < 10000))
	{
		std::cout << "Podany numer indeksu jest nieprawid³owy, poniewa¿ ma ponad 5 cyfr lub poni¿ej 5 cyfr.\n";
		numer = 0;
	}
	else
	{
		numer = numer_temp;
	}
};

void student::set_ocena (float ocena_temp = 0.0, bool komunikat = true)
{
	if ((ocena_temp != 2) && (ocena_temp != 3) && (ocena_temp != 3.5) && (ocena_temp != 4) && (ocena_temp != 4.5) && (ocena_temp != 5))
	{
		if (komunikat == true)
		{
			std::cout << "Podana ocena koñcowa jest nieprawid³owa, poniewa¿ nie jest ona 2, 3, 3.5, 4, 4.5 lub 5.\n";
		}
		ocena = 0;
	}
	else
	{
		ocena = ocena_temp;
	}
};

//metody klasy pracownik
void pracownik::set_numer (int numer_temp = 0)
{
	if ((numer_temp > 9999999) || (numer_temp < 1000000))
	{
		std::cout << "Podany numer indeksu jest nieprawid³owy, poniewa¿ ma ponad 7 cyfr lub poni¿ej 7 cyfr.\n";
		numer = 0;
	}
	else
	{
		numer = numer_temp;
	}
};

void pracownik::set_ocena (float ocena_temp = 0.0, bool komunikat = true)
{
	if ((ocena_temp > 5) || (ocena_temp < 0))
	{
		if (komunikat == true)
		{
			std::cout << "Podana ocena koñcowa jest nieprawid³owa, poniewa¿ nie jest ona wiêksza od 5 lub mniejsza od 0.\n";
		}
		ocena = 0;
	}
	else
	{
		ocena = ocena_temp;
	}
};

//pozosta³e funkcje
pracownik* dodaj_pracownika (int nr_umowy_temp = 0, std::string nazwisko_temp = "", float ocena_temp = 0, pracownik *wsk = NULL, bool ocena_obowiazkowa = true, bool komunikat = true)
{
	if (wsk == NULL)
	{
		wsk = new pracownik (nazwisko_temp, ocena_temp, nr_umowy_temp, false);
		wsk->nast = NULL;
		wsk->poprz = NULL;
	}
	else
	{
		while (wsk != NULL)
		{
			if (wsk->nast == NULL)
			{
				break;
			}
			else
			{
				wsk = (pracownik*)wsk->nast;
			}
		}
		wsk->nast = new pracownik (nazwisko_temp, ocena_temp, nr_umowy_temp, false);
		wsk->nast->nast = NULL;
		wsk->nast->poprz = wsk;
	}
	
	while (wsk->poprz != NULL)
	{
		wsk = (pracownik*)wsk->poprz;
	}
	return wsk;
};

student* dodaj_studenta (int nr_indeksu_temp = 0, std::string nazwisko_temp = "", float ocena_temp = 0, student *wsk = NULL, bool ocena_obowiazkowa = true, bool komunikat = true)
{
	if (wsk == NULL)
	{
		wsk = new student (nazwisko_temp, ocena_temp, nr_indeksu_temp, false);
		wsk->nast = NULL;
		wsk->poprz = NULL;
	}
	else
	{
		while (wsk != NULL)
		{
			if (wsk->nast == NULL)
			{
				break;
			}
			else
			{
				wsk = (student*)wsk->nast;
			}
		}
		wsk->nast = new student (nazwisko_temp, ocena_temp, nr_indeksu_temp, false);
		wsk->nast->nast = NULL;
		wsk->nast->poprz = wsk;
	}
	
	while (wsk->poprz != NULL)
	{
		wsk = (student*)wsk->poprz;
	}
	return wsk;
};