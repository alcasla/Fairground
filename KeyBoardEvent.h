#ifndef KEYBOARDEVENT_H
#define KEYBOARDEVENT_H

#include <iostream>
#include <osgGA/GUIEventHandler>
#include <osg/Vec3d>
#include <osg/PolygonMode>
#include <osgUtil/LineSegmentIntersector>
#include <osgViewer/Viewer>
#include <osg/ShapeDrawable>
#include <osg/MatrixTransform>
#include <osg/Node>

#include "Coche.h"
#include "Cabina.h"
#include "Escena3D.h"


class KeyBoardEvent : public osgGA::GUIEventHandler
{
      private:
	osg::ref_ptr<Escena3D> scene;
	osg::ref_ptr<Coche> coche;
	int option;
	
      public:
	KeyBoardEvent( osg::ref_ptr<Escena3D> e );
          virtual bool handle(const osgGA::GUIEventAdapter& ea,osgGA::GUIActionAdapter& aa);
          osg::Node* getOrCreateSelectionBox();
          int getOption();
};

#endif

