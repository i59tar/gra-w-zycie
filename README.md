# gra-w-zycie
Gra w życie. Język: C/C++

#changelog

V0.2
- Teraz można w terminalu wprowadzić dodatkowe zmienne:
- - 1. zmienna - decyduje o szerokości tablicy
- - 2. zmienna - decyduje o wysokości tablicy
- - 3. zmienna - decyduje o odstępie czasowym między pokoleniami komórek (w milisekundach)
Zaleca się używania odstępów czasowych większych niż 30 (ms) z powodu 'migotania' ekranu

#Info

- program uruchamiany w terminalu, bez zmiennych
- symulacja Gry w Życie wg. Conwaya:
- - Każda komórka na 2-wymiarowej tablicy ma 2 stany: żywy(1) lub martwy(0)
- - Każda komórka może mieć max. 8 sąsiadów.
- - Jeżeli komórka ma 3 sąsiadów, staje się żywa
- - Jeżeli komórka ma 2 sąsiadów, zachowuje swój poprzedni stan
- - W każdym innym wypadku staje się martwa
- - Symulacja trwa aż do momentu, gdy zdecydujemy się zgasić aplikację


