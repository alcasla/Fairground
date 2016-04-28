#include "Particulas.h"
#include <iostream>

using namespace std;

Particulas::Particulas(){

	
}

osgParticle::ParticleSystem* Particulas::crearSistema(osg::Group *parent,int color){

	osgParticle::Particle ptemplate;
	
	    ptemplate.setLifeTime(1.8);        // seconds of life

	    // the following ranges set the envelope of the respective
	    // graphical properties in time.
	    ptemplate.setSizeRange(osgParticle::rangef(0.75f, 3.0f));
	    ptemplate.setAlphaRange(osgParticle::rangef(0.0f, 1.5f));

	   if(color==1){
	    ptemplate.setColorRange(osgParticle::rangev4(
	        osg::Vec4(1, 0.5f, 0.3f, 1.5f),
	        osg::Vec4(0, 0.7f, 1.0f, 0.0f)));
	   }
	    else if(color==2){
		ptemplate.setColorRange(osgParticle::rangev4(
	        osg::Vec4(1, 0.3f, 0.8f, 1.3f),
	        osg::Vec4(0, 1.7f, 1.0f, 0.5f)));
		
	   }
	   else{
		ptemplate.setColorRange(osgParticle::rangev4(
	        osg::Vec4(1, 1.5f, 0.2f, .5f),
	        osg::Vec4(0, 0.2f, 1.7f, 1.2f)));

	   }
	
	    // these are physical properties of the particle
	    ptemplate.setRadius(3.0f);    // 5 cm wide particles
	    ptemplate.setMass(1.0f);    // 50 g heavy
	
	    // As usual, let's create the ParticleSystem object and set its
	    // default state attributes. This time we use a texture named
	    // "smoke.rgb", you can find it in the data distribution of OSG.
	    // We turn off the additive blending, because smoke has no self-
	    // illumination.
	    osg::ref_ptr<osgParticle::ParticleSystem> ps = new osgParticle::ParticleSystem;
	    ps->setDefaultAttributes("Images/smoke.rgb", false, false);
	
	    // assign the particle template to the system.
	    ps->setDefaultParticleTemplate(ptemplate);
	    ps->getDefaultParticleTemplate().setShape(osgParticle::Particle::LINE);
/*
	osg::ref_ptr<osg::BlendFunc> blendFunc = new osg::BlendFunc;
	blendFunc->setFunction( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
	osg::ref_ptr<osg::Texture2D> texture = new osg::Texture2D;
	texture->setImage( osgDB::readImageFile("pato.jpg") );
//
	osg::StateSet* ss = ps->getOrCreateStateSet();
	ss->setAttributeAndModes( blendFunc.get() );
	ss->setTextureAttributeAndModes( 0, texture.get() );
	ss->setAttribute( new osg::Point(20.0f) );

	ss->setTextureAttributeAndModes( 0, new osg::PointSprite );
	ss->setMode( GL_LIGHTING, osg::StateAttribute::OFF);
	ss->setRenderingHint( osg::StateSet::TRANSPARENT_BIN );
*/
	osg::ref_ptr<osgParticle::RandomRateCounter> rrc =new osgParticle::RandomRateCounter;
	rrc->setRateRange( 100, 200 );

	osg::ref_ptr<osgParticle::ModularEmitter> emitter =new osgParticle::ModularEmitter;
	emitter->setParticleSystem( ps.get() );
	emitter->setCounter( rrc.get() );
	
	osgParticle::RadialShooter* smokeShooter = new osgParticle::RadialShooter();

    // Set properties of this shooter 
    smokeShooter->setThetaRange(0.0, 3.14159); // radians, relative to Z axis.
    smokeShooter->setInitialSpeedRange(1,2); // meters/second
    // Use this shooter for our emitter
	emitter->setShooter(smokeShooter);

	osg::ref_ptr<osgParticle::AccelOperator> accel =new osgParticle::AccelOperator;
	//accel->setToGravity();

	osg::ref_ptr<osgParticle::ModularProgram> program =new osgParticle::ModularProgram;
	program->setParticleSystem( ps.get() );
	program->addOperator( accel.get() );

	osg::ref_ptr<osg::Geode> geode = new osg::Geode;
	geode->addDrawable( ps.get() );
	parent->addChild( emitter.get() );
	parent->addChild( program.get() );
	parent->addChild( geode.get() );
return ps.get();
}


