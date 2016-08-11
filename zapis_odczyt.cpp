#include "zapis_odczyt.h"
#include "obiekty.h"
#include "menu.h"
#include <iostream>
#include <fstream>
#include <string>

szablon* odczyt (szablon* glowa_szablon_temp)
{
	glowa_szablon_temp = NULL;
	if (czy_jest_plik ("lista.txt") == 1)
	{
		std::ifstream plik3;
		std::string temp = "";
		plik3.open("lista.txt", std::ios_base::in);

		while (!(plik3.eof()))
		{
			std::streamoff temp_dlugosc = plik3.tellg();
			getline(plik3, temp);
			if ((temp == "") || (temp == "Lista student�w:")) //pomijanie napisu "Lista student�w:"
			{
				continue;
			}
			else if (temp == "Lista pracownik�w:") //kiedy napis "Lista pracownik�w:", zako�czenie p�tli while
			{
				break;
			}
			else
			{
				plik3.seekg (temp_dlugosc);
			}
			
			//studenci
			int nr_indeksu_temp = 0;
			std::string nazwisko_temp = "";
			float ocena_temp = 0;
			plik3 >> nr_indeksu_temp >> nazwisko_temp >> ocena_temp;
			glowa_szablon_temp = dodaj_studenta (nr_indeksu_temp, nazwisko_temp, ocena_temp, (student*)glowa_szablon_temp, true, false);
			std::cout << "\n";
		}

		if (glowa_szablon_temp == NULL)
		{
			plik3.seekg(0, std::ios::beg);
			getline(plik3, temp); //pomijanie napisu "Lista pracownik�w:"
		}
		
		while (!(plik3.eof()))
		{
			std::streamoff temp_dlugosc = plik3.tellg();
			getline(plik3, temp);
			if (temp == "")
			{
				continue;
			}
			else
			{
				plik3.seekg (temp_dlugosc);
			}
			
			//pracownicy
			int nr_umowy_temp = 0;
			std::string nazwisko_temp = "";
			float ocena_temp = 0;
			plik3 >> nr_umowy_temp >> nazwisko_temp >> ocena_temp;
			glowa_szablon_temp = dodaj_pracownika (nr_umowy_temp, nazwisko_temp, ocena_temp, (pracownik*)glowa_szablon_temp, true, false);
		}
	}
	else
	{
		std::cout << "Plik lista.txt nie istnieje lub nie zawiera �adnych danych.\nProgram ko�czy prac�.\n";
		system ("pause");
		exit(1);
	}
	while (glowa_szablon_temp->poprz != NULL)
	{
		glowa_szablon_temp = glowa_szablon_temp->poprz;
	}
	return glowa_szablon_temp;
};


szablon* zapis (szablon* glowa_szablon_temp)
{
	std::fstream plik2;
	plik2.open("lista.txt", std::ios_base::out | std::ios_base::trunc); //dane s� tracone, plik w trybie do zapisu
	if(!plik2.is_open())
	{
		//b��d podczas otwarcia pliku
		std::cout << "Wyst�pi� b��d podczas pr�by otwarcia pliku �lista.txt� do zapisu.\nProgram zostanie zako�czony.\n";
		system ("pause");
		exit(1);
		return NULL;
	}
	
	if (glowa_szablon_temp != NULL) //s� studenci
	{
		plik2 << "Lista student�w:\n";
		while (true)
		{
			if (glowa_szablon_temp->jaka_lista() == "Lista student�w:\n")
			{
				plik2 << glowa_szablon_temp->get_numer() << " " << glowa_szablon_temp->get_nazwisko() << " " << glowa_szablon_temp->get_ocena() << "\n";
			}
			if (glowa_szablon_temp->nast != NULL)
			{
				glowa_szablon_temp = glowa_szablon_temp->nast;
			}
			else
			{
				break;
			}
		}
		plik2 << "\n";
	}
	
	while (glowa_szablon_temp->poprz != NULL)
	{
		glowa_szablon_temp = glowa_szablon_temp->poprz;
	}
	if (glowa_szablon_temp != NULL) //s� pracownicy
	{
		plik2 << "Lista pracownik�w:\n";
		while (true)
		{
			if (glowa_szablon_temp->jaka_lista() == "Lista pracownik�w:\n")
			{
				plik2 << glowa_szablon_temp->get_numer() << " " << glowa_szablon_temp->get_nazwisko() << " " << glowa_szablon_temp->get_ocena() << "\n";
			}
			if (glowa_szablon_temp->nast != NULL)
			{
				glowa_szablon_temp = glowa_szablon_temp->nast;
			}
			else
			{
				break;
			}
		}
	}
	plik2.close();
	while (glowa_szablon_temp->poprz != NULL)
	{
		glowa_szablon_temp = glowa_szablon_temp->poprz;
	}
	return glowa_szablon_temp;
};

int czy_jest_plik (std::string nazwa_temp)
{
	std::ifstream plik4;
	plik4.open(nazwa_temp, std::ios_base::in | std::ios_base::ate); //otwiera plik do odczytu i ustawia si� na jego ko�cu
	
	if(!plik4.is_open())
	{
		//brak pliku
		return 0;
	}
	else if (!plik4.tellg()) //sprawdzenie czy plik jest pusty
	{
		//pusty plik
		plik4.close();
		return 2;
	}
	else
	{
		//niepusty plik
		plik4.seekg(0, std::ios::beg); //ponownie wczytuje plik od poczatku
		plik4.close();
		return 1;
	}
};

std::fstream otworz_plik_do_zapisu ()
{
	std::fstream plik1;
	std::string wybor;
	
	for (int i=0; i<1; )
	{
		tekst_wysrodkowany (std::string ("Prosz� poda� nazw� pliku do zapisu (wraz z rozszerzeniem):\n"));
		//czyszczenie bufora klawiatury
		std::cin.clear();
		std::cin.sync();
		std::cin >> wybor;
		if (czy_jest_plik (wybor) == 1)
		{
			std::cout << "Plik zawiera ju� dane.\n";
			system ("pause");
		}
		else
		{
			plik1.open(wybor, std::ios_base::out | std::ios_base::trunc);
			i++;
		}
	}
	return plik1;
};