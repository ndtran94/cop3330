/*
Implementation file for classes:
Box
Cylinder
Plane

*/


#include <shapes.h>
#include <cmath> // M_PI defined to 21 significant digits



// 
// 
// BOX DEF CONSTRUCTOR
// 
// Pre-condition:
// Post-condition: initializes private data to 0
Box::Box() : length_( 0.0 ), width_( 0.0 ), height_( 0.0 )
{
  //  std::cout << "Box() " << std::endl; 
}
//
//
// BOX PARAM. CONSTRUCTOR
//
// Pre-Condition: float l, w, h
// Post-Condition: Iniitalize data with parameters
Box::Box( float l, float w, float h ) : length_( l ), width_( w ), height_( h )
{
  // std::cout << "Box( l, w, h )" << std::endl; 
}   
//
//
// BOX DESTRUCTOR
//
// Pre-Condition:
// Post-Condition: deallocate memory
Box::~Box()
{
  //  std::cout << "~BOX() " << std::endl;
}
//
//
// BOX VOLUME
//
// Pre-Condiiton: l,w,h are initialized
// Post-condition: returns volume in float
float Box::Volume() const
{
  float retval = length_ * width_ * height_;
  return retval;
}
//
//
// CYLINDER CONSTRUCTOR
//
// Pre-Condition:
// Post-Condition: initialize private state
Cylinder::Cylinder() : length_( 0.0 ), radius_( 0.0 )
{
  // std::cout << "CYLINDER() " << std::endl;
}
//
// CYLINDER PARM CONSTRUCTOR
// 
// Pre-Condition: 
// Post-Condition: initialize private state
Cylinder::Cylinder( float l, float r ) : length_( l ), radius_( r )
{
  // std::cout << "CYLINDER( l ,  r )" << std::endl;
} 
//
//
// CYLINDER DECONSTRUCTOR
//
// Pre-Condition:
// Post-Condition: deallocate memory
Cylinder::~Cylinder()
{
  // std::cout << "~Cylinder()" << std::endl; 
}
//
//
// CYLINDER VOLUME
// Pre-Condiiton: 
// Post-Condition: returns computed float Volume
float Cylinder::Volume() const
{
  return ( M_PI * pow( radius_, 2 ) * length_ ); 
}
//
//
// PLANE DEFAULT CONSTRUCTOR
// Pre-Condition:
// Post-Condition: intiializes plane default constructor
Plane::Plane() : length_( 0.0 ), width_( 0.0 )
{
  // std::cout << "PLANE()" << std::endl;
}
//
//
// PLANE PARAM CONSTRUCTOR
// Pre-Condition: passes float l , w
// Post-Condition: initializes private state with constructor
Plane::Plane( float l , float w ) : length_( l ), width_( w )
{
  // std::cout << " PLANE( l ,w ) " << std::endl; 
}
//
//
// PLANE DECONSTRUCTOR
// Pre-Condition:
// Post-Condiiton: deallocate memory
Plane::~Plane()
{
  // std::cout << "~PLANE() " << std::endl;
}
//
//
// PLANE AREA
// Pre-Condition:
// Post-Condition: compute area float returns float
float Plane::Area() const
{
  return( length_ * width_ ); 
}
