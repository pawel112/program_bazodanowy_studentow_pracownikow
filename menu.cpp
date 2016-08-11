#include "menu.h"
#include "zapis_odczyt.h"
#include "obiekty.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

void tekst_wysrodkowany (std::string &podany_tekst)
{
	int licznik = 0;
	int tymczasowa = 0;
	for (int j=0; j<static_cast<int> (podany_tekst.length()); j++)
	{
		if (((static_cast<int> (podany_tekst[licznik]) < 32) || (static_cast<int> (podany_tekst[licznik]) > 127)) && (static_cast<int> (podany_tekst[licznik]) != -91) && (static_cast<int> (podany_tekst[licznik]) != -58) && (static_cast<int> (podany_tekst[licznik]) != -54) && (static_cast<int> (podany_tekst[licznik]) != -93) && (static_cast<int> (podany_tekst[licznik]) != -47) && (static_cast<int> (podany_tekst[licznik]) != -45) && (static_cast<int> (podany_tekst[licznik]) != -116) && (static_cast<int> (podany_tekst[licznik]) != -113) && (static_cast<int> (podany_tekst[licznik]) != -81) && (static_cast<int> (podany_tekst[licznik]) != -71) && (static_cast<int> (podany_tekst[licznik]) != -26) && (static_cast<int> (podany_tekst[licznik]) != -22) && (static_cast<int> (podany_tekst[licznik]) != -77) && (static_cast<int> (podany_tekst[licznik]) != -15) && (static_cast<int> (podany_tekst[licznik]) != -13) && (static_cast<int> (podany_tekst[licznik]) != -100) && (static_cast<int> (podany_tekst[licznik]) != -97) && (static_cast<int> (podany_tekst[licznik]) != -65 && (static_cast<int> (podany_tekst[licznik]) != -106))) //warunek znajduje bia³e znaki z pominiêciem liter u¿ywanych, tylko w jêzyku polskim, pominiêcie równie¿ myœlnika
		{
			for (int i=0; i<(80-licznik+tymczasowa)/2; i++)
			{
				std::cout << " ";
			}
			for (int i=tymczasowa; i<licznik; i++)
			{
				std::cout << podany_tekst[i];
			}
			std::cout << "\n";
			licznik++;  //pomija bia³y znak
			tymczasowa = licznik;
		}
		else
		{
			licznik++;
		}
	}
};

student* nowy_student (std::string tekst, student *glowa_studenci_temp)
{
	system ("cls");
	student *wsk_temp = glowa_studenci_temp;
	std::string nazwisko_temp = "";
	int nr_indeksu_temp = 0;
	tekst_wysrodkowany (tekst+"DODAWANIE STUDENTA:\n\n");
	
	//czyszczenie bufora klawiatury
	std::cin.clear();
	std::cin.sync();
	tekst_wysrodkowany (std::string ("Proszê podaæ nazwisko studenta:\n"));
	std::cin >> nazwisko_temp;
	
	//czyszczenie bufora klawiatury
	std::cin.clear();
	std::cin.sync();
	tekst_wysrodkowany (std::string ("Proszê podaæ numer indeksu studenta:\n"));
	std::cin >> nr_indeksu_temp;

	if ((nr_indeksu_temp > 99999) || (nr_indeksu_temp < 10000))
	{
		std::cout << "Podany numer indeksu jest nieprawid³owy, poniewa¿ ma ponad 5 cyfr lub poni¿ej 5 cyfr.\n";
		system ("pause");
		return glowa_studenci_temp;
	}
	
	while (wsk_temp->poprz != NULL)
	{
		wsk_temp = (student*)wsk_temp->poprz;
	}
	if (wsk_temp != NULL)
	{
		while (wsk_temp->nast != NULL)
		{
			if (wsk_temp->get_numer() == nr_indeksu_temp)
			{
				tekst_wysrodkowany (std::string ("Podany numer indeksu ju¿ istnieje w bazie.\n"));
				system ("pause");
				return glowa_studenci_temp;
			}
			
			if (wsk_temp->nast != NULL)
			{
				wsk_temp = (student*)wsk_temp->nast;
			}
		}
	}

	glowa_studenci_temp = dodaj_studenta(nr_indeksu_temp, nazwisko_temp, 0, glowa_studenci_temp,false,true);

	tekst_wysrodkowany (std::string ("Dodano studenta.\n"));
	system ("pause");
	return glowa_studenci_temp;
};

