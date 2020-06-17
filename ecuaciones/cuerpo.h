#ifndef CUERPO_H
#define CUERPO_H
#include <math.h>


class cuerpo
{
    double radio=0,posx=0,posy=0;
    double velx=0,vely=0;
    double ax=0,ay=0;
    double masa=0;
    int id;
    float angulo=0, G=6.67384*pow(10,-11);

public:
    cuerpo();

    cuerpo(double x_,double y_,double masa_,double radio_,double velx_,double vely_,int id);

    void actualizar_posicion(float delta_t);
    void actualizar_velocidad(double,double,double);

    double getPosx() const;
    double getPosy() const;
    int getId() const;
    double getMasa() const;
};

#endif // CUERPO_H
