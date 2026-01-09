#include "romberg.h"
#include "trapezoidal.h"
#include <cmath>

std::vector<std::vector<double>> romberg(double a, double b, int maxLevel)
{
    std::vector<std::vector<double>> R(maxLevel, std::vector<double>(maxLevel));

    for (int k = 0; k < maxLevel; k++)
    {
        int n = 1 << k;
        R[k][0] = trapezoidal(a, b, n);

        for (int j = 1; j <= k; j++)
        {
            R[k][j] = R[k][j - 1] +
                      (R[k][j - 1] - R[k - 1][j - 1]) / (pow(4, j) - 1);
        }
    }
    return R;
}
