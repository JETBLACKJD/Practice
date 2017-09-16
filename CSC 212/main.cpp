#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
int powerofint(int somewhat ,int exp);
int main()
{
    int power;
    cout << "   power   pow(2)\n";
    cout << "   -----   ---------";

    for (power = 1 ; power <= 10; power++)
        cout << setw(10) << power<< setw(13) << pow(2.0,power) << '\n';

 return 0;
}
int powerofint(int somewhat ,int exp)
{
    int i;
    int partialval =1;

    for (i=1; i<=exp; i++);
        partialval= partialval * somewhat;
    return partialval;
}
