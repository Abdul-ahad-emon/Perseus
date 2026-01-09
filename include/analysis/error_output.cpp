#include <fstream>
#include <cmath>
#include "romberg.h"
#include "simpson.h"

void generate_error_files(double a, double b, double exact)
{
    std::ofstream fRom("error_romberg.csv");
    std::ofstream fSimp("error_simpson.csv");

    fRom << "level,error\n";
    fSimp << "n,error\n";

    auto R = romberg(a, b, 6);

    for (int k = 0; k < 6; k++)
        fRom << k << "," << fabs(R[k][k] - exact) << "\n";

    for (int n = 2; n <= 128; n *= 2)
    {
        double val = simpson(a, b, n);
        fSimp << n << "," << fabs(val - exact) << "\n";
    }
}
