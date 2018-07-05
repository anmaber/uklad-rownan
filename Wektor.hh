#ifndef WEKTOR_HH
#define WEKTOR_HH

#include "rozmiar.h"
#include <iostream>
using namespace std;

/****************************************************
*                  KLASA WEKTOR                     *
*****************************************************
* Dane skladowe:                                    *
*  - tablica liczb zmiennoprzecinkowych             *
* Metody:                                           *
* -oblicznie dlugosci wektora                       *
* -przeci¹zenia operatorów w celu:                  *
*   dodawania, odejmowania, mnozenia wektora        *
*   przez liczbê, ilorazu przez liczbê, przypisania *
*   iloczynu skalarego, bezposredniego wczytywania  *
*   i odczytywania danych z tablicy                 *
****************************************************/

class Wektor {

    double tablica[ROZMIAR];

  public:

      double dlugosc();
      Wektor operator + (Wektor &Wek);
      Wektor operator - (Wektor &Wek);
      Wektor operator * (double const &liczba);
      Wektor operator / (double &liczba);
      Wektor& operator = (const Wektor &Wek);
      double operator * (Wektor const &Wek);
      double operator [] (int indeks)const;
      double& operator [] (int indeks);


};


std::istream& operator >> (std::istream &Strm, Wektor &Wek);
std::ostream& operator << (std::ostream &Strm, const Wektor &Wek);

#endif
