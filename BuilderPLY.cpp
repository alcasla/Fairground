#include "BuilderPLY.h"

BuilderPLY::BuilderPLY(string name)
{
    nombre = name;
}

osg::Node* BuilderPLY::buildObject()
{
   osg::Node* n = new osg::Node;
   n = osgDB::readNodeFile( nombre );
   
   return n;
}