pracownik* nowy_pracownik (std::string tekst, pracownik *glowa_pracownicy_temp)
{
	system ("cls");
	pracownik *wsk_temp = glowa_pracownicy_temp;
	std::string nazwisko_temp = "";
	int nr_umowy_temp = 0;
	tekst_wysrodkowany (tekst+"DODAWANIE PRACOWNIKA:\n\n");
	
	//czyszczenie bufora klawiatury
	std::cin.clear();
	std::cin.sync();
	tekst_wysrodkowany (std::string ("Proszê podaæ nazwisko pracownika:\n"));
	std::cin >> nazwisko_temp;
	
	//czyszczenie bufora klawiatury
	std::cin.clear();
	std::cin.sync();
	tekst_wysrodkowany (std::string ("Proszê podaæ numer umowy pracownika:\n"));
	std::cin >> nr_umowy_temp;

	if ((nr_umowy_temp > 9999999) || (nr_umowy_temp < 1000000))
	{
		std::cout << "Podany numer indeksu jest nieprawid³owy, poniewa¿ ma ponad 7 cyfr lub poni¿ej 7 cyfr.\n";
		system ("pause");
		return glowa_pracownicy_temp;
	}
	
	
	while (wsk_temp->poprz != NULL)
	{
		wsk_temp = (pracownik*)wsk_temp->poprz;
	}
	if (wsk_temp != NULL)
	{
		while (wsk_temp->nast != NULL)
		{
			if (wsk_temp->get_numer() == nr_umowy_temp)
			{
				tekst_wysrodkowany (std::string ("Podany numer umowy ju¿ istnieje w bazie.\n"));
				system ("pause");
				return glowa_pracownicy_temp;
			}
			
			if (wsk_temp->nast != NULL)
			{
				wsk_temp = (pracownik*)wsk_temp->nast;
			}
		}
	}
	glowa_pracownicy_temp = dodaj_pracownika(nr_umowy_temp, nazwisko_temp, 0, glowa_pracownicy_temp,false,true);
	tekst_wysrodkowany (std::string ("Dodano pracownika.\n"));
	system ("pause");
	return glowa_pracownicy_temp;
};

student* usun_studenta (std::string tekst, student *glowa_studenci_temp)
{
	system ("cls");
	student *wsk_temp = glowa_studenci_temp;
	student *usuw = NULL;
	std::string nazwisko_temp = "";
	int nr_indeksu_temp = 0;
	tekst_wysrodkowany (tekst+"USUWANIE STUDENTA:\n\n");
	
	//czyszczenie bufora klawiatury
	std::cin.clear();
	std::cin.sync();
	tekst_wysrodkowany (std::string ("Proszê podaæ numer indeksu studenta do usuniêcia:\n"));
	std::cin >> nr_indeksu_temp;

	if (wsk_temp != NULL)
	{
		while (wsk_temp->nast != NULL)
		{
			if (wsk_temp->get_numer() == nr_indeksu_temp)
			{
				break;
			}
			wsk_temp = (student*)wsk_temp->nast;
		}
		if ((wsk_temp->nast == NULL) && (wsk_temp->get_numer() != nr_indeksu_temp))
		{
			tekst_wysrodkowany (std:: string ("Nie znaleziono studenta.\n"));
			system ("pause");
			while (wsk_temp->poprz != NULL)
			{
				wsk_temp = (student*)wsk_temp->poprz;
			}
			return wsk_temp;
		}
		else
		{
			if ((wsk_temp->poprz == NULL) && (wsk_temp->nast == NULL)) //element pojedyñczy
			{
				delete wsk_temp;
				wsk_temp = NULL;
			}
			else if (wsk_temp->poprz == NULL) //pocz¹tek
			{
				usuw = wsk_temp;
				wsk_temp = (student*)wsk_temp->nast;
				wsk_temp->poprz = NULL;
				delete usuw;
				usuw = NULL;
			}
			else if (wsk_temp->nast == NULL) //koniec
			{
				usuw = wsk_temp;
				wsk_temp = (student*)wsk_temp->poprz;
				wsk_temp->nast = NULL;
				delete usuw;
				usuw = NULL;
			}
			else //œrodek
			{
				usuw = wsk_temp;
				wsk_temp = (student*)wsk_temp->poprz;
				wsk_temp->nast = wsk_temp->nast->nast;
				wsk_temp->nast->poprz = wsk_temp;
				delete usuw;
				usuw = NULL;
			}
		}
	}
	else
	{
		tekst_wysrodkowany (std:: string ("Lista studentów jest pusta.\n"));
		system ("pause");
		return NULL;
	}

	while (wsk_temp->poprz != NULL)
	{
		wsk_temp = (student*)wsk_temp->poprz;
	}

	tekst_wysrodkowany (std::string ("Usuniêto studenta.\n"));
	system ("pause");
	return wsk_temp;
};

pracownik* usun_pracownika (std::string tekst, pracownik *glowa_pracownicy_temp)
{
	system ("cls");
	pracownik *wsk_temp = glowa_pracownicy_temp;
	pracownik *usuw = NULL;
	std::string nazwisko_temp = "";
	int nr_umowy_temp = 0;
	tekst_wysrodkowany (tekst+"USUWANIE PRACOWNIKA:\n\n");

	//czyszczenie bufora klawiatury
	std::cin.clear();
	std::cin.sync();
	tekst_wysrodkowany (std::string ("Proszê podaæ numer umowy pracownika do usuniêcia:\n"));
	std::cin >> nr_umowy_temp;

	if (wsk_temp != NULL)
	{
		while (wsk_temp->nast != NULL)
		{
			if (wsk_temp->get_numer() == nr_umowy_temp)
			{
				break;
			}
			wsk_temp = (pracownik*)wsk_temp->nast;
		}
		if ((wsk_temp->nast == NULL) && (wsk_temp->get_numer() != nr_umowy_temp))
		{
			tekst_wysrodkowany (std:: string ("Nie znaleziono pracownika.\n"));
			system ("pause");
			while (wsk_temp->poprz != NULL)
			{
				wsk_temp = (pracownik*)wsk_temp->poprz;
			}
			return wsk_temp;
		}
		else
		{
			if ((wsk_temp->poprz == NULL) && (wsk_temp->nast == NULL)) //element pojedyñczy
			{
				delete wsk_temp;
				wsk_temp = NULL;
			}
			else if (wsk_temp->poprz == NULL) //pocz¹tek
			{
				usuw = wsk_temp;
				wsk_temp = (pracownik*)wsk_temp->nast;
				wsk_temp->poprz = NULL;
				delete usuw;
				usuw = NULL;
			}
			else if (wsk_temp->nast == NULL) //koniec
			{
				usuw = wsk_temp;
				wsk_temp = (pracownik*)wsk_temp->poprz;
				wsk_temp->nast = NULL;
				delete usuw;
				usuw = NULL;
			}
			else //œrodek
			{
				usuw = wsk_temp;
				wsk_temp = (pracownik*)wsk_temp->poprz;
				wsk_temp->nast = wsk_temp->nast->nast;
				wsk_temp->nast->poprz = wsk_temp;
				delete usuw;
				usuw = NULL;
			}
		}
	}
	else
	{
		tekst_wysrodkowany (std:: string ("Lista pracowników jest pusta.\n"));
		system ("pause");
		return NULL;
	}

	while (wsk_temp->poprz != NULL)
	{
		wsk_temp = (pracownik*)wsk_temp->poprz;
	}

	tekst_wysrodkowany (std::string ("Usuniêto pracownika.\n"));
	system ("pause");
	return wsk_temp;
}

