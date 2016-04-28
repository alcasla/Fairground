#include "Textura.h"


Textura::Textura( std::string name, osg::ref_ptr<osg::Node> n )
{
      osg::Texture2D* texture = new osg::Texture2D;
      texture->setDataVariance( osg::Object::DYNAMIC );	//Posibilita control de borrado
      osg::Image* image = osgDB::readImageFile( name );
      if( !image )  exit(-1);
      texture->setImage( image );
      texture->setWrap( osg::Texture::WRAP_S, osg::Texture::REPEAT );
      texture->setWrap( osg::Texture::WRAP_T, osg::Texture::REPEAT );
      osg::StateSet* stateOne = new osg::StateSet;
      stateOne->setTextureAttributeAndModes( 0, texture, osg::StateAttribute::ON );
      n->setStateSet( stateOne );
}
