
#include <iostream>
#include <math.h>
#include <random>
#include <chrono>
#include <fstream>
using namespace std;

int main ()
{
    int polje2d [12][12];
    int redak, stupac, odluka;
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    default_random_engine generator(seed);
    uniform_int_distribution<int> distribution(1,10);

    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            polje2d[i][j] = 0;
        }
    }

    cout << "Ako zelite spremiti igru napisite 0 za redak. " <<endl;
    cout << "Da li zelite ucitati staru igru (0 - NE, 1 - DA)? ";
    cin >> odluka;
    if(odluka == 1)
    {
        ifstream dat;
        dat.open("minolovac.data", ios::in);
        char c;
        int a;
        for (int i = 0; i < 12; i++)
        {
            for (int j = 0; j < 12; j++)
            {
                dat >> a >> c;
                polje2d[i][j] = a;
            }
        }
        dat.close();
    }
    else
    {
        int postavljanje_mine = 0;
        while (postavljanje_mine < 10)
        {
            redak = distribution(generator);
            stupac = distribution(generator);
            // cout << redak << " " << stupac << endl;

            if (polje2d[redak][stupac] != -1)
            {
                polje2d[redak][stupac] = -1;
                postavljanje_mine ++;
            }
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
    int polje_br_mina [12][12];
    for (int i = 1; i < 11; i++)
    {
        if(i < 10 ) cout << i << " | ";
        else cout << i << "| ";
        for (int j = 1; j < 11; j++)
        {
            if (polje2d[i][j] == -1)
            {
                cout << "+" << "   ";
            }
            else
            {
                int broj_mina = 0;
                if( polje2d [i-1][j-1] == -1) broj_mina++;
                if( polje2d [i][j-1] == -1) broj_mina++;
                if( polje2d [i+1][j-1] == -1) broj_mina++;
                if( polje2d [i-1][j] == -1) broj_mina++;
                if( polje2d [i+1][j] == -1) broj_mina++;
                if( polje2d [i-1][j+1] == -1) broj_mina++;
                if( polje2d [i][j+1] == -1) broj_mina++;
                if( polje2d [i+1][j+1] == -1) broj_mina++;

                polje_br_mina[i][j] = broj_mina;
                cout << broj_mina << "   "; //! ispisuje broj mina u susjedstvu
            }
        }

        cout << endl;
    }
    redak = 0;
    stupac = 0;
    int broj_otvorenih = 0;
    while(1)
    {
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
                if (polje2d[i][j] == 1)
                {
                    cout << polje_br_mina[i][j] << "   ";
                }
                else if(polje2d[i][j] == -1 && redak == i && stupac == j)
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
        if(polje2d[redak][stupac] == -1)
        {
            cout << "GAME OVER!!" << endl;
            break;
        }
        cout << "Unesite redak koji zelite igrati: ";
        cin >> redak;
        if( redak == 0 )
        {
           cout << "Game Saved!" << endl;
           ofstream dat;
           dat.open("minolovac.data");
           for(int i=0;i<12;i++)
           {
               for(int j=0;j<12;j++)
               {
                   dat << polje2d[i][j] << ",";
               }
               dat << endl;
            }
           dat.close();
        }
        cout << "Unesite stupac koji zelite igrati: ";
        cin >> stupac;
        if( polje2d[redak][stupac] != -1 )
        {
            polje2d [redak][stupac] = 1;
            broj_otvorenih ++;
        }
        if(broj_otvorenih >= 90)
        {
            cout << "Igrac je pobjedio" << endl;
            break;
        }

    }
}
