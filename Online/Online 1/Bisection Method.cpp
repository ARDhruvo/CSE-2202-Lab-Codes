#include <bits/stdc++.h>
#include <cmath>
using namespace std;

float f(float x)
{
    float res = pow(x,5) - (27 * pow(x, 3)) + 30.5;
    return res;
}

int main()
{
    float x1 = 5, x2 = 6;
    float root = x1;
    // float root;
    float f0, relError = 0;
    float f1 = f(x1);
    float f2 = f(x2);
    int iteration = 0;
    if((f1 * f2) >= 0)
    {
        cout << "Wrong Guess" << endl;
    }
    else
    {
        do
        {
            iteration++;
            float rootPrev = root;
            cout << rootPrev << endl;
            root = (x1+x2)/2;
            f1 = f(x1);
            f2 = f(x2);
            f0 = f(root);
            string cng;
            relError = fabs((root - rootPrev)/rootPrev);

            if((f1 * f0) > 0)
            {
                x1 = root;
                cng = "Lower Limit";
            }
            else
            {
                x2 = root;
                cng = "Upper Limit";
            }
            cout << "Number of iteration: " << iteration <<  " Lower Limit: " << x1<< " Upper Limit: " << x2 << " Root: " << root << " Limit Change: " << cng << endl;
            cout << endl;
        } while (relError >= 0.0005);

    }
}
