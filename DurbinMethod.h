#pragma once

#include <complex>
#include <cmath>

#define PI 3.14159265358979311600


double Real_Part_Func(const double &t, const double &sigma, int N, const double &T, const double &x, std::complex<double> (*F)(const std::complex<double> &s,double x));

double Img_Part_Func(const double &t, const double &sigma, int N, const double &T, const double &x, std::complex<double> (*F)(const std::complex<double> &s,const double &x));

double f_N(const double &t, const double &sigma, int N, const double &T, const double &x, std::complex<double> (*F)(const std::complex<double> &s,const double &x));