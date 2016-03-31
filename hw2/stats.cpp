/*
  stats.cpp
  
  implementation stats.h 
  Date Created: 01/14/15
*/
#include <iostream>
#include <stats.h>
///////////////////////////////
//
//  M  E  A  N
//
//////////////////////////////
float Mean( const int *array, size_t size )
// Pre-Condition: pointer to first element in the array, number of elem.
// Post-Condition: returns mean
{
  float sum = 0.0;
  float mean = 0.0;
  float x = 0.0;
  size_t i = 0;
  // add all of the int values in the array
  if( size == 0 )
    {
      mean = 0.0;
      return mean;
    }  
  while( i < size )
    {  
      x = static_cast< float >( array[ i ]);
      sum = sum + x;
      ++i;
    }
  // static_cast int sum to float
  sum = static_cast< float >( sum );
  // calculate mean
  mean = sum / size;
  return mean;
}
/////////////////////////////////////////////
//
//  M  E  D  I  A  N
//
////////////////////////////////////////////
float Median( int* array, size_t size )
// Pre-Condition: ref to first element in array, size of array
// Post-Condition: returns median
{
  // value to be returned
  float median = 0.0;
  // sort array
  Sort( array, size );
  // check if array has even/off number of elements  
  //  even number of elements in an array
  if( ( size % 2 ) == 0 )
    {
      float x1;
      float x2;
      x1 = static_cast< float >( array[ size / 2] );
      x2 = static_cast< float >( array[ (size / 2 ) - 1 ] );
      median = ( x1 + x2 ) / 2.0;
    }
  // odd number of elements in an array
  else
    {
      median = array[ size / 2 ];
    }
  return median;
}
///////////////////////////////////////////
//
//  S  O  R  T
//
///////////////////////////////////////////
void Sort( int* array, size_t size )
// Pre-Condition: the pointer to first arr element, size of array
// Post-Condition: Insertion Sort. Sort original array by reference
{
  int temp = 0;
  size_t j = 0;
  // loop to traverse entire away
  for( size_t i = 0; i < size; ++i )
    {
      temp = array[ i ];
      // compare
      j = i;
      while( j > 0 && temp < array[ j - 1 ] )
	{
	  // first value is greater than second value
	  // swap
          array[ j ] = array[ j - 1 ];
          j--;
	}// end while
      array[ j ] = temp;
    } // end for
}
////////////////////////////////
//
// P R I N T
//
///////////////////////////////
void Print( int* array, size_t size )
{
  size_t i = 0;
  while( i < size )
    {
      std::cout << array[ i ] << " " ;
      ++i;
    }// end while
}
