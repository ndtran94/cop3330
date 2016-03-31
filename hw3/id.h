/*
 * Author: Nhi Tran
 * HW #3
 * File : id.h
 * Class ID
 * implementation of id.cpp
 * Course: COP3330
 * Date Due: Feb 1, 2015
 */

#ifndef ID_H
#define ID_H
#include <iostream>
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
#endif/*
       * Author: Nhi Tran
       * HW #3
       * File : id.h
       * Class ID
       * implementation of id.cpp
       * Course: COP3330
       * Date Due: Feb 1, 2015
       */

#ifndef ID_H
#define ID_H
#include <iostream>
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
#endif
