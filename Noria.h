#ifndef NORIA_H
#define NORIA_H

#include "BuilderCabina.h"
#include "BuilderNoria.h"
#include "Cabina.h"
#include "Torus.h"
#include "Textura.h"
#include "Animado.h"

#include <osg/PositionAttitudeTransform>
#include <osg/Group>
#include <osg/Node>


class Noria: public osg::Group, Animado
{
   private:
      float angle;
      float scX, scY, scZ;
      float incremento;
      
      osg::ref_ptr<osg::MatrixTransform> rotacion;
      osg::ref_ptr<Cabina> cab1;
      osg::ref_ptr<Cabina> cab2;
      osg::ref_ptr<Cabina> cab3;
      osg::ref_ptr<Cabina> cab4;
      osg::ref_ptr<Cabina> cab5;
      osg::ref_ptr<Cabina> cab6;
      osg::ref_ptr<Cabina> cab7;
      osg::ref_ptr<Cabina> cab8;
   
   public:
      Noria();
      void update();
      void drawRotation();
      void click();
};

#endif