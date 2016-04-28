#ifndef BUILDERCABINA_H
#define BUILDERCABINA_H

#include <osg/Node>
#include <osg/Geode>
#include <osg/ShapeDrawable>

#include "Builder.h"

using namespace std;


class BuilderCabina :public Builder
{
    private:

    public:
      BuilderCabina();
      virtual osg::Node* buildObject();
};

#endif //BUILDERCABINA_H