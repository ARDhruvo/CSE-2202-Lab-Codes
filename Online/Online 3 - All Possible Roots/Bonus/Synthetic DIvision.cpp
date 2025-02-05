
#include <bits/stdc++.h>
#include <cmath>
using namespace std;

#define paragraph cout << endl

int deg = 0;
vector<float> a; // a is the coefficients of the equations
vector<float> p; // p is for Horner's rule

void printEqn()
{
    for (int i = deg; i >= 1; i--) // For printing the equation
    {
        cout << a[i] << "x^" << i;
        if (a[i - 1] >= 0)
        {
            cout << " + ";
        }
        else
        {
            cout << " ";
        }
    }
    cout << a[0] << "= 0" << endl;
    paragraph;
}

void synthDiv(float xr)
{

    vector<float> b(deg + 1);
    b[deg] = 0;
    for (int k = deg; k > 0; k--)
    {
        b[k - 1] = a[k] + (xr * b[k]);
    }
    for (int k = deg; k >= 0; k--)
    {
        a[k] = b[k];
    }
    deg--;
}

double f(float x)
{
    int k = deg;
    p[deg] = a[deg]; // p(n) = a(n)

    for (k; k > 0; k--)
    {
        p[k - 1] = a[k - 1] + (p[k] * x); // p(n-1) = a(n-1) + (p(n) * x)
    }

    return p[0]; // p(0) is the evaluated expression
}

int main()
{
    cout << "Enter Degree of Equation: ";
    cin >> deg;
    a.resize(deg + 1);
    p.resize(deg + 1);
    for (int i = deg; i >= 0; i--)
    {
        cout << "Enter x^" << i << ": ";
        cin >> a[i]; // a[i] is the coefficient of (i+1)th term in the equation
    }
    paragraph;

    printEqn();
    while (deg)
    {
        cout << "Enter dividend: ";
        float x;
        cin >> x;
        synthDiv(x);
        printEqn();
    }
}
