#include "Escena3D.h"


Escena3D::Escena3D()
{
      cam = new Camera();
      Luz* light0 = new Luz(0,osg::Vec3(-5.0f,-5.0f,5.0f),osg::Vec4(1.0f,1.0f,1.0f,1.0f));
      
      osg::Geode* espacio = new osg::Geode;
      espacio = crearEspacio( "espacio.jpg", 4.8 );
      
      //PacoPArk
      osg::ref_ptr<osg::Group> entrada = new osg::Group;
      entrada = enter();
      
      //Arbustos
      osg::ref_ptr<osg::Group> plantas = new osg::Group;
      plantas = naturaleza();
      
      //Portada
      osg::ref_ptr<osg::Group> portada = new osg::Group;
      portada = entradaLuces();
      
      //Inicialización atracciones
      tiovivo = new Carrusel();
      noria = new Noria();
      cocheschoque = new Atraccion();
      
      //Suelo escena
      osg::ref_ptr<osg::MatrixTransform> suelo = setFloor();
      //Posicionamiento NORIA
      osg::ref_ptr<osg::MatrixTransform> positionNoria = new osg::MatrixTransform;
      positionNoria->setMatrix( osg::Matrix::translate(0.8, 1.0, 0.0) );
      positionNoria->addChild( noria );
      //Posicionamiento TIOVIVO
      osg::ref_ptr<osg::MatrixTransform> escaleTiovivo = new osg::MatrixTransform;
      escaleTiovivo->setMatrix( osg::Matrix::scale(0.7, 0.7, 0.5) );
      escaleTiovivo->addChild( tiovivo );
      //Posicionamiento COCHESCHOQUE
      osg::ref_ptr<osg::MatrixTransform> positionCoches = new osg::MatrixTransform;
      positionCoches->setMatrix( osg::Matrix::translate(-1.0, 1.1, 0.0) );
      positionCoches->addChild( cocheschoque );
      
	

      this->getOrCreateStateSet()->setMode(GL_LIGHT0, osg::StateAttribute::ON);
      cam->addChild(light0);

	
      
      light0->addChild( entrada );
      light0->addChild( portada );
      light0->addChild( plantas );
      light0->addChild( espacio );
      light0->addChild(positionCoches);
      light0->addChild(positionNoria);
      light0->addChild(escaleTiovivo);
      light0->addChild(suelo);

	//Particulas
	osg::ref_ptr<osg::MatrixTransform> mt = new osg::MatrixTransform;
		mt->setMatrix( osg::Matrix::scale(.06,.06,.06)*osg::Matrix::translate(-1.0,3.6,1.2) );
	osg::ref_ptr<osg::MatrixTransform> mt2 = new osg::MatrixTransform;
		mt2->setMatrix(osg::Matrix::scale(.06,.06,.06)*osg::Matrix::translate(-.4,3.6,1.1));
	osg::ref_ptr<osg::MatrixTransform> mt3 = new osg::MatrixTransform;
		mt3->setMatrix(osg::Matrix::scale(.06,.06,.06)*osg::Matrix::translate(-0.76,3.6,1.32));

	osg::ref_ptr<osgParticle::ParticleSystem> ps1=partis->crearSistema(mt,1);
	osg::ref_ptr<osgParticle::ParticleSystem> ps2= partis->crearSistema(mt2,2);
	osg::ref_ptr<osgParticle::ParticleSystem> ps3= partis->crearSistema(mt3,3);
	osgParticle::ParticleSystemUpdater *psu= new osgParticle::ParticleSystemUpdater;
	psu->addParticleSystem(ps1);
	psu->addParticleSystem(ps2);
	psu->addParticleSystem(ps3);
	light0->addChild(mt.get());
	light0->addChild(mt2.get());
	light0->addChild(mt3.get());
	this->addChild(psu);
      this->addChild(cam);
}

void Escena3D::update( int option )
{
      noria->update();
      tiovivo->update();
      cocheschoque->update();
      
      if( option == 1 )
      {
         cam->setViewMatrixAsLookAt(osg::Vec3d(cocheschoque->getPositionX(0)-1.0, cocheschoque->getPositionY(0)+1.1, 0.0825), 
			      osg::Vec3d(osg::Vec3d(cocheschoque->getPositionX(0)-1.05 +1.0*sin(cocheschoque->getAngle(0)), cocheschoque->getPositionY(0)+1.1 -1.0*cos(cocheschoque->getAngle(0)), 0.08)), 
			      osg::Vec3d(0.0, 0.0, 1.0));
      }
}

