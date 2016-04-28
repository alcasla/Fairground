#ifndef atraccion_h
#define atraccion_h

#include <iostream>
#include <osg/Group>
#include <osg/Node>
#include <osg/Geometry>
#include <vector>

#include "BuilderPLY.h"
#include "BuilderCoche.h"
#include "BuilderBase.h"
#include "Coche.h"
#include "Textura.h"
#include "Animado.h"


class Atraccion : public osg::Group, Animado
{
      private:
         vector<Coche*> coches;
         
      public:
         Atraccion();
         void update();
         void updateChoques();
         float getPositionX(int numCar);
         float getPositionY(int numCar);
         float getAngle(int numCar);
};

#endif
