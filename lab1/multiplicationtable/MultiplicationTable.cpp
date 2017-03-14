//
// Created by Admin on 2017-03-14.
//

#include "MultiplicationTable.h"

void MultiplicationTable(int tab[][10])
{
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            tab[i][j]=(i+1)*(j+1);
        }
    }
}

void Display(int tab[][10])
{
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            cout.width(4);
            cout << tab[i][j];
        }
        cout << endl;
    }
}