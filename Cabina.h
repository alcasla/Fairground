#ifndef CABINA_H
#define CABINA_H

#include "Textura.h"

#include <osg/MatrixTransform>


class Cabina: public osg::MatrixTransform
{
   private:
      float pos[3];
      
   public:
      Cabina( osg::ref_ptr<osg::Node> geo );
      void setScale( float x, float y, float z );
      void setTranslate( float x, float y, float z );
      void setRotate( float a, int x, int y, int z );
};

#endif