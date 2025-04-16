#include <iostream>
#include "NumMethod.h"
#include "DurbinMethod.h"

std::complex<double> sinus(std::complex<double> s, double x) {
    std::complex<double> plus1(1,0);
    return s/(s*s + plus1);
}

int main() {
    double x = 3;
    double sigma = 5;
    int N = 2000;
    double T = 10;
/*     for (int t = 0; t <= 200; t+=1) {
        std::cout << "(" << t/100. <<  ",\t" <<  f_N(t/100.*PI, sigma, N, T, x, sinus) << ")" << std::endl;
    } */

    for (int t = 0; t <= 300; t+=5) {
        double f = f_N(t/10000., sigma, N, T, x, u_cap);
        std::cout << "(" << t/1000. << ",\t" << f << ")" << std::endl;
    }

}