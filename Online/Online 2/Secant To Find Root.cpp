#include <bits/stdc++.h>
#include <cmath>
using namespace std;

// Find the roots f the equation x^3 - x - 1 = 0 by
// 1. Taking input of the equation's coefficients
// 2. Using Horner's rule to calculate f(x)
// 3. Stopping when the two iterative solutions are correct upto 4 digits

#define paragraph cout << endl

vector<float> a(4); // a is the coefficients of the equations
vector<float> p(4); // p is for Horner's rule

double f(float x)
{
    int k = 4;
    p[3] = a[3]; // p(n) = a(n)

    for (k; k > 0; k--)
    {
        p[k - 1] = a[k-1] + (p[k] * x); // p(n-1) = a(n-1) + (p(n) * x)
    }

    return p[0]; // p(0) is the evaluated expression

}

int main()
{
    for (int i = 0; i < 4; i++)
    {
        cout << "Enter x^" << i << ": ";
        cin >> a[i]; // a[i] is the coefficient of (i+1)th term in the equation
    }
    paragraph;

    for (int i = 3; i >= 1; i--) // For printing the equation
    {
        cout << a[i] << "x^" << i;
        if (a[i-1] >= 0)
        {
            cout << " + ";
        }
        else
        {
            cout << " ";
        }

    }
    cout << a[0] << endl;
    paragraph;;

    float x0, x1, x2, absErr;
    int it = 0;
    cout << "Enter x0 and x1: ";
    cin >> x0 >> x1;
    paragraph;

    // Required Output:
    cout << "Iteration\tx0\tx1\tx2\tAbsolute Error"<< endl;
    do
    {
        it++;
        float f0 = f(x0), f1 = f(x1);
        x2 = ((x0 * f1) - (x1 * f0))/(f1 - f0);
        absErr = fabs((x2 - x1));
        cout << it << "\t\t" << x0 << "\t" << x1 << "\t" << x2 << "\t" << absErr << endl;
        x0 = x1;
        x1 = x2;
    }
    while (absErr >= 0.00001);
}
