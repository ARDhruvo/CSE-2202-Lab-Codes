#include <bits/stdc++.h>
#include <cmath>
using namespace std;

/*
5
1 3
2 4
3 5
4 6
5 8
 */

#define paragraph cout << endl

vector<float> x, y, xsq, xy;

float sumX = 0, sumY = 0, sumXSQ = 0, sumXY = 0;

void printTable(int n)
{
    cout << "\tx\ty\tx^2\txy" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "\t" << x[i] << "\t" << y[i] << "\t" << xsq[i] << "\t" << xy[i] << endl;
    }
    paragraph;
    cout << "Sum:" << "\t" << sumX << "\t" << sumY << "\t" << sumXSQ << "\t" << sumXY << endl;
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

    float a = (sumY / n) - (b * (sumX / n));

    cout << "Required Linear Equation: y = " << a << " + " << b << "x";
}

int main()
{
    int n;
    cout << "Enter number of points: ";
    cin >> n;
    x.resize(n);
    y.resize(n);
    xsq.resize(n);
    xy.resize(n);
    paragraph;

    cout << "Enter points:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
        xsq[i] = pow(x[i], 2);
        xy[i] = x[i] * y[i];

        sumX += x[i];
        sumY += y[i];
        sumXSQ += xsq[i];
        sumXY += xy[i];
    }
    paragraph;

    printTable(n);
    paragraph;

    regression(n);
    paragraph;
}