student* wpisz_ocene_studentowi (std::string tekst, student *glowa_studenci_temp)
{
	system ("cls");
	student *wsk_temp = glowa_studenci_temp;
	int nr_indeksu_temp = 0;
	float ocena_temp = 0;
	tekst_wysrodkowany (tekst+"WPISYWANIE OCENY STUDENTOWI:\n\n");
	
	//czyszczenie bufora klawiatury
	std::cin.clear();
	std::cin.sync();
	tekst_wysrodkowany (std::string ("Proszê podaæ numer indeksu studenta:\n"));
	std::cin >> nr_indeksu_temp;
	
	//czyszczenie bufora klawiatury
	std::cin.clear();
	std::cin.sync();
	tekst_wysrodkowany (std::string ("Proszê podaæ ocenê:\n"));
	std::cin >> ocena_temp;

	if ((ocena_temp != 2) && (ocena_temp != 3) && (ocena_temp != 3.5) && (ocena_temp != 4) && (ocena_temp != 4.5) && (ocena_temp != 5))
	{
		std::cout << "Podana ocena koñcowa jest nieprawid³owa, poniewa¿ nie jest ona 2, 3, 3.5, 4, 4.5 lub 5.\n";
		system ("pause");
		return wsk_temp;
	}

	if (wsk_temp != NULL)
	{
		while (wsk_temp->nast != NULL)
		{
			if (wsk_temp->get_numer() == nr_indeksu_temp)
			{
				break;
			}
			wsk_temp = (student*)wsk_temp->nast;
		}
		if ((wsk_temp->nast == NULL) && (wsk_temp->get_numer() != nr_indeksu_temp))
		{
			tekst_wysrodkowany (std:: string ("Nie znaleziono studenta.\n"));
			system ("pause");
			while (wsk_temp->poprz != NULL)
			{
				wsk_temp = (student*)wsk_temp->poprz;
			}
			return wsk_temp;
		}
		else
		{
			if (wsk_temp->get_ocena () == 0)
			{
				wsk_temp->set_ocena(ocena_temp, false);
			}
			else
			{
				tekst_wysrodkowany (std::string ("Dla tego studenta ju¿ jest podana ocena.\n"));
				system ("pause");
				while (wsk_temp->poprz != NULL)
				{
					wsk_temp = (student*)wsk_temp->poprz;
				}
				return wsk_temp;
			}
		}
	}
	else
	{
		tekst_wysrodkowany (std::string ("Lista studentów jest pusta.\n"));
		system ("pause");
		return NULL;
	}

	while (wsk_temp->poprz != NULL)
	{
		wsk_temp = (student*)wsk_temp->poprz;
	}

	if (wsk_temp->get_ocena() != 0)
	{
		tekst_wysrodkowany (std::string ("Poprawnie dodano ocenê studentowi.\n"));
	}
	system ("pause");
	return wsk_temp;
};

pracownik* wpisz_ocene_pracownikowi (std::string tekst, pracownik *glowa_pracownicy_temp)
{
	system ("cls");
	pracownik *wsk_temp = glowa_pracownicy_temp;
	int nr_umowy_temp = 0;
	float ocena_temp = 0;
	tekst_wysrodkowany (tekst+"WPISYWANIE OCENY PRACOWNIKOWI:\n\n");
	
	//czyszczenie bufora klawiatury
	std::cin.clear();
	std::cin.sync();
	tekst_wysrodkowany (std::string ("Proszê podaæ numer umowy pracownika:\n"));
	std::cin >> nr_umowy_temp;
	
	//czyszczenie bufora klawiatury
	std::cin.clear();
	std::cin.sync();
	tekst_wysrodkowany (std::string ("Proszê podaæ ocenê:\n"));
	std::cin >> ocena_temp;

	if ((ocena_temp > 5) || (ocena_temp < 0))
	{
		std::cout << "Podana ocena koñcowa jest nieprawid³owa, poniewa¿ nie jest ona 2, 3, 3.5, 4, 4.5 lub 5.\n";
		system ("pause");
		return wsk_temp;
	}
	
	if (wsk_temp != NULL)
	{
		while (wsk_temp->nast != NULL)
		{
			if (wsk_temp->get_numer() == nr_umowy_temp)
			{
				break;
			}
			wsk_temp = (pracownik*)wsk_temp->nast;
		}
		if ((wsk_temp->nast == NULL) && (wsk_temp->get_numer() != nr_umowy_temp))
		{
			tekst_wysrodkowany (std:: string ("Nie znaleziono pracownika.\n"));
			system ("pause");
			while (wsk_temp->poprz != NULL)
			{
				wsk_temp = (pracownik*)wsk_temp->poprz;
			}
			return wsk_temp;
		}
		else
		{
			if (wsk_temp->get_ocena () == 0)
			{
				wsk_temp->set_ocena (ocena_temp, false);
			}
			else
			{
				tekst_wysrodkowany (std::string ("Dla tego pracownika ju¿ jest podana ocena.\n"));
				system ("pause");
				while (wsk_temp->poprz != NULL)
				{
					wsk_temp = (pracownik*)wsk_temp->poprz;
				}
				return wsk_temp;
			}
		}
	}
	else
	{
		tekst_wysrodkowany (std:: string ("Lista pracowników jest pusta.\n"));
		system ("pause");
		return NULL;
	}

	while (wsk_temp->poprz != NULL)
	{
		wsk_temp = (pracownik*)wsk_temp->poprz;
	}

	if (wsk_temp->get_ocena() != 0)
	{
		tekst_wysrodkowany (std::string ("Poprawnie dodano ocenê pracownikowi.\n"));
	}
	system ("pause");
	return wsk_temp;
};

