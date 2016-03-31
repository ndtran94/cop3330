#include <iostream>
#include <queue.t>

// uncomment one of these to define the type of data:

/*//  A1: makes stacks of char */
//typedef char ElementType;
//const char* eT = "char";
// end A1

/* //  A2: makes stacks of String */
// #include <xstring.cpp>
// typedef fsu::String ElementType;
// const char* eT = "String";
// end A2 */

/* A3: makes stacks of int */
typedef int ElementType;
const char* eT = "int";
// end A2

/* A4: makes stack of int */
//#include <id.cpp>
//typedef fsu::ID ElementType;
//const char* eT = "ID";
// end A4

void menu()
{
  std::cout << "Push(Tval)  .............  + or 1 " << std::endl;
  std::cout << "Pop()  ..................  - or 2 " << std::endl;
  std::cout << "Clear()  ................  C " << std::endl;
  std::cout << "Front()  ...............   F " << std::endl;
  std::cout << "Empty()  ................  E " << std::endl;
  std::cout << "Size()  .................  S " << std::endl;
  std::cout << "Copies  .................  = " << std::endl;
  std::cout << "Display stack ...........  D " << std::endl;
  std::cout << "Display this menu  ......  M " << std::endl;
  std::cout << "Enter [command][argument] ('M' for menu, 'Q' to quit):";
}

//typedef fsu::Queue<T,N> Queue;
using namespace fsu;
int main()
{
  std::cout << "This is a Queue < " << eT << "  > test program" << std::endl;
  std::string choice1 = " ";
  char choice2;
  fsu::Queue< ElementType > q1;
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
            || choice2 == 'F' || choice2 == 'E' || choice2 == 'S'
            || choice2 == '=' || choice2 == 'D' 
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
			    q1.Push( entry );
			  }
			  break;
			case '+':
			  {
			    ElementType entry;
			    std::cout << "Please enter item to push into stack: ";
			    std::cin >> entry;
			    q1.Push( entry );
			  }
			  break;
			case '2':
			  if( q1.Empty() )
			    {
			      std::cout << "Queue is empty. Nothing to pop " << std::endl;
			    }
			  else
			    {
			      std::cout << "Item: " <<  q1.Pop() << " Popped" << std::endl;
			    }
			  break;
			case '-':
			  if( q1.Empty() )
			    {
			      std::cout << "Queue is empty. Nothing to pop " << std::endl;
			    }
			  else
			    {
			      std::cout << "Item: " <<  q1.Pop() << " Popped" << std::endl;
			    }
			  break;
			case 'C':
			  if( q1.Empty() )
			    {
			      std::cout << "Queue is Empty. Nothing To Clear." << std::endl;
			    }
			  else
			    {
			      std::cout << "Clearing..." << std::endl;
			    }
			  q1.Clear();
			  break;
			case 'F':
			  std::cout << "Front is: " << q1.Front() << std::endl;
			  break;
			case 'E':
			  if( q1.Empty() )
			    {
			      std::cout << "Front is Empty" << std::endl;
			    }
			  else
			    {
			      std::cout << "Queue is not Empty" << std::endl;
			    }
			  break;
			case 'S':
			  std::cout << "Size: " << q1.Size() << std::endl;
			  break;
			case '=':
			  // Copy test
			  {
			    fsu::Queue< ElementType > copy( q1 ) ;
			    std::cout << "\n\n-Copied object:"
				      << "size: " << copy.Size() << '\n'
				      << "               content: ";
			    //copy.Display(std::cout);
			    std::cout << copy;
			    std::cout << '\n';
			    std::cout << "-------" << std::endl;
			  }
			  {
			    // Assignm test]
			    fsu::Queue< ElementType > assignm;
			    assignm = q1;
			    std::cout << "-Assign Test: ";
			    std::cout << "Original object: "
				      << "size: " << q1.Size() << '\n';
			    std::cout << "             content: ";
			    q1.Display(std::cout);
			    std::cout << '\n';
			    std::cout << "-Assignee object: ";
			    std::cout << "size: " << assignm.Size() << '\n';
			    std::cout << "                content: ";
			    std::cout << assignm;
			    //assignm.Display(std::cout);
			    std::cout << '\n';
			  }
			  break;
			case 'D':
			  if( !q1.Empty() )
			    {
			      std::cout << "Display Front to Back: ";
			      // q1.Display(std::cout);
			      std::cout << q1;
			      std::cout << "\n";
			    }
			  else
			    {
			      std::cerr << "Empty queue.nothing to print\n"
				}
			  break;
			}// end switch
		    } // end inner if
		  do{
		    std::cout << "Enter [command][argument] ('M' for menu, 'Q' to quit): ";
		    std::cin >> choice1;
		  }while( choice1.length() > 1 );
		  choice2 = toupper( choice1[0] );
		}// end while
	    }// end if 'Q'
	}
    }while( choice2 != 'Q' );
  std::cout << "\n\nHave a nice day" << std::endl;
}
