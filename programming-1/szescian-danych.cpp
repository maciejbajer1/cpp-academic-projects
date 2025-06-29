//Maciej Bajer
#include <iostream>
using namespace std;


int main()
{

    int dlugoscKrawedzi;
    cin >> dlugoscKrawedzi;

    long long szescian [dlugoscKrawedzi] [dlugoscKrawedzi] [dlugoscKrawedzi];

  for (int d = 0; d < dlugoscKrawedzi ; d++){
        for (int h = 0; h < dlugoscKrawedzi; h++){
            for (int w = 0; w < dlugoscKrawedzi; w++){
                cin >> szescian[d] [h] [w];
            }
        }
    }

    char operacja = ' ';
    char wymiar = ' ';
    int i;
    long long macierz [dlugoscKrawedzi][dlugoscKrawedzi];

    while (operacja != 'E') {
        cin >> operacja;

        if (operacja == 'D')
        {

            long long wyznacznik;
            cin >> wymiar;
            cin >> i;

            int rozmiar;
            rozmiar = dlugoscKrawedzi;

            if (wymiar == 'l')
            {
                for (int d = 0; d < dlugoscKrawedzi; d++)
                {
                    for (int w = 0; w < dlugoscKrawedzi; w++)
                    {
                        macierz[d][w] = szescian[d][i][w];
                    }
                }


                int znak = 1; //bo zamiana wierszy

                for (int k = 0; k < rozmiar - 1; k++)
                {
                    if (macierz[k][k] == 0)
                    {
                        int j = 0;
                        for (j = k + 1; j < rozmiar; j++)
                        {
                            if (macierz[j][k] != 0)
                            {
                                bool rownosc = true;

                                for (int i = 0; i < rozmiar; i++)
                                {
                                    if (macierz[j][i] != macierz[k][i])
                                    {
                                        rownosc = false; // mozliwy wyznacznik = 0;!!!!!!!
                                        wyznacznik = 0;
                                        break;
                                    }
                                }

                                if (!rownosc)
                                {
                                    for (int i = 0; i < rozmiar; i++)
                                    {
                                        int temp = macierz[j][i];
                                        macierz[j][i] = macierz[k][i];
                                        macierz[k][i] = temp;
                                    }
                                }

                                znak = -znak;
                                break;
                            }
                        }

                        if (j == rozmiar) 
                        {
                            wyznacznik = 0;
                        }
                    }

                    for (int i = k + 1; i < rozmiar; i++)
                    {
                        for (int j = k + 1; j < rozmiar; j++)
                        {
                            macierz[i][j] = macierz[k][k] * macierz[i][j] - macierz[i][k] * macierz[k][j];
                            if (k != 0)
                            {
                                if (macierz [k - 1][k - 1])
                                macierz[i][j] = macierz [i] [j] / macierz[k - 1][k - 1];
                            }
                        }
                    }
                }

                wyznacznik = znak * macierz[rozmiar - 1][rozmiar - 1];

                cout << wyznacznik;
                cout << endl;
            }


            if (wymiar == 'v')
            {

                for (int h = 0; h < dlugoscKrawedzi; h++)
                {
                    for (int d = 0; d < dlugoscKrawedzi; d++)
                    {
                        macierz[h][d] = szescian[h][d][i];
                    }
                }
                int znak = 1;

                for (int k = 0; k < rozmiar - 1; k++)
                {
                    if (macierz[k][k] == 0)
                    {
                        int j = 0;
                        for (j = k + 1; j < rozmiar; j++)
                        {
                            if (macierz[j][k] != 0)
                            {
                                bool rownosc = true;

                                for (int i = 0; i < rozmiar; i++)
                                {
                                    if (macierz[j][i] != macierz[k][i])
                                    {
                                        rownosc = false; 
                                        wyznacznik = 0;
                                        break;
                                    }
                                }

                                if (!rownosc)
                                {
                                    for (int i = 0; i < rozmiar; i++)
                                    {
                                        int temp = macierz[j][i];
                                        macierz[j][i] = macierz[k][i];
                                        macierz[k][i] = temp;
                                    }
                                }

                                znak = -znak;
                                break;
                            }
                        }

                        if (j == rozmiar)
                        {
                            wyznacznik = 0;
                        }
                    }

                    for (int i = k + 1; i < rozmiar; i++)
                    {
                        for (int j = k + 1; j < rozmiar; j++)
                        {
                            macierz[i][j] = macierz[k][k] * macierz[i][j] - macierz[i][k] * macierz[k][j];
                            if (k != 0)
                            {
                                if (macierz [k - 1][k - 1])
                                    macierz[i][j] = macierz [i] [j] / macierz[k - 1][k - 1];                            }
                        }
                    }
                }

                wyznacznik = znak * macierz[rozmiar - 1][rozmiar - 1];

                cout << wyznacznik;
                cout << endl;
            }


            if (wymiar == 'p')
            {
                for (int d = 0; d < dlugoscKrawedzi; d++)
                {
                    for (int h = 0; h < dlugoscKrawedzi; h++)
                    {
                        macierz[d][h] = szescian[i][d][h];
                    }
                }

                int znak = 1;

                for (int k = 0; k < rozmiar - 1; k++)
                {
                    if (macierz[k][k] == 0)
                    {
                        int j = 0;
                        for (j = k + 1; j < rozmiar; j++)
                        {
                            if (macierz[j][k] != 0)
                            {
                                bool rownosc = true;

                                for (int i = 0; i < rozmiar; i++)
                                {
                                    if (macierz[j][i] != macierz[k][i])
                                    {
                                        rownosc = false;
                                        wyznacznik = 0;
                                        break;
                                    }
                                }

                                if (!rownosc)
                                {
                                    for (int i = 0; i < rozmiar; i++)
                                    {
                                        int temp = macierz[j][i];
                                        macierz[j][i] = macierz[k][i];
                                        macierz[k][i] = temp;
                                    }
                                }

                                znak = -znak;
                                break;
                            }
                        }

                        if (j == rozmiar)
                        {
                           wyznacznik = 0;
                        }
                    }

                    for (int i = k + 1; i < rozmiar; i++)
                    {
                        for (int j = k + 1; j < rozmiar; j++)
                        {
                            macierz[i][j] = macierz[k][k] * macierz[i][j] - macierz[i][k] * macierz[k][j];
                            if (k != 0)
                            {
                                if (macierz [k - 1][k - 1])
                                    macierz[i][j] = macierz [i] [j] / macierz[k - 1][k - 1];                            }
                        }
                    }
                }

                wyznacznik = znak * macierz[rozmiar - 1][rozmiar - 1];

                cout << wyznacznik;
                cout << endl;
            }
        }

        if (operacja == 'C') {
            long long prostopadloscian[32][32][32];
            long long sumaP = 0;

          for (int i = 0; i < dlugoscKrawedzi; i++) {
                for (int j = 0; j < dlugoscKrawedzi; j++) {
                    for (int k = 0; k < dlugoscKrawedzi; k++) {
                        prostopadloscian[i][j][k] = szescian[i][j][k];
                    }
                }
            }

            int l;
            int v;
            int p;
            int h;
            int w;
            int d;

            cin >> l;
            cin >> v;
            cin >> p;

            cin >> h;
            cin >> w;
            cin >> d;


            int wspolczynnikP;
            int wspolczynnikV;
            int wspolczynnikL;

            if (p < dlugoscKrawedzi / 2) {
                wspolczynnikP = 1;
            }
            if (p >= dlugoscKrawedzi / 2) {
                wspolczynnikP = -1;
            }

            if (v < dlugoscKrawedzi / 2) {
                wspolczynnikV = 1;
            }
            if (v >= dlugoscKrawedzi / 2) {
                wspolczynnikV = -1;
            }

            if (l < dlugoscKrawedzi / 2) {
                wspolczynnikL = 1;
            }
            if (l >= dlugoscKrawedzi / 2) {
                wspolczynnikL = -1;
            }
            for (int i = 0; i <= d; i++) {
                for (int j = 0; j <= h; j++) {
                    for (int k = 0; k <= w; k++) {
                        if (p + wspolczynnikP * i >= 0 && p + wspolczynnikP * i < dlugoscKrawedzi &&
                            l + wspolczynnikL * j >= 0 && l + wspolczynnikL * j < dlugoscKrawedzi &&
                            v + wspolczynnikV * k >= 0 && v + wspolczynnikV * k < dlugoscKrawedzi) {
                            sumaP += prostopadloscian[p + wspolczynnikP * i][l + wspolczynnikL * j][v + wspolczynnikV * k];
                        }
                    }
                }
            }
            cout << sumaP;
            cout << endl;
        }
        if (operacja == 'T') {
            long long czworoscian[32][32][32];
            long long sumaC = 0;

            for (int i = 0; i < dlugoscKrawedzi; i++) {
                for (int j = 0; j < dlugoscKrawedzi; j++) {
                    for (int k = 0; k < dlugoscKrawedzi; k++) {
                        czworoscian[i][j][k] = szescian[i][j][k];
                    }
                }
            }

            int l;
            int v;
            int p;
            int e;

            cin >> l;
            cin >> v;
            cin >> p;

            cin >> e;

            int wspolczynnikP;
            int wspolczynnikV;
            int wspolczynnikL;

            if (p < dlugoscKrawedzi / 2) {
                wspolczynnikP = 1;
            }
            if (p >= dlugoscKrawedzi / 2) {
                wspolczynnikP = -1;
            }

            if (v < dlugoscKrawedzi / 2) {
                wspolczynnikV = 1;
            }
            if (v >= dlugoscKrawedzi / 2) {
                wspolczynnikV = -1;
            }

            if (l < dlugoscKrawedzi / 2) {
                wspolczynnikL = 1;
            }
            if (l >= dlugoscKrawedzi / 2) {
                wspolczynnikL = -1;
            }


            for (int i = 0; i <= e; i++) {
                for (int j = 0; j <= e; j++) {
                    for (int k = 0; k <= e; k++) {
                        if (p + wspolczynnikP * i >= 0 && p + wspolczynnikP * i < dlugoscKrawedzi &&
                            l + wspolczynnikL * j >= 0 && l + wspolczynnikL * j < dlugoscKrawedzi &&
                            v + wspolczynnikV * k >= 0 && v + wspolczynnikV * k < dlugoscKrawedzi &&
                            e >= i + j + k) {
                            sumaC += czworoscian[p + wspolczynnikP * i][l + wspolczynnikL * j][v + wspolczynnikV * k];
                        }
                    }
                }

            }
            cout << sumaC;
            cout << endl;
        }

        if (operacja == 'O') {

            long long oktal[32][32][32];
            long long sumaO = 0;

            for (int i = 0; i < dlugoscKrawedzi; i++) {
                for (int j = 0; j < dlugoscKrawedzi; j++) {
                    for (int k = 0; k < dlugoscKrawedzi; k++) {
                        oktal[i][j][k] = szescian[i][j][k];
                    }
                }
            }

            int l;
            int v;
            int p;
            int r;

            cin >> l;
            cin >> v;
            cin >> p;
            cin >> r;

            int wP;
            int wV;
            int wL;

            if (p < dlugoscKrawedzi / 2) {
                wP = 1;
            }
            if (p >= dlugoscKrawedzi / 2) {
                wP = -1;
            }

            if (v < dlugoscKrawedzi / 2) {
                wV = 1;
            }
            if (v >= dlugoscKrawedzi / 2) {
                wV = -1;
            }

            if (l < dlugoscKrawedzi / 2) {
                wL = 1;
            }
            if (l >= dlugoscKrawedzi / 2) {
                wL = -1;
            }

            //i, j, k musza zawierac sie w (-r, r)
            //rownanie okregu 3 wyamiry w warunku


            for (int i = 0; i <= r && i >= -r; i ++){
                for (int j = 0; j <= r && j >= -r; j ++){
                    for (int k = 0; k <= r && k >= -r; k ++){
                        if (p + wP * i >= 0 && p + wP * i < dlugoscKrawedzi &&
                            l + wL * j >= 0 && l + wL * j < dlugoscKrawedzi &&
                            v + wV * k >= 0 && v + wV * k < dlugoscKrawedzi &&
                            (p - (p + wP * i)) * (p - (p + wP * i)) + (l - (l + wL * j)) * (l - (l + wL * j)) + (v - (v + wV * k)) * (v - (v + wV * k)) <= r * r){
                            sumaO += oktal [p + wP * i][l + wL * j][v + wV * k];
                        }
                    }
                }
            }
            cout << sumaO;
            cout << endl;

        }
    }



    return 0;
}
