#include <iostream>
#include <stack.t>
// uncomment one of these to define the type of data:

/*//  A1: makes stacks of char */
//typedef char ElementType;
//const char* eT = "char";
// end A1 

/* //  A2: makes stacks of String */
#include <string.h>
typedef fsu::String ElementType;
const char* eT = "String";
// end A2 */

/* A3: makes stacks of int */
//typedef int ElementType;
//const char* eT = "int";
//const char ofc = ' ';
// end A2 

void menu()
{
  std::cout << "Push(Tval)  .............  + or 1 " << std::endl;
  std::cout << "Pop()  ..................  - or 2 " << std::endl;
  std::cout << "Clear()  ................  C " << std::endl;
  std::cout << "Top()  ..................  T " << std::endl;
  std::cout << "Empty()  ................  E " << std::endl;
  std::cout << "Size()  .................  S " << std::endl;
  std::cout << "Copies  .................  = " << std::endl;
  std::cout << "Display stack ...........  D " << std::endl;
  std::cout << "Dump() ..................  U " << std::endl;
  std::cout << "Display this menu  ......  M " << std::endl;
  std::cout << "Enter [command][argument] ('M' for menu, 'Q' to quit):";
}
//typedef fsu::Stack<typename T , size_t N> Stack;
using namespace fsu;
int main()
{
  std::cout << "\n***This is a Stack < " << eT << " > test program" << std::endl;
  std::string choice1 = " ";
  char choice2;
  fsu::Stack< ElementType > s;
  do
    {
      std::cout << "\n\n";
      menu();
      std::cin >> choice1;
      if( choice1.length() == 1 )
	{
	  choice2 = toupper( choice1[ 0 ] );
	  while( choice2 != 'M' && choice2 != 'Q' )
	    {
	      if( choice2 != 'Q' && choice2 != 'M' )
		{
		  if( choice2 == '1' || choice2 == '2' || choice2 == 'C'
              || choice2 == 'T' || choice2 == 'E' || choice2 == 'S' 
              || choice2 == '=' || choice2 == 'D' || choice2 == 'U' 
		      || choice2 == '+' || choice2 == '-' )
		    {
		      std::cout << "\n";
		      switch( choice2 )
			{
			case '1':
			  {
			    ElementType entry;
			    std::cout << "Please enter item to push into stack: ";
			    std::cin >> entry;
			    s.Push( entry );
			  }
			  break;
			case '+':
			  {
			    ElementType entry;
			    std::cout << "Please enter item to push into stack: ";
			    std::cin >> entry;
			    s.Push( entry );
			  }
			  break;
			case '2':
			  if( s.Empty() )
			    {
			      std::cout << "Stack is empty. Nothing to pop " << std::endl; 
			    }
			  else
			    {
			      std::cout << "Item: " <<  s.Pop() << " Popped" << std::endl;
			    }
			  break;
			case '-':
			  if( s.Empty() )
			    {
			      std::cout << "Stack is empty. Nothing to pop " << std::endl;
			    }
			  else
			    {
			      std::cout << "Item: " <<  s.Pop() << " Popped" << std::endl;
			    }
			  break; 
			case 'C':
			  if( s.Empty() )
			    {
			      std::cout << "Stack is Empty. Nothing To Clear." << std::endl;
			    }
			  else
			    {
			      std::cout << "Clearing..." << std::endl;
			    }
			  s.Clear();
			  break;
			case 'T':
			  std::cout << "Top is: " << s.Top() << std::endl;
			  break;
			case 'E':
			  if( s.Empty() )
			    {
			      std::cout << "Stack is Empty" << std::endl;
			    }
			  else
			    {
			      std::cout << "Stack is not Empty" << std::endl;
			    }
			  break;
			case 'S':
			  std::cout << "Size: " << s.Size() << std::endl; 
			  break;
			case '=':
			  // Copy test
			  {
			    fsu::Stack< ElementType > copy( s ) ;
			    std::cout << "\n\n-Copied object:"
				      << "size: " << copy.Size() << '\n'
				      << "               content: "; 
			    copy.Display(std::cout); 
			    std::cout << '\n';
			    std::cout << "-------" << std::endl;
			  }
			  {
			    // Assignm test]
			    fsu::Stack< ElementType > assignm;
			    assignm = s;
			    std::cout << "-Assign Test: ";
			    std::cout << "Original object: "
				      << "size: " << s.Size() << '\n';
			    std::cout << "             content: ";
			    s.Display(std::cout);
			    std::cout << '\n';
			    std::cout << "-Assignee object: ";
			    std::cout << "size: " << assignm.Size() << '\n';
			    std::cout << "                content: ";
			    assignm.Display(std::cout);
			    std::cout << '\n';
			  }
			  break;
			case 'D':
			  if( !s.Empty() )
			    {
			      std::cout << "Display Top to bottom: ";
			      //s.Display(std::cout);
			      std::cout << s; 
			      std::cout << "\n";
			    }
			  else
			    {
			      std::cerr << "Empty stack.nothing to print\n"; 
			    }
			  break;
			case 'U':
			  std::cout << "Dump Private Data:";
			  s.Dump(std::cout);
			  std::cout << "\n";
			  break;
			}// end switch
		    } // end inner if
		  do{
		    std::cout << "Enter [command][argument] ('M' for menu, 'Q' to quit): ";
		    std::cin >> choice1;
		  }while( choice1.length() > 1 );
		  choice2 = toupper( choice1[0] );
		}
	    }
	}
    }while( choice2 != 'Q' );
  std::cout << "\n\nHave a nice day" << std::endl;
}
