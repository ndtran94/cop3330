/**
   test2.cpp

   test2 harness for class ID
   specifically tests for ownership of data pointed to by name_
*/

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <id.h>

int main()
{
  // char myName [13] = {'C','h','r','i','s',' ','L','a','c','h','e','r','\0'};
  char myName [13] = "Chris Lacher";
  int  myAge = 100;

  // char tonyName [12] = {'T','o','n','y',' ','H','a','r','r','i','s','\0'};
  char tonyName [13] = "Tony Harris";
  int  tonyAge = 30;

  // char debiName [12] = {'M','a','t','t',' ','P','o','r','t','e','r','\0'};
  char debiName [13] = "Debora Roy";
  int  debiAge = 20;

  ID p1(myName, myAge), p2(tonyName,tonyAge), p3(debiName, debiAge);
  std::cout << " IDs after declaration:\n"; 
  std::cout << "  p1 = " << p1 << '\n';
  std::cout << "  p2 = " << p2 << '\n';
  // std::cout << "  p3 = " << p3 << '\n';

  strcpy (myName,tonyName);    // copy tonyName to myName
  strcpy (tonyName,debiName);  // copy debiName to tonyName
  myAge = tonyAge;             // copy tonyAge to myAge
  tonyAge = debiAge;           // copy debiAge to tonyAge

  std::cout << " IDs after client program changes myName and myAge:\n"; 
  std::cout << "  p1 = " << p1 << '\n';
  std::cout << "  p2 = " << p2 << '\n';
  // std::cout << "  p3 = " << p3 << '\n';
}
