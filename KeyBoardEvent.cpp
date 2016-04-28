#include "KeyBoardEvent.h"
#include <osgViewer/Viewer>


using namespace std;

KeyBoardEvent::KeyBoardEvent( osg::ref_ptr<Escena3D> e )
{
	scene = e;
	option = 0;
}

int KeyBoardEvent::getOption()
{
      return option;
}

bool KeyBoardEvent::handle(const osgGA::GUIEventAdapter& ea,osgGA::GUIActionAdapter& aa)
{
      switch(ea.getEventType())
      {
	  case(osgGA::GUIEventAdapter::KEYDOWN):
	  {
	        switch(ea.getKey())
	        {
		    case 'w': {scene->getCamera()->setViewMatrixAsLookAt(osg::Vec3d(0.0,3.0,0.2),osg::Vec3d(0.0,0.0,0.0),osg::Vec3d(0.0,-1.0,0.0));
			      option = 0;}
			      break;
		    case 'q': {scene->getCamera()->setViewMatrixAsLookAt(osg::Vec3d(0.0,-2.5,0.2),osg::Vec3d(0.0,0.0,0.0),osg::Vec3d(0.0,1.0,0.0));
			      option = 0;}
			      break;
		    case 'd': {scene->getCamera()->setViewMatrixAsLookAt(osg::Vec3d(0.0,-4.0,2.0),osg::Vec3d(0.0,0.0,0.8),osg::Vec3d(0.0,1.0,0.0));
			      option = 0;}
			      break;
		    case 'p': {scene->getCamera()->setViewMatrixAsLookAt(osg::Vec3d(-3.0,-3.1,1.2),osg::Vec3d(-0.5,-0.5,0.0),osg::Vec3d(0.0,0.0,1.0));
			      option = 0;}
			      break;
		    case 'c': option = 1;
			      break;
		    case 'z': coche->stoper();
			      break;
		    case 'a': coche->girar(4);
			      break;
		    case 's': coche->girar(-4);
			      break;
		    case 'o': coche->speed( 1.2 );
			      break;
		    case 'l': coche->speed( 0.8 );
			      break;
	        }
	  }
	  case(osgGA::GUIEventAdapter::RELEASE):
	  {
	        osgViewer::Viewer* viewer = dynamic_cast<osgViewer::Viewer*>(&aa);
	        if( viewer )
	        {
		    osg::ref_ptr<osgUtil::LineSegmentIntersector> intersector = new osgUtil::LineSegmentIntersector( osgUtil::Intersector::WINDOW, ea.getX(), ea.getY() );
		    osgUtil::IntersectionVisitor iv( intersector.get() );
		    iv.setTraversalMask( ~0x1 );
		    viewer->getCamera()->accept( iv );
		    
		    if( intersector->containsIntersections() )
		    {
			osgUtil::LineSegmentIntersector::Intersection result = *( intersector->getIntersections().begin() );
			
			//Recorre objetos de cerca a lejos hasta encontrar COCHE, NORIA o CARRUSEL
			while( !dynamic_cast<Coche*> (result.nodePath.back()) 
			   && !dynamic_cast<Noria*> (result.nodePath.back())
			   && !dynamic_cast<Carrusel*> (result.nodePath.back())
			   && result.nodePath.size()>1 )
			   { result.nodePath.pop_back(); }
			   
			if( dynamic_cast<Coche*> (result.nodePath.back()) )	//Click Coche
			{
			   coche = (Coche*)result.nodePath.back();
			}
			if( dynamic_cast<Noria*> (result.nodePath.back()) )	//Click Noria
			{
			   Noria* noria = (Noria*)result.nodePath.back();
			   noria->click();
			}
			if( dynamic_cast<Carrusel*> (result.nodePath.back()) )	//Click TioVivo
			{
			   Carrusel* tiovivo = (Carrusel*)result.nodePath.back();
			   tiovivo->click();
			}
		    }
	        }
	        return false;
	  }
	  default:
	     return false;
      }
}

