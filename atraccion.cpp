#include "atraccion.h"
#include "Euclidea.h"

using namespace std;


Atraccion::Atraccion()
{
      Builder* builderCoche = new BuilderPLY( "coche.ply" );
      osg::ref_ptr<osg::Node> geomCoche= builderCoche->buildObject();
      Textura *coche = new Textura( "coche.jpg", geomCoche );

      Builder* geomBase = new BuilderBase();
      osg::ref_ptr<osg::Node> base= geomBase->buildObject();

      Coche *coche1 = new Coche( geomCoche );
      coche1->inicialize( -0.25, 0.0, 0.022, 1.2 );
      coches.push_back(coche1);

      Coche *coche2 = new Coche( geomCoche );
      coche2->inicialize( 0.25, 0.0, 0.022, 2.0 );
      coches.push_back(coche2);
      
      Coche *coche3 = new Coche( geomCoche );
      coche3->inicialize( 0.0, 0.0, 0.022, 4.0 );
      coches.push_back(coche3);
      
      this->addChild(base);
      this->addChild(coches[0]);
      this->addChild(coches[1]);
      this->addChild(coches[2]);
}

void Atraccion::update()
{
      updateChoques();
      coches[0]->update();
      coches[1]->update();
      coches[2]->update();
}

void Atraccion::updateChoques()
{
      int angulo = rand()%10;	 	// random[0, 10]
      angulo+=10;			// r = [10,20]
   
      for( int i=0 ; i<coches.size() ; i++ )
         for( int j=i+1 ; j<coches.size() ; j++ )
         {
	  if( distanciaEuclidea( coches[i]->getPosX(),coches[i]->getPosY(), 
			      coches[j]->getPosX(),coches[j]->getPosY()) < 0.1 )
	  {
	     coches[i]->girar( angulo );
	     coches[j]->girar( angulo );
	  }
         }
}

float Atraccion::getPositionX(int numCar)
{
      return coches[numCar]->getPosX();
}

float Atraccion::getPositionY(int numCar)
{
      return coches[numCar]->getPosY();
}

float Atraccion::getAngle(int numCar)
{
      return coches[numCar]->getAngle();
}

