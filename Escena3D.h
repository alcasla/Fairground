#ifndef ESCENE3D_H
#define ESCENE3D_H

#include "carrusel.h"
#include "Noria.h"
#include "atraccion.h"
#include "Camera.h"
#include "Luz.h"
#include "Textura.h"

#include <osg/Group>
#include <osg/Camera>
#include <osg/Vec3d>
#include <osg/Texture2D>
#include <osgDB/ReadFile> 
#include <osg/PositionAttitudeTransform>
#include <osg/LightSource>
#include <osg/Material>
#include <osg/PolygonOffset>
#include <osg/PolygonMode>

#include "Particulas.h"
#include <osgParticle/ParticleSystem>
#include <osgParticle/ParticleSystemUpdater>


class Escena3D : public osg::Group
{
      private:
         osg::ref_ptr<Noria> noria;
         osg::ref_ptr<Carrusel> tiovivo;
         osg::ref_ptr<Atraccion> cocheschoque;
         osg::ref_ptr<Camera> cam;
   	osg::ref_ptr<Particulas> partis;
	
      public:
         Escena3D();
         void update( int option );
         osg::ref_ptr<osg::Camera> getCamera();
         osg::ref_ptr<osg::MatrixTransform> setFloor();
         osg::Geode* crearEspacio(const std::string& nombreTextura, double radio);
         osg::ref_ptr<osg::Group> enter();
         osg::ref_ptr<osg::Group> naturaleza();
         osg::ref_ptr<osg::Group> entradaLuces();
};


#endif
