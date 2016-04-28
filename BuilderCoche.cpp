#include "BuilderCoche.h"

BuilderCoche::BuilderCoche(){}


osg::Node* BuilderCoche::buildObject()
{
	BuilderPLY *ply = new BuilderPLY( "coche.ply" );
	osg::Node *coc = ply->buildObject();
}
