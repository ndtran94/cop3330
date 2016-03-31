/*
Driver to test vehicles.cpp and shapes.cpp 
Array of pointers to base class
*/

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vehicles.h>

const size_t maxEntrySize = 20;
const size_t maxVehicles  = 100;
int main(int argc, char* argv[])
{
  
  Vehicle*    Vptr;              // pointer to dynamically allocated Vehicle
                                 // object
  VehicleType v;                 // to hold type of vehicle
  char        sn   [maxEntrySize]; 
  char        dot  [maxEntrySize]; 
  Vehicle*     array[ maxVehicles ];
  int         inputNumberOfVehicles = 0; 
  int         idx = 0;
  // set float precision
  std::cout << std::fixed << std::showpoint << std:: setprecision(2); 
  std::cout << "RLC Tracker... " << std::endl;
 do 
   {
     int numCars       = 0;
     int numTrucks     = 0;
     int numTankers    = 0;
     int numVans       = 0;
     int numFlatbeds   = 0;
     int numUnknown    = 0;
     int numBadSN      = 0;
     float tolls       = 0.0;
     int numPassengers = 0;  
     idx = 0; // reset idx 
     // read stdin for number of Vehicles
     std::cin >> inputNumberOfVehicles;
     // read stding for string
     if( inputNumberOfVehicles < 100 && inputNumberOfVehicles > 0 )
       {  
	 while( idx < inputNumberOfVehicles )
	   {
	     std::cin >> sn;
	     v = Vehicle::SnDecode( sn );
	     if( v == badSn )
	       {
		 //  std::cout << "badsn" << std::endl;
		 Vptr = new Vehicle( sn, 0 );
		 ++numBadSN;
	       }         
	     else // is a vehicle
	       {
		 // read for passengercapacity
		 std::cin >> numPassengers;
		 if( v == vehicle || v == car )
		   {
		     // is it a vehicle or car
		     if( v == vehicle )
		       {
			 Vptr = new Vehicle( sn, numPassengers );
			 ++numUnknown;
		       }
		     else
		       {
			 // v == car
			 Vptr = new Car( sn, numPassengers );
			 ++numCars;
		       }// end v == car else
		   }// isa v == truck || v == van || v == tanker || v == flatbed )
		 else
		   {
		     // optional dimensions
		     float d1, d2, d3 = 0.0; 
		     // DOTLicnse
		     std::cin >> dot;
		     // optional dimernsions for van tanker flatbed 
		     // only parse for two dimensions
		     if( v == truck )
		       {
			 Vptr = new Truck( sn, numPassengers, dot );
			 ++numTrucks;
		       }
		     else
		       {
			 // is a van / tanker / flatbed
			 // needs at least additional 2 additional dimensions
			 std::cin >> d1;
			 std::cin >> d2;
			 if( v == tanker || v == flatbed )
			   {
			     if( v == tanker )
			       {
				 Vptr = new Tanker( sn, numPassengers, dot, d1, d2 );
				 ++numTankers;
			       }
			     else
			       { 
				 // is a flatbed
				 Vptr = new Flatbed( sn, numPassengers, dot, d1, d2 );
				 ++numFlatbeds;
			       } // end else
			   }// end if v == flatbed or tanker
			 else // is a van   
			   {
			     if( v == van )
			       {
				 // needs 3rd dimensions 
				 std::cin >> d3;
				 Vptr = new Van( sn, numPassengers, dot, d1, d2, d3 );
				 ++numVans;
			       } // end if a van 
			   }// end else
		       }// end if( v != truck )
		   }// end else //( v == truck || v == van || v == tanker || v == flt
	       }// end else
	     array[ idx ] = Vptr;
	     ++idx;
	     tolls = tolls + Vptr->Toll();
	   }// end while
	 // print data
	 //        std::cout << '\n' << "Segment Summary" << std::endl;
	 std::cout << "====================="  << std::endl;
	 std::cout << "Cars: "          <<  numCars << std::endl;
	 std::cout << "Trucks: "        <<  numTrucks << std::endl;
	 std::cout << "Vans: "          <<  numVans << std::endl;
	 std::cout << "Flatbeds: "      << numFlatbeds << std::endl;
	 std::cout << "Unknowns: "      << numUnknown << std::endl;
	 std::cout << "Badsn: "         << numBadSN << std::endl;
	 std::cout << "Tolls:$ "        << tolls << std::endl;
	 std::cout << "Segment Details" << std::endl;
	 std::cout << "====================="  << std::endl;
	 std::cout << std::setw(10) << std::right << "Type" 
		   << std::setw(10) << std::right << "Toll"
		   << std::setw(10) << std::right << "PassCap"
		   << std::setw(10) << std::right << "LoadCap"
		   << std::setw(15) << std::right << "DOT License" 
		   << std::setw(15) << std::right << "Serial Number"
		   << std::endl;
	 std::cout << std::setw(10) << std::right << "----"
		   << std::setw(10) << std::right << "----"
		   << std::setw(10) << std::right << "----"
		   << std::setw(10) << std::right << "----"
		   << std::setw(15) << std::right << "----"
		   << std::setw(15) << std::right << "----"
		   << std::endl;
       
	 for( int i = 0 ; i < idx; ++i )
	   {
	     std::cout << std::setw( 10 ) << std::right << array[ i ] -> ShortName()
		       << std::setw( 10 ) << std::right << array[ i ]->Toll()
		       << std::setw( 10 ) << std::right << array[ i ]->PassengerCapacity()
		       << std::setw( 10 ) << std::right << array[ i ]->LoadCapacity();
	     VehicleType t;
	     std::string temp = array[ i ]->SerialNumber();
	     t = Vehicle::SnDecode( &temp[ 0 ] ); 
	     if( t == vehicle || t == car || t == badSn  )  
	       {
		 std::cout << std::setw( 10 ) << std::right << "(NA)";
	       }
	     else
	       {
		 Vehicle * ptr = array[ i ];
		 std::cout << std::setw( 10 ) << std::right << dynamic_cast<Truck*>(ptr) -> DOTLicense();
	       }
	     std::cout << std::setw( 15 ) << array[ i ] -> SerialNumber() << std::endl; 
	   }// end for 
      
      
       }// end if
   }while( inputNumberOfVehicles < 100 && inputNumberOfVehicles > 0 );
 
 return 0;
} // end main
