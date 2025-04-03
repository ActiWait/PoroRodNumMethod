#include "durbin.h"

std::complex<double> F(std::complex<double> s)
{
  return std::complex<double> (120.0/pow(s, 6));
}

double f(double t)
{
  return pow(t, 5);
}

double Real_Part_Func(double t, double sigma, int N, double T) {
    double answer = 0;
    for (int k = 1; k <= N; ++k) {
        answer += F(std::complex<double>(sigma, k*PI/T)).real()*std::cos(k * t * PI / T);
    }
    return answer;
}

double Img_Part_Func(double t, double sigma, int N, double T) {
    double answer = 0;
    for (int k = 1; k <= N; ++k) {
        answer += F(std::complex<double>(sigma, k*PI/T)).imag()*std::sin(k * t * PI / T);
    }
    return answer;
}

double f_N(double t, double sigma, int N, double T) {
    return (std::exp(sigma * t)/T) * (0.5 * F(std::complex<double>(sigma, 0)).real() + Real_Part_Func(t, sigma, N, T) - Img_Part_Func(t, sigma, N, T));
}