#include "UkladRownanLiniowych.hh"

/****Pobieranie macierzy i wektora z sekcji private oraz wpisywanie do nich wartosci*****/

Macierz UkladRownanLiniowych :: pobierzm()const
{
    Macierz tmp=Mac;
    return tmp;
}


Wektor UkladRownanLiniowych :: pobierzw()const
{
    Wektor wol=wolne;
    return wol;
}


Macierz& UkladRownanLiniowych :: pobierzm()
{
    return Mac;
}


Wektor& UkladRownanLiniowych :: pobierzw()
{
    return wolne;
}

//oblicza blad

Wektor UkladRownanLiniowych::obliczblad()
{
    Wektor blad;
    blad=(Mac.transponuj()*rozwiaz())-wolne;
    return blad;
}

//oblicza dlugosc wektora bledu

double UkladRownanLiniowych :: obliczdlbl()
{
    double bladdlugosc;
    bladdlugosc=obliczblad().dlugosc();
    return bladdlugosc;
}

//rozwiazuje uklad rownan

Wektor UkladRownanLiniowych :: rozwiaz()
{
    Wektor rozwiazanie;
    Macierz tmp=pobierzm();
    Wektor wol=pobierzw();
    double w=0;
    w=tmp.wyznacznik();

//zabezpieczenie przed dzieleniem przrz 0

     if(fabs(w)<0)
    {
       cerr<<"wyznacznik glowny wynosi 0, nie umiem rozwiazac rownania";
       exit(1);
    }


    for (int i=0; i<ROZMIAR; i++)
    {

        Macierz tmp=pobierzm();
        tmp[i]=wol;
        rozwiazanie[i]=(tmp.wyznacznik()/w);
    }
    return rozwiazanie;
}


std :: istream& operator >> (std::istream &Strm, UkladRownanLiniowych &UklRown)
{
    Strm>>UklRown.pobierzm();
    Strm>>UklRown.pobierzw();

    return Strm;
}

std :: ostream& operator << ( std::ostream &Strm, const UkladRownanLiniowych &UklRown)
{
    Strm<<"Macierz A^T:"<<endl<<endl;
    Strm<<UklRown.pobierzm()<<endl<<endl;
    Strm<<"Wektor wyrazow wolnych b:"<<endl<<endl;
    Strm<<"\t"<<UklRown.pobierzw()<<endl<<endl;
    return Strm;
}

Wektor operator *( const Macierz &m, const Wektor &w )
{
    Wektor wynik;
    for(int i=0; i<ROZMIAR; ++i)
    {
        wynik[i]=m[i]*w;
    }

    return wynik;
}




