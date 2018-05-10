#ifndef OBIEKT_H
#define OBIEKT_H


class obiekt
{
public:
    obiekt();

    double simulate(double qwe, double dt, double setpoint);
    double T;
private:
    double M = 1000;
    double v = 1;
    double q = 1;
    double n = 7;
    double m = 300;
    double c = 800;
    double c_s = 1000;
    double Ro_s = 1;
    double q0 = 0.5;
    double Tp = 1500;
    double Ro = 1;
    double T0 = 20;

};

#endif // OBIEKT_H
