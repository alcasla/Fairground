#include "BuilderCabina.h"

BuilderCabina::BuilderCabina(){}

osg::Node* BuilderCabina::buildObject()
{
      osg::Group* cuerpo = new osg::Group;
   
      //Base
      osg::ref_ptr<osg::Geode> base = new osg::Geode;
      osg::ref_ptr<osg::ShapeDrawable> suelo = new osg::ShapeDrawable;
      suelo->setShape( new osg::Box( osg::Vec3(0.0,0.0,0.0), 0.4,0.4,0.05 ) );
      base->addDrawable(suelo);
      
      osg::ref_ptr<osg::ShapeDrawable> pared1 = new osg::ShapeDrawable;
      pared1->setShape( new osg::Box( osg::Vec3(0.0,-0.175,0.17), 0.4,0.05,0.3 ) );
      base->addDrawable(pared1);
      
      osg::ref_ptr<osg::ShapeDrawable> pared2 = new osg::ShapeDrawable;
      pared2->setShape( new osg::Box( osg::Vec3(0.0,0.175,0.17), 0.4,0.05,0.3 ) );
      base->addDrawable(pared2);
      
      osg::ref_ptr<osg::ShapeDrawable> pared3 = new osg::ShapeDrawable;
      pared3->setShape( new osg::Box( osg::Vec3(0.175,0.0,0.17), 0.05,0.3,0.3 ) );
      base->addDrawable(pared3);
      
      osg::ref_ptr<osg::ShapeDrawable> pared4 = new osg::ShapeDrawable;
      pared4->setShape( new osg::Box( osg::Vec3(-0.175,0.0,0.17), 0.05,0.3,0.3 ) );
      base->addDrawable(pared4);
      
      cuerpo->addChild(base);
      
      //Tejado y barras
      osg::ref_ptr<osg::Geode> tejado = new osg::Geode;
      osg::ref_ptr<osg::ShapeDrawable> techo = new osg::ShapeDrawable;
      techo->setShape( new osg::Cone( osg::Vec3(0.0,0.0,0.65), 0.32,0.24 ) );
      tejado->addDrawable(techo);
      
      osg::ref_ptr<osg::ShapeDrawable> pilar1 = new osg::ShapeDrawable;
      pilar1->setShape( new osg::Box( osg::Vec3(-0.18,-0.18,0.465), 0.03,0.03,0.28 ) );
      tejado->addDrawable(pilar1);
      
      osg::ref_ptr<osg::ShapeDrawable> pilar2 = new osg::ShapeDrawable;
      pilar2->setShape( new osg::Box( osg::Vec3(0.18,-0.18,0.465), 0.03,0.03,0.28 ) );
      tejado->addDrawable(pilar2);
      
      osg::ref_ptr<osg::ShapeDrawable> pilar3 = new osg::ShapeDrawable;
      pilar3->setShape( new osg::Box( osg::Vec3(0.18,0.18,0.465), 0.03,0.03,0.28 ) );
      tejado->addDrawable(pilar3);
      
      osg::ref_ptr<osg::ShapeDrawable> pilar4 = new osg::ShapeDrawable;
      pilar4->setShape( new osg::Box( osg::Vec3(-0.18,0.18,0.465), 0.03,0.03,0.28 ) );
      tejado->addDrawable(pilar4);
      
      cuerpo->addChild(tejado);
      
      return cuerpo;
}
