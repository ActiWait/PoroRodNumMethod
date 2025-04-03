#pragma once

#include <complex>
#include <cmath>

#define PI 3.14159265358979311600

std::complex<double> F(std::complex<double> s);

double f(double t);

double Real_Part_Func(double t, double sigma, int N, double T);

double Img_Part_Func(double t, double sigma, int N, double T);

double f_N(double t, double sigma, int N, double T);