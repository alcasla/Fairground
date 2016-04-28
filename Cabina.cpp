#include <iostream>
#include "Cabina.h"

using namespace std;


Cabina::Cabina( osg::ref_ptr<osg::Node> geo )
{
      addChild(geo);
      Textura* t = new Textura("cabinas.jpg", geo);
}

void Cabina::setScale( float x, float y, float z )
{
  setMatrix(osg::Matrix::scale(x,y,z) );
}

void Cabina::setTranslate( float x, float y, float z )
{
   setMatrix(getMatrix()*osg::Matrix::translate(x,y,z) );
}

void Cabina::setRotate( float a, int x, int y, int z )
{
   if(x==1)
      setMatrix(getMatrix()*osg::Matrix::rotate( a, osg::X_AXIS ) );
   if(y==1)
      setMatrix(getMatrix()*osg::Matrix::rotate( a, osg::Y_AXIS ) );
   if(z==1)
      setMatrix(getMatrix()*osg::Matrix::rotate( a, osg::Z_AXIS ) );
}
