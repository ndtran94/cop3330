/*
  main.cpp
  Date Created: 01/21/2014
  Name: Nhi Tran
  COP3330
  Assignment HW2
  create an array of integers,
  read through standard input,
  sort, and report - median, mean of integers 
*/
#include <iostream>
#include <cstdlib>
#include <stats.h>

int main()
{

  // read from standard input
  int num;
  int nel = 0 ; // number of elements read
  int arr[ 100 ]; // 100 integers max size
  for( int i = 0; i < 100; ++i )
    {
      arr[ i ] = 0;
    } 
  // loop : n < 100, isdigit, eof
  std::cout << "Entering Values...." << std::endl;
  while( std::cin >> num && nel < 100 )
    {
      // check if non digit
      // convert string into int
      // put int intput into int array
      arr[ nel ] = num;
      ++nel;
    }
  std::cout << "--------------" << std::endl;
  std::cout << "Data as entered: ";
  Print( arr, nel );
  // calculate mean
  std::cout << "\n" << "Mean: " << Mean( arr, nel ) << std::endl;
  // calculate median
  std::cout << "Median: " << Median( arr, nel ) << std::endl;
  std::cout << "Data after sort: ";
  Print( arr, nel );

   
 
 
     
 
     
     
            
}
