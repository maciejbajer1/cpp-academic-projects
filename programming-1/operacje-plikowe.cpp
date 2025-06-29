//Maciej Bajer
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct dane {
    int liczba;
    string zdanie;
    string znak;
    struct {
        bool logiczna;
        unsigned int cha;
        float rzeczywista;
    }
    set1, set2, set3, set4;
};

void ladowanieDanych (dane& dane, fstream& plik)
{
    string pomocniczy;
    getline (plik, pomocniczy); 
    getline (plik, dane.zdanie);
    getline (plik, pomocniczy);
    dane.znak = pomocniczy;

    plik >> dane.set1.logiczna;
    plik >> dane.set1.cha;
    plik >> dane.set1.rzeczywista;
    plik >> dane.set2.logiczna;
    plik >> dane.set2.cha;
    plik >> dane.set2.rzeczywista;
    plik >> dane.set3.logiczna;
    plik >> dane.set3.cha;
    plik >> dane.set3.rzeczywista;
    plik >> dane.set4.logiczna;
    plik >> dane.set4.cha;
    plik >> dane.set4.rzeczywista;
}

void doPliku (dane& dane, fstream& plik)
{
    plik << dane.liczba << endl;
    plik << dane.zdanie << endl;
    plik << dane.znak << endl;

    plik << dane.set1.logiczna;
    plik << ' ';
    plik << dane.set1.cha;
    plik << ' ';
    plik << dane.set1.rzeczywista;
    plik << endl;

    plik << dane.set2.logiczna;
    plik << ' ';
    plik << dane.set2.cha;
    plik << ' ';
    plik << dane.set2.rzeczywista;
    plik << endl;

    plik << dane.set3.logiczna;
    plik << ' ';
    plik << dane.set3.cha;
    plik << ' ';
    plik << dane.set3.rzeczywista;
    plik << endl;

    plik << dane.set4.logiczna;
    plik << ' ';
    plik << dane.set4.cha;
    plik << ' ';
    plik << dane.set4.rzeczywista;
    plik << endl;

}

bool czyTakieSame (dane& dane1, dane& dane2)
{
    bool rowne;
    if   (dane1.liczba == dane2.liczba &&
             dane1.zdanie == dane2.zdanie &&
             dane1.znak == dane2.znak &&
             dane1.set1.logiczna == dane2.set1.logiczna &&
             dane1.set1.cha == dane2.set1.cha &&
             dane1.set1.rzeczywista == dane2.set1.rzeczywista &&
             dane1.set2.logiczna == dane2.set2.logiczna &&
             dane1.set2.cha == dane2.set2.cha &&
             dane1.set2.rzeczywista == dane2.set2.rzeczywista &&
             dane1.set3.logiczna == dane2.set3.logiczna &&
             dane1.set3.cha == dane2.set3.cha &&
             dane1.set3.rzeczywista == dane2.set3.rzeczywista &&
             dane1.set4.logiczna == dane2.set4.logiczna &&
             dane1.set4.cha == dane2.set4.cha &&
             dane1.set4.rzeczywista == dane2.set4.rzeczywista)
    {
        rowne = true;
    }
    else
    {
        rowne = false;
    }
    return rowne;
}

