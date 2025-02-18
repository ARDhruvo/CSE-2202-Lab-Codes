#include <bits/stdc++.h>
#include <cmath>
using namespace std;

/*
5
1 0.5
2 2
3 4.5
4 8
5 12.5
 */

#define paragraph cout << endl

vector<float> x, lnx, y, lny, xsq, xy;

float sumX = 0, sumY = 0, sumXSQ = 0, sumXY = 0;

void printTable(int n)
{
    cout << "\tx\ty\tlnx\tlny\tx^2\txy" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << setprecision(5) << "\t" << x[i] << "\t" << y[i] << "\t" << lnx[i] << "\t" << lny[i] << "\t" << xsq[i] << "\t" << xy[i] << endl;
    }
    paragraph;
    cout << "Sum:" << "\t\t\t" << sumX << "\t" << sumY << "\t" << sumXSQ << "\t" << sumXY << endl;
}

void regression(int n)
{
    float denominator = (n * sumXSQ) - pow(sumX, 2);
    if (denominator == 0)
    {
        cout << "Regression Not Possible" << endl;
        return;
    }
    float b = ((n * sumXY) - (sumX * sumY)) / denominator;

    float R = (sumY / n) - (b * (sumX / n));

    float a = exp(R);

    cout << "Required Linear Equation: y = " << a << "x^" << b;
}

int main()
{
    int n;
    cout << "Enter number of points: ";
    cin >> n;
    x.resize(n);
    lnx.resize(n);
    lny.resize(n);
    y.resize(n);
    xsq.resize(n);
    xy.resize(n);
    paragraph;

    cout << "Enter points:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];

        lnx[i] = log(x[i]);
        lny[i] = log(y[i]);
        xsq[i] = pow(lnx[i], 2);
        xy[i] = lnx[i] * lny[i];

        sumX += lnx[i];
        sumY += lny[i];
        sumXSQ += xsq[i];
        sumXY += xy[i];
    }
    paragraph;

    printTable(n);
    paragraph;

    regression(n);
    paragraph;
}
