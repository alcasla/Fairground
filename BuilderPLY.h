#ifndef BUILDERPLY_H
#define BUILDERPLY_H

#include <osg/Geometry>
#include <osg/Node>
#include <osgDB/ReadFile>
#include <osg/Referenced>

#include "Builder.h"

using namespace std;


class BuilderPLY :public Builder
{
    private:
       string nombre;

    public:
      BuilderPLY(string name);
      virtual osg::Node* buildObject();
};

#endif //BUILDERPLY_H