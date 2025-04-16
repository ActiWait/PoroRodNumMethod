#include <iostream>
#include "method.h"
#include "durbin.h"

int main() {
    double x = 3;
    double sigma = 0.3;
    int N = 10;
    double T = 10;

    for (int t = 0; t <= 300; t+=10) {
        double f = f_N(t/10000., sigma, N, T, x, u_cap);
        std::cout << "(" << t/10000. << ",\t" << f << ")" << std::endl;
    }

}