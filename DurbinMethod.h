#pragma once

#include <complex>
#include <cmath>

#define PI 3.14159265358979311600


double Real_Part_Func(double t, double sigma, int N, double T, double x, std::complex<double> (*F)(std::complex<double> s,double x));

double Img_Part_Func(double t, double sigma, int N, double T, double x, std::complex<double> (*F)(std::complex<double> s,double x));

double f_N(double t, double sigma, int N, double T, double x, std::complex<double> (*F)(std::complex<double> s,double x));