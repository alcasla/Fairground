#ifndef BUILDERTIOVIVO_H
#define BUILDERTIOVIVO_H

#include <osg/Node>
#include <osg/MatrixTransform>
#include <osg/Geode>
#include <osg/ShapeDrawable>
#include <osg/Group>

#include "Builder.h"

using namespace std;

class BuilderTiovivo : public Builder
{
      public:
         BuilderTiovivo();
         virtual osg::Node* buildObject();
};

#endif

