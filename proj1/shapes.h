/*
Definitions for classes:
Box, 
Cylinder,
Plane
*/

#ifndef _SHAPES_H
#define _SHAPES_H
//#include <cmath> // M_PI defined to 21 significant digits
#include <iostream>


class Box
{
 public:
  // Default Constructor
  Box (); 
  // Parameterized constructor, initializes class variables
  Box( float l , float w , float h ); 
  // Destructor
  virtual ~Box();
  // Returns Volume of box object
  float Volume() const;
 private:
  Box           ( const Box&  ); // Private copy constructor
  Box& operator=( const Box&  ); // Private assign. operator
 protected:
  float length_;
  float width_;
  float height_;
};
  
class Cylinder
{
 public:
  Cylinder();                       // Default Constructor
  Cylinder( float l , float r );    // Param. Construtor 
  virtual ~Cylinder();              // Destructor
  float Volume() const;             // return volume
 private:
  Cylinder           ( const Cylinder&  ); // copy constructor
  Cylinder& operator=( const Cylinder&  ); // assign. operator
 protected:
  float length_;
  float radius_;
};

class Plane
{
 public:
  Plane();                    // default constructor 
  Plane( float l , float w ); // Parameterized Constructor
  virtual ~Plane();           // Destructor
  float Area() const;         // compute Plane area
 private:
  Plane           ( const Plane & ); // copy constructor
  Plane& operator=( const Plane&  );  // assignm. operator
 protected:
  float length_;
  float width_;
};

#endif 
