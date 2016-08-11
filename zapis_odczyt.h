#pragma once

#include "obiekty.h"

szablon* odczyt (szablon *glowa_szablon);
szablon* zapis (szablon *glowa_szablon);
std::fstream otworz_plik_do_zapisu ();
int czy_jest_plik (std::string nazwa_temp);