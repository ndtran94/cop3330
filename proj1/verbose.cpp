/*
Includes both implementation for shapes.h and vehicles.h
Has cout statements for constructors and destructors

*/

#include <shapes.h>
#include <cmath> // M_PI defined to 21 significant digits
#include <vehicles.h>

// 
// 
// BOX DEF CONSTRUCTOR
// 
// Pre-condition:
// Post-condition: initializes private data to 0
Box::Box() : length_( 0.0 ), width_( 0.0 ), height_( 0.0 )
{
  std::cout << "Box() " << std::endl; 
}
//
//
// BOX PARAM. CONSTRUCTOR
//
// Pre-Condition: float l, w, h
// Post-Condition: Iniitalize data with parameters
Box::Box( float l, float w, float h ) : length_( l ), width_( w ), height_( h )
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
  std::cout << "CYLINDER() " << std::endl;
}
//
// CYLINDER PARM CONSTRUCTOR
// 
// Pre-Condition: 
// Post-Condition: initialize private state
Cylinder::Cylinder( float l, float r ) : length_( l ), radius_( r )
{
  std::cout << "CYLINDER( l ,  r )" << std::endl;
} 
//
//
// CYLINDER DECONSTRUCTOR
//
// Pre-Condition:
// Post-Condition: deallocate memory
Cylinder::~Cylinder()
{
  std::cout << "~Cylinder()" << std::endl; 
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
  std::cout << "PLANE()" << std::endl;
}
//
//
// PLANE PARAM CONSTRUCTOR
// Pre-Condition: passes float l , w
// Post-Condition: initializes private state with constructor
Plane::Plane( float l , float w ) : length_( l ), width_( w )
{
  std::cout << " PLANE( l ,w ) " << std::endl; 
}
//
//
// PLANE DECONSTRUCTOR
// Pre-Condition:
// Post-Condiiton: deallocate memory
Plane::~Plane()
{
  std::cout << "~PLANE() " << std::endl;
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


// VEHICLE DEF. CONSTRUCTOR
// Pre-Condition:
// Post-Condition: intiialize private state
Vehicle::Vehicle()
{
  std::cout << "VEHICLE()" << std::endl;
  const int serialMaxSize = 20;
  serialNumber_ = new char [ serialMaxSize ];
  serialNumber_[ 19 ] = '\0';
  strcpy( serialNumber_, " " );
  passengerCapacity_ = 0;
}

//
//
// PARAM CONSTRUCTOR
// Pre-Condition: char* ptr, and int
// Post-Condition: initializes state
Vehicle::Vehicle( char const * s, unsigned int x )
{
  std::cout << "VEHICLE( *s, x )" << std::endl;
  const int serialMaxSize = 20;
  serialNumber_ = new char [ serialMaxSize ];
  serialNumber_[ 19 ] = '\0';
  strcpy( serialNumber_, s );  
  passengerCapacity_ = x; 
}
//
//
// VEHICLE DECONSTRUCTOR
// Pre-Condition: none
// Post-Condition: deallocates any dynamic memory
Vehicle::~Vehicle()
{
  std::cout << "~VEHICLES() " << std::endl;
  delete [] serialNumber_;
}

//
//
// STATIC VEHICLE TYPE SNDECODE
// Pre-Condition: sn was initialized
// Post-Condition: returns vehicle type
VehicleType Vehicle::SnDecode( const char * sn )
{
  switch( sn[ 0 ] )
    {
    case '1':
      //std::cout << "sndecode is 1" << std::endl;
      return vehicle;
      break;
    case '2':
      //std::cout << "sndecoe is 2" << std::endl;
      return car;
      break;
    case '3':
      //std::cout << "sndecode is 3" << std::endl;
      return truck;
      break;
    case '4':
      //std::cout << "sndecode is 4" << std::endl;
      return van;
      break;
    case '5':
      //std::cout << "sn is 5" << std::endl; 
      return tanker;
      break;
    case '6':
      //std::cout <<"sn is 6" << std::endl;
      return flatbed;
      break;
    default:
      //std::cout <<"sn is 0 " << std::endl;
      //std::cout << "sn[0]: " << sn[ 0 ] << std::endl; 
      // bad sn
      return badSn;
      break; 
    }
}
//
//
// VEHICLE TOLL
// Pre-condition: $2.00 minumum for all vehicles
// Post-Condition : returns $2.00
float Vehicle::Toll() const
{
  return 2.00;
}
//
//
// VEHICLE SN
// Pre-Condition
// post-consition:
const char* Vehicle::SerialNumber() const
{
  std::string badSN = "Bad Serial Number"; 
  if( serialNumber_[ 0 ] == 0 )
    {
      return &badSN[ 0 ];
    }
  return &serialNumber_[0];
}

//
//
// VEHICLE CAPACITY
// Pre-Condition: Capacity is returned
// Post-Condition: returns 0.0
unsigned int Vehicle::PassengerCapacity() const
{
  return passengerCapacity_;
} 

//
// VEHICLE RETURN LOAD CAPACITY
// Pre-Condition: 
// Post-Condition: reutnrs 0.0
float Vehicle::LoadCapacity() const
{ 
  returns 0.0;
}

//
// VEHICE SHORTNAME
// Pre-Condition: 
// Post-Condition: returns "UNK"
const char* Vehicle::ShortName() const
{
  return "UNK";
}

////////////////////////////////////////////////////////////////////////

//
//
// CAR DEFAULT CONSTRUCTOR
//
//
//
Car::Car() : Vehicle()
{
  std::cout << "CAR()" << std::endl;
}
//
//
// CAR PARM CONSTRUCOT
Car::Car( char* sn, unsigned int capacity )         
  : Vehicle( sn, capacity )
{
  std::cout << "CAR PARAM CONSTRUCTOR" << std::endl;
}
// CAR SHORTNAME
// Pre-Condition:
// PostCondition: reutnrs "CAR"
const char* Car::ShortName() const
{ return "CAR"; }  
//
//
// CAR DECONSTRUCOTR
Car::~Car()
{
  std::cout << "~CAR()" << std::endl;
}
////////////////////////////////////////////////////////////////////////

//
//
// TRUCK
// Pre-Condition:
// Post-Condition: intialize truck private data
Truck::Truck() 
  : Vehicle()
{
  std::cout << "TRUCK()" << std::endl;
  const int licenseMaxSize = 20;
  DOTLicense_ = new char[ licenseMaxSize ];
  DOTLicense_[ 19 ] = '\0';
  strcpy( DOTLicense_, " " );
}

//
//
// TRUCK PARAM CONSTRUCTOR
// Pre-Condition: passes parrameters for DOTLicense, and Vehicle
// Post-Condition: initializes state with parameters
Truck::Truck( char *sn, unsigned int capacity, char *dot ) 
  : Vehicle( sn, capacity )
{
  std::cout << "TRUCK( sn, cap,dot )" << std::endl;
  std::cout << "CAPACITY: " << capacity << std::endl;
  const int licenseMaxSize = 20;
  DOTLicense_ = new char[ licenseMaxSize ];
  DOTLicense_[ 19 ] = '\0';
  strcpy( DOTLicense_, dot );
}

//
//
// TRUCK DECONSTRUCTOR
// Pre-condition: dynamically allocated DOTLicenses array
// Post-Condition: deallocate memory
Truck::~Truck()
{
  std::cout << "~TRUCK()" << std::endl;
  delete [] DOTLicense_;
}

//
//
// TRUCK SHORTNAME
// Pre-Condiiton: none
// Post-Condition: returns "TRK"
const char* Truck::ShortName() const
{
  return "TRK";
} 

//
//
// TRUCK RETURN LICESNSE NUMBER
// Pre-Condin: sn[ 0 ] is either 3,4,5,6
// Post-Condition: returns correct toll
float Truck::Toll() const
{
  //minimum $10.00 for trucks
  return 10.00;
}

////////////////////////////////////////////////////////

//
//
// VAN
Van::Van() : Truck(), Box()
{
  std::cout << "VAN()" << std::endl; 
} 

//
// VAN PAARM
//
//
Van::Van ( char* sn, unsigned int cap, char*dot , float l, float w, float h)
  : Truck(sn,cap,dot), Box( l,w,h) 
{
  std::cout << "VAN( parameters ) " << std::endl;
}

//
//
// ~VAN
//
Van::~Van()
{
  std::cout << "~VAN() " << std::endl;
}


//
// LOAD CAPACITY VAN
// Pre-Condition: Box state is initialized 
// Post-Condition: returns Load Capacity - the volume of the Box
float Van::Lut << "TANKER() " << std::endl;
}

