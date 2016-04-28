#ifndef BUILDERCABALLITO_H
#define BUILDERCABALLITO_H

#include <osg/Node>
#include <osg/MatrixTransform>

#include "Builder.h"
#include "BuilderPLY.h"


using namespace std;


class BuilderCaballito : public Builder
{
    public:
      BuilderCaballito();
      virtual osg::Node* buildObject();
};

#endif //BUILDERPLY_H
