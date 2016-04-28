#ifndef TEXTURA_H
#define TEXTURA_H

#include <osg/StateSet>
#include <osg/Texture2D>
#include <osgDB/ReadFile>

class Textura :public osg::StateSet
{
      public:
         Textura( std::string name, osg::ref_ptr<osg::Node> n );
};

#endif