/*
 * Author: Nhi Tran
 * HW #3
 * File : id.cpp
 * implementation of id.h
 * Course: COP3330
 * Date Due: Feb 1, 2015
 */
#ifndef ID_CPP
#define ID_CPP
#include <string.h>
#include <iostream>
#include <queue.t>

namespace fsu
{
class ID
{
public:
  ID                 ();                    // Default constructor
  ID                 ( const char* , int );// Explicit Value Constructor
  ID                 ( const ID& );         // Copy Constructor
  const ID &operator=( const ID& );         // Copy Assignment Operator
  ~ID();                                       // Destructor
  void        SetName( const char* );       // sets the name_ field
  void        SetAge ( int );               // sets the age_ field
  const char* GetName() const;          // returns a const pointer to the name
                                        // field
  int         GetAge () const;          // returns the age field by value
  friend std::ostream& operator<<( std::ostream & os, ID & idToPrint );
private:
  char* name_;  // name field
  int age_;     // age field
};
  template < typename T >
  std::ostream& operator << (std::ostream& os, const Queue<T>& Q )
  {
    //Q.Display (os, '\0');
    Queue::Link *linkPtr = firstLink_->nextLink;
    while( linkPtr ! lastLink_ )
      {

      }
    return os;
  }
  /////////////////////////////////
  //
  //  D E F . C O N S T R U C T O R
  //
  ///////////////////////////////////
  ID::ID()
  {
    std::cout << "IN DEFAULT CONSTRUCTOR" << std::endl;
    // allocate name memory
    std::string defName = "#";
    int defAge = -1;
    name_ = new char[ 10 ]; // allocate dynamic char array memory
    // set name to '#'
    this->SetName( &defName[0] );
    // set age to -1
    this->SetAge( defAge );
  }
  /////////////////////////////////////
  //
  //   E X P . V A L  - C O N S T R.
  //
  /////////////////////////////////////
  // Pre-Condtion:
  // Post-Condition:
  ID::ID( const char* n, int x )
  {
    std::cout << "IN EXPLICIT VALUE CONSTRUCTOR" << std::endl;
    // allocate memory of ID
    name_ = new char[ 10 ];
    this->SetName( n );
    this->SetAge( x );
  }
  /////////////////////////////////////
  //
  //   C O P Y  -  C O N S T R U C T O R
  //
  /////////////////////////////////////
  // Pre-Condition: object of type ID passed as value parameter.
  // Post-Condition: return value is a value of class ID
  ID::ID( const ID& origID )
  {
    // pass original as a vlaue paraeter
    // initializes a new object from an existing object.
    // copies the values in the data members from the origID
    // uses new to allocate a new name_ char array pointer by origID
    name_ = new char[ 10 ];
    // char *tempPtr = origID->GetName();
    this->SetName( origID.GetName() );
    this->SetAge( origID.GetAge() );
  }
  ////////////////////////////////////////
  //
  //  A S S I G N M E N T . O P
  //
  ////////////////////////////////////////
  // Pre-Condition: pass ID object by const value reference
  // Post-Condition: creates a shallow copy
  const ID &ID::operator=( const ID& rightHandID )
  {
    // check for self assignment
    if( this!= &rightHandID )
      {
	this->SetName( rightHandID.GetName() );
	this->SetAge( rightHandID.GetAge() );
      }
    return *this;
  }
  ////////////////////////////////////////
  //
  //   S E T  N A M E
  //
  ////////////////////////////////////////
  // Pre-Condition: pointer to const char *x
  // Post-Condition: ID data member 'name_' set
  void ID::SetName( const char*x )
  {
    strcpy( name_, x );
  }
  ///////////////////////////////////////
  //
  //  S E T  A G E
  //
  ////////////////////////////////////////
  // Pre-Condition: integer value paramer
  // Post-Condition: ID data member 'age_' set
  void ID::SetAge( int x )
  {
    this->age_ = x;
  }
  //////////////////////////////////////
  //
  // G E T  N A M E
  //
  ///////////////////////////////////////
  // Pre-Condition: none
  // Post-Condition: returns a const pointer to the name
  const char* ID::GetName() const
  {
    return name_;
  }
  ///////////////////////////////////////
  //
  //  G E T   A G E
  ///////////////////////////////////////
  // Pre-Condition: none
  // Post-Condition: returns int ID age_
  int ID::GetAge() const
  {
    return age_;
  }
  ///////////////////////////////////////
  //   < <
  //
  ///////////////////////////////////////
  std::ostream& operator << ( std::ostream &os, ID & idToPrint )
  {
    size_t i = 0;
    std::string temp;
    strcpy( &temp[ 0 ], idToPrint.GetName());
    while( i != strlen( &temp[ 0 ] ) )
      {
	os << temp[ i ];
	++i;
      }
    std::cout << "\t" << idToPrint.GetAge();


    return os;
  }
  ID::~ID()
  {
    delete name_;
  }




}; // end namespace
#endif
