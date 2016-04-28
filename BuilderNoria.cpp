#include "BuilderNoria.h"

BuilderNoria::BuilderNoria(){}

osg::Node* BuilderNoria::buildObject()
{
      osg::Group* noria = new osg::Group;
      osg::MatrixTransform* cuerpo = new osg::MatrixTransform;
   
      //Cara 1
      osg::ref_ptr<osg::Geode> barra = new osg::Geode;
      osg::ref_ptr<osg::ShapeDrawable> b = new osg::ShapeDrawable;
      b->setShape( new osg::Box( osg::Vec3(0.0,0.0,0.0),0.015,0.015,1.2 ) );
      barra->addDrawable(b);
      cuerpo->addChild(barra);
      
      osg::ref_ptr<osg::MatrixTransform> m1 = new osg::MatrixTransform;
      m1->setMatrix( osg::Matrix::rotate(0.19f, osg::Y_AXIS) );
      m1->addChild(barra);
      cuerpo->addChild(m1);

      osg::ref_ptr<osg::MatrixTransform> m2 = new osg::MatrixTransform;
      m2->setMatrix( osg::Matrix::rotate(0.38f, osg::Y_AXIS) );
      m2->addChild(barra);
      cuerpo->addChild(m2);

      osg::ref_ptr<osg::MatrixTransform> m3 = new osg::MatrixTransform;
      m3->setMatrix( osg::Matrix::rotate(0.57f, osg::Y_AXIS) );
      m3->addChild(barra);
      cuerpo->addChild(m3);
      
      osg::ref_ptr<osg::MatrixTransform> m4 = new osg::MatrixTransform;
      m4->setMatrix( osg::Matrix::rotate(0.76f, osg::Y_AXIS) );
      m4->addChild(barra);
      cuerpo->addChild(m4);
      
      osg::ref_ptr<osg::MatrixTransform> m5 = new osg::MatrixTransform;
      m5->setMatrix( osg::Matrix::rotate(0.95f, osg::Y_AXIS) );
      m5->addChild(barra);
      cuerpo->addChild(m5);
      
      osg::ref_ptr<osg::MatrixTransform> m6 = new osg::MatrixTransform;
      m6->setMatrix( osg::Matrix::rotate(1.14f, osg::Y_AXIS) );
      m6->addChild(barra);
      cuerpo->addChild(m6);
      
      osg::ref_ptr<osg::MatrixTransform> m7 = new osg::MatrixTransform;
      m7->setMatrix( osg::Matrix::rotate(1.33f, osg::Y_AXIS) );
      m7->addChild(barra);
      cuerpo->addChild(m7);
      
      osg::ref_ptr<osg::MatrixTransform> m8 = new osg::MatrixTransform;
      m8->setMatrix( osg::Matrix::rotate(1.52f, osg::Y_AXIS) );
      m8->addChild(barra);
      cuerpo->addChild(m8);
      
      osg::ref_ptr<osg::MatrixTransform> m9 = new osg::MatrixTransform;
      m9->setMatrix( osg::Matrix::rotate(1.71f, osg::Y_AXIS) );
      m9->addChild(barra);
      cuerpo->addChild(m9);
      
      osg::ref_ptr<osg::MatrixTransform> m10 = new osg::MatrixTransform;
      m10->setMatrix( osg::Matrix::rotate(1.9f, osg::Y_AXIS) );
      m10->addChild(barra);
      cuerpo->addChild(m10);
      
      osg::ref_ptr<osg::MatrixTransform> m11 = new osg::MatrixTransform;
      m11->setMatrix( osg::Matrix::rotate(2.09f, osg::Y_AXIS) );
      m11->addChild(barra);
      cuerpo->addChild(m11);
      
      osg::ref_ptr<osg::MatrixTransform> m12 = new osg::MatrixTransform;
      m12->setMatrix( osg::Matrix::rotate(2.28f, osg::Y_AXIS) );
      m12->addChild(barra);
      cuerpo->addChild(m12);
      
      osg::ref_ptr<osg::MatrixTransform> m13 = new osg::MatrixTransform;
      m13->setMatrix( osg::Matrix::rotate(2.47f, osg::Y_AXIS) );
      m13->addChild(barra);
      cuerpo->addChild(m13);
      
      osg::ref_ptr<osg::MatrixTransform> m14 = new osg::MatrixTransform;
      m14->setMatrix( osg::Matrix::rotate(2.66f, osg::Y_AXIS) );
      m14->addChild(barra);
      cuerpo->addChild(m14);
      
      osg::ref_ptr<osg::MatrixTransform> m15 = new osg::MatrixTransform;
      m15->setMatrix( osg::Matrix::rotate(2.85f, osg::Y_AXIS) );
      m15->addChild(barra);
      cuerpo->addChild(m15);
      
      osg::ref_ptr<osg::MatrixTransform> m16 = new osg::MatrixTransform;
      m16->setMatrix( osg::Matrix::rotate(3.0f, osg::Y_AXIS) );
      m16->addChild(barra);
      cuerpo->addChild(m16);
      
      //Cara 2
      osg::ref_ptr<osg::Geode> barra2 = new osg::Geode;
      osg::ref_ptr<osg::ShapeDrawable> b2 = new osg::ShapeDrawable;
      b2->setShape( new osg::Box( osg::Vec3(0.0,0.16,0.0),0.015,0.015,1.2 ) );
      barra2->addDrawable(b2);
      cuerpo->addChild(barra2);
      
      osg::ref_ptr<osg::MatrixTransform> m17 = new osg::MatrixTransform;
      m17->setMatrix( osg::Matrix::rotate(0.19f, osg::Y_AXIS) );
      m17->addChild(barra2);
      cuerpo->addChild(m17);

      osg::ref_ptr<osg::MatrixTransform> m18 = new osg::MatrixTransform;
      m18->setMatrix( osg::Matrix::rotate(0.38f, osg::Y_AXIS) );
      m18->addChild(barra2);
      cuerpo->addChild(m18);

      osg::ref_ptr<osg::MatrixTransform> m19 = new osg::MatrixTransform;
      m19->setMatrix( osg::Matrix::rotate(0.57f, osg::Y_AXIS) );
      m19->addChild(barra2);
      cuerpo->addChild(m19);
      
      osg::ref_ptr<osg::MatrixTransform> m20 = new osg::MatrixTransform;
      m20->setMatrix( osg::Matrix::rotate(0.76f, osg::Y_AXIS) );
      m20->addChild(barra2);
      cuerpo->addChild(m20);
      
      osg::ref_ptr<osg::MatrixTransform> m21 = new osg::MatrixTransform;
      m21->setMatrix( osg::Matrix::rotate(0.95f, osg::Y_AXIS) );
      m21->addChild(barra2);
      cuerpo->addChild(m21);
      
      osg::ref_ptr<osg::MatrixTransform> m22 = new osg::MatrixTransform;
      m22->setMatrix( osg::Matrix::rotate(1.14f, osg::Y_AXIS) );
      m22->addChild(barra2);
      cuerpo->addChild(m22);
      
      osg::ref_ptr<osg::MatrixTransform> m23 = new osg::MatrixTransform;
      m23->setMatrix( osg::Matrix::rotate(1.33f, osg::Y_AXIS) );
      m23->addChild(barra2);
      cuerpo->addChild(m23);
      
      osg::ref_ptr<osg::MatrixTransform> m24 = new osg::MatrixTransform;
      m24->setMatrix( osg::Matrix::rotate(1.52f, osg::Y_AXIS) );
      m24->addChild(barra2);
      cuerpo->addChild(m24);
      
      osg::ref_ptr<osg::MatrixTransform> m25 = new osg::MatrixTransform;
      m25->setMatrix( osg::Matrix::rotate(1.71f, osg::Y_AXIS) );
      m25->addChild(barra2);
      cuerpo->addChild(m25);
      
      osg::ref_ptr<osg::MatrixTransform> m26 = new osg::MatrixTransform;
      m26->setMatrix( osg::Matrix::rotate(1.9f, osg::Y_AXIS) );
      m26->addChild(barra2);
      cuerpo->addChild(m26);
      
      osg::ref_ptr<osg::MatrixTransform> m27 = new osg::MatrixTransform;
      m27->setMatrix( osg::Matrix::rotate(2.09f, osg::Y_AXIS) );
      m27->addChild(barra2);
      cuerpo->addChild(m27);
      
      osg::ref_ptr<osg::MatrixTransform> m28 = new osg::MatrixTransform;
      m28->setMatrix( osg::Matrix::rotate(2.28f, osg::Y_AXIS) );
      m28->addChild(barra2);
      cuerpo->addChild(m28);
      
      osg::ref_ptr<osg::MatrixTransform> m29 = new osg::MatrixTransform;
      m29->setMatrix( osg::Matrix::rotate(2.47f, osg::Y_AXIS) );
      m29->addChild(barra2);
      cuerpo->addChild(m29);
      
      osg::ref_ptr<osg::MatrixTransform> m30 = new osg::MatrixTransform;
      m30->setMatrix( osg::Matrix::rotate(2.66f, osg::Y_AXIS) );
      m30->addChild(barra2);
      cuerpo->addChild(m30);
      
      osg::ref_ptr<osg::MatrixTransform> m31 = new osg::MatrixTransform;
      m31->setMatrix( osg::Matrix::rotate(2.85f, osg::Y_AXIS) );
      m31->addChild(barra2);
      cuerpo->addChild(m31);
      
      osg::ref_ptr<osg::MatrixTransform> m32 = new osg::MatrixTransform;
      m32->setMatrix( osg::Matrix::rotate(3.0f, osg::Y_AXIS) );
      m32->addChild(barra2);
      cuerpo->addChild(m32);
      
      noria->addChild(cuerpo);
      
      osg::ref_ptr<osg::Geode> base = new osg::Geode;
      osg::ref_ptr<osg::ShapeDrawable> p1 = new osg::ShapeDrawable;
      p1->setShape( new osg::Box( osg::Vec3(0.0,-0.04,-0.4),0.06,0.03,1.0 ) );
      base->addDrawable(p1);
      osg::ref_ptr<osg::ShapeDrawable> p2 = new osg::ShapeDrawable;
      p2->setShape( new osg::Box( osg::Vec3(0.0,0.2,-0.4),0.06,0.04,1.0 ) );
      base->addDrawable(p2);
      osg::ref_ptr<osg::ShapeDrawable> bass = new osg::ShapeDrawable;
      bass->setShape( new osg::Box( osg::Vec3(0.0,0.09,-0.9),0.6,0.6,0.06 ) );
      base->addDrawable(bass);
      
      noria->addChild(base);
      
      return noria;
}