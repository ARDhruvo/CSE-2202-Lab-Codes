#include <bits/stdc++.h>
using namespace std;

float prevx1 = 0, prevx2 = 0, prevx3 = 0, prevx4 = 0;

void gaussSeidel(float x1, float x2, float x3, float x4, float absErr)
{
    do
    {
        x1 = (18 - prevx2 - (3 * prevx3) - prevx4) / 5;
        prevx1 = x1;
        x2 = (17 - (prevx1 * 2) - (3 * prevx3) - (2 * prevx4)) / 9;
        prevx2 = x2;
        x3 = (23 - (prevx1) - (2 * prevx2) - (prevx4 * 3)) / 7;
        prevx3 = x3;
        x4 = (14 - prevx1 - prevx2 - (prevx3)) / 3;
        absErr = fabs(x4 - prevx4);
        prevx4 = x4;
    } while (absErr >= 0.001);

    cout << "x1 = " << x1 << endl
         << "x2 = " << x2 << endl
         << "x3 = " << x3 << endl
         << "x4 = " << x4 << endl;
}

int main()
{
    float x1, x2, x3, x4;
    float absErr = 0;

    gaussSeidel(x1, x2, x3, x4, absErr);
}
