#ifndef BUILDER_H
#define BUILDER_H

#include <osg/Group>
#include <osg/Referenced>


class Builder :public osg::Referenced
{
   public:
      virtual osg::Node* buildObject()=0;
};

#endif //BUILDER_H