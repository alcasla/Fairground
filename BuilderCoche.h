#ifndef BUILDERCOCHE_H
#define BUILDERCOCHE_H

#include <osg/Node>
#include <osg/MatrixTransform>

#include "Builder.h"
#include "BuilderPLY.h"

using namespace std;

class BuilderCoche : public Builder
{
      public:
         BuilderCoche();
         virtual osg::Node* buildObject();
};

#endif
