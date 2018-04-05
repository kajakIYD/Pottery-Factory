#ifndef OBIEKT_H
#define OBIEKT_H


class obiekt
{
public:
    obiekt(double A, double c);

    double A;
    double c;
    double h = 10;
    double G=0;
    double T=20;
    double simulate(double qwe, double dt, double Tp);


};

#endif // OBIEKT_H
