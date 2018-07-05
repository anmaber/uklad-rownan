#include <iostream>
#include "Wektor.hh"
#include "Macierz.hh"
#include "UkladRownanLiniowych.hh"



using namespace std;


int main()
{


    UkladRownanLiniowych   UklRown;

    cout << endl << " Start programu " << endl << endl;
    cout<<"Wprowadź wspolczynniki układu" <<endl<<endl;

    cin>>UklRown;
    cout<<UklRown;
    cout<<"Rozwiazanie x= (";
    for (int i=0; i<ROZMIAR; ++i)
    {
        cout<<"x"<<i+1<<",";
    }
    cout<<")"<<endl;
    cout<<"\t"<<UklRown.rozwiaz()<<endl<<endl;
    cout<<"Wektor bledu:\t Ax-b = ("<<UklRown.obliczblad()<<")"<<endl<<endl;
    cout<<"Dlugosc wektora bledu ||Ax-b|| = "<<UklRown.obliczdlbl()<<endl;


}
