#include "trapezoidal.h"
#include "functions.h"

double trapezoidal(double a, double b, int n)
{
    double h = (b - a) / n;
    double sum = 0.5 * (f(a) + f(b));

    for (int i = 1; i < n; i++)
        sum += f(a + i * h);

    return sum * h;
}
