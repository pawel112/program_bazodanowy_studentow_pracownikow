# Program bazodanowy studentów i pracowników

Program umożliwia zarządzanie bazą danych studentów i pracowników uczelni. Baza danych jest przechowywana w pliku "lista.txt".
Przykładowy plik jest w repozytorium.


Opis wyboru opcji w menu:
1 – Dodawanie studenta lub pracownika (liczba całkowita od 1 do 2)
  1.1 – Dodawanie studenta
    1.1.1. Podawanie nazwiska studenta (typ tekstu: string)
    1.1.2. Podawanie numeru indeksu studenta (typ tekstu: liczba całkowita, 5 cyfr)
  1.2 Dodawanie pracownika
    1.2.1. Podawanie nazwiska  pracownika (typ tekstu: string)
    1.2.2. Podawanie numeru umowy pracownika (typ tekstu: liczba całkowita, 7 cyfr)
2 – Usuwanie studenta lub pracownika (liczba całkowita od 1 do 2)
  1.1 – Usuwanie studenta
    1.1.1. Podawanie numeru indeksu studenta (typ tekstu: liczba całkowita, 5 cyfr)
  1.2 Usuwanie pracownika
    1.2.1. Podawanie numeru umowy pracownika (typ tekstu: liczba całkowita, 7 cyfr)
3 – Wpisywanie oceny studentowi lub pracownikowi (liczba całkowita od 1 do 2)
  1.1 –  Wpisywanie oceny studentowi
    1.1.1. Podawanie numeru indeksu studenta (typ tekstu: liczba całkowita, 5 cyfr)
    1.1.2. Podanie oceny studenta (liczba z zakresu: 2, 3, 3.5, 4, 4.5 lub 5)
  1.2 Usuwanie pracownika
    1.2.1. Wpisywanie oceny pracownikowi (typ tekstu: liczba całkowita, 7 cyfr)
    1.2.2. Podanie oceny pracownika (liczba rzeczywista z zakresu od 0 do 5 włącznie)
4 – Sortowanie listy studentów lub pracowników (liczba całkowita od 1 do 2)
  1.1 Sortowanie listy studentów – program sortuje (pokazuję) listę studentów wg ocen od najniższych do najwyższych, studenci bez oceny są na końcu listy
  1.2 Sortowanie listy pracowników - program sortuje (pokazuję) listę pracowników wg ocen od najniższych do najwyższych, pracownicy bez oceny są na końcu listy
5 – Drukowanie do pliku listy studentów i pracowników (liczba całkowita od 1 do 2)
  1.1 Drukowanie do pliku listy studentów i pracowników z ich ocenami
    1.1.1. Podanie nazwy pliku docelowego (typ tekstu: string)
  1.2 Drukowanie do pliku listy studentów tylko z wybraną oceną
    1.2.1. Podanie oceny studentów (liczba z zakresu: 0 (brak oceny), 2, 3, 3.5, 4, 4.5 lub 5)
    1.2.2. Podanie nazwy pliku docelowego (typ tekstu: string)
6 – Obliczenie listy studentów – program oblicza (pokazuje) liczbę studentów nie posiadających oceny oraz posiadających ocenę 2, 3, 3.5, 4, 4.5 oraz 5
7 – Wyjście do systemu Windows – zakończenie pracy programu


Struktura pliku „lista.txt”. Przykładowy plik z listą znajduje się w archiwum (nazwa pliku „lista.txt”).
napis „Lista studentów:”
numer_indeksu, ImieNazwisko ocena
enter
napis „Lista pracowników:”
numer_umowy, ImieNazwisko ocena
enter
