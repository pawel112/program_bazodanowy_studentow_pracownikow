# Program bazodanowy studentów i pracowników

Program umożliwia zarządzanie bazą danych studentów i pracowników uczelni. Baza danych jest przechowywana w pliku "lista.txt".
Przykładowy plik jest w repozytorium.

## Spis treści

1. [Opis wyboru opcji w menu](#menu)
2. [Struktura pliku „lista.txt”](#lista)
3. [Licencja](#licencja)


<a name="menu"></a>
## 1. Opis wyboru opcji w menu:
1 – Dodawanie studenta lub pracownika (liczba całkowita od 1 do 2)<br />
&nbsp;&nbsp;1.1 – Dodawanie studenta<br />
&nbsp;&nbsp;&nbsp;&nbsp;1.1.1. - Podawanie nazwiska studenta (typ tekstu: string)<br />
&nbsp;&nbsp;&nbsp;&nbsp;1.1.2. - Podawanie numeru indeksu studenta (typ tekstu: liczba całkowita, 5 cyfr)<br />
&nbsp;&nbsp;1.2 - Dodawanie pracownika<br />
&nbsp;&nbsp;&nbsp;&nbsp;1.2.1. - Podawanie nazwiska  pracownika (typ tekstu: string)<br />
&nbsp;&nbsp;&nbsp;&nbsp;1.2.2. - Podawanie numeru umowy pracownika (typ tekstu: liczba całkowita, 7 cyfr)<br />
2 – Usuwanie studenta lub pracownika (liczba całkowita od 1 do 2)<br />
&nbsp;&nbsp;1.1 – Usuwanie studenta<br />
&nbsp;&nbsp;&nbsp;&nbsp;1.1.1. - Podawanie numeru indeksu studenta (typ tekstu: liczba całkowita, 5 cyfr)<br />
&nbsp;&nbsp;1.2 - Usuwanie pracownika<br />
&nbsp;&nbsp;&nbsp;&nbsp;1.2.1. - Podawanie numeru umowy pracownika (typ tekstu: liczba całkowita, 7 cyfr)<br />
3 – Wpisywanie oceny studentowi lub pracownikowi (liczba całkowita od 1 do 2)<br />
&nbsp;&nbsp;1.1 –  Wpisywanie oceny studentowi<br />
&nbsp;&nbsp;&nbsp;&nbsp;1.1.1. - Podawanie numeru indeksu studenta (typ tekstu: liczba całkowita, 5 cyfr)<br />
&nbsp;&nbsp;&nbsp;&nbsp;1.1.2. - Podanie oceny studenta (liczba z zakresu: 2, 3, 3.5, 4, 4.5 lub 5)<br />
&nbsp;&nbsp;1.2 - Usuwanie pracownika<br />
&nbsp;&nbsp;&nbsp;&nbsp;1.2.1. - Wpisywanie oceny pracownikowi (typ tekstu: liczba całkowita, 7 cyfr)<br />
&nbsp;&nbsp;&nbsp;&nbsp;1.2.2. - Podanie oceny pracownika (liczba rzeczywista z zakresu od 0 do 5 włącznie)<br />
4 – Sortowanie listy studentów lub pracowników (liczba całkowita od 1 do 2)<br />
&nbsp;&nbsp;1.1 - Sortowanie listy studentów – program sortuje (pokazuję) listę studentów wg ocen od najniższych do najwyższych, studenci bez oceny są na końcu listy<br />
&nbsp;&nbsp;1.2 - Sortowanie listy pracowników - program sortuje (pokazuję) listę pracowników wg ocen od najniższych do najwyższych, pracownicy bez oceny są na końcu listy<br />
5 – Drukowanie do pliku listy studentów i pracowników (liczba całkowita od 1 do 2)<br />
&nbsp;&nbsp;1.1 - Drukowanie do pliku listy studentów i pracowników z ich ocenami<br />
&nbsp;&nbsp;&nbsp;&nbsp;1.1.1. - Podanie nazwy pliku docelowego (typ tekstu: string)<br />
&nbsp;&nbsp;1.2 - Drukowanie do pliku listy studentów tylko z wybraną oceną<br />
&nbsp;&nbsp;&nbsp;&nbsp;1.2.1. - Podanie oceny studentów (liczba z zakresu: 0 (brak oceny), 2, 3, 3.5, 4, 4.5 lub 5)<br />
&nbsp;&nbsp;&nbsp;&nbsp;1.2.2. - Podanie nazwy pliku docelowego (typ tekstu: string)<br />
6 – Obliczenie listy studentów – program oblicza (pokazuje) liczbę studentów nie posiadających oceny oraz posiadających ocenę 2, 3, 3.5, 4, 4.5 oraz 5<br />
7 – Wyjście do systemu Windows – zakończenie pracy programu<br />


<a name="lista"></a>
## 2. Struktura pliku „lista.txt”
Struktura pliku „lista.txt”.<br />
Przykładowy plik z listą znajduje się w archiwum (nazwa pliku „lista.txt”).<br />

napis „Lista studentów:”<br />
numer_indeksu, ImieNazwisko ocena<br />
enter<br />
napis „Lista pracowników:”<br />
numer_umowy, ImieNazwisko ocena<br />
enter<br />

<a name="licencja"></a>
## 3. Licencja
Twórca / twórcy zezwalają każdemu na ściąganie, przeglądanie, modyfikację któregokolwiek plików oraz na publikację plików w tym
projekcie. Wykorzystywanie któregokolwiek pliku lub jego fragmentu w  innych projektach, publicznie udostępnienie pliku lub jego fragmentu, a także inne czynności bez zgody pawel112 jest zabronione.
