#include <bits/stdc++.h>
#include <cmath>
using namespace std;

double f(float x) // Given Equation
{
    // double res = pow(x, 3) - x - 1; // Alt equation
    double res = pow(x, 3) - (2 * x) - 1;
    return res;
}

double g(float x) // Convergent Equation of the given equation; The same equation modified such that LHS has ONLY x
{
    // double res = (((x + 1)/ (pow(x, 2)))+x)/2;
    double res = (pow(x, 3) - 1) / 2;
    return res;
}

int main()
{
    float x0, x1, e, N; // x0 is inital value, e is tolerable error and N is maximum number of iterations
    cout << "Enter Initial Value, Tolerable Error and Maximum Number of Iterations: ";
    cin >> x0 >> e >> N;
    int step = 1; // Step counter for checking iteration number
    do
    {
        step++;       // Updates iteration number
        if (step > N) // If number of iterations is greater than the max number of iterations, the equation will not have a solution in this number of iterations
        {
            cout << "Not Convergent" << endl;
            return 0; // Stops program if its diverging
        }
        x1 = g(x0); // Uses convergent equation to find root
        x0 = x1;    // Updates x0 for the next iteration
    } while (fabs(f(x1)) > e); // Loop stops when f(root) is greater than the desired error

    cout << "Root  = " << x1 << endl;
}
