#include "obiekt.h"

obiekt::obiekt(double A, double c):
    A(A),
    c(c)
{

}

double obiekt::simulate(double qwe, double dt, double Tp)
{
    //h += (1/A)*(qwe - c*h) * dt;
    double M = 1000;
    double v = 1;
    double n = 7;
    double m = 300;
    double c = 0.8*1000;
    double c_s = 1000;
    double Ro_s = 1;
    double q0 = 0.5;
    double Ro = 1;
    double T0 = 20;
    double Tp0=Tp;
    G =  1/(M*c)*((n+1)*qwe*Ro_s*c_s*(Tp-T) - m*v*c*(T-T0));
    T = T + G*dt;
    return T;
}
