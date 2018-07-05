#include "Macierz.hh"
using namespace std;

//wykonuje eliminacje gaussa

double Macierz:: gauss()
{
    int i,j,k;
    double p;

    for(i=0; i<(ROZMIAR-1); ++i)
    {
        for(j=i+1; j<ROZMIAR; ++j)
        {
            p=double(tablica[j][i]/tablica[i][i]);
            for(k=0; k<ROZMIAR; ++k)
            {
                tablica[j][k]-=p*tablica[i][k];
            }
        }

    }

    return wyznacznikgaus();
}

// wylicza wyznacznik po sprowadzenu do mac trojkatnej za pomoca eliminacja gausa

double Macierz :: wyznacznikgaus()
{
    double w=1.0;

    for(int i=0; i<ROZMIAR; ++i)
    {
        w*=tablica[i][i];
    }

    return w;
}

// transponuje dana macierz

Macierz Macierz :: transponuj()
{
    Macierz t;
    for (int i=0; i<ROZMIAR; ++i)
    {
        for(int j=0; j<ROZMIAR; ++j)
        {
            t[i][j]=tablica[j][i];

        }
    }
    return t;
}

/*operator przypisania
 *dane wejściowe:
 * referencja do macierzy, macierz
 *zwraca:
 * wskaznik this do macierzy danej referencyjnie
 */

Macierz& Macierz:: operator = (const Macierz &Mac)
{

    for (int i=0; i<ROZMIAR; ++i)
    {
        tablica[i]=Mac[i];
    }
    return *this;
}


/* OPERATORY INDEKSUJACE
 * zwracaja dany element tablicy ktora jest w sekcji private
 */

Wektor Macierz:: operator [] (int indeks)const
{
    return tablica[indeks];
}

Wektor& Macierz:: operator [] (int indeks)
{
    return tablica[indeks];
}

//interfejs do wyznacznika, zabezpiecza przed zmienieniem miejsc w oryginalnej macierzy wspolczynnikow

double Macierz:: wyznacznik() const
{
    Macierz tmp=(*this);

    return tmp.gauss();
}

/* OPERATOR WEJSCIA
 * dane wejsciowe:
 *  referencja do strumienia, referencja do macierzy
 * zwraca strumien wejsciowy
 */

std :: istream& operator >> (std::istream &Strm, Macierz &Mac)
{
    for(int i=0; i<ROZMIAR; ++i)
    {
        Strm>>Mac[i];
    }
    return Strm;
}

/* OPERATOR WYJSCIA
 * dane wejsciowe:
 *  referencja do strumienia, referencja do macierzy(const bo nie zmieniamy nic w jego wartosci)
 * zwraca strumien wyjsciowy
 */


std :: ostream& operator << (std::ostream &Strm, const Macierz &Mac)
{

    for(int i=0; i<ROZMIAR; ++i)
    {

        Strm<<"\t"<<Mac[i]<<std :: endl;
    }
    return Strm;
}

