#include "Noria.h"


Noria::Noria()
{
      angle = 0.0;
      scX = scY = scZ = 0.25;
      incremento = 0.002;
   
      //Geometria estructura
      Builder* geomNoria = new BuilderNoria();
      osg::ref_ptr<osg::Node> noria = geomNoria->buildObject();
      Textura* textureBase = new Textura("baseNoria.jpg", noria);
      
      OsgTools::Torus t(2.0,3.0);
      t.setColor(osg::Vec4(1.0f, 0.6f, 1.0f, 1.0f));
      osg::ref_ptr<osg::Geode> rueda = t();
      //Cara1
      osg::PositionAttitudeTransform* ruedaTransForm = new osg::PositionAttitudeTransform();  
      osg::Quat rq; rq.makeRotate( 1.57, 1, 0, 0);//rotacion
      ruedaTransForm->setScale( osg::Vec3d(0.22, 0.22, 0.035) );
      ruedaTransForm->setAttitude( rq );
      ruedaTransForm->addChild(rueda);
      //Cara2
      osg::PositionAttitudeTransform* ruedaTransForm2 = new osg::PositionAttitudeTransform();  
      osg::Quat rq2; rq2.makeRotate( 1.57, 1, 0, 0);//rotacion
      ruedaTransForm2->setPosition( osg::Vec3d(0.0, 0.16, 0.0) );
      ruedaTransForm2->setScale( osg::Vec3d(0.22, 0.22, 0.035) );
      ruedaTransForm2->setAttitude( rq );
      ruedaTransForm2->addChild(rueda);

   
      //Geometría cabina
      Builder* geomCabina = new BuilderCabina();
      osg::ref_ptr<osg::Node> cabina = geomCabina->buildObject();

      
      cab1 = new Cabina( cabina );	//Cabina 1
      cab2 = new Cabina( cabina );	//Cabina 2
      cab3 = new Cabina( cabina );	//Cabina 3
      cab4 = new Cabina( cabina );	//Cabina 4
      cab5 = new Cabina( cabina );	//Cabina 5
      cab6 = new Cabina( cabina );	//Cabina 6
      cab7 = new Cabina( cabina );	//Cabina 7
      cab8 = new Cabina( cabina );	//Cabina 8
      
      
      rotacion = new osg::MatrixTransform;
      rotacion->addChild(ruedaTransForm);
      rotacion->addChild(ruedaTransForm2);
      rotacion->addChild(cab1);
      rotacion->addChild(cab2);
      rotacion->addChild(cab3);
      rotacion->addChild(cab4);
      rotacion->addChild(cab5);
      rotacion->addChild(cab6);
      rotacion->addChild(cab7);
      rotacion->addChild(cab8);
      
      drawRotation();
      
      osg::ref_ptr<osg::Group> gn = new osg::Group;
      gn->addChild(rotacion);
      gn->addChild(noria);
      
      osg::ref_ptr<osg::MatrixTransform> upToFloor = new osg::MatrixTransform;
      upToFloor->setMatrix( osg::Matrix::translate(0.0, 0.0, 0.88) );
      upToFloor->addChild( gn );
      
      this->addChild(upToFloor);
}

void Noria::update()
{
      angle += incremento;
      if( angle > 6.2832 )
         angle = 0;
      drawRotation();
}

void Noria::drawRotation()
{
      //Cabina 1
      cab1->setScale( scX, scY, scZ );
      cab1->setRotate(-angle, 0,1,0);
      cab1->setTranslate( 0.0, 0.08, 0.6);
      //Cabina 2
      cab2->setScale( scX, scY, scZ );
      cab2->setRotate(-angle, 0,1,0);
      cab2->setTranslate( 0.42, 0.08, 0.48);
      //Cabina 3
      cab3->setScale( scX, scY, scZ );
      cab3->setRotate(-angle, 0,1,0);
      cab3->setTranslate( 0.6, 0.08, 0.0);
      //Cabina 4
      cab4->setScale( scX, scY, scZ );
      cab4->setRotate(-angle, 0,1,0);
      cab4->setTranslate( 0.42, 0.08, -0.48);
      //Cabina 5
      cab5->setScale( scX, scY, scZ );
      cab5->setRotate(-angle, 0,1,0);
      cab5->setTranslate( 0.0, 0.08, -0.6);
      //Cabina 6
      cab6->setScale( scX, scY, scZ );
      cab6->setRotate(-angle, 0,1,0);
      cab6->setTranslate( -0.42, 0.08, -0.48);
      //Cabina 7
      cab7->setScale( scX, scY, scZ );
      cab7->setRotate(-angle, 0,1,0);
      cab7->setTranslate( -0.6, 0.08, 0.0);
      //Cabina 8
      cab8->setScale( scX, scY, scZ );
      cab8->setRotate(-angle, 0,1,0);
      cab8->setTranslate( -0.42, 0.08, 0.48);
      
      rotacion->setMatrix( osg::Matrix::rotate(angle, osg::Y_AXIS) );
}

void Noria::click()
{
      if(incremento<=0.1) incremento = incremento*1.5;
      else incremento = 0.002;
}