void odwrtonySortInt (string plik1, string pomocniczy1, string pomocniczy2)
{
    fstream pierwszy;
    fstream pomoc1;
    fstream pomoc2;

    dane dane1, dane2;

    bool zamiana;

    pierwszy.open(plik1.c_str(), fstream :: in);
    pomoc1.open(pomocniczy1.c_str(), fstream :: out);
    string liniaSortInt1;
    while (getline(pierwszy, liniaSortInt1))
    {
        pomoc1 << liniaSortInt1 << endl;
    }

    pierwszy.close();
    pomoc1.close();

    pierwszy.open(plik1.c_str(), fstream :: out);
    pierwszy.close();

    while (true)
    {
        pomoc1.open(pomocniczy1.c_str(), fstream :: in);
        pomoc2.open(pomocniczy2.c_str(), fstream :: out);

        zamiana = false;

        if (pomoc1 >> dane1.liczba)
        {
            ladowanieDanych(dane1, pomoc1);

            while (pomoc1 >> dane2.liczba)
            {
                ladowanieDanych(dane2, pomoc1);

                if (dane1.liczba < dane2.liczba)
                {
                    doPliku(dane2, pomoc2);
                    zamiana = true;
                }
                else
                {
                    doPliku(dane1, pomoc2);
                    dane1 = dane2;
                }
            }
            doPliku(dane1, pomoc2);
        }
        pomoc1.close();
        pomoc2.close();

        if (zamiana)
        {
            pomoc1.open(pomocniczy1.c_str(), fstream :: out);
            pomoc2.open(pomocniczy2.c_str(), fstream :: in);
            string liniaSortInt2;
            while(getline(pomoc2, liniaSortInt2))
            {
                pomoc1 << liniaSortInt2 << endl;
            }
            pomoc1.close();
            pomoc2.close();
        }
        else
        {
            break;
        }
    }

    pierwszy.open(plik1.c_str(), fstream :: out);
    pomoc1.open(pomocniczy1.c_str(), fstream :: in);
    string liniaSortInt3;
    while(getline(pomoc1, liniaSortInt3))
    {
        pierwszy << liniaSortInt3 << endl;
    }
    pierwszy.close();
    pomoc1.close();

    pomoc1.open(pomocniczy1.c_str(), fstream :: out);
    pomoc1.close();
    pomoc2.open(pomocniczy2.c_str(), fstream :: out);
    pomoc2.close();
}

void liczbaWystapien (string plik1, string pomocniczy1, string pomocniczy2, int& licznikMax, int& maxInt)
{
    fstream pierwszy;
    fstream pomoc1;
    fstream pomoc2;

    dane dane1, dane2;

    int licznik = 1;
    licznikMax = 0;
    maxInt = 0;

    pomoc2.open(pomocniczy2.c_str(), fstream :: out);
    pierwszy.open(plik1.c_str(), fstream :: in);

    string przeniesienie;
    while (getline(pierwszy, przeniesienie))
    {
        pomoc2 << przeniesienie << endl;
    }

    pierwszy.close();
    pomoc2.close();

    pierwszy.open(plik1.c_str(), fstream :: in);

    while ( pierwszy >> dane1.liczba)
    {
        ladowanieDanych(dane1, pierwszy);

        while (pierwszy >> dane2.liczba)
        {
            ladowanieDanych(dane2, pierwszy);


            if (dane1.liczba == dane2.liczba)
            {
                licznik++;


                if(licznik > licznikMax)
                {
                    licznikMax = licznik;
                    maxInt = dane1.liczba;
                }
            }
            if (dane1.liczba < dane2.liczba)
            {
                licznik = 1;
            }
        }
        pierwszy.close();
        pierwszy.open(plik1.c_str(), fstream :: in);

        string linia;
        for (int i = 0; i < 7; i++)
        {
            if (!getline(pierwszy, linia))
            {
                continue;
            }
        }
        pomoc1.open(pomocniczy1.c_str(), fstream :: out);
        while (getline(pierwszy, linia))
        {
            pomoc1 << linia << endl;
        }
        pomoc1.close();

        pierwszy.close();
        pierwszy.open(plik1.c_str(), fstream :: out); 

        pomoc1.open(pomocniczy1.c_str(), fstream :: in);
        while (getline(pomoc1, linia))
        {
            pierwszy << linia << endl;
        }

        pierwszy.close();
        pierwszy.open(plik1.c_str(), fstream :: in);

        pomoc1.close();

        pomoc1.open(pomocniczy1.c_str(), fstream :: out);
        pomoc1.close();
        licznik = 1;

    }

    pierwszy.close();
    pomoc2.open(pomocniczy2.c_str(), fstream :: in);
    pierwszy.open(plik1.c_str(), fstream :: out);

    string przeniesienie2;
    while (getline(pomoc2, przeniesienie2))
    {
        pierwszy << przeniesienie2 << endl;
    }

    pierwszy.close();
    pomoc2.close();

    pomoc2.open(pomocniczy2.c_str(), fstream :: out);
    pomoc2.close();

    pierwszy.open(plik1.c_str(), fstream :: in);
    pierwszy >> dane1.liczba;
    pierwszy.close();

    if (licznikMax == 0)
    {
        licznikMax = 1;
        maxInt = dane1.liczba;

    }
}

