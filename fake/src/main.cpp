#include <iostream>
#include <string.h>
using namespace std;

#include "../inc/algs.h"

int main(void)
{
    string s1;
    string s2;

    cout << "Source string: ";
    cin >> s1;
    cout << endl << "Target string: ";
    cin >> s2;

    cout << "Dam-Lev Matrix: " << DamLev_Matrix(s1, s2) << endl;

    return 0;
}
