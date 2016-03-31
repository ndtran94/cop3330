#ifndef _VEHICLES_H
#define _VEHICLES_H

class Vehicle
{
 public:
  // Default Constructor
  Vehicle()
    : serialNumber_{ ' ' }, passengerCapacity{ 0 }
  { std::cout << "Vehicle()" << std::endl; }
  // Parameterized Constructor
  Vehicle ( char* s, int x )
    {
      passengerCapacity = x;
      strcpy( serialNumber_ , s );
      std::cout << "Vehicle( s, x ) :serial#: " << serialNumber_  << std::endl;
    } 
  // Destructor
  ~Vehicle(){ std::cout << "~Vehicle()" << std::endl; }
 private: 
  // Private Copy Constructor
  Vehicle( const Vehicle & other ){ /* do nothing */ }
  // Private Assignment Constructor
  Vehicle& operator=( const Vehicle& other ){ /* do nothing */ } 
 private:
  char *serialNumber_;
  unsigned int passengerCapacity;
};


#endif