void liczbaZestawow (string plik2, int& ileZestawow)
{
    fstream plik;
    dane dane1;
    ileZestawow = 0;
    plik.open(plik2.c_str(), fstream :: in);

    while (plik >> dane1.liczba)
    {
        ladowanieDanych(dane1, plik);
        ileZestawow++;
    }
    plik.close();
}

void liczbaWystapien2 (string plik1, string pomocniczy1, string pomocniczy2, int& licznikMax, int& maxInt)
{
    fstream pierwszy;
    fstream pomoc1;
    fstream pomoc2;

    dane dane1, dane2;

    int licznik = 0;
    licznikMax = 0;
    maxInt = 0;
    int n = 0;
    int iloscZestawow = 0;
    int i = 1;

    liczbaZestawow(plik1, iloscZestawow);

    pierwszy.open(plik1.c_str(), fstream :: in);
    while (pierwszy >> dane1.liczba)
    {
        ladowanieDanych(dane1, pierwszy);
        n++;
        if (i == iloscZestawow)
        {
            pierwszy.close();
            pierwszy.open(plik1.c_str(), fstream:: in);
            i = 0;
        }

        while (pierwszy >> dane2.liczba)
        {

            ladowanieDanych(dane2, pierwszy);
            {
                if (dane1.liczba == dane2.liczba)
                {
                    licznik++;
                    i++;

                    if (licznik > licznikMax)
                    {
                        licznikMax = licznik;
                        maxInt = dane1.liczba;
                    }

                }
                if (dane1.liczba != dane2.liczba)
                {
                    licznik = 0;
                    i++;
                }
            }
        }
        pierwszy.close();
        pierwszy.open(plik1.c_str(), fstream :: in);
        string linia;
        for (int i = 0; i < (7 * n); i++)
        {
            if (!getline(pierwszy, linia))
            {
                continue;
            }
        }
    }
    pierwszy.close();
    pierwszy.open(plik1.c_str(), fstream :: in);
    pierwszy >> dane1.liczba;
    ladowanieDanych(dane1, pierwszy);
    if (licznikMax == 1)
    {
        maxInt = dane1.liczba;
    }
    pierwszy.close();
}

