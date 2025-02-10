#include <bits/stdc++.h>
using namespace std;

#define paragraph cout << endl

vector<float> xx, yy, zz;

double x(float y, float z)
{
    return (5 - y - z) / 2;
}

double y(float x, float z)
{
    return (15 - (3 * x) - (2 * z)) / 5;
}

double z(float y, float x)
{
    return (8 - (2 * x) - y) / 4;
}

int main()
{
    cout << "Given Equations: " << endl;
    cout << "2x + y + z = 15" << endl
         << "3x + 5y + 2z = 15" << endl
         << "2x + y + 4z = 8" << endl;
    paragraph;

    cout << "Enter Number of iterations: ";
    int it;
    cin >> it;
    xx.resize(it + 1);
    yy.resize(it + 1);
    zz.resize(it + 1);
    xx[0] = 0;
    yy[0] = 0;
    zz[0] = 0;

    cout << "Iteration\tx\ty\tz" << endl;
    int k = 1;
    float xFin = 0, yFin = 0, zFin = 0;
    while (k <= it)
    {
        xx[k] = x(yy[k - 1], zz[k - 1]);
        yy[k] = y(xx[k - 1], zz[k - 1]);
        zz[k] = z(yy[k - 1], xx[k - 1]);
        cout << k << "\t\t" << xx[k] << "\t" << yy[k] << "\t" << zz[k] << endl;
        xFin = xx[k];
        yFin = yy[k];
        zFin = zz[k];
        k++;
    }
    paragraph;

    cout << "x = " << xFin << endl
         << "y = " << yFin << endl
         << "z = " << zFin << endl;
}