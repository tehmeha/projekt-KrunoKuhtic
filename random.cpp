#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <ctime>
using namespace std;

int generiraj_broj()
{
    srand (time(0));
    return rand () %10+1;

}
int main()
{
int polje2d [11][11];
    for (int i = 1; i < 11; i++)
    {
        for (int j = 1; j < 11; j++)
        {
            polje2d[i][j] = 0;
        }
    }

int redak, stupac;
int postavljene_mine = 0;
    while (postavljene_mine < 20)
    {
        redak = generiraj_broj();
        stupac = generiraj_broj();

        if (polje2d[redak][stupac] != -1)
        {
            polje2d[redak][stupac] = -1;
            postavljene_mine ++;
            cout << postavljene_mine << endl;
        }
    }
        cout << endl;
        cout << "    ";
        for (int i = 1; i < 11; i++)
        {
            cout << i << "   ";
        }
        cout << endl;
        for (int i = 1; i < 43; i++)
        {
            cout << "-" ;
        }
        cout << endl;
        for (int i = 1; i < 11; i++)
        {
            if(i < 10 ) cout << i << " | ";
            else cout << i << "| ";
            for (int j = 1; j < 11; j++)
            {
                if(polje2d[i][j] == -1)
                {
                    cout << "+" << "   ";
                }
                else
                {
                    cout << "-" << "   ";
                }

            }
            cout << endl;
        }
}
