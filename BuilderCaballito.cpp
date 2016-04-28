#include "BuilderCaballito.h"
//#include <osg/Texture3D>

BuilderCaballito::BuilderCaballito()
{
}

osg::Node* BuilderCaballito::buildObject()
{
    osg::Group* g = new osg::Group;
    osg::ref_ptr<osg::MatrixTransform> matrizC = new osg::MatrixTransform;
    
   // osg::ref_ptr<osg::Texture3D> texture = new osg::Texture3D;
    //osg::ref_ptr<osg::Image> image = osgDB::readImageFile("lata-coke.jpg");
    

	//texture->setImage(image.get());

    BuilderPLY* ply = new BuilderPLY( "caballito2.ply");
    osg::Node* caballo = ply->buildObject();

    ply = new BuilderPLY( "barra_carrusel.ply" );
    osg::Node* barra = ply->buildObject();
    
    matrizC->setMatrix( osg::Matrix::scale(2.3,2.3,2.3) * osg::Matrix::translate(0,5.8,2.5) );
    
    matrizC->addChild( caballo );
  
    
    g->addChild( matrizC );
    //g->addChild( matrizB );

	//g->getOrCreateStateSet()->setTextureAttributeAndModes(0,texture.get(),osg::StateAttribute::ON);

	
    
    return g;
}

	