//
//
// TANKER PARAMETERS
Tanker::Tanker ( char* sn, unsigned int cap, char*dot , float l, float r )
  : Truck(sn,cap,dot), Cylinder(l,r)
{
  std::cout << "TANKER(param)" << std::endl;
}
//
//
// LOAD CAPACITY
// Pre-Condition: l, r are initialize
// Post-Condition: return volume of cylinder
float Tanker::LoadCapacity() const
{
  float retval = Cylinder::Volume();
  return retval;
}

//
//
// TANKER SHORT NAME
// Pre-Condition:
// Post-Condition: returns "TNK"
const char* Tanker::ShortName() const
{ return "TNK"; }

//
// TANKER DESTRUCTOR
//
//
Tanker::~Tanker()
{
  std::cout << "~TANKER() " << std::endl;
}

//////////////////////D CAPACITY
// Pre-Condition: planes state is initializes
// Post-Condition:returns area
float Flatbed::LoadCapacity() const
{
  float retval = Plane::Area();
  return retval;
}    
//
// FLATBED SHORTNAME
// Pre-Condition:
// Post-Condition: returns "FLT"
const char* Flatbed::ShortName() const
{ return "FLT"; }

//
//
// FLATBED DESTRUCTORS
Flatbed::~Flatbed()
{
  std::cout << "~FLATBED()" << std::endl;
}
