#include <iostream>
#include "caballito.h"

#include <osgDB/ReadFile>
#include <osg/Texture2D>
using namespace std;

Caballito::Caballito( osg::ref_ptr<osg::Node> geo,float x,float y,float z,bool valor )
{
      pos[0]=x;
      pos[1]=y;
      pos[2]=z;
      bajar=valor;

      addChild(geo);
}

void Caballito::setScale( float x, float y, float z )
{
      setMatrix(osg::Matrix::scale(x,y,z) );
}

void Caballito::setTranslate( float x, float y, float z )
{
      setMatrix(getMatrix()*osg::Matrix::translate(x,y,z) );
}

void Caballito::setRotate( float a, int x, int y, int z )
{
      if(x==1)
         setMatrix(getMatrix()*osg::Matrix::rotate( a, osg::X_AXIS ) );
      if(y==1)
         setMatrix(getMatrix()*osg::Matrix::rotate( a, osg::Y_AXIS ) );
      if(z==1)
         setMatrix(getMatrix()*osg::Matrix::rotate( a, osg::Z_AXIS ) );
}

bool Caballito::getValor()
{
      return bajar;
}

void Caballito::setValor(bool dato)
{
      bajar=dato;
}

