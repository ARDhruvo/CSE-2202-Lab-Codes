#include <bits/stdc++.h>
#include <cmath>
using namespace std;

double f(float x) // Given Equation
{
    // double res = pow(x, 3) - x - 1; // Alt equation
    double res = pow(x, 3) - (2 * x) - 1;
    return res;
}

int main()
{
    float x0, x1, x2, e, relErr; // x0 and x1 are initial values, e is tolerable error and relErr is Relative Error
    cout << "Enter Initial Values and Tolerable Error: ";
    cin >> x0 >> x1 >> e;
    do
    {
        float f0 = f(x0), f1 = f(x1);             // Function values for the ease of calculation
        x2 = ((x0 * f1) - (x1 * f0)) / (f1 - f0); // Formula for Secant method where x2 is root; f1 and f0 can be replaced wit f(x1) and f(x0) respectively
        relErr = fabs((x2 - x1) / x2);            // Finding out the relative error to continue loop
        x0 = x1;                                  // Updating x0 with x1 for next iteration
        x1 = x2;                                  // Updating x1 with x2 for next iteration
    } while (relErr > e);

    cout << "Root  = " << x2 << endl;
}
