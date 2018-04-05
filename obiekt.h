#ifndef OBIEKT_H
#define OBIEKT_H


class obiekt
{
public:
    obiekt(double A, double c);

    double A;
    double c;
    double h = 10;
    double simulate(double qwe, double dt);


};

#endif // OBIEKT_H