int licznik_s (student *glowa_studenci_temp)
{
	int licznik = 0;
	if (glowa_studenci_temp != NULL)
	{
		while (glowa_studenci_temp->poprz != NULL)
		{
			glowa_studenci_temp = (student*)glowa_studenci_temp->poprz;
		}

		while (true)
		{
			if (glowa_studenci_temp->jaka_lista() == "Lista studentów:\n")
			{
				licznik++;
			}

			if (glowa_studenci_temp->nast != NULL)
			{
				glowa_studenci_temp = (student*)glowa_studenci_temp->nast;
			}
			else
			{
				break;
			}
		}

		while (glowa_studenci_temp->poprz != NULL)
		{
			glowa_studenci_temp = (student*)glowa_studenci_temp->poprz;
		}
	}
	return licznik;
};

int licznik_p (pracownik *glowa_pracownicy_temp)
{
	int licznik = 0;
	if (glowa_pracownicy_temp != NULL)
	{
		while (glowa_pracownicy_temp->poprz != NULL)
		{
			glowa_pracownicy_temp = (pracownik*)glowa_pracownicy_temp->poprz;
		}

		while (true)
		{
			if (glowa_pracownicy_temp->jaka_lista() == "Lista pracowników:\n")
			{
				licznik++;
			}

			if (glowa_pracownicy_temp->nast != NULL)
			{
				glowa_pracownicy_temp = (pracownik*)glowa_pracownicy_temp->nast;
			}
			else
			{
				break;
			}
		}

		while (glowa_pracownicy_temp->poprz != NULL)
		{
			glowa_pracownicy_temp = (pracownik*)glowa_pracownicy_temp->poprz;
		}
	}
	return licznik;
};

student* sortuj_studentow (std::string tekst, student *glowa_studenci_temp)
{
	system ("cls");
	student *wsk_temp = glowa_studenci_temp;
	int licznik_studentow = licznik_s (glowa_studenci_temp);
	tekst_wysrodkowany (tekst+"SORTOWANIE STUDENTÓW:\n\n");

	if (wsk_temp != NULL)
	{
		if (wsk_temp->jaka_lista() == "Lista studentów:\n")
		{
			for (int i=0; i<licznik_studentow; i++)
			{
				for (int j=0; j<licznik_studentow-i-1; j++)
				{
					while (wsk_temp->poprz != NULL)
					{
						wsk_temp = (student*)wsk_temp->poprz;
					}

					for (int k=0; k<j; k++)
					{
						wsk_temp = (student*)wsk_temp->nast;
					}
					if (wsk_temp->get_ocena() > wsk_temp->nast->get_ocena() )
					{
						zamiana_student (wsk_temp, (student*)wsk_temp->nast);
					}
				}
			}

			//przenoszenie studentów z ocen¹ 0 na koniec
			while (wsk_temp->poprz != NULL)
			{
				wsk_temp = (student*)wsk_temp->poprz;
			}
			for (int i=0; i<licznik_studentow; i++)
			{
				for (int j=0; j<licznik_studentow-i-1; j++)
				{
					while (wsk_temp->poprz != NULL)
					{
						wsk_temp = (student*)wsk_temp->poprz;
					}
					for (int k=0; k<j; k++)
					{
						wsk_temp = (student*)wsk_temp->nast;
					}
					zamiana_student (wsk_temp, (student*)wsk_temp->nast);
				}
			}
		}
		else
		{
			if (wsk_temp->nast != NULL)
			{
				wsk_temp = (student*)wsk_temp->nast;
			}
		}
	}

	if (licznik_studentow == 0)
	{
		tekst_wysrodkowany (std::string ("Lista studentów jest pusta.\n"));
		system ("pause");
		return NULL;
	}

	while (glowa_studenci_temp->poprz != NULL)
	{
		glowa_studenci_temp = (student*)glowa_studenci_temp->poprz;
	}

	for (int i=0; i<licznik_studentow; i++)
	{
		std::cout << i+1 << ": " << glowa_studenci_temp->get_numer() << " " << glowa_studenci_temp->get_nazwisko() << " " << glowa_studenci_temp->get_ocena() << "\n";
		glowa_studenci_temp = (student*)glowa_studenci_temp->nast;
	}

	system ("pause");

	while (glowa_studenci_temp->poprz != NULL)
	{
		glowa_studenci_temp = (student*)glowa_studenci_temp->poprz;
	}
	return glowa_studenci_temp;
};

