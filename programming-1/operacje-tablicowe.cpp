//Maciej Bajer
#include <iostream>
using namespace std;

int main()
{
    int numOfSessions = 0;
    int i = 0;

    cin >> numOfSessions;

    while (i < numOfSessions)
    {

        int numOfElements = 0;
        cin >> numOfElements;
        int array1[numOfElements];
        int t = 0;
        while (t < numOfElements) {
            cin >> array1[t];
            t = t + 1;
        }

        t = 0;
        while (t < numOfElements) {
            cout << array1[t] << " ";
            t = t + 1;
        }
        cout << endl;

        char operation = ' ';

        while (operation != 'F') {

            cin >> operation;

            if (operation == 'R') {
                int indexR;
                int lengthR;
                int properIndexR;
                int finalIndexR;
                int numOfFragmentsR;
                int jR;
                int tempVariableR = 0;
                int properIndexR1;

                cin >> indexR;
                cin >> lengthR;

                if (lengthR != 0)
                {
                    properIndexR = ((indexR % numOfElements) + numOfElements) % numOfElements;
                    finalIndexR = ((properIndexR + lengthR - 1) % numOfElements) % numOfElements;
                    numOfFragmentsR = (numOfElements / lengthR);

                    while (numOfFragmentsR > 0)
                    {
                        properIndexR1 = properIndexR;
                        jR = 0;
                        while (jR < (lengthR / 2))
                        {
                            tempVariableR = array1[properIndexR];
                            array1[properIndexR] = array1[finalIndexR];
                            array1[finalIndexR] = tempVariableR;

                            properIndexR = (((properIndexR + numOfElements + 1) % numOfElements) + numOfElements) % numOfElements;
                            finalIndexR = (((finalIndexR - 1 + numOfElements) % numOfElements) % numOfElements) % numOfElements;
                            jR = jR + 1;
                        }
                        properIndexR = (((properIndexR1 + lengthR) % numOfElements) + numOfElements) % numOfElements;
                        finalIndexR = (((properIndexR + lengthR - 1) % numOfElements) + numOfElements) % numOfElements;

                        numOfFragmentsR = numOfFragmentsR - 1;
                    }
                }
            }
            else
            {
                if (operation == 'C')
                {
                    int indexC;
                    int lengthC;
                    int properIndexC;
                    int finalIndexC;
                    int numOfFragmentsC;
                    int jC;
                    int tempVariableC = 0;
                    int properIndexC1;

                    cin >> indexC;
                    cin >> lengthC;

                    if (lengthC != 0)
                    {
                        properIndexC = ((indexC % numOfElements) + numOfElements) % numOfElements;
                        finalIndexC = ((properIndexC + lengthC) % numOfElements) % numOfElements;
                        numOfFragmentsC = (numOfElements / lengthC);

                        while ((numOfFragmentsC / 2) > 0)
                        {
                            properIndexC1 = properIndexC;

                            jC = 0;
                            while (jC < lengthC)
                            {
                                tempVariableC = array1[properIndexC];
                                array1[properIndexC] = array1[finalIndexC];
                                array1[finalIndexC] = tempVariableC;

                                properIndexC = (((properIndexC + 1) % numOfElements) + numOfElements) % numOfElements;
                                finalIndexC = (((finalIndexC + 1) % numOfElements) + numOfElements) % numOfElements;

                                jC = jC + 1;
                            }
                            properIndexC = (((properIndexC1 + (2 * lengthC)) % numOfElements) + numOfElements) % numOfElements;
                            finalIndexC = (((finalIndexC + lengthC) % numOfElements) + numOfElements) % numOfElements;
                            numOfFragmentsC = numOfFragmentsC - 2;
                        }
                    }
                }
                else
                {
                    if (operation == 'S')
                    {
                        int indexS;
                        int properIndexS;
                        int lengthS;
                        int absoluteLengthS;
                        int numOfFragmentsS;
                        int restS;
                        int tempVariableS;
                        int kS;
                        int jS;
                        int properIndexS1;

                        cin >> indexS;
                        cin >> lengthS;

                        if (lengthS != 0)
                        {

                            if (lengthS > 0)
                            {
                                absoluteLengthS = lengthS;
                            }
                            if (lengthS < 0)
                            {
                                absoluteLengthS = -(lengthS);
                            }

                            restS = ((numOfElements % absoluteLengthS) + absoluteLengthS) % absoluteLengthS;
                            properIndexS = ((indexS % numOfElements) + numOfElements) % numOfElements;
                            numOfFragmentsS = (numOfElements / absoluteLengthS);

                            while (numOfFragmentsS > 0)
                            {
                                properIndexS1 = properIndexS;
                                if (lengthS > 0)
                                {
                                    kS = 0;
                                    while (kS < (absoluteLengthS - 1))
                                    {
                                        properIndexS = properIndexS1;
                                        jS = 0;
                                        while (jS < (absoluteLengthS - kS - 1))
                                        {
                                            int Index;
                                            int nextIndex = (((properIndexS + 1) % numOfElements) + numOfElements) % numOfElements;
                                            Index = ((properIndexS % numOfElements) + numOfElements) % numOfElements;

                                            if (array1[Index] > array1[nextIndex])
                                            {
                                                tempVariableS = array1[Index];
                                                array1[Index] = array1[nextIndex];
                                                array1[nextIndex] = tempVariableS;
                                            }
                                            properIndexS = (((properIndexS + 1) % numOfElements) + numOfElements) % numOfElements;
                                            jS = jS + 1;
                                        }

                                        kS = kS + 1;
                                    }
                                }
                                if (lengthS < 0)
                                {
                                    kS = 0;
                                    while (kS < (absoluteLengthS - 1))
                                    {
                                        properIndexS = properIndexS1;
                                        jS = 0;
                                        while (jS < (absoluteLengthS - kS - 1))
                                        {
                                            int Index;
                                            int nextIndex = (((properIndexS + 1) % numOfElements) + numOfElements) % numOfElements;
                                            Index = ((properIndexS % numOfElements) + numOfElements) % numOfElements;

                                            if (array1[Index] < array1[nextIndex])
                                            {
                                                tempVariableS = array1[Index];
                                                array1[Index] = array1[nextIndex];
                                                array1[nextIndex] = tempVariableS;
                                            }
                                            properIndexS = (((properIndexS + 1) % numOfElements) + numOfElements ) % numOfElements;
                                            jS = jS + 1;
                                        }

                                        kS = kS + 1;
                                    }
                                }
                                properIndexS = (((properIndexS1 + absoluteLengthS) % numOfElements) + numOfElements) % numOfElements;
                                numOfFragmentsS = numOfFragmentsS - 1;
                            }
                            while (restS > 0)
                            {
                                properIndexS1 = properIndexS;

                                if (lengthS > 0)
                                {
                                    kS = 0;
                                    while (kS < (restS - 1))
                                    {
                                        properIndexS = properIndexS1;
                                        jS = 0;
                                        while (jS < (restS - 1 - kS))
                                        {
                                            int Index;
                                            int nextIndex = (((properIndexS + 1) % numOfElements) + numOfElements) % numOfElements;
                                            Index = ((properIndexS % numOfElements) + numOfElements) % numOfElements;

                                            if (array1[Index] > array1[nextIndex])
                                            {
                                                tempVariableS = array1[Index];
                                                array1[Index] = array1[nextIndex];
                                                array1[nextIndex] = tempVariableS;
                                            }
                                            properIndexS = (((properIndexS + 1) % numOfElements) + numOfElements ) % numOfElements;
                                            jS = jS + 1;
                                        }
                                        kS = kS + 1;
                                    }
                                }
                                if (lengthS < 0)
                                {
                                    kS = 0;
                                    while (kS < (restS - 1))
                                    {
                                        properIndexS = properIndexS1;
                                        jS = 0;
                                        while (jS < (restS - 1 - kS))
                                        {
                                            int Index;
                                            int nextIndex = (((properIndexS + 1) % numOfElements) + numOfElements) % numOfElements;
                                            Index = ((properIndexS % numOfElements) + numOfElements) % numOfElements;

                                            if (array1[Index] < array1[nextIndex])
                                            {
                                                tempVariableS = array1[Index];
                                                array1[Index] = array1[nextIndex];
                                                array1[nextIndex] = tempVariableS;
                                            }
                                            properIndexS = (((properIndexS + 1) % numOfElements) + numOfElements ) % numOfElements;
                                            jS = jS + 1;
                                        }
                                        kS = kS + 1;
                                    }
                                }
                                restS = restS - restS;
                            }

                        }
                    }
                    else
                    {
                        if (operation == 'M')
                        {
                            int indexM;
                            int properIndexM;
                            int lengthM;
                            int moveM;
                            int numOfFragments = 0;
                            int finalIndexM;
                            int tempVariableM;
                            int restM;
                            int properIndexM1;
                            int lengthM1 = 0;
                            int move1;

                            cin >> indexM;
                            cin >> lengthM;
                            cin >> moveM;




                            if (lengthM != 0)
                            {
                                numOfFragments = (numOfElements / lengthM);
                                properIndexM = ((indexM % numOfElements) + numOfElements) % numOfElements;

                                restM = ((numOfElements % lengthM) + lengthM) % lengthM;
                                finalIndexM = (((properIndexM + lengthM - 1) % numOfElements) + numOfElements) % numOfElements;

                                lengthM1 = lengthM;
                                move1 = moveM;
                                int rest1;
                                rest1 = restM;


                                while (numOfFragments > 0)
                                {
                                    if (moveM > 0)
                                    {
                                        properIndexM1 = properIndexM;
                                        moveM = ((moveM % lengthM) + lengthM) % lengthM;
                                        while (moveM > 0)
                                        {
                                            while ((lengthM - 1) > 0)
                                            {

                                                tempVariableM = array1[properIndexM];
                                                array1[properIndexM] = array1[finalIndexM];
                                                array1[finalIndexM] = tempVariableM;

                                                properIndexM = (((properIndexM1 + lengthM - 1) % numOfElements) + numOfElements) % numOfElements;
                                                finalIndexM = (((properIndexM - 1) % numOfElements) + numOfElements) % numOfElements;
                                                lengthM = lengthM - 1;
                                            }

                                            properIndexM = (((properIndexM1) % numOfElements) + numOfElements) % numOfElements;
                                            lengthM = lengthM1;
                                            finalIndexM = (((properIndexM + lengthM - 1) % numOfElements) + numOfElements) % numOfElements;
                                            moveM = moveM - 1;
                                        }

                                        properIndexM = (((properIndexM1 + lengthM) % numOfElements) + numOfElements) % numOfElements;
                                        finalIndexM = (((properIndexM + lengthM - 1) % numOfElements) + numOfElements) % numOfElements;
                                        moveM = move1;
                                    }
                                    if (moveM < 0)
                                    {
                                        properIndexM1 = properIndexM;

                                        int moveLeft1;
                                        moveLeft1 = ((moveM % lengthM) + lengthM) % lengthM;

                                        while ( moveLeft1 > 0)
                                        {
                                            while ((lengthM - 1) > 0)
                                            {

                                                tempVariableM = array1[properIndexM];
                                                array1[properIndexM] = array1[finalIndexM];
                                                array1[finalIndexM] = tempVariableM;

                                                properIndexM = (((properIndexM1 + lengthM - 1) % numOfElements) + numOfElements) % numOfElements;
                                                finalIndexM = (((properIndexM - 1) % numOfElements) + numOfElements) % numOfElements;
                                                lengthM = lengthM - 1;
                                            }

                                            properIndexM = (((properIndexM1) % numOfElements) + numOfElements) % numOfElements;
                                            lengthM = lengthM1;
                                            finalIndexM = (((properIndexM + lengthM - 1) % numOfElements) + numOfElements) % numOfElements;
                                            moveLeft1 = moveLeft1 - 1;
                                        }

                                        properIndexM = (((properIndexM1 + lengthM) % numOfElements) + numOfElements) % numOfElements;
                                        finalIndexM = (((properIndexM + lengthM - 1) % numOfElements) + numOfElements) % numOfElements;
                                        moveM = move1;
                                    }

                                    numOfFragments = numOfFragments - 1;
                                }
                                while (restM > 0)
                                {

                                    if (moveM > 0) {
                                        rest1 = restM;
                                        properIndexM1 = properIndexM;
                                        finalIndexM = (((properIndexM + restM - 1) % numOfElements) + numOfElements) %
                                                     numOfElements;
                                        while (moveM > 0) {
                                            restM = rest1;
                                            while ((restM - 1) > 0) {

                                                tempVariableM = array1[properIndexM];
                                                array1[properIndexM] = array1[finalIndexM];
                                                array1[finalIndexM] = tempVariableM;

                                                properIndexM =
                                                        (((properIndexM1 + restM - 1) % numOfElements) + numOfElements) %
                                                        numOfElements;
                                                finalIndexM = (((properIndexM - 1) % numOfElements) + numOfElements) %
                                                             numOfElements;
                                                restM = restM - 1;
                                            }

                                            properIndexM =
                                                    (((properIndexM1) % numOfElements) + numOfElements) % numOfElements;

                                            finalIndexM =
                                                    (((properIndexM + rest1 - 1) % numOfElements) + numOfElements) %
                                                    numOfElements;
                                            moveM = moveM - 1;
                                        }
                                    }
                                    if (moveM < 0)
                                    {
                                        properIndexM1 = properIndexM;

                                        int moveLeft;
                                        moveLeft = ((moveM % restM) + restM) % restM;
                                        finalIndexM = (((properIndexM + restM - 1) % numOfElements) + numOfElements) %
                                                     numOfElements;

                                        while (moveLeft > 0) {
                                            restM = rest1;
                                            while ((restM - 1) > 0) {

                                                tempVariableM = array1[properIndexM];
                                                array1[properIndexM] = array1[finalIndexM];
                                                array1[finalIndexM] = tempVariableM;

                                                properIndexM =
                                                        (((properIndexM1 + restM - 1) % numOfElements) + numOfElements) %
                                                        numOfElements;
                                                finalIndexM = (((properIndexM - 1) % numOfElements) + numOfElements) %
                                                             numOfElements;
                                                restM = restM - 1;
                                            }

                                            properIndexM =
                                                    (((properIndexM1) % numOfElements) + numOfElements) % numOfElements;
                                            finalIndexM =
                                                    (((properIndexM + rest1 - 1) % numOfElements) + numOfElements) %
                                                    numOfElements;
                                            moveLeft = moveLeft - 1;
                                        }
                                    }
                                    restM = restM - restM;
                                }
                            }
                        }
                    }
                }
            }
        }

        numOfSessions = numOfSessions - 1;
        t = 0;
        while (t < numOfElements)
        {
            cout << array1[t] << " ";
            t = t + 1;
        }
        cout << endl;
    }
    return 0;
}
