#ifndef CAMERA_H
#define CAMERA_H

#include <osg/Camera>
#include <osg/MatrixTransform>

class Camera:public osg::Camera
{
      public:
	Camera();
	void changeCamera(osg::Vec3 eye,osg::Vec3 center,osg::Vec3 up);
};
#endif
