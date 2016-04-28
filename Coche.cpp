#include "Coche.h"

// static float movimiento = 0.0025;
static double grado = 0.01745329251;

Coche::Coche(osg::ref_ptr<osg::Node> nod)
{
      addChild(nod);
      angle = 1.57;
      movimiento = 0.002;
      updating = true;
}

void Coche::inicialize( float x, float y , float z, double ang )
{
   posX = x;
   posY = y;
   posZ = z;
   angle = ang;
}

void Coche::setScale(float x, float y,float z)
{
      setMatrix(osg::Matrix::scale(x,y,z));
}

void Coche::setTranslate(float x, float y, float z)
{
      setMatrix(getMatrix()*osg::Matrix::translate(x,y,z));
}

void Coche::setRotate(float angle, int x, int y, int z)
{
      setMatrix(getMatrix()*osg::Matrix::rotate(angle,x,y,z));
}

float Coche::getPosX()
{
      return posX;
}

float Coche::getPosY()
{
      return posY;
}

double Coche::getAngle()
{
      return angle;
}

void Coche::update()
{
   if(updating)
   {
      int angulo = rand()%60 - 30;  // random[-25, 25]
      if( angulo > 0 ) angulo+=30;	else angulo-=30;	// r = [-50,-25] U [25,50]
      
      //Control choque con paredes
      if( posX > 0.52 )	//Choca lado X
      {
         girar( angulo );
         posX -= 0.02;
      }
      if( posX < -0.52 )	//Choca lado -X
      {
         girar( angulo );
         posX += 0.02;
      }
      if( posY > 0.27 )	//Choca lado Y
      {
         girar( angulo );
         posY -= 0.02;
      }
      if( posY < -0.27 )	//Choca lado -Y
      {
         girar( angulo );
         posY += 0.02;
      }
      
      if(angle > 6.2832)  angle -= 6.2832;	//Módulo 2*PI del ángulo
      
      posX += sin(angle)*movimiento;
      posY -= cos(angle)*movimiento;
      
      setScale(.001,.001,.001);
      setRotate(angle, 0,0,1);
      setTranslate( posX, posY, posZ );
   }
}

void Coche::girar( int grados )
{
      angle += grados*grado;
}

void Coche::stoper()
{
      updating = !updating;
}

void Coche::speed( float incDec )
{
      movimiento = movimiento*incDec;
      if(movimiento < 0.1 && incDec>1 )	//Cuando paramos para arrancar
         movimiento = movimiento*incDec;
}

