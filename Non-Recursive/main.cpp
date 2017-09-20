#include<iostream>
using namespace std;

int NRFACT(int n);

int main()
{
    int n;

    cin >> n;

    cout <<  n << " = " << NRFACT(n);

    return 0;
}

int NRFACT(int n)
{
    int i;
    int NRFACT = 1;
    for(i=1; 1<=n; i++)
        {NRFACT = NRFACT * i;
        }
    return 0;


}
