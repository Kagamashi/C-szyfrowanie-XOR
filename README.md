# C-szyfrowanie-XOR
Opis projektu. 
Szyfrowanie polega na poddawaniu operacji XOR danego bajtu z wynikiem szyfrowania bajtu poprzedniego i kluczem (liczba 0-255).

Do szyfrowania pierwszego bajtu używany jest klucz i wektor inicjalizujący (0xAA), gdyż wynik poprzedniego szyfrowania nie jest dostępny.

Przykład (prezentacja szesnastkowa): 
Plik źródłowy - przed szyfrowaniem:
54 6f 20 6a 65 73 74

Plik wynikowy - po szyfrowaniu z kluczem 123 (7B szesnastkowo):
85 91 ca db c5 cd c2
