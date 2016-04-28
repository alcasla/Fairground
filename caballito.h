#ifndef caballito_h
#define caballito_h

#include <osg/MatrixTransform>
#include <osg/Texture2D>
#include <osg/AnimationPath>
class Caballito: public osg::MatrixTransform
{
   private:
      float pos[3];
      bool bajar;
   public:
      Caballito( osg::ref_ptr<osg::Node> geo,float x, float y,float z,bool valor );
      void setScale( float x, float y, float z );
      void setTranslate( float x, float y, float z );
      void setRotate( float a, int x, int y, int z );
      bool getValor();
      void setValor(bool);
      
};

#endif
