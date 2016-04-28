#include "Luz.h"

Luz::Luz(unsigned int num, const osg::Vec3& trans, const osg::Vec4& color)
{
      osg::ref_ptr<osg::Light> light = new osg::Light;
      light->setLightNum(num);
//       light->setDiffuse(color);
      light->setPosition( osg::Vec4(trans[0],trans[1],trans[2],1.0f));
      light->setAmbient( osg::Vec4( 0.3f, 0.3f, 0.3f, 1.0f ) );

      osg::ref_ptr<osg::LightSource> lightSource = new osg::LightSource;
      lightSource->setLight(light);
      addChild(lightSource);
}