void przenoszenieZnajacLiczbeWystapien (string plik1 , string pomocniczy1, string pomocniczy2)
{
    fstream pierwszy;
    fstream pomoc1;
    fstream pomoc2;

    dane dane1, dane2;

    int ileZestawow = 0;
    int licznikMax = 0;
    int maxInt = 0;
    string linia;

    liczbaWystapien(plik1, pomocniczy1, pomocniczy2, licznikMax, maxInt);
    liczbaZestawow (plik1, ileZestawow);

    pierwszy.open(plik1.c_str(), fstream :: in);
    pomoc1.open(pomocniczy1.c_str(), fstream :: out | fstream :: app);
    pomoc2.open(pomocniczy2.c_str(), fstream :: out | fstream :: app);

    int n = 0;
    int ileZestawow2 = 0;


    while (pierwszy >> dane1.liczba && ileZestawow2 != ileZestawow)
    {
        ladowanieDanych(dane1, pierwszy);

        if (dane1.liczba == maxInt)
        {
            doPliku(dane1, pomoc1);
            n++;
        }
        if (dane1.liczba != maxInt)
        {
            doPliku(dane1, pomoc2);
            n++;
        }
        if ((ileZestawow - ileZestawow2) == n)
        {
            pomoc2.close();
            pomoc1.close();
            pierwszy.close();
            pierwszy.open(plik1.c_str(), fstream::out);
            pomoc2.open(pomocniczy2.c_str(), fstream::in);

            string przeniesienie;
            while (getline(pomoc2, przeniesienie)) {
                pierwszy << przeniesienie << endl;
            }
            pierwszy.close();
            pomoc2.close();
            pomoc2.open(pomocniczy2.c_str(), fstream :: out | fstream :: app);
            pomoc2.close();
            n = 0;
            liczbaWystapien2(plik1, pomocniczy1, pomocniczy2, licznikMax, maxInt);
            liczbaZestawow(pomocniczy1, ileZestawow2);
            pierwszy.close();
            pierwszy.open(plik1.c_str(), fstream :: in);
            pomoc2.open(pomocniczy2.c_str(), fstream :: out);
            pomoc1.open(pomocniczy1.c_str(), fstream :: out | fstream :: app);
        }
    }
    pierwszy.close();
    pomoc1.close();
    pomoc2.close();

    pomoc1.open(pomocniczy1.c_str(), fstream :: in);
    pierwszy.open(plik1.c_str(), fstream :: out);

    string przeniesienie2;
    while (getline(pomoc1, przeniesienie2))
    {
        pierwszy << przeniesienie2 << endl;
    }

    pierwszy.close();
    pomoc1.close();


}

void SortChar (string plik1 , string pomocniczy1, string pomocniczy2)
{
    fstream pierwszy;
    fstream pomoc1;
    fstream pomoc2;

    dane dane1, dane2;

    bool zamiana;

    pierwszy.open(plik1.c_str(), fstream :: in);
    pomoc1.open(pomocniczy1.c_str(), fstream :: out);
    string liniaSortInt1;
    while (getline(pierwszy, liniaSortInt1))
    {
        pomoc1 << liniaSortInt1 << endl;
    }

    pierwszy.close();
    pomoc1.close();

    pierwszy.open(plik1.c_str(), fstream :: out);
    pierwszy.close();

    while (true) {
        pomoc1.open(pomocniczy1.c_str(), fstream::in);
        pomoc2.open(pomocniczy2.c_str(), fstream::out);

        zamiana = false;

        if (pomoc1 >> dane1.liczba) 
        {
            ladowanieDanych(dane1, pomoc1);

            while (pomoc1 >> dane2.liczba) {
                ladowanieDanych(dane2, pomoc1);

                if (dane1.liczba == dane2.liczba && ((dane1.set1.cha + dane1.set2.cha + dane1.set3.cha + dane1.set4.cha) % 256) < ((dane2.set1.cha + dane2.set2.cha + dane2.set3.cha + dane2.set4.cha) % 256)) {
                    doPliku(dane2, pomoc2);
                    zamiana = true;
                } else {
                    doPliku(dane1, pomoc2);
                    dane1 = dane2;
                }
            }
            doPliku(dane1, pomoc2);
        }
        pomoc1.close();
        pomoc2.close();

        if (zamiana) {
            pomoc1.open(pomocniczy1.c_str(), fstream::out);
            pomoc2.open(pomocniczy2.c_str(), fstream::in);
            string liniaSortInt2;
            while (getline(pomoc2, liniaSortInt2)) {
                pomoc1 << liniaSortInt2 << endl;
            }
            pomoc1.close();
            pomoc2.close();
        } else {
            break;
        }
    }

    pierwszy.open(plik1.c_str(), fstream :: out);
    pomoc1.open(pomocniczy1.c_str(), fstream :: in);
    string liniaSortInt3;
    while(getline(pomoc1, liniaSortInt3))
    {
        pierwszy << liniaSortInt3 << endl;
    }
    pierwszy.close();
    pomoc1.close();

    pomoc1.open(pomocniczy1.c_str(), fstream :: out);
    pomoc1.close();
    pomoc2.open(pomocniczy2.c_str(), fstream :: out);
    pomoc2.close();
}

