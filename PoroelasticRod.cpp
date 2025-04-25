#include  <fstream>
#include "NumMethod.h"
#include "DurbinMethod.h"
#include <iostream>

int main() {
    double x = 3;
    double sigma = 5;
    int N = 20000;
    double T = 10;
    std::ofstream fin;
    fin.open("Result_Displacement.csv", std::ios::out);
    fin << "TimeStep" << ";" << "Displacement" << "\n"; 
    for (size_t t = 0; t <= 300; t+=1) {
        double f = f_N(t/10000., sigma, N, T, x, u_cap);
        fin << t/10000. << ";" << f << "\n"; 
    }
    fin.close();

    x = 0;
    fin.open("Result_Stress.csv", std::ios::out);
    fin << "TimeStep" << ";" << "Stress" << "\n"; 
    for (int t = 0; t <= 300; t+=1) {
        double f = f_N(t/10000., sigma, N, T, x, p_cap);
        fin << t/10000. << ";" << f << std::endl;
    }
    fin.close();

}