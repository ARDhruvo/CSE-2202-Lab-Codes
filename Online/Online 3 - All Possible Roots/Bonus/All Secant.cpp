
#include <bits/stdc++.h>
#include <cmath>
using namespace std;

#define paragraph cout << endl

int deg = 0;
bool imaginary = false;
vector<float> a;  // a is the coefficients of the equations
vector<float> p;  // p is for Horner's rule
set<float> roots; // p is for Horner's rule

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
    cout << a[0] << endl;
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

bool complexCheck()
{
    double p = pow((a[deg - 1] / a[deg]), 2);
    double q = 2 * (a[deg - 2] / a[deg]);
    if ((p - q) < 0)
    {
        return true;
    }
    return false;
}

double searchBracket()
{
    double p = pow((a[deg - 1] / a[deg]), 2);
    double q = 2 * (a[deg - 2] / a[deg]);
    return pow((p - q), 0.5);
}

void secant()
{
    while (deg > 1)
    {
        imaginary = complexCheck();
        if (imaginary)
        {
            cout << "There are Imaginary Roots" << endl;
            return;
        }
        float xd = .001;
        float x0 = -searchBracket();
        float xm = searchBracket();
        float x1 = x0 + xd;

        float x2, absErr;

        while ((f(x0) * f(x1)) >= 0)
        {
            if (x1 > xm)
            {
                break;
            }
            x0 = x1;
            x1 = x0 + xd;
        }

        paragraph;

        do
        {
            float f0 = f(x0), f1 = f(x1);             // Function values for the ease of calculation
            x2 = ((x0 * f1) - (x1 * f0)) / (f1 - f0); // Formula for Secant method where x2 is root; f1 and f0 can be replaced wit f(x1) and f(x0) respectively
            absErr = fabs((x2 - x1));                 // Finding out the relative error to continue loop
            x0 = x1;                                  // Updating x0 with x1 for next iteration
            x1 = x2;                                  // Updating x1 with x2 for next iteration
        } while (absErr > 0.00001);
        roots.insert(x2);
        synthDiv(x2);
        printEqn();
    }
    float x0 = (-a[0]) / a[1];
    roots.insert(x0);
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

    secant();

    cout << "Roots using secant: " << endl;
    for (auto i : roots)
    {
        cout << i << "\t";
    }
}
