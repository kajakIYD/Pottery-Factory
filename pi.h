#ifndef PI_H
#define PI_H


class PI
{
    public:
        // Kp - proportional gain
        // Ki - integral gain
        // dt - loop interval gain
        // max_u - maximum value of manipulated variable
        // min_u - minimum value of manipulated variable

        PI(double dt, double max_u, double Kr, double Ti);

        double simulate(double pv, double dt);

        ~PI();
        double dt;
        double max_u;
        double min_u;
        double Kr;
        double Ti;
        double e0;
        double integral;
        double u;
        double setpoint;
    private:

};

#endif // PI_H
