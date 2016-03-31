#include <shapes.h>
#include <vehicles.h>
#include <iostream>

int main()
{
  //  std::cout << "main..." << std::endl;
  /*  Box b;
  Box b1( 1.0, 2.0, 1.0 );
  std::cout << "Volume of b1: " << b1.Volume() << std::endl;
  Cylinder c;
  Cylinder c1( 1.0, 2.0 );
  std::cout << "Volume of c1: " << c1.Volume() << std::endl;  
  Plane p;
  Plane p1( 1.9999, 5.0 );
  std::cout << "Area of p1: " << p1.Area() << std::endl;
  Vehicle v;
 Vehicle( &sn, 0 );
  

 std::cout << "--------------------" << std::endl;
  Car car1;
  Car car2( &sn, 4 );
  std::cout << "--------------------" << std::endl;
  Truck truck1;
  */
  char sn = '6'; 
  Van v1( 1.0, 2.0, 3.0, &sn, 5, &sn );
  std::cout << "Van load capacity: " << v1.LoadCapacity() << std::endl;
  std::cout << "--------------------" << std::endl;
  Tanker t1( 1.5, 2.8, &sn, 5, &sn ); 
  //t1.LoadCapacity(); // 36.95
  std::cout << "tanker capacity: " << t1.LoadCapacity() << std::endl; 

  std::cout << "--------------------" << std::endl;
  Flatbed f1( 5.0, 2.0, &sn, 5, &sn );
  std::cout << "f1 Area: " << f1.LoadCapacity() << std::endl; 
}
