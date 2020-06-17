#include "cuerpo.h"

double cuerpo::getPosx() const
{
    return posx;
}

double cuerpo::getPosy() const
{
    return posy;
}

int cuerpo::getId() const
{
    return id;
}

double cuerpo::getMasa() const
{
    return masa;
}

cuerpo::cuerpo()
{

}

cuerpo::cuerpo(double x_, double y_, double masa_, double radio_, double velx_, double vely_,int id_)
{
    posx = x_;
    posy = y_;
    masa = masa_;
    radio = radio_;
    velx = velx_;
    vely = vely_;
    id = id_;

}

void cuerpo::actualizar_posicion(float delta_t)
{
    velx = velx + (ax*delta_t);
    vely = vely + (ay*delta_t);
    posx = posx + (velx*delta_t) + ((ax*(delta_t*delta_t))/2);
    posy = posy + (vely*delta_t) + ((ay*(delta_t*delta_t))/2);
}

void cuerpo::actualizar_velocidad(double x, double y, double masa2)
{
    angulo = atan2((y-posy),(x-posx));
    radio = pow(pow((x-posx),2)+pow((y-posy),2),1/2);
    double aux_acx,aux_acy;
    aux_acx = (((G*masa2)/(radio*radio))*cos(angulo));
    aux_acy = (((G*masa2)/(radio*radio))*sin(angulo));
    ax+= aux_acx;
    ay+= aux_acy;

}