void SortCount (string plik1 , string pomocniczy1, string pomocniczy2)
{
    fstream pierwszy;
    fstream pomoc1;
    fstream pomoc2;

    pomoc1.open(pomocniczy1.c_str(), fstream :: out); 
    pomoc1.close();

    pomoc2.open(pomocniczy1.c_str(), fstream :: out);
    pomoc2.close();

    pierwszy.open(plik1.c_str(), fstream :: in);



    odwrtonySortInt(plik1, pomocniczy1, pomocniczy2);
    przenoszenieZnajacLiczbeWystapien(plik1, pomocniczy1, pomocniczy2);
    SortChar(plik1, pomocniczy1, pomocniczy2);




    pierwszy.close();

    pomoc1.open(pomocniczy1.c_str(), fstream :: out); //na koncu to samo na wszelki wypadek
    pomoc1.close();

    pomoc2.open(pomocniczy1.c_str(), fstream :: out);
    pomoc2.close();

}

void SymmetricDifference (string plik1, string plik2, string pomocniczy)
{
    fstream pierwszy;
    fstream drugi;
    fstream pomoc;

    dane dane1, dane2;
    bool sprawdzenie = false;

    pomoc.open (pomocniczy.c_str(), fstream::out); 
    pomoc.close();

    drugi.open(plik2.c_str(),fstream::in);
    pomoc.open(pomocniczy.c_str(), fstream::out);

    string linia;
    while (getline(drugi, linia)) { 
        pomoc << linia << endl;
    }

    drugi.close();
    pomoc.close();

    drugi.open(plik2.c_str(), fstream::out);  
    drugi.close();

    pomoc.open(pomocniczy.c_str(), fstream::in);


    while (pomoc >> dane1.liczba)  
    {
        ladowanieDanych(dane1, pomoc);
        pierwszy.open (plik1.c_str(), fstream::in);

        while (pierwszy >> dane2.liczba) 
        {
            ladowanieDanych(dane2, pierwszy);

            if (czyTakieSame(dane1, dane2))
            {
                sprawdzenie = true;
            }
        }

        pierwszy.close();

        if (sprawdzenie == false)
        {
            pierwszy.open(plik1.c_str(), fstream::app | fstream::out);
            doPliku(dane1, pierwszy);
            pierwszy.close();
        }
        else
        {
            drugi.open(plik2.c_str(), fstream::app | fstream::out);
            doPliku(dane1, drugi); 
            drugi.close();
        }
        sprawdzenie = false;
    }
    pomoc.close();
    drugi.close();

    pomoc.open(pomocniczy.c_str(), fstream :: out);
}