osg::ref_ptr< osg::Camera > Escena3D::getCamera()
{
   return cam;
}

osg::ref_ptr<osg::MatrixTransform> Escena3D::setFloor()
{
      osg::ref_ptr<osg::Geode> floor = new osg::Geode;
      osg::ref_ptr<osg::ShapeDrawable> f1 = new osg::ShapeDrawable;		//Baldosa 1
      f1->setShape(new osg::Box(osg::Vec3(0,0,0),1.5,1.5,0.02));		
      floor->addDrawable(f1);
      osg::ref_ptr<osg::ShapeDrawable> f2 = new osg::ShapeDrawable;		//Baldosa 2
      f2->setShape(new osg::Box(osg::Vec3(-1.5,0,0),1.5,1.5,0.02));		
      floor->addDrawable(f2);
      osg::ref_ptr<osg::ShapeDrawable> f3 = new osg::ShapeDrawable;		//Baldosa 3
      f3->setShape(new osg::Box(osg::Vec3(1.5,0,0),1.5,1.5,0.02));		
      floor->addDrawable(f3);
      osg::ref_ptr<osg::ShapeDrawable> f4 = new osg::ShapeDrawable;		//Baldosa 4
      f4->setShape(new osg::Box(osg::Vec3(1.5,1.5,0),1.5,1.5,0.02));		
      floor->addDrawable(f4);
      osg::ref_ptr<osg::ShapeDrawable> f5 = new osg::ShapeDrawable;		//Baldosa 5
      f5->setShape(new osg::Box(osg::Vec3(0.0,1.5,0),1.5,1.5,0.02));		
      floor->addDrawable(f5);
      osg::ref_ptr<osg::ShapeDrawable> f6 = new osg::ShapeDrawable;		//Baldosa 6
      f6->setShape(new osg::Box(osg::Vec3(-1.5,1.5,0),1.5,1.5,0.02));		
      floor->addDrawable(f6);
      osg::ref_ptr<osg::ShapeDrawable> f7 = new osg::ShapeDrawable;		//Baldosa 7
      f7->setShape(new osg::Box(osg::Vec3(1.5,3.0,0),1.5,1.5,0.02));		
      floor->addDrawable(f7);
      osg::ref_ptr<osg::ShapeDrawable> f8 = new osg::ShapeDrawable;		//Baldosa 8
      f8->setShape(new osg::Box(osg::Vec3(0.0,3.0,0),1.5,1.5,0.02));		
      floor->addDrawable(f8);
      osg::ref_ptr<osg::ShapeDrawable> f9 = new osg::ShapeDrawable;		//Baldosa 9
      f9->setShape(new osg::Box(osg::Vec3(-1.5,3.0,0),1.5,1.5,0.02));		
      floor->addDrawable(f9);
      osg::ref_ptr<osg::ShapeDrawable> f10 = new osg::ShapeDrawable;	//Baldosa 10
      f10->setShape(new osg::Box(osg::Vec3(1.5,-1.5,0),1.5,1.5,0.02));		
      floor->addDrawable(f10);
      osg::ref_ptr<osg::ShapeDrawable> f11 = new osg::ShapeDrawable;	//Baldosa 11
      f11->setShape(new osg::Box(osg::Vec3(0.0,-1.5,0),1.5,1.5,0.02));		
      floor->addDrawable(f11);
      osg::ref_ptr<osg::ShapeDrawable> f12 = new osg::ShapeDrawable;	//Baldosa 12
      f12->setShape(new osg::Box(osg::Vec3(-1.5,-1.5,0),1.5,1.5,0.02));		
      floor->addDrawable(f12);
      
      Textura* textureFloor = new Textura( "floor.jpg", floor );
      
      osg::ref_ptr<osg::MatrixTransform> transFloor = new osg::MatrixTransform;
      transFloor->setMatrix( osg::Matrix::translate(0.0,0.0,-0.05) );
      transFloor->addChild( floor );
      
      return transFloor;
}

