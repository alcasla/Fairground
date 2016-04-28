#include "BuilderBase.h"

BuilderBase::BuilderBase(){}

osg::Node* BuilderBase::buildObject()
{
      osg::Group* cuerpo = new osg::Group;
      osg::Group* resultado = new osg::Group;
     
      //Base
      osg::ref_ptr<osg::Geode> base = new osg::Geode;
      osg::ref_ptr<osg::ShapeDrawable> b = new osg::ShapeDrawable;
      b->setShape(new osg::Box(osg::Vec3(0,0,0),1.23,.7,.04));		
      base->addDrawable(b);
      Textura *buildBase = new Textura( "baseCocheschoque.jpg", base );


      //pilares
      osg::ref_ptr<osg::Geode> pilar= new osg::Geode;
      Textura *buildCoches = new Textura( "basePilares.jpg", pilar );
      osg::ref_ptr<osg::ShapeDrawable> p = new osg::ShapeDrawable;
      osg::ref_ptr<osg::MatrixTransform> p1 = new osg::MatrixTransform;
      osg::ref_ptr<osg::MatrixTransform> p2 = new osg::MatrixTransform;
      osg::ref_ptr<osg::MatrixTransform> p3 = new osg::MatrixTransform;
      osg::ref_ptr<osg::MatrixTransform> p4 = new osg::MatrixTransform;

      p->setShape(new osg::Box(osg::Vec3(0,0,0),0.85,0.85,1.0));
      pilar->addDrawable(p);
      p1->setMatrix(osg::Matrix::scale(.1,.09,.32)*osg::Matrix::rotate(osg::DegreesToRadians(0.0),0,0,1)*osg::Matrix::translate(-.57,.31,.18));
      p2->setMatrix(osg::Matrix::scale(.1,.09,.32)*osg::Matrix::rotate(osg::DegreesToRadians(0.0),0,0,1)*osg::Matrix::translate(-.57,-.31,.18));

      p3->setMatrix(osg::Matrix::scale(.1,.09,.32)*osg::Matrix::rotate(osg::DegreesToRadians(0.0),0,0,1)*osg::Matrix::translate(.57,.31,.18));

      p4->setMatrix(osg::Matrix::scale(.1,.09,.32)*osg::Matrix::rotate(osg::DegreesToRadians(0.0),0,0,1)*osg::Matrix::translate(.57,-.31,.18));

      p1->addChild(pilar);
      p2->addChild(pilar);
      p3->addChild(pilar);
      p4->addChild(pilar);
      

      //Techo
      osg::ref_ptr<osg::Geode> base2 = new osg::Geode;
      osg::ref_ptr<osg::ShapeDrawable> b2 = new osg::ShapeDrawable;
      b2->setShape(new osg::Box(osg::Vec3(0,0,0.325),1.23,.7,.04));		
      base2->addDrawable(b2);
      Textura *buildTecho = new Textura( "techoCocheschoque.jpg", base2 );

      cuerpo->addChild(base);
      cuerpo->addChild(base2);
      cuerpo->addChild(p1);
      cuerpo->addChild(p2);
      cuerpo->addChild(p3);
      cuerpo->addChild(p4);
      
      //giro
      osg::ref_ptr<osg::MatrixTransform> rotado = new osg::MatrixTransform;

      rotado->addChild(cuerpo);
      resultado->addChild(rotado);

      return resultado;
}
