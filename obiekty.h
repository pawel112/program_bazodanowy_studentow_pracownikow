#pragma once

#include <iostream>

//klasa szablon
class szablon
{
private:
	std::string nazwisko;
	float ocena;
	int numer;
public:
	szablon *nast;
	szablon *poprz;
	
	//metody
	szablon (): nazwisko(""), numer(NULL), ocena(NULL) {}; //konstruktor
	szablon (std::string nazwisko_t, float ocena_t, int numer_t): nazwisko(nazwisko_t), numer(numer_t) { set_ocena(ocena_t, true); }; //konstruktor
	szablon (szablon &szablon_t): nazwisko(szablon_t.nazwisko), numer(szablon_t.numer) { set_ocena(szablon_t.ocena, true); }; //konstruktor
	void set_nazwisko (std::string nazwisko_temp) { this->nazwisko = nazwisko_temp; };
	virtual void set_ocena (float ocena_temp, bool komunikat);
	virtual void set_numer (int numer_temp) { this->numer = numer_temp; };
	std::string get_nazwisko (void) { return this->nazwisko; };
	float get_ocena (void) { return this->ocena; };
	int get_numer (void) { return this->numer; };
	virtual std::string jaka_lista (void) { return "Lista szablonów:\n"; };

	friend class student;
	friend class pracownik;
};

//student
class student: public szablon
{
public:	
	//metody
	student () { set_nazwisko(""); set_ocena(NULL, false); }; //konstruktor
	student (std::string nazwisko_t, float ocena_t, int nr_indeksu_t, bool komunikat_t) { set_numer(nr_indeksu_t); set_nazwisko(nazwisko_t); set_ocena(ocena_t, komunikat_t); }; //konstruktor
	student (student &student_t) { set_numer(student_t.numer); set_nazwisko(student_t.nazwisko); set_ocena(student_t.ocena, true); }; //konstruktor
	void set_ocena (float ocena_temp, bool komunikat);
	void set_numer (int numer_temp);
	std::string jaka_lista (void) { return "Lista studentów:\n"; };

	friend student* dodaj_studenta(int nr_indeksu_temp, std::string nazwisko_temp, float ocena_temp, student *wsk, bool ocena_obowiazkowa, bool komunikat);
};

//pracownik
class pracownik: public szablon
{
public:
	//metody
	pracownik () { set_nazwisko(""); set_ocena(NULL, false); }; //konstruktor
	pracownik (std::string nazwisko_t, float ocena_t, int nr_umowy_t, bool komunikat_t) { set_numer(nr_umowy_t); set_nazwisko(nazwisko_t); set_ocena(ocena_t, komunikat_t); } //konstruktor
	pracownik (pracownik &pracownik_t) { set_numer(pracownik_t.numer); set_nazwisko(pracownik_t.nazwisko); set_ocena(pracownik_t.ocena, true); } //konstruktor
	void set_ocena (float ocena_temp, bool komunikat);
	void set_numer (int numer_temp);
	std::string jaka_lista (void) {  return "Lista pracowników:\n"; };

	friend pracownik* dodaj_pracownika(int nr_umowy_temp, std::string nazwisko_temp, float ocena_temp, pracownik *wsk, bool ocena_obowiazkowa, bool komunikat);
};