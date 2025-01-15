#include <bits/stdc++.h>
#include <cmath>
using namespace std;

#define paragraph cout << endl
#define is ==
#define isnt !=

// vector<float> b;
// vector<float> a;

void printEqn(vector<float> a, int deg) // This isn't perfect. It needs to be worked on later
{
    for (int i = deg - 1; i > 0; i--)
    {
        if (a[i] == 0)
        {
            continue;
        }
        if (a[i] == -1)
        {
            cout << " -";
        }
        else if ((a[i] > 1) || (a[i] < -1))
        {
            if (a[i] < -1)
            {
                cout << " ";
            }
            cout << a[i];
        }
        cout << "x";
        if (i > 1)
        {
            cout << "^" << i;
        }
        if (a[i - 1] >= 0)
        {
            cout << " + ";
        }
    }
    if (a[0] != 0)
    {
        if (a[0] < 0)
        {
            cout << " ";
        }
        cout << a[0];
    }
    cout << " = 0" << endl;
}

float Horner(float x, vector<float> a, int n)
{
    int k = n; // For loop purposes
    vector<float> b(k); // bk represents the new coefficients to be used for calculations
    k--;

    b[k] = a[k]; // b(n) = a(n)
    for (k; k > 0; k--)
    {
        b[k - 1] = a[k - 1] + (b[k] * x); // b(n-1) = a(n-1) + b(n)x
    }

    return b[0]; // b(0) is the evaluated value
}

int main()
{
    int deg;
    cout << "Enter degree of equation: ";
    cin >> deg;
    while (deg < 0) // Degree cannot be negative here
    {
        paragraph;
        cout << "Negative degree not allowed\nPlease try again!\n\nEnter degree of equation: ";
        cin >> deg;
    }
    deg++;
    vector<float> a(deg, 0); // Coefficients of the equation
    paragraph;

    for (int i = 0; i < deg; i++)
    {
        cout << "Enter a" << i << ": ";
        cin >> a[i];
    }
    paragraph;

    cout << "Input Equation:" << endl;
    printEqn(a, deg);
    paragraph;

    float x;
    cout << "Enter x to evaluate: ";
    cin >> x;
    paragraph;

    float res = Horner(x, a, deg);
    cout << "Evaluated result: " << res << endl;
}
