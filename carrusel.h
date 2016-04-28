#ifndef carrusel_h
#define carrusels_h

#include "caballito.h"
#include "Textura.h"
#include "Animado.h"

#include <osg/MatrixTransform>
#include <osg/Group>
#include <osg/Geometry>
#include <osg/Node>


class Carrusel: public osg::Group, Animado
{
   private:
	osg::ref_ptr<Caballito> cab1;
	osg::ref_ptr<Caballito> cab2;
	osg::ref_ptr<Caballito> cab3;
	osg::ref_ptr<Caballito> cab4;
	osg::ref_ptr<osg::MatrixTransform> rotado;
	float angle;
	float inc;
	float dato[4];
   public:
      Carrusel();
	void update();
	float incremento(osg::ref_ptr<Caballito>,int);
	void click();
};

#endif
