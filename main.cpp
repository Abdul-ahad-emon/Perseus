#include <iostream>
#include <iomanip>
#include <cmath>
#include "romberg.h"
#include "simpson.h"

void generate_error_files(double a, double b, double exact);

int main()
{
    double a = 0.0, b = 1.0;
    double exact = 1.0 - cos(1.0);

    auto R = romberg(a, b, 6);

    std::cout << std::fixed << std::setprecision(12);
    std::cout << "Romberg Table:\n";

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j <= i; j++)
            std::cout << R[i][j] << " ";
        std::cout << "\n";
    }

    std::cout << "\nBest Romberg = " << R[5][5] << "\n";
    std::cout << "Exact = " << exact << "\n";
    std::cout << "Error = " << fabs(R[5][5] - exact) << "\n";

    double S = simpson(a, b, 4);
    std::cout << "\nSimpson = " << S << "\n";
    std::cout << "Simpson Error = " << fabs(S - exact) << "\n";

    generate_error_files(a, b, exact);
}
