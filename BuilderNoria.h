#ifndef BUILDERNORIA_H
#define BUILDERNORIA_H

#include <osg/Node>
#include <osg/MatrixTransform>
#include <osg/Geode>
#include <osg/ShapeDrawable>
#include <osg/Group>

#include "Builder.h"

using namespace std;

class BuilderNoria : public Builder
{
      public:
         BuilderNoria();
         virtual osg::Node* buildObject();
};

#endif