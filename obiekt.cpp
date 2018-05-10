#include "obiekt.h"

obiekt::obiekt()
{

}

double obiekt::simulate(double qwe, double dt, double setpoint)
{
    Tp = setpoint;
    double G =  1/(M*c)*((n+1)*qwe*Ro_s*c_s*(Tp-T) - m*v*c*(T-T0));
    T = T + G*dt;
    return T;
}
