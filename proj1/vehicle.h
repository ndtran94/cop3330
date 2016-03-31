/*
  Defines all classes for vehicles
  includes classes: 
  Class Vehicle, Car, Truck, Van, Flatbbed, Tanker
*/
#include <iostream>
#ifndef _VEHICLES_H
#define _VEHICLES_H
#include <shapes.h>
enum VehicleType{ badSn = 0 , vehicle = 1 , car = 2, truck = 3, van = 4, tanker = 5, flatbed = 6 };

class Vehicle
{
 public:
  Vehicle();                         // Default Constructor
  explicit Vehicle( char const * , unsigned int );   // Parameter Constructor
  virtual ~Vehicle();                // Destructor
  const char*          SerialNumber     () const ; // returns sn
  unsigned int         PassengerCapacity() const ; //return cap
  virtual float        LoadCapacity     () const ; // returns 0 
  virtual const char*  ShortName        () const;  // returns "UNK"
  virtual float        Toll             () const;  // return toll
  static VehicleType   SnDecode         ( const char*  ); // ret. vehicletype
 private:
  Vehicle           ( const Vehicle&  ); // copy construcotr
  Vehicle& operator=( const Vehicle&  ); // assignment operator
 protected:
  char* serialNumber_;
  unsigned int passengerCapacity_;
};

// class Car inherits from Vehicle
class Car : public Vehicle
{
 public:
  Car();                                          // Default Constructor 
  Car( char* sn, unsigned int capacity );         // Param. Constructor
  virtual ~Car();                                // Deconstructor
  const char* ShortName() const; // returns "CAR" 
 private:
  Car           ( const Car& ); //copy constructor
  Car& operator=( const Car& ); //assignment constructor
};

// class Truck inherits from Vehicle
class Truck : public Vehicle
{
 public:
  Truck();                                         // Default Constructor
  Truck( char *sn, unsigned int cap , char *dot ); // Param. Constructor
  virtual ~Truck();                       // Destructor 
  virtual const char* ShortName () const;   // returns "TRK"
  float               Toll      () const;   // returns toll fee based on schedule
  const char*         DOTLicense() const;   // returns license number
 protected:
  char* DOTLicense_;
 private:
  Truck           ( const Truck&  ); // copy constructor
  Truck& operator=( const Truck&  ); // assign. constructor
};

// class Van inherits from Truck and Box
class Van : public Truck, public Box
{
 public:
  Van ();                                                                  // Default Constructor
  Van ( char* sn, unsigned int cap, char*dot , float l, float w, float h); // Param Construct
  virtual ~Van();   // Destructor
  float               LoadCapacity() const;  // returns volume of box
  const char*         ShortName   () const;  // returns "VAN"
 private:
  Van           ( const Van& );      // Private Copy Constructor prototype
  Van& operator=( const Van& );      // Private Copy assignment prototype
};

// class Tanker inherits from Truck , Cylindert
class Tanker : public Truck, public Cylinder
{
 public:
  Tanker ();                                                         // def constructor
  Tanker ( char* sn, unsigned int cap, char*dot , float l, float r );// param constructor
  virtual ~Tanker(); // Destructor
 private:
  Tanker           ( const Tanker&  );  // private copy constructor
  Tanker& operator=( const Tanker&  );  // private assignment 
 public:
  float LoadCapacity   () const; // returns volume of cylinder   
  const char* ShortName() const; // returns "TNK"
}; 

// class Flat Bed inherits from Truck, Plane
class Flatbed : public Truck, public Plane
{
 public:
  Flatbed();                                                        // def constructor
  Flatbed( char* sn, unsigned int cap, char*dot ,float l, float w );// param construct
  virtual ~Flatbed(); // Deconstructor
 private:
  Flatbed           ( const Flatbed&  ); // private copy constructor
  Flatbed& operator=( const Flatbed&  ); // private assignment
 public:
  float LoadCapacity   () const; // returns area of the plane
  const char* ShortName() const; // returns "FLT"
};


#endif
