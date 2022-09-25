#include <iostream>
#include <string.h>
using namespace std;

#include "algs.h"

int main(void)
{
    string s1;
    string s2;

    cout << "Source string: ";
    cin >> s1;
    cout << "Target string: ";
    cin >> s2;

    cout << endl;
    cout << "Lev Matrix: " << Lev_Matrix(s1, s2) << endl;
    cout << "Dam-Lev Matrix: " << DamLev_Matrix(s1, s2) << endl;
    cout << "Dam-Lev Recursion: " << DamLev_Recursion(s1, s2) << endl;
    cout << "Dam-Lev Recursion with cache: " << DamLev_RecursionWithCache(s1, s2) << endl;

    return 0;
}
