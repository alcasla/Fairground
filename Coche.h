#ifndef COCHE_H
#define COCHE_H

#include "Textura.h"
#include "Animado.h"

#include <osg/MatrixTransform>


class Coche : public osg::MatrixTransform, Animado
{
      private:
         float posX, posY, posZ;
         double angle;
         float movimiento;
         bool updating;
         
      public:
         Coche(osg::ref_ptr<osg::Node> nod);
         void inicialize( float x, float y,float z, double ang );
         void setScale(float x, float y, float z);
         void setTranslate(float x, float y, float z);
         void setRotate(float angle, int x, int y, int z);
         float getPosX();
         float getPosY();
         double getAngle();
         void update();
         void girar( int grados );	//Gira numero de grados
         void stoper();
         void speed( float incDec );	//Argumento multiplicador de velocidad
};

#endif
