#ifndef CUERPO_H
#define CUERPO_H
#include <math.h>


class cuerpo
{
    double radio,posx,posy;
    double velx,vely;
    double ax,ay;
    double masa;
    int G=1,delta_t=1,id;
    float angulo;

public:
    cuerpo();

    cuerpo(double x_,double y_,double masa_,double radio_,double velx_,double vely_,int id);

    void actualizar_posicion(int delta_t);
    void actualizar_velocidad(double,double,double);

    double getPosx() const;
    double getPosy() const;
};

#endif // CUERPO_H
