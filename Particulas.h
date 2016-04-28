#ifndef PARTICULAS_H
#define PARTICULAS_H

#include <osg/Geode>
#include <osg/Group>
#include <osgDB/ReadFile>
#include <osg/Texture2D>
#include <osg/Point>
#include <osg/PointSprite>
#include <osgParticle/Particle>
#include <osgParticle/ParticleSystem>
#include <osgParticle/ParticleSystemUpdater>
#include <osgParticle/ModularEmitter>
#include <osgParticle/ModularProgram>
#include <osgParticle/RandomRateCounter>
#include <osgParticle/SectorPlacer>
#include <osgParticle/RadialShooter>
#include <osgParticle/AccelOperator>
#include <osgParticle/FluidFrictionOperator>
#include <osg/BlendFunc>

using namespace std;

class Particulas : public osg::Group{
 private:

 public:
	Particulas();
	osgParticle::ParticleSystem* crearSistema(osg::Group* padres,int color);

};

#endif