osg::Geode* Escena3D::crearEspacio( const std::string& nombreTextura, double radio)
{
    osg::Sphere *spaceSphere = new osg::Sphere( osg::Vec3( 0.0, 0.0, 0.0 ), radio );

    osg::ShapeDrawable *sSpaceSphere = new osg::ShapeDrawable (spaceSphere);

    if( !nombreTextura.empty() )
    {
        osg::Image* image = osgDB::readImageFile (nombreTextura);
        if ( image )
        {
            sSpaceSphere->getOrCreateStateSet()->setTextureAttributeAndModes( 0, new osg::Texture2D( image ), osg::StateAttribute::ON );
            sSpaceSphere->setColor( osg::Vec4(1.0f,1.0f,1.0f,1.0f) );
        }
    }

    osg::Geode* geodeSpace = new osg::Geode();
    geodeSpace->addDrawable (sSpaceSphere);
    return geodeSpace;

}

osg::ref_ptr< osg::Group > Escena3D::enter()
{
      osg::ref_ptr<osg::Geode> e = new osg::Geode;
      osg::ref_ptr<osg::ShapeDrawable> pared = new osg::ShapeDrawable;
      pared->setShape(new osg::Box(osg::Vec3(0,0,0.2),0.4,0.05,.5));		
      e->addDrawable(pared);
      Textura* texPacoPark = new Textura("pacoPark.jpg", e);
      
      osg::ref_ptr<osg::MatrixTransform> posicion = new osg::MatrixTransform;
      posicion->setMatrix( osg::Matrix::rotate(-0.75f, osg::Z_AXIS) * osg::Matrix::translate(-2.05,-1.25,0.0) );
      posicion->addChild(e);
      
      osg::ref_ptr<osg::MatrixTransform> posicion2 = new osg::MatrixTransform;
      posicion2->setMatrix( osg::Matrix::rotate(-0.75f, osg::Z_AXIS) * osg::Matrix::translate(-1.22,-2.03,0.0) );
      posicion2->addChild(e);
      
      osg::ref_ptr<osg::Group> todo = new osg::Group;
      todo->addChild(posicion);
      todo->addChild(posicion2);
      
      return todo;
}

