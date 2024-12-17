#include <stdio.h>
#include <math.h>

// Make this in cpp
// Make this using recursion

double f(float x)
{
    return (x * x * x - x - 1);
}

void main()
{
    float a = 1, b = 2;
    int iteration = 0;
    float root;
    float f0, f1, f2;
    float relError = 0;
    if (f(a) * f(b) > 0)
    {
        printf("wrong guess");
    }

    do
    {
        iteration++;
        f1 = f(a);
        f2 = f(b);
        root = (((a*f2) - (b*f1))/(f2-f1));
        f0 = f(root);
        relError = fabs((a - b) / a);

        if (f1 * f0 < 0)
        {
            b = root;
            f2 = f0;
        }
        else
        {
            a = root;
            f1 = f0;
        }
        printf("\nIteration Number: %d\n", iteration);
        printf("Root = %f\n", root);
        printf("Relative Error = %f \n", relError);

    } while (fabs(f(root)) >= 0.000001);

    printf("\n\nRoot = %f\n", root);
}
