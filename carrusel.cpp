#include "carrusel.h"
#include "Builder.h"
#include "BuilderPLY.h"
#include "BuilderCaballito.h"
#include "BuilderTiovivo.h"

#include <iostream>
#include <osg/Texture2D>
#include <osg/Vec3>
#include <osgDB/ReadFile> 
#include <osg/PositionAttitudeTransform>
#include <osg/AnimationPath>


using namespace std;

Carrusel::Carrusel()
{
      for(int i=0;i<4;i++){
	     dato[i]=0.0;
      }
      angle =0.0;
      inc = 0.4;
	
      //Edificio
      Builder* geomTiovivo = new BuilderTiovivo();
      osg::ref_ptr<osg::Node> tiovivo = geomTiovivo->buildObject();
      Textura *textureBuild = new Textura( "madera.jpg", tiovivo );
      
      //Geometría caballo
      Builder* geomCaballo = new BuilderCaballito();
      osg::ref_ptr<osg::Node> caballo = geomCaballo->buildObject();
      Textura *textureHorse = new Textura( "caballo.jpg", caballo );

      BuilderPLY* ply = new BuilderPLY( "barra_carrusel.ply" );
      osg::ref_ptr<osg::Node> barra = ply->buildObject();
      Textura *textureBarra = new Textura( "barra.jpg", barra );

      osg::ref_ptr<osg::MatrixTransform> matrizB = new osg::MatrixTransform;

      matrizB->setMatrix( osg::Matrix::scale(.1,.1,.1)*osg::Matrix::scale(0.028, 0.028, 0.038));
      matrizB->addChild( barra );
    

      //Caballo 1
      cab1 = new Caballito( caballo,0.0,-0.2,0.0,true );
      osg::ref_ptr<osg::MatrixTransform> barra1 = new osg::MatrixTransform;
      barra1->setMatrix(osg::Matrix::translate(0.0,-0.2,-0.05));
      barra1->addChild(matrizB);
      //Caballo 2
      cab2 = new Caballito( caballo, 0.2,0.0,0.0,false);
      osg::ref_ptr<osg::MatrixTransform> barra2 = new osg::MatrixTransform;
      barra2->setMatrix(osg::Matrix::translate(0.24,0.05,-0.05));
      barra2->addChild(matrizB);
      //Caballo 3
      cab3 = new Caballito( caballo,0.0,0.2,0.0,true);
      osg::ref_ptr<osg::MatrixTransform> barra3 = new osg::MatrixTransform;
      barra3->setMatrix(osg::Matrix::translate(0.0,0.29,-0.05));
      barra3->addChild(matrizB);
      //Caballo 4
      cab4 = new Caballito( caballo,-0.2,0.0,0.0,false);
      osg::ref_ptr<osg::MatrixTransform> barra4 = new osg::MatrixTransform;
      barra4->setMatrix(osg::Matrix::translate(-0.24,0.05,-0.05));
      barra4->addChild(matrizB);
	
      rotado = new osg::MatrixTransform;
      rotado->addChild(tiovivo);
      rotado->addChild(cab1);
	
      rotado->addChild(cab2);
      rotado->addChild(cab3);
      rotado->addChild(cab4);
      rotado->addChild(barra1);
      rotado->addChild(barra2);
      rotado->addChild(barra3);
      rotado->addChild(barra4);
	

      this->addChild(rotado);
}
float Carrusel::incremento(osg::ref_ptr<Caballito> cab,int i){
	if(cab->getValor()){
		dato[i]-=.002;
		if(dato[i]<-.05){
			cab->setValor(false);
		}
	}
	else{
		dato[i]+=.002;
		if(dato[i]>.05){
			cab->setValor(true);
		}
	}
}
void Carrusel::update(){
	 
	  incremento(cab1,0);
	  cab1->setScale( 0.028, 0.028, 0.038 );
      	  cab1->setRotate(0.0f, 1, 0, 0);
     	  cab1->setTranslate( 0, -0.2, dato[0]);

	incremento(cab2,1);
	 cab2->setScale( 0.028, 0.028, 0.038 );
     	 cab2->setRotate(1.57f, 0, 0, 1);
      	 cab2->setTranslate( 0.2, 0.0, dato[1]);

	incremento(cab3,2);
	 cab3->setScale( 0.028, 0.028, 0.038 );
     	 cab3->setRotate(3.14f, 0, 0, 1);
     	 cab3->setTranslate( 0.0, 0.2, dato[2]);

	incremento(cab4,3);
	 cab4->setScale( 0.028, 0.028, 0.038 );
      	 cab4->setRotate(-1.57f, 0, 0, 1);
      	 cab4->setTranslate( -0.2, 0.0, dato[3]);
	
	angle += inc;
	rotado->setMatrix(osg::Matrix::rotate(osg::DegreesToRadians(angle),osg::Z_AXIS));

}

void Carrusel::click()
{
      if(inc<=2.025) inc = inc*1.5;
      else inc = 0.4;
}