osg::ref_ptr< osg::Group > Escena3D::naturaleza()
{
      osg::ref_ptr<osg::Group> arbol = new osg::Group;
   
      osg::ref_ptr<osg::Geode> copa = new osg::Geode;
      osg::ref_ptr<osg::ShapeDrawable> geoArbusto = new osg::ShapeDrawable;
      geoArbusto->setShape(new osg::Sphere(osg::Vec3(0,0,0.22), 0.08));
      copa->addDrawable(geoArbusto);
      Textura* texCopa = new Textura("arbusto.jpg", copa);
      
      osg::ref_ptr<osg::Geode> tronco = new osg::Geode;
      osg::ref_ptr<osg::ShapeDrawable> geoTronco = new osg::ShapeDrawable;
      geoTronco->setShape(new osg::Box(osg::Vec3(0,0,0),0.02,0.02,0.3));
      tronco->addDrawable(geoTronco);
      Textura* texTronco = new Textura("madera.jpg", tronco);
      
      arbol->addChild( copa );
      arbol->addChild( tronco );
      
      //Arbustos entrada
      osg::ref_ptr<osg::MatrixTransform> arbusto1 = new osg::MatrixTransform;
      arbusto1->setMatrix( osg::Matrix::translate(-1.82,-1.48,0.0) );
      arbusto1->addChild(arbol);
      osg::ref_ptr<osg::MatrixTransform> arbusto2 = new osg::MatrixTransform;
      arbusto2->setMatrix( osg::Matrix::translate(-1.6,-1.2,0.0) );
      arbusto2->addChild(arbol);
      osg::ref_ptr<osg::MatrixTransform> arbusto3 = new osg::MatrixTransform;
      arbusto3->setMatrix( osg::Matrix::translate(-1.38,-0.92,0.0) );
      arbusto3->addChild(arbol);
      osg::ref_ptr<osg::MatrixTransform> arbusto4 = new osg::MatrixTransform;
      arbusto4->setMatrix( osg::Matrix::translate(-1.48,-1.82,0.0) );
      arbusto4->addChild(arbol);
      osg::ref_ptr<osg::MatrixTransform> arbusto5 = new osg::MatrixTransform;
      arbusto5->setMatrix( osg::Matrix::translate(-1.23,-1.57,0.0) );
      arbusto5->addChild(arbol);
      osg::ref_ptr<osg::MatrixTransform> arbusto6 = new osg::MatrixTransform;
      arbusto6->setMatrix( osg::Matrix::translate(-0.98,-1.32,0.0) );
      arbusto6->addChild(arbol);
      //Arbustos ambiente
      osg::ref_ptr<osg::MatrixTransform> arbusto7 = new osg::MatrixTransform;
      arbusto7->setMatrix( osg::Matrix::translate(-1.0,-0.0,0.0) );
      arbusto7->addChild(arbol);
      osg::ref_ptr<osg::MatrixTransform> arbusto8 = new osg::MatrixTransform;
      arbusto8->setMatrix( osg::Matrix::translate(-0.36,0.45,0.0) );
      arbusto8->addChild(arbol);
      osg::ref_ptr<osg::MatrixTransform> arbusto9 = new osg::MatrixTransform;
      arbusto9->setMatrix( osg::Matrix::translate(1.5,-0.3,0.0) );
      arbusto9->addChild(arbol);
      osg::ref_ptr<osg::MatrixTransform> arbusto10 = new osg::MatrixTransform;
      arbusto10->setMatrix( osg::Matrix::translate(1.,0.15,0.0) );
      arbusto10->addChild(arbol);
      osg::ref_ptr<osg::MatrixTransform> arbusto11 = new osg::MatrixTransform;
      arbusto11->setMatrix( osg::Matrix::translate(-1.8,0.2,0.0) );
      arbusto11->addChild(arbol);
      osg::ref_ptr<osg::MatrixTransform> arbusto12 = new osg::MatrixTransform;
      arbusto12->setMatrix( osg::Matrix::translate(0.4,-0.6,0.0) );
      arbusto12->addChild(arbol);
      osg::ref_ptr<osg::MatrixTransform> arbusto13 = new osg::MatrixTransform;
      arbusto13->setMatrix( osg::Matrix::translate(0.2,1.6,0.0) );
      arbusto13->addChild(arbol);
      osg::ref_ptr<osg::MatrixTransform> arbusto14 = new osg::MatrixTransform;
      arbusto14->setMatrix( osg::Matrix::translate(-1.5,1.9,0.0) );
      arbusto14->addChild(arbol);
      osg::ref_ptr<osg::MatrixTransform> arbusto15 = new osg::MatrixTransform;
      arbusto15->setMatrix( osg::Matrix::translate(-0.6,2.6,0.0) );
      arbusto15->addChild(arbol);
      
      osg::ref_ptr<osg::Group> arbustos = new osg::Group;
      arbustos->addChild(arbusto1);
      arbustos->addChild(arbusto2);
      arbustos->addChild(arbusto3);
      arbustos->addChild(arbusto4);
      arbustos->addChild(arbusto5);
      arbustos->addChild(arbusto6);
      arbustos->addChild(arbusto7);
      arbustos->addChild(arbusto8);
      arbustos->addChild(arbusto9);
      arbustos->addChild(arbusto10);
      arbustos->addChild(arbusto11);
      arbustos->addChild(arbusto12);
      arbustos->addChild(arbusto13);
      arbustos->addChild(arbusto14);
      arbustos->addChild(arbusto15);
      
      return arbustos;
}

osg::ref_ptr< osg::Group > Escena3D::entradaLuces()
{
      osg::ref_ptr<osg::Geode> p = new osg::Geode;
      osg::ref_ptr<osg::ShapeDrawable> port = new osg::ShapeDrawable;
      port->setShape(new osg::Box(osg::Vec3(-0.55,3.8,0.8),3.4,0.05,1.9));		
      p->addDrawable(port);
      Textura* texPacoPark = new Textura("portada.jpg", p);
      
      osg::ref_ptr<osg::Group> todo = new osg::Group;
      todo->addChild(p);
      
      return todo;
}