pracownik* sortuj_pracownikow (std::string tekst, pracownik *glowa_pracownicy_temp)
{
	system ("cls");
	pracownik *wsk_temp = glowa_pracownicy_temp;
	pracownik *wsk2_temp = NULL;
	tekst_wysrodkowany (tekst+"SORTOWANIE PRACOWNIKÓW:\n\n");

	//szukanie pracowników
	int tablica[100];
	int licznik = 0;
	int licznik2 = 0;
	for (int i=0; i<100; i++)
	{
		tablica[i] = 0;
	}

	if (wsk_temp != NULL)
	{
		while (true)
		{
			if (wsk_temp->jaka_lista() == "Lista pracowników:\n")
			{
				tablica[licznik] = licznik2;
				licznik++;
			}
		
			if (wsk_temp->nast != NULL)
			{
				wsk_temp = (pracownik*)wsk_temp->nast;
				licznik2++;
			}
			else
			{
				break;
			}
		}

		for (int i=0; i<licznik; i++)
		{
			for (int j=0; j<licznik-i-1; j++)
			{
				while (wsk_temp->poprz != NULL)
				{
					wsk_temp = (pracownik*)wsk_temp->poprz;
				}

				for (int k=0; k<tablica[j]; k++)
				{
					wsk_temp = (pracownik*)wsk_temp->nast;
				}
				if (wsk_temp->get_ocena() > wsk_temp->nast->get_ocena() )
				{
					zamiana_pracownik (wsk_temp, (pracownik*)wsk_temp->nast);
				}
			}
		}

		for (int i=0; i<licznik; i++)
		{
			for (int j=0; j<licznik-i-1; j++)
			{
				while (wsk_temp->poprz != NULL)
				{
					wsk_temp = (pracownik*)wsk_temp->poprz;
				}

				for (int k=0; k<tablica[j]; k++)
				{
					wsk_temp = (pracownik*)wsk_temp->nast;
				}
				if (wsk_temp->get_ocena() == 0)
				{
					zamiana_pracownik (wsk_temp, (pracownik*)wsk_temp->nast);
				}
			}
		}



		
		while (wsk_temp->poprz != NULL)
		{
			wsk_temp = (pracownik*)wsk_temp->poprz;
		}
	}

	if (tablica[0] == 0)
	{
		tekst_wysrodkowany (std::string ("Lista pracowników jest pusta.\n"));
		system ("pause");
		return NULL;
	}

	while (glowa_pracownicy_temp->poprz != NULL)
	{
		glowa_pracownicy_temp = (pracownik*)glowa_pracownicy_temp->poprz;
	}

	for (int i=0; i<tablica[0]; i++)
	{
		glowa_pracownicy_temp = (pracownik*)glowa_pracownicy_temp->nast;
	}

	for (int i=0; i<licznik; i++)
	{
		std::cout << i+1 << ": " << glowa_pracownicy_temp->get_numer() << " " << glowa_pracownicy_temp->get_nazwisko() << " " << glowa_pracownicy_temp->get_ocena() << "\n";
		if (glowa_pracownicy_temp->nast != NULL)
		{
			glowa_pracownicy_temp = (pracownik*)glowa_pracownicy_temp->nast;
		}
	}

	system ("pause");

	while (glowa_pracownicy_temp->poprz != NULL)
	{
		glowa_pracownicy_temp = (pracownik*)glowa_pracownicy_temp->poprz;
	}
	return glowa_pracownicy_temp;
};

szablon* oblicz_studentow (std::string tekst, szablon *glowa_szablon)
{
	int liczba_studentow_z_5 = 0;
	int liczba_studentow_z_4_5 = 0;
	int liczba_studentow_z_4 = 0;
	int liczba_studentow_z_3_5 = 0;
	int liczba_studentow_z_3 = 0;
	int liczba_studentow_z_2 = 0;
	

	if (glowa_szablon != NULL)
	{
		while (true)
		{
			if (glowa_szablon->jaka_lista() == "Lista studentów:\n")
			{
				if (glowa_szablon->get_ocena() == 5)
				{
					liczba_studentow_z_5++;
				}
				else if (glowa_szablon->get_ocena() == 4.5)
				{
					liczba_studentow_z_4_5++;
				}
				else if (glowa_szablon->get_ocena() == 4)
				{
					liczba_studentow_z_4++;
				}
				else if (glowa_szablon->get_ocena() == 3.5)
				{
					liczba_studentow_z_3_5++;
				}
				else if (glowa_szablon->get_ocena() == 3)
				{
					liczba_studentow_z_3++;
				}
				else if (glowa_szablon->get_ocena() == 2)
				{
					liczba_studentow_z_2++;
				}
			}

			if (glowa_szablon->nast != NULL)
			{
				glowa_szablon = glowa_szablon->nast;
			}
			else
			{
				break;
			}
		}
	}

	system ("cls");
	tekst_wysrodkowany (tekst+"OBLICZANIE STUDENTÓW:\n\n");
	tekst_wysrodkowany (std::string ("Liczba studentów z ocen¹:\n5.0 - ") + std::to_string (static_cast <unsigned long long> (liczba_studentow_z_5)) + std::string ("\n4.5 - ") + std::to_string (static_cast <unsigned long long> (liczba_studentow_z_4_5)) + std::string ("\n4.0 - ") + std::to_string (static_cast <unsigned long long> (liczba_studentow_z_4)) + std::string ("\n3.5 - ") + std::to_string (static_cast <unsigned long long> (liczba_studentow_z_3_5)) + std::string ("\n3.0 - ") + std::to_string (static_cast <unsigned long long> (liczba_studentow_z_3)) + std::string ("\n2.0 - ") + std::to_string (static_cast <unsigned long long> (liczba_studentow_z_2)) + std::string ("\n"));
	system ("pause");

	while (glowa_szablon->poprz != NULL)
	{
		glowa_szablon = glowa_szablon->poprz;
	}

	return glowa_szablon;
};

