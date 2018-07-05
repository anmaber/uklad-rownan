#include "Wektor.hh"
#include <math.h>

/*Oblicza długosc wektora
 *dane wejsciowe:
 * wektor
 *zwraca:
 * dlugosc wektora
 */

double Wektor::dlugosc()
{
    return sqrt((*this)*(*this));
}

/* operator dodawania
 * dane wejsciowe:
 *  Wektory
 * zwraca:
 *  sume dwoch wektorow
 */

Wektor Wektor :: operator + (Wektor &Wek)
{
    Wektor wynik;
    for(int i=0; i<ROZMIAR; ++i)
    {
        wynik[i]=Wek[i]+this->tablica[i];
    }
    return wynik;
}

/* operator odejmowania
 * dane wejsciowe:
 *  Wektory
 * zwraca:
 *  roznice dwoch wektorow
 */

Wektor Wektor:: operator - (Wektor &Wek)
{
    Wektor wynik;
    for(int i=0; i<ROZMIAR; ++i)
    {
        wynik[i]=this->tablica[i]-Wek[i];
    }
    return wynik;
}

/*mnożenie wektora razy liczbe
 *dane wejsciowe:
 * wektor, liczba
 * zwraca wektor (iloczyn wektora wejsciowego i liczby)
 */

Wektor Wektor:: operator * (double const &liczba)
{
    Wektor wynik;
    for(int i=0; i<ROZMIAR; ++i)
    {
        wynik[i]=this->tablica[i]*liczba;
    }

    return wynik;
}

/*dzielenie wektora przez liczbe
 *dane wejsciowe:
 * wektor, liczba
 * zwraca wektor (iloraz wektora wejsciowego i liczby)
 */

Wektor Wektor :: operator / (double &liczba)
{
    Wektor wynik;
    for(int i=0; i<ROZMIAR; ++i)
    {
        wynik[i]=this->tablica[i]/liczba;
    }

    return wynik;
}

/*operator przypisania
 *dane wejściowe:
 * referencja do wektora, wektor
 *zwraca:
 * wskaznik this do wektora danego referencyjnie
 */

Wektor& Wektor :: operator = (const Wektor &Wek)
{

    for(int i=0; i<ROZMIAR; ++i)
    {
        tablica[i]=Wek[i];
    }
    return *this;
}


/*iloczyn skalarny
 *dane wejsciowe
 * wektor, wektor
 *zwraca
 *  iloczyn skalarny dwoch wektorow
 */

double Wektor :: operator * (Wektor const &Wek)
{
    double wynik=0;

    for(int i=0; i<ROZMIAR; ++i)
    {
        wynik+=this->tablica[i]*Wek[i];
    }

    return wynik;
}
/* OPERATORY INDEKSUJACE
 * zwracaja dany element tablicy ktora jest w sekcji private
 */

double Wektor:: operator [] (int indeks)const
{
    return tablica[indeks];
}

double& Wektor:: operator [] (int indeks)
{
    return tablica[indeks];
}

/* OPERATOR WEJSCIA
 * dane wejsciowe:
 *  referencja do strumienia, referencja do wektora
 * zwraca strumien wejsciowy
 */

std :: istream& operator >> (std::istream &Strm, Wektor &Wek)
{
    for(int i=0; i<ROZMIAR; ++i)
    {
        Strm>>Wek[i];
    }
    return Strm;
}

/* OPERATOR WYJSCIA
 * dane wejsciowe:
 *  referencja do strumienia, referencja do wektora(const bo nie zmieniamy nic w jego wartosci)
 * zwraca strumien wyjsciowy
 */

std ::ostream& operator << (std::ostream &Strm, const Wektor &Wek)
{

    for(int i=0; i<ROZMIAR; ++i)
    {

        Strm<<Wek[i]<<"\t";
    }
    return Strm;
}


