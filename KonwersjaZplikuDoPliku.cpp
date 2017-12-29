#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <string>

using namespace std;

vector <string> pobierzKontaktyzPlikuZrodlowego(string nazwaPliku)
{
    fstream plik;
    string linia;
    vector <string> pobraneKontakty;
    string pobranyKontakt =  "";
    string rozszerzenie = ".txt";

    string nazwaPlikuZrodlowego = nazwaPliku + rozszerzenie;

    plik.open(nazwaPlikuZrodlowego.c_str(),ios::in);

    if( plik.good()==false)
    {
        cout<<"Plik nie istnieje!";
        exit(0);
    }
    int nr_linii=1;
    int indeks = 0;
    while(getline(plik,linia))
    {
        switch(nr_linii)
        {
        case 1:
            pobranyKontakt += linia + "|";
            break;
        case 2:
            pobranyKontakt += linia + "|";
            break;
        case 3:
            pobranyKontakt += linia + "|";
            break;
        case 4:
            pobranyKontakt += linia + "|";
            break;
        case 5:
            pobranyKontakt += linia + "|";
            break;
        case 6:
            pobranyKontakt += linia + "|";
            break;
        }
        nr_linii++;
        if(nr_linii == 7)
        {
            pobraneKontakty.push_back(pobranyKontakt);
            pobranyKontakt.clear();
            nr_linii= 1;
            indeks++;
        }
    }
    plik.close();

    return pobraneKontakty;
}
void zapiszDaneDoPliku(vector<string> &pobraneKontakty,string nazwaPlikuZrodlowego)
{
    fstream plik;
    string nazwaPlikuWyjsciowego = nazwaPlikuZrodlowego +="_nowy_format.txt";
    plik.open(nazwaPlikuWyjsciowego.c_str(), ios::out);

    if (plik.good())
    {
        for(int x = 0; x<pobraneKontakty.size(); x++)
        {
            plik << pobraneKontakty[x]<<endl;
        }
        pobraneKontakty.clear();
    }
    plik.close();
}
int main()
{
    string nazwaPliku;
    cout<<"Podaj nazwe pliku zrodlowego: "<<endl;
    cin>>nazwaPliku;
    vector<string>kontaktyZPierwotnegoPliku = pobierzKontaktyzPlikuZrodlowego(nazwaPliku);

    zapiszDaneDoPliku(kontaktyZPierwotnegoPliku,nazwaPliku);

    return 0;
}
