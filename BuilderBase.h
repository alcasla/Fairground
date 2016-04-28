#ifndef BUILDERBASE_H
#define BUILDERBASE_H

#include <osg/Node>
#include <osg/MatrixTransform>
#include <osg/Geode>
#include <osg/ShapeDrawable>
#include <osg/Group>

#include "Builder.h"
#include "Textura.h"

using namespace std;

class BuilderBase : public Builder
{
      public:
         BuilderBase();
         virtual osg::Node* buildObject();
};

#endif