void SortInt (string plik1, string pomocniczy1, string pomocniczy2)
{
    fstream pierwszy;
    fstream pomoc1;
    fstream pomoc2;

    dane dane1, dane2;

    bool zamiana;

    pierwszy.open(plik1.c_str(), fstream :: in);
    pomoc1.open(pomocniczy1.c_str(), fstream :: out);

    string liniaSortInt1;
    while (getline(pierwszy, liniaSortInt1))
    {
        pomoc1 << liniaSortInt1 << endl;
    }

    pierwszy.close();
    pomoc1.close();

    pierwszy.open(plik1.c_str(), fstream :: out);
    pierwszy.close();

    while (true)
    {
        pomoc1.open(pomocniczy1.c_str(), fstream :: in);
        pomoc2.open(pomocniczy2.c_str(), fstream :: out);

        zamiana = false;

        if (pomoc1 >> dane1.liczba) 
        {
            ladowanieDanych(dane1, pomoc1);

            while (pomoc1 >> dane2.liczba)
            {
                ladowanieDanych(dane2, pomoc1);

                if (dane1.liczba > dane2.liczba)
                {
                    doPliku(dane2, pomoc2);
                    zamiana = true;
                }
                else
                {
                    doPliku(dane1, pomoc2);
                    dane1 = dane2;
                }
            }
            doPliku(dane1, pomoc2);
        }
        pomoc1.close();
        pomoc2.close();

        if (zamiana)
        {
            pomoc1.open(pomocniczy1.c_str(), fstream :: out);
            pomoc2.open(pomocniczy2.c_str(), fstream :: in);
            string liniaSortInt2;
            while(getline(pomoc2, liniaSortInt2))
            {
                pomoc1 << liniaSortInt2 << endl;
            }
            pomoc1.close();
            pomoc2.close();
        }
        else
        {
            break;
        }
    }

    pierwszy.open(plik1.c_str(), fstream :: out);
    pomoc1.open(pomocniczy1.c_str(), fstream :: in);
    string liniaSortInt3;
    while(getline(pomoc1, liniaSortInt3))
    {
        pierwszy << liniaSortInt3 << endl;
    }
    pierwszy.close();
    pomoc1.close();

    pomoc1.open(pomocniczy1.c_str(), fstream :: out);
    pomoc1.close();
    pomoc2.open(pomocniczy2.c_str(), fstream :: out);
    pomoc2.close();
}

void SortString ( string plik1 , string pomocniczy1 , string pomocniczy2)
{
    fstream pierwszy;
    fstream pomoc1;
    fstream pomoc2;

    dane dane1, dane2;

    bool zamiana;

    pierwszy.open(plik1.c_str(), fstream :: in);
    pomoc1.open(pomocniczy1.c_str(), fstream :: out);
    string liniaSortInt1;
    while (getline(pierwszy, liniaSortInt1))
    {
        pomoc1 << liniaSortInt1 << endl;
    }

    pierwszy.close();
    pomoc1.close();

    pierwszy.open(plik1.c_str(), fstream :: out);
    pierwszy.close();

    while (true) {
        pomoc1.open(pomocniczy1.c_str(), fstream::in);
        pomoc2.open(pomocniczy2.c_str(), fstream::out);

        zamiana = false;

        if (pomoc1 >> dane1.liczba)
        {
            ladowanieDanych(dane1, pomoc1);

            while (pomoc1 >> dane2.liczba) {
                ladowanieDanych(dane2, pomoc1);

                if (dane1.zdanie > dane2.zdanie) {
                    doPliku(dane2, pomoc2);
                    zamiana = true;
                } else {
                    doPliku(dane1, pomoc2);
                    dane1 = dane2;
                }
            }
            doPliku(dane1, pomoc2);
        }
        pomoc1.close();
        pomoc2.close();

        if (zamiana) {
            pomoc1.open(pomocniczy1.c_str(), fstream::out);
            pomoc2.open(pomocniczy2.c_str(), fstream::in);
            string liniaSortInt2;
            while (getline(pomoc2, liniaSortInt2)) {
                pomoc1 << liniaSortInt2 << endl;
            }
            pomoc1.close();
            pomoc2.close();
        } else {
            break;
        }
    }

    pierwszy.open(plik1.c_str(), fstream :: out);
    pomoc1.open(pomocniczy1.c_str(), fstream :: in);
    string liniaSortInt3;
    while(getline(pomoc1, liniaSortInt3))
    {
        pierwszy << liniaSortInt3 << endl;
    }
    pierwszy.close();
    pomoc1.close();

    pomoc1.open(pomocniczy1.c_str(), fstream :: out);
    pomoc1.close();
    pomoc2.open(pomocniczy2.c_str(), fstream :: out);
    pomoc2.close();
}




