#include <iostream>
#include <stack.cpp>

int main()
{
 
  std::cout << "Test #1 declaring Stact<int,2> s1;" << std::endl;
  Stack<int,2> s1;
  int val1 = 1;
  int val2 = 2;
  int val3 = 3;
  std::cout << "s1 Dump(std::cout)" << std::endl;
  s1.Dump( std::cout );
  s1.Push(val1 );
  s1.Push(val2 );
  s1.Push( val3 );
  std::cout << "After: Pushing values 1, 2, 3....." << std::endl;
  std::cout << "3 should not be pushed, because s1 capacity is only 2" << std::endl;
  s1.Dump( std::cout ); 
  s1.Display(std::cout);
  std::cout << "Testing pop.. Should pop off 2... " << std::endl;
  s1.Pop();
  s1.Dump(std::cout);
  s1.Display(std::cout );
  std::cout << "Push 3 into s1..." << std::endl;
  s1.Push( val3 );
  s1.Display(std::cout);
  std::cout << "\n\n\n" << std::endl;
  std::cout << "--------------------" << std::endl;
  std::cout << "Testing copy constructor" << std::endl;
  std::cout << "Declaring:   Stack<int,2> s2( s1 );" << std::endl;
  std::cout << "s2 shouldve copied into 1, 3" << std::endl;
  Stack<int ,2> s2( s1 );
  std::cout << "pringing s2: "; 
  s2.Display( std::cout );

  std::cout << "\n\n\n" << std::endl;
  std::cout << "--------------------" << std::endl;
  std::cout << "Testing assignmentoperator" << std::endl;
  Stack< int,2 > s3;
  s3 = s1;
  std::cout << "s3 = s1" << std::endl;
  s3.Display(std::cout);
  s3.Dump(std::cout);
  std::cout << "************************" << std::endl;
  std::cout << "***********************" << std::endl;
 
}   
