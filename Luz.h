#ifndef LUZ_H
#define LUZ_H

#include <osg/Light>
#include <osg/Group>
#include <osg/LightSource>

class Luz :public  osg::Group
{
      public:
         Luz(unsigned int num, const osg::Vec3& trans, const osg::Vec4& color);
};

#endif