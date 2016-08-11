#pragma once

#include "obiekty.h"
#include <string>

void tekst_wysrodkowany (std::string &podany_tekst);
void zamiana_student (student *pierwszy, student *drugi);
void zamiana_pracownik (pracownik *pierwszy, pracownik *drugi);
student* nowy_student (std::string tekst, student *glowa_studenci_temp);
pracownik* nowy_pracownik (std::string tekst, pracownik *glowa_pracownicy_temp);
student* usun_studenta (std::string tekst, student *glowa_studenci_temp);
pracownik* usun_pracownika (std::string tekst, pracownik *glowa_pracownicy_temp);
student* wpisz_ocene_studentowi (std::string tekst, student *glowa_studenci_temp);
pracownik* wpisz_ocene_pracownikowi (std::string tekst, pracownik *glowa_pracownicy_temp);
student* sortuj_studentow (std::string tekst, student *glowa_studenci_temp);
pracownik* sortuj_pracownikow (std::string tekst, pracownik *glowa_pracownicy_temp);
szablon* oblicz_studentow (std::string tekst, szablon *glowa_szablon);
szablon* drukuj_pracownikow_i_studentow (std::string tekst, szablon *glowa_szablon);
szablon* drukuj_studentow (std::string tekst, szablon *glowa_szablon);
void dodaj (std::string tekst, szablon *glowa_szablon);
void usun (std::string tekst, szablon *glowa_szablon);
void wpisz (std::string tekst, szablon *glowa_szablon);
void sortuj (std::string tekst, szablon *glowa_szablon);
void drukuj (std::string tekst, szablon *glowa_szablon);
void menu (szablon *glowa_szablon);
void zamiana_student (student *pierwszy, student *drugi);
void zamiana_pracownik (pracownik *pierwszy, pracownik *drugi);
int licznik_s (student *glowa_studenci_temp);
int licznik_p (pracownik *glowa_pracownicy_temp);