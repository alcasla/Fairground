#include "BuilderTiovivo.h"

BuilderTiovivo::BuilderTiovivo(){}

osg::Node* BuilderTiovivo::buildObject()
{
      osg::Group* cuerpo = new osg::Group;
   
      //Base
      osg::ref_ptr<osg::Geode> base = new osg::Geode;
      osg::ref_ptr<osg::ShapeDrawable> b = new osg::ShapeDrawable;
      b->setShape( new osg::Cylinder( osg::Vec3(0.0,0.0,0.0),0.32,0.1 ) );
      base->addDrawable(b);
      cuerpo->addChild(base);
      
      //Pilar central
      osg::ref_ptr<osg::Geode> pilar = new osg::Geode;
      osg::ref_ptr<osg::ShapeDrawable> p = new osg::ShapeDrawable;
      p->setShape( new osg::Cylinder( osg::Vec3(0.0,0.0,0.4),0.06,0.8 ) );
      pilar->addDrawable(p);
      cuerpo->addChild(pilar);
      
      //Techo
      osg::ref_ptr<osg::Geode> techo = new osg::Geode;
      osg::ref_ptr<osg::ShapeDrawable> t = new osg::ShapeDrawable;
      t->setShape( new osg::Cone( osg::Vec3(0.0,0.0,0.7),0.32,0.3 ) );
      techo->addDrawable(t);
      cuerpo->addChild(techo);
      
      return cuerpo;
}
