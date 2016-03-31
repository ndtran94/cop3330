#include <shapes.h>

// 
// 
// BOX DEF CONSTRUCTOR
// 
// Pre-condition:
// Post-condition: initializes private data to 0
Box::Box() : length_( 0.0 ), width_( 0.0 ), height( 0.0 )
{
  std::cout << "Box() " << std::endl; 
}
//
//
// BOX PARAM. CONSTRUCTOR
//
// Pre-Condition: float l, w, h
// Post-Condition: Iniitalize data with parameters
Box::Box( float l, float w, float h ) : length_( l ), width_( w ), height_( w )
{
  std::cout << "Box( l, w, h )" << std::endl; 
}   
//
//
// BOX DESTRUCTOR
//
// Pre-Condition:
// Post-Condition: deallocate memory
Box::~Box()
{
  std::cout << "~BOX() " << std::endl;
}
