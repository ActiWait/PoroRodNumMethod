#pragma once

#include <cmath>
#include <complex>

#define PI 3.14159265358979311600

const double K = 2.1e8;
const double G = 9.8e7;
const double ro = 1884;
const double K_s = 1.1e10;
const double ro_f = 1000;
const double K_f = 3.3e9;
const double k = 3.55e-9;
const double fi = 0.5;
const double L = 3;
const double S_0 = 1;
const std::complex<double> scale2(2,0);
const std::complex<double> scale4(4,0);
const std::complex<double> sum1(1,0);

double alpha();

double ro_a();

std::complex<double> betta(const std::complex<double> &s);

double R();

double E();

std::complex<double> A(const std::complex<double> &s);

std::complex<double> B(const std::complex<double> &s);

std::complex<double> C(const std::complex<double> &s);

std::complex<double> lambda(int ind, const std::complex<double> &s);

std::complex<double> d(int ind, const std::complex<double> &s);

std::complex<double> u_cap(const std::complex<double> &s, const double &x);

std::complex<double> p_cap(const std::complex<double> &s, const double &x);