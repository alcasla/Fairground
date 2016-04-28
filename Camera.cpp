#include "Camera.h"

Camera::Camera()
{
      setClearMask(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

      osg::Vec3d eye(0.0,-4.0,2.0);
      osg::Vec3d center(0.0,0.0,0.8);
      osg::Vec3d up(0.0,1.0,0.0);

      setViewMatrixAsLookAt(eye,center,up);
}

void Camera::changeCamera(osg::Vec3 eye,osg::Vec3 center,osg::Vec3 up)
{
      setViewMatrixAsLookAt(eye,center,up);
}
