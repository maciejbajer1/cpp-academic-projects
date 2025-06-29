//Maciej Bajer
#include <iostream>
using namespace std;

void bubbleSort( int array[])
{
    int temp = 0;
    for (int i = 0; array[i] != -1; i++)
        for(int j = 0; array[j + 1] != -1; j++)
            if (array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
}

bool Empty (int array[])
{
    if (array[0] == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Nonempty (int array[])
{
    if (array[0] != -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Cardinality (int array[], int* a)
{
    *a = 0;
    for (int i = 0; array[i] != -1; i++)
    {
        (*a)++;
    }
}

bool Element (int a, int array[])
{
    for (int i = 0; array[i] != -1; i++)
    {
        if (array[i] == a)
        {
            return true;
        }
    }
    return false;
}

double Arithmetic (int array[])
{
    double licznik = 0;
    int mianownik = 0;

    if (array[0] == -1)
    {
        return 0;
    }

    for (int i = 0; array[i] != -1; i++)
    {
        licznik = licznik + array[i];
        mianownik++;
    }
    return (licznik / mianownik);
}

double Harmonic (int array[])
{
    double licznik = 0;
    double mianownik = 0;
    if (array[0] == -1)
    {
        return 1;
    }

    for (int i = 0; array[i] != -1; i++)
    {
        licznik++;
        mianownik = mianownik + (1.0 / array[i]);
    }
    return (licznik  / mianownik);
}

void Intersection (int array[], int array2[], int intersection[])
{
    int j = 0;
    for (int i = 0; array[i] != -1; i++)
    {
        if (Element (array[i], array2))
        {
            intersection[j] = array[i];
            j++;
        }
    }
    intersection[j] = -1;
    bubbleSort(intersection);
}

void Union (int array[], int array2[], int sum[])
{
    int j = 0;
    for ( int i = 0; array[i] != -1; i++)
    {
        if (!Element(array[i], array2))
        {
            sum[j] = array[i];
            j++;
        }
        if (Element(array[i], array2))
        {
            sum[j] = array[i];
            j++;
        }
    }
    for (int i = 0; array2[i] != -1; i++){

        if (!Element(array2[i], array))
        {
            sum[j] = array2[i];
            j++;
        }
    }
    sum[j] = -1;
    bubbleSort(sum);
}

void Difference (int array[], int array2[], int diff[])
{
    int j = 0;
    for (int i = 0; array[i] != -1; i++)
    {
        if(!Element (array[i], array2))
        {
            diff[j] = array[i];
            j++;
        }
    }
    diff[j] = -1;
    bubbleSort(diff);
}

void Symmetric (int array[], int array2[], int sym[])
{
    int j = 0;
    for (int i = 0; array[i] != -1; i++)
    {
        if (!Element (array[i], array2))
        {
            sym[j] = array[i];
            j++;
        }
    }
    for (int i = 0; array2[i] != -1; i++)
    {
        if (!Element (array2[i], array))
        {
            sym[j] = array2[i];
            j++;
        }
    }
    sym[j] = -1;
    bubbleSort(sym);
}

bool Subset (int array[], int array2[])
{
    int j = 0;
    int i;
    for (i = 0; array[i] != -1; i++)
    {
        if (Element(array[i], array2))
        {
            j++;
        }
    }
        if (j == i)
        {
            return true;
        }
        else
        {
            return false;
        }
}

bool Equal (int array[], int array2[])
{
    if ( Subset (array, array2) && Subset (array2, array))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Create (int a, int array [], int array2 [])
{
    int j = 0;
    for (int i = 0; i < a; i++)
    {
        if (!Element (array[i], array2) && (array[i] > 0) && (array[i] <= 4095))
        {
            array2[j] = array[i];
            j++;
        }
    }
    array2[j] = -1;
    bubbleSort(array2);
}

void Add (int a, int array[])
{
    int j = 0;
    int temp = 0;
    if (!Element (a, array) && (a > 0) && (a <= 4095))
    {
        for (int i = 0; array[i] != -1; i++)
        {
            j++;
        }

        temp = array[j];
        array [j] = a;
        a = temp;
        array[j + 1] = -1;

        bubbleSort(array);
    }
}

void Complement (int array[], int array2[])
{
    int j = 0;
    for (int i = 1; i <= 4095; i++)
    {
        if(!Element (i, array))
        {
            array2[j] = i;
            j++;
        }
    }
    array2[j] = -1;
    bubbleSort(array2);
}

void MinMax (int array[], int* min, int &max)
{
    if (array[0] == -1)
    {
        return ;
    }

    *min = array[0];
    max = array[0];

    for (int i = 0; array[i] != -1; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
        if (array[i] < *min)
        {
            *min = array[i];
        }
    }
    return;
}

void Properties (int array[], char cg [], double &art, double *har, int &mini, int* maksy, int &moc)
{
    for (int i = 0; cg[i] != 0; i++)
    {
        if (cg[i] == 'a')
        {
            art = Arithmetic(array);
        }
        if (cg[i] == 'h')
        {
            *har = Harmonic(array);
        }
        if (cg[i] == 'm')
        {
            MinMax(array, &mini, *maksy);
        }
        if (cg[i] == 'c')
        {
            Cardinality(array, &moc);
        }
    }
    return;
}