szablon* drukuj_pracownikow_i_studentow (std::string tekst, szablon *glowa_szablon)
{
	std::fstream plik1;
	system ("cls");
	tekst_wysrodkowany (tekst+"DRUKOWANIE STUDENTÓW I PRACOWNIKÓW:\n\n");
	plik1 = otworz_plik_do_zapisu();
	int licznik = 0;

	plik1 << "Zarz¹dzanie baz¹  danych  o  wynikach  studentów  i  pracowników" << "\n\nLista studentów:\n\n";
	if (glowa_szablon != NULL)
	{
		plik1 << "Nr indeksu" << std::setw(20) << "Nazwisko" << std::setw(19) << "Ocena\n";
		plik1 << std::setfill('-') << std::setw(53) << "-" << "\n" << std::setfill(' ');
		while (true)
		{
			if (glowa_szablon->jaka_lista() == "Lista studentów:\n")
			{
				licznik++;
				plik1 << std::setw(22) << std::left << glowa_szablon->get_numer();
				plik1 << std::setw(21) << std::left << glowa_szablon->get_nazwisko();
				if (glowa_szablon->get_ocena() != 0)
				{
					plik1 << std::setw(10) << std::left << glowa_szablon->get_ocena();
				}
				else
				{
					plik1 << std::setw(10) << std::left << "Brak oceny";
				}

				if (glowa_szablon->nast != NULL)
				{
					plik1 << "\n";
				}
			}
			if (glowa_szablon->nast != NULL)
			{
				glowa_szablon = glowa_szablon->nast;
			}
			else
			{
				break;
			}
		}
	}
	
	if (licznik == 0)
	{
		plik1 << "Brak studentów.\n";
	}
	
	licznik = 0;
	plik1 << "\n\nLista pracowników:\n\n";
	
	if (glowa_szablon != NULL)
	{
		while (glowa_szablon->poprz != NULL)
		{
			glowa_szablon = glowa_szablon->poprz;
		}
		plik1 << std::setw(22) << "Nr umowy" << std::setw(21) << "Nazwisko" << "Ocena\n";
		plik1 << std::setfill('-') << std::setw(53) << "-" << "\n" << std::setfill(' ');
		while (true)
		{
			if (glowa_szablon->jaka_lista() == "Lista pracowników:\n")
			{
				licznik++;
				plik1 << std::setw(22) << std::left << glowa_szablon->get_numer();
				plik1 << std::setw(21) << std::left << glowa_szablon->get_nazwisko();
				if (glowa_szablon->get_ocena() != 0)
				{
					plik1 << std::setw(10) << std::left << glowa_szablon->get_ocena();
				}
				else
				{
					plik1 << std::setw(10) << std::left << "Brak oceny";
				}

				if (glowa_szablon->nast != NULL)
				{
					plik1 << "\n";
				}
			}
			if (glowa_szablon->nast != NULL)
			{
				glowa_szablon = glowa_szablon->nast;
			}
			else
			{
				break;
			}
		}
	}
	
	if (licznik == 0)
	{
		plik1 << "Brak pracowników.\n";
	}
	plik1 << "\n\nKoniec wydruku.";
	plik1.close();

	std::cout << "Dane do pliku zapisano.\n";
	system ("pause");

	return glowa_szablon;
}

