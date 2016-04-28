#include <osg/Node>
#include "Escena3D.h"

#include <osg/Geode>
#include <osgViewer/Viewer>
#include <osgGA/TrackballManipulator>

#include "KeyBoardEvent.h"

int main()
{
    osgViewer::Viewer viewer;
    osg::ref_ptr <Escena3D> sc = new Escena3D();
    KeyBoardEvent *keyboardevent= new KeyBoardEvent( sc );

    viewer.setSceneData( sc );
    viewer.addEventHandler(keyboardevent);

//     viewer.setCameraManipulator(new osgGA::TrackballManipulator());
    viewer.realize();
    
    while( !viewer.done() )
    {
       sc->update( keyboardevent->getOption() );
       viewer.frame();
    }
    return 0;
}

