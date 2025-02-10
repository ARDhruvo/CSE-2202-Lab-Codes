#include <bits/stdc++.h>
using namespace std;

#define paragraph cout << endl

double eval(float c, float i, float j, float k)
{
    return (c - i - j) / k;
}

int main()
{
    cout << "3 variable Jacobi:" << endl;
    cout << "Equation format: ax + by + cz = d" << endl;
    paragraph;

    vector<float> a(4, 0), b(4, 0), c(4, 0), d(4, 0);
    for (int i = 1; i < 4; i++)
    {
        cout << "Enter a, b, c and d of equation " << i << ": ";
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }
    paragraph;

    for (int i = 1; i < 4; i++)
    {
        cout << a[i] << "x + " << b[i] << "y + " << c[i] << "z = " << d[i] << endl;
    }
    paragraph;

    float prevx, prevy, prevz;
    cout << "Enter initial values of x, y and z: ";
    cin >> prevx >> prevy >> prevz;
    float x = prevx, y = prevy, z = prevz;
    paragraph;

    cout << "Enter Number of iterations: ";
    int it;
    cin >> it;
    paragraph;

    cout << "Iteration\tx\t\ty\t\tz" << endl;
    int i = 1;
    for (it; it > 0; it--)
    {
        x = eval(d[1], (b[1] * prevy), (c[1] * prevz), a[1]);
        y = eval(d[2], (c[2] * prevz), (a[2] * prevx), b[2]);
        z = eval(d[3], (a[3] * prevx), (b[3] * prevy), c[3]);
        cout << i++ << "\t\t" << x << "\t\t" << y << "\t\t" << z << endl;
        prevx = x;
        prevy = y;
        prevz = z;
    }
    paragraph;

    cout << "Jacobi Evaluated:" << endl;
    cout << "x = " << x << endl
         << "y = " << y << endl
         << "z = " << z << endl;
}