szablon* drukuj_studentow (std::string tekst, szablon *glowa_szablon)
{
	std::fstream plik1;
	int licznik = 0;
	float ocena_temp = 0.0;
	system ("cls");
	tekst_wysrodkowany (tekst+"DRUKOWANIE STUDENTÓW I PRACOWNIKÓW:\n\n");
	tekst_wysrodkowany (std::string ("Proszê podaæ ocenê:\n"));
	//czyszczenie bufora klawiatury
	std::cin.clear();
	std::cin.sync();
	std::cin >> ocena_temp;

	if ((ocena_temp != 2) && (ocena_temp != 3) && (ocena_temp != 3.5) && (ocena_temp != 4) && (ocena_temp != 4.5) && (ocena_temp != 5))
	{
		std::cout << "Podana ocena jest nieprawid³owa, poniewa¿ nie jest ona 2, 3, 3.5, 4, 4.5 lub 5.\n";
		system ("pause");
		return glowa_szablon;
	}

	plik1 = otworz_plik_do_zapisu();
	
	plik1 << "Zarz¹dzanie baz¹  danych  o  wynikach  studentów  i  pracowników" << "\n\nLista studentów z ocen¹ " << ocena_temp << ":\n\n";
	
	if (glowa_szablon != NULL)
	{
		plik1 << "Nr indeksu" << std::setw(20) << "Nazwisko" << std::setw(19) << "Ocena\n";
		plik1 << std::setfill('-') << std::setw(53) << "-" << "\n" << std::setfill(' ');
		
		while (glowa_szablon->poprz != NULL)
		{
			glowa_szablon = glowa_szablon->poprz;
		}

		while (true)
		{
			if (glowa_szablon->jaka_lista() == "Lista studentów:\n")
			{
				if ((glowa_szablon->get_ocena() == ocena_temp) || (glowa_szablon->get_ocena() == 0))
				{
					plik1 << std::setw(22) << std::left << glowa_szablon->get_numer();
					plik1 << std::setw(21) << std::left << glowa_szablon->get_nazwisko();
					if (glowa_szablon->get_ocena() != 0)
					{
						plik1 << std::setw(10) << std::left << glowa_szablon->get_ocena() << "\n";
					}
					else
					{
						plik1 << std::setw(10) << std::left << "Brak oceny" << "\n";
					}
					licznik++;
				}
			}

			if (glowa_szablon->nast != NULL)
			{
				glowa_szablon = glowa_szablon->nast;
			}
			else
			{
				break;
			}
		}
	}
	
	if (licznik == 0)
	{
		plik1 << "¯aden ze studentów nie ma takiej oceny.";
	}
	plik1 << "\nKoniec wydruku.";
	plik1.close();

	while (glowa_szablon->poprz != NULL)
	{
		glowa_szablon = glowa_szablon->poprz;
	}
	
	std::cout << "Dane do pliku zapisano.\n";
	system ("pause");
	return glowa_szablon;
};

void zamiana_student (student *pierwszy, student *drugi)
{
	student *temp = new student;
	temp->set_numer (pierwszy->get_numer() );
	temp->set_nazwisko (pierwszy->get_nazwisko() );
	temp->set_ocena (pierwszy->get_ocena(), false);

	pierwszy->set_numer (drugi->get_numer() );
	pierwszy->set_nazwisko (drugi->get_nazwisko() );
	pierwszy->set_ocena (drugi->get_ocena(), false);

	drugi->set_numer (temp->get_numer() );
	drugi->set_nazwisko (temp->get_nazwisko() );
	drugi->set_ocena (temp->get_ocena(), false);

	delete temp;
};

void zamiana_pracownik (pracownik *pierwszy, pracownik *drugi)
{
	pracownik *temp = new pracownik;
	temp->set_numer (pierwszy->get_numer() );
	temp->set_nazwisko (pierwszy->get_nazwisko() );
	temp->set_ocena (pierwszy->get_ocena(), false);

	pierwszy->set_numer (drugi->get_numer() );
	pierwszy->set_nazwisko (drugi->get_nazwisko() );
	pierwszy->set_ocena (drugi->get_ocena(), false);

	drugi->set_numer (temp->get_numer() );
	drugi->set_nazwisko (temp->get_nazwisko() );
	drugi->set_ocena (temp->get_ocena(), false);

	delete temp;
};

void dodaj (std::string tekst, szablon *glowa_szablon)
{
	system ("cls");
	tekst_wysrodkowany (tekst+"DODAWANIE:\n\n");
	tekst_wysrodkowany (std::string ("1. Dodaj studenta\n2. Dodaj pracownika\n3. Powrót do menu\nProszê wybraæ opcjê: "));
	//czyszczenie bufora klawiatury
	std::cin.clear();
	std::cin.sync();
	int wybor;
	std::cin >> wybor;
	switch (wybor)
	{
		case 1:
			glowa_szablon = nowy_student (tekst, (student*)glowa_szablon);
			glowa_szablon = zapis (glowa_szablon);
			menu (glowa_szablon);
			break;
		case 2:
			glowa_szablon = nowy_pracownik (tekst, (pracownik*)glowa_szablon);
			glowa_szablon = zapis (glowa_szablon);
			menu (glowa_szablon);
			break;
		case 3:
			menu (glowa_szablon);
			break;
		default:
			system ("cls");
			tekst_wysrodkowany (tekst+"Podana liczba / ci¹g znaków nie jest liczb¹ od 1 do 3.");
			system ("pause");
			dodaj (tekst, glowa_szablon);
			break;
	}
};

void usun (std::string tekst, szablon* glowa_szablon)
{
	system ("cls");
	tekst_wysrodkowany (tekst+"USUWANIE:\n\n");
	tekst_wysrodkowany (std::string ("1. Usuñ studenta\n2. Usuñ pracownika\n3. Powrót do menu\nProszê wybraæ opcjê: "));
	//czyszczenie bufora klawiatury
	std::cin.clear();
	std::cin.sync();
	int wybor;
	std::cin >> wybor;
	switch (wybor)
	{
		case 1:
			glowa_szablon = usun_studenta (tekst, (student*)glowa_szablon);
			glowa_szablon = zapis (glowa_szablon);
			menu (glowa_szablon);
			break;
		case 2:
			glowa_szablon = usun_pracownika (tekst, (pracownik*)glowa_szablon);
			glowa_szablon = zapis (glowa_szablon);
			menu (glowa_szablon);
			break;
		case 3:
			menu (glowa_szablon);
			break;
		default:
			system ("cls");
			tekst_wysrodkowany (tekst+"Podana liczba / ci¹g znaków nie jest liczb¹ od 1 do 3.");
			system ("pause");
			usun (tekst, glowa_szablon);
			break;
	}
};

