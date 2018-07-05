#ifndef MACIERZ_HH
#define MACIERZ_HH

#include "rozmiar.h"
#include "Wektor.hh"
#include <iostream>
#include <cmath>

/****************************************************
*                  KLASA MACIERZ                    *
*****************************************************
* Dane skladowe:                                    *
*  - tablica wektorów                               *
* Metody:                                           *
*  -przeksztalcenie do macierzy trojkatnej (gauss)  *
*  -obliczenie wyznacznika z macierzy trojkatnej    *
*  -transponowanie macierzy                         *
*  -obliczanie wyznacznika                          *
*  -przeciazenia operatorów w celu:                 *
*     bezposredniego wczytywania i odczytywania     *
*     danych z tablicy, przypisania macierzy        *
****************************************************/

class Macierz
{
    Wektor tablica[ROZMIAR];
    double gauss();
    double wyznacznikgaus();

public:

    Macierz transponuj();
    double wyznacznik() const;
    Macierz& operator = (const Macierz &Mac);
    Wektor operator [] (int indeks)const;
    Wektor& operator [] (int indeks);
    double operator () (int wiersz,int kolumna)const;

};



std::istream& operator >> (std::istream &Strm, Macierz &Mac);
std::ostream& operator << (std::ostream &Strm, const Macierz &Mac);




#endif
