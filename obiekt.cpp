#include "obiekt.h"

obiekt::obiekt(double A, double c):
    A(A),
    c(c)
{

}

double obiekt::simulate(double qwe, double dt)
{
    h += (1/A)*(qwe - c*h) * dt;
    return h;
}
