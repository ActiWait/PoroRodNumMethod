#include "NumMethod.h"


double alpha() {  //(3)
    return 1 - K/K_s;
}

double ro_a() { //(4)
    return 0.66 * fi * ro_f; // C = 0.66
}

std::complex<double> betta(std::complex<double> s) { //(4)
    return (k * ro_f * pow(fi, 2)*pow(s, 2))/(pow(fi, 2)*s + pow(s, 2)*k*(ro_a() + fi * ro_f));
}

double R() { //(5)
    return (pow(fi, 2)*K_f*pow(K_s, 2))/(K_f*(K_s - K) + fi*K_s*(K_s - K_f));
}

double E() { //(10)
    return K + (4.0/3.0)*G;
}

std::complex<double> A(std::complex<double> s) { //(12)
    return E() * betta(s) / ro_f;
}

std::complex<double> B(std::complex<double> s) { //(12)
    return (E() * pow(fi, 2) / R()) + (ro - betta(s)*ro_f)*betta(s)/ro_f + (alpha() - betta(s))*(alpha() - betta(s));
}

std::complex<double> C(std::complex<double> s) {
    return pow(fi, 2)*(ro - betta(s)*ro_f)/R();
}

std::complex<double> lambda(int ind, std::complex<double> s) { //(11)
    std::complex<double> scale4(4,0);
    std::complex<double> scale2(2,0);
    switch (ind) {
    case 1:
        return  sqrt((B(s) + sqrt(B(s)*B(s) - scale4*A(s)*C(s)))/(scale2*A(s)));
        break;
    case 2:
        return  sqrt((B(s) - sqrt(B(s)*B(s) - scale4*A(s)*C(s)))/(scale2*A(s)));
        break;
    case 3:
        return -sqrt((B(s) + sqrt(B(s)*B(s) - scale4*A(s)*C(s)))/(scale2*A(s)));
        break;
    case 4:
        return -sqrt((B(s) - sqrt(B(s)*B(s) - scale4*A(s)*C(s)))/(scale2*A(s)));
        break;
    }
    return -1;
}


std::complex<double> d(int ind, std::complex<double> s) {       //(13)
    return (E()*pow(lambda(ind, s),2) - (ro - betta(s)*ro_f))/((alpha() - betta(s))*lambda(ind,s));
}

std::complex<double> u_cap(std::complex<double> s, double x) {  //(8)
    std::complex<double> scale2(2,0);
    std::complex<double> sum1(1,0);

    std::complex<double> scale = S_0/(E()*s*s*(d(1,s) * lambda(2,s) - d(2,s)* lambda(1,s)));
    std::complex<double> desired    = (d(2,s) * (exp(- lambda(1, s) * s * (L - x)) - exp(- lambda(1, s) * s * (L + x))))/(sum1 + exp((-scale2* lambda(1, s) * s * L)));
    std::complex<double> deductible = (d(1,s) * (exp(- lambda(2, s) * s * (L - x)) - exp(- lambda(2, s) * s * (L + x))))/(sum1 + exp((-scale2 * lambda(2, s) * s * L)));
    return scale*(desired - deductible);
}
std::complex<double> p_cap(std::complex<double> s, double x) { //(9)
    std::complex<double> scale2(2,0);
    std::complex<double> sum1(1,0);

    std::complex<double> scale = (S_0 * d(1,s) * d(2, s))/(E()*s*(d(1,s) * lambda(2,s) - d(2,s)* lambda(1,s)));
    std::complex<double> desired    = ((exp(-lambda(1, s) * s * (L - x)) + exp(-lambda(1, s) * s * (L + x))))/(sum1 + exp((-scale2 * lambda(1, s) * s * L)));
    std::complex<double> deductible = ((exp(-lambda(2, s) * s * (L - x)) + exp(-lambda(2, s) * s * (L + x))))/(sum1 + exp((-scale2 * lambda(2, s) * s * L)));
    return scale*(desired - deductible);
}