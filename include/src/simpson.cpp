#include "simpson.h"
#include "functions.h"

double simpson(double a, double b, int n)
{
    if (n % 2 != 0) n++;

    double h = (b - a) / n;
    double sum = f(a) + f(b);

    for (int i = 1; i < n; i++)
    {
        double x = a + i * h;
        if (i % 2 == 0) sum += 2 * f(x);
        else sum += 4 * f(x);
    }

    return sum * h / 3.0;
}
