#include "DurbinMethod.h"


double Real_Part_Func(double t, double sigma, int N, double T, double x, std::complex<double> (*F)(std::complex<double> s,double x)) {
    double answer = 0;
    for (int k = 1; k <= N; ++k) {
        answer += F(std::complex<double>(sigma, k*PI/T), x).real()*std::cos(k * t * PI / T);
    }
    return answer;
}

double Img_Part_Func(double t, double sigma, int N, double T, double x, std::complex<double> (*F)(std::complex<double> s, double x)) { 
    double answer = 0;
    for (int k = 1; k <= N; ++k) {
        answer += F(std::complex<double>(sigma, k*PI/T), x).imag()*std::sin(k * t * PI / T);
    }
    return answer;
}

double f_N(double t, double sigma, int N, double T, double x, std::complex<double> (*F)(std::complex<double> s, double x)) {
    return (std::exp(sigma * t)/T) * (0.5 * F(std::complex<double>(sigma, 0), x).real() + Real_Part_Func(t, sigma, N, T, x, F) - Img_Part_Func(t, sigma, N, T, x, F));
}