void wpisz (std::string tekst, szablon *glowa_szablon)
{
	system ("cls");
	tekst_wysrodkowany (tekst+"WPISYWANIE OCENY:\n\n");
	tekst_wysrodkowany (std::string ("1. Wpisz ocenê studentowi\n2. Wpisz ocenê pracownikowi\n3. Powrót do menu\nProszê wybraæ opcjê: "));
	//czyszczenie bufora klawiatury
	std::cin.clear();
	std::cin.sync();
	int wybor;
	std::cin >> wybor;
	switch (wybor)
	{
		case 1:
			glowa_szablon = wpisz_ocene_studentowi (tekst, (student*)glowa_szablon);
			glowa_szablon = zapis (glowa_szablon);
			menu (glowa_szablon);
			break;
		case 2:
			glowa_szablon = wpisz_ocene_pracownikowi (tekst, (pracownik*)glowa_szablon);
			glowa_szablon = zapis (glowa_szablon);
			menu (glowa_szablon);
			break;
		case 3:
			menu (glowa_szablon);
			break;
		default:
			system ("cls");
			tekst_wysrodkowany (tekst+"Podana liczba / ci¹g znaków nie jest liczb¹ od 1 do 3.");
			system ("pause");
			wpisz (tekst, glowa_szablon);
			break;
	}
};

void sortuj (std::string tekst, szablon *glowa_szablon)
{
	system ("cls");
	tekst_wysrodkowany (tekst+"SORTOWANIE:\n\n");
	tekst_wysrodkowany (std::string ("1. Sortuj studentów pod wzglêdem ocen rosn¹co\n2. Sortuj pracowników pod wzglêdem ocen rosn¹co\n3. Powrót do menu\nProszê wybraæ opcjê: "));
	//czyszczenie bufora klawiatury
	std::cin.clear();
	std::cin.sync();
	int wybor;
	std::cin >> wybor;
	switch (wybor)
	{
		case 1:
			glowa_szablon = sortuj_studentow (tekst, (student*)glowa_szablon);
			menu (glowa_szablon);
			break;
		case 2:
			glowa_szablon = sortuj_pracownikow (tekst, (pracownik*)glowa_szablon);
			menu (glowa_szablon);
			break;
		case 3:
			menu (glowa_szablon);
			break;
		default:
			system ("cls");
			tekst_wysrodkowany (tekst+"Podana liczba / ci¹g znaków nie jest liczb¹ od 1 do 3.");
			system ("pause");
			sortuj (tekst, glowa_szablon);
			break;
	}
};

void drukuj (std::string tekst, szablon *glowa_szablon)
{
	system ("cls");
	tekst_wysrodkowany (tekst+"DRUKOWANIE DO PLIKU:\n\n");
	tekst_wysrodkowany (std::string ("1. Drukuj do pliku listê studentów i pracowników wraz z ich ocenami\n2. Drukuj do pliku listê studentów z okreœlon¹ ocen¹\n3. Powrót do menu\nProszê wybraæ opcjê: "));
	//czyszczenie bufora klawiatury
	std::cin.clear();
	std::cin.sync();
	int wybor;
	std::cin >> wybor;
	switch (wybor)
	{
		case 1:
			glowa_szablon = drukuj_pracownikow_i_studentow (tekst, glowa_szablon);
			menu (glowa_szablon);
			break;
		case 2:
			glowa_szablon = drukuj_studentow (tekst, glowa_szablon);
			menu (glowa_szablon);
			break;
		case 3:
			menu (glowa_szablon);
			break;
		default:
			system ("cls");
			tekst_wysrodkowany (tekst+"Podana liczba / ci¹g znaków nie jest liczb¹ od 1 do 3.");
			system ("pause");
			drukuj (tekst, glowa_szablon);
			break;
	}
};

void menu (szablon *glowa_szablon)
{
	system ("cls");
	std::string tekst = "Zarz¹dzanie baz¹  danych  o  wynikach  studentów  i  pracowników\nAutor: Pawe³ Roszatycki\n\n";
	tekst_wysrodkowany (tekst+"MENU:\n\n");
	tekst_wysrodkowany (std:: string ("1. Dodaj studenta lub pracownika\n2. Usuñ studenta lub pracownika\n3. Wpisz ocenê studentowi lub pracownikowi\n4. Sortuj studentów lub pracowników\n5. Drukuj listê studentów i pracowników do pliku\n6. Oblicz listê studentów\n7. Wyjœcie do Windows\nProszê wybraæ opcjê: "));
	//czyszczenie bufora klawiatury
	std::cin.clear();
	std::cin.sync();
	int wybor;
	std::cin >> wybor;
	switch (wybor)
	{
		case 1:
			dodaj (tekst, glowa_szablon);
			break;
		case 2:
			usun (tekst, glowa_szablon);
			break;
		case 3:
			wpisz (tekst, glowa_szablon);
			break;
		case 4:
			sortuj (tekst, glowa_szablon);
			break;
		case 5:
			drukuj (tekst, glowa_szablon);
			break;
		case 6:
			glowa_szablon = oblicz_studentow (tekst, glowa_szablon);
			menu (glowa_szablon);
			break;
		case 7:
			exit(0);
			break;
		default:
			system ("cls");
			tekst_wysrodkowany (tekst+"Podana liczba / ci¹g znaków nie jest liczb¹ od 1 do 7.");
			system ("pause");
			menu (glowa_szablon);
			break;
	}
};