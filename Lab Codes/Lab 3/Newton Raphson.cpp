#include <bits/stdc++.h>
#include <cmath>
using namespace std;

double f(float x) // Given Equation
{
    // double res = pow(x, 3) - x - 1; // Alt equation
    double res = pow(x, 3) - (2 * x) - 1;
    return res;
}

double f_der(float x) // Differentiation of the given equation with respect to x
{
    // double res = (3 * pow(x, 2)) - 1;
    double res = (3 * pow(x, 2)) - 2;
    return res;
}

int main()
{
    float x0, e; // x0 is initial value and e is the error for stopping criteria
    cout << "Enter Initial Value and Tolerable Error: ";
    cin >> x0 >> e;
    float f1 = f(x0); // Setting an initial value of f1 for the loop
    do
    {
        if (f_der(x0) == 0) // If derivative of the given equation is 0 then the value in the iteration will be infinity
        {
            cout << "Mathematical Error" << endl;
            return 0; // Ends program if the value is 0
        }
        float x1 = x0 - (f(x0) / f_der(x0)); // Formula for Newton Raphson's Iteration
        x0 = x1;                             // Updates x0 as root and for the next iteration and
        f1 = fabs(f(x1));                    // Takes absolute value of f(x1)
    } while (f1 > e);

    cout << "Root  = " << x0 << endl;
}
