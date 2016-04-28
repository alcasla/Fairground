cmake_minimum_required(VERSION 2.8)
if(COMMAND cmake_policy)
      cmake_policy(SET CMP0003 NEW)
endif(COMMAND cmake_policy)

PROJECT(Parque)

FIND_PACKAGE(OpenSceneGraph  COMPONENTS osgViewer osgUtil osgGA osgDB osgText osgParticle)

include_directories( include )
file( GLOB TARGET_SRC *.cpp )

LINK_LIBRARIES ( ${OPENSCENEGRAPH_LIBRARIES} )
LINK_DIRECTORIES ( ${OPENSCENEGRAPH_LIB_DIRS} )

include_directories (${OPENSCENEGRAPH_INCLUDE_DIRS})
add_executable (parque ${TARGET_SRC} )
target_link_libraries(parque ${OPENSCENEGRAPH_LIBRARIES})