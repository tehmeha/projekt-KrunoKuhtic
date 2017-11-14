#include<iostream>
#include<math.h>
using namespace std;

int main()
{
   int polje2d[12][12]={{0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,-1,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,-1,-1,0,0,0},
                        {0,0,0,0,0,0,0,0,0,-1,0,0},
                        {0,0,0,0,-1,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,-1,0,0,0,0,0},
                        {0,0,-1,-1,0,0,0,0,0,0,0,0},
                        {0,0,0,0,-1,-1,0,0,0,0,0,0},
                        {0,0,-1,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0}};
    int polje_br_mina[12][12];
   for(int i = 1; i < 11; i++)
   {
       for(int j = 1; j < 11; j++)
       {
            if( polje2d[i][j] ==-1 )
            {
                cout<< "+" << "   ";
            }
            else
            {
                int broj_mina = fabs(polje2d[i-1][j-1] + polje2d[i][j-1] + polje2d[i+1][j-1] + polje2d[i-1][j] + polje2d[i+1][j] + polje2d[i-1][j+1] + polje2d[i][j+1] + polje2d[i+1][j+1]);
                polje_br_mina[i][j] = broj_mina;
                 cout<<broj_mina << "   ";
            }

       }
       cout << endl;
   }
   while(1)
   {
       cout << endl;
       cout << "   ";
       for (int i = 1; i < 11; i++)
       {
           cout << i << "   ";
       }
       cout << endl;
       for (int i = 1; i < 43; i++)
       {
           cout << "-";
       }
       cout << endl;
       for (int i = 1; i < 11; i++)
       {
           if(i < 10 ) cout << i << " | ";
           else cout << i << "| ";
           for (int j = 1; j < 11; j++)
           {
               if(polje2d[i][j] == 1)
               {
                   cout << polje_br_mina[i][j] << "   ";
               }
               else
               {
                   cout << "-" << "   ";
               }
           }
           cout << endl;
       }
       int redak;
       cout << "redak: ";
       cin >> redak;
       int stupac;
       cout << "stupac: ";
       cin >> stupac;

       if (polje2d[redak][stupac] == -1)
       {
           cout << "GAME OVER!!,sjebo si..."<< endl;
           break;
       }
       else
       {
           polje2d[redak][stupac] = 1;
       }
   }

}

