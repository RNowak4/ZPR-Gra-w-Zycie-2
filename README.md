# ZPR-Gra-w-Zycie
Szkielet aplikacji.

Autorzy: 
Damian Mazurkiewicz, Radosław Nowak.

Opis:
Szkielet aplikacji zawiera podstawową strukturę klas. Wykorzystuje bibliotekę SDL 2.03. Pokazuje użycie tej biblioteki
( wyświatlanie scenerii i obracających się stworzeń, można poruszać się po planszy używając strzałek ). Użyta jest także biblioteka boost, klasa boost::timer, do odliczania czasu gry.

Kompilacja:

1) Linux

Wymagane biblioteki boost_1_57, SDL 2.0.3, SDL_image 2.0

Kompilacja za pomocą pliku makefile, z głównego katalogu.

2) Windows Visual C++

Pliki projektu Visual Studio C++ znajdują się w katalogu Windows - Visual Studio.

Potrzebna jest instalacja bibliotek:

SDL 2.0.3: https://www.libsdl.org/download-2.0.php (plik SDL2-devel-2.0.3-VC.zip (Visual C++ 32/64-bit)) 
- rozpakować na dysku C.

SDL_Image: https://www.libsdl.org/projects/SDL_image/ (plik S SDL2_image-devel-2.0.0-VC.zip (Visual C++ 32/64-bit)) 
- pliki .lib C:/SDL2-2.0.3/lib/x86
- pliki nagłówkowe C:/SDL2-2.0.3/include
 
Pliki dll z bibliotek SDL są już w folderze z projektem.

Boost: 
-pobierz i rozpakuj http://www.boost.org, potem w terminalu  Visual Studio wpisz 'bootstrap', potem 'bjam.exe - build -type = complete' .
-'bjam.exe --build-type=complete install' (Kopiuje nagłówki i biblioteki do katalogu to C:/Boost)


