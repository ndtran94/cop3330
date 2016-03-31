// stack.t
#ifndef STACK_T
#define STACK_T
#include <iostream>

namespace fsu
{

  template < typename T, size_t N = 100 >
  class Stack
  {
  public:
    Stack             ();             // default constructor
    Stack             (T fill);       // puts "fill" in each slot of the
    // underlying
    //array (keeps size = 0)
  Stack             (const Stack&); // copy constructor
    ~Stack            ();             // destructor
    Stack& operator=(const Stack&); // assignment operator
    void     Push     (const T& t); // push t onto stack; error if full
    T        Pop      ();           // pop stack and return removed
    T&       Top      ();           // return top element of stack; error
    // is empty
    const T& Top      () const;     // const version
  size_t   Size     () const{ return size_; }    // return number of elements in
    size_t   Capacity () const{ return capacity_; } // return storage capacity
    bool     Empty    () const;     // return 1/true if stack is empty, 0/false
    void     Clear    ();           // make the stack empty
    void     Display  (std::ostream& , char ofc = '\0') const; // output  stack
    void     Dump     (std::ostream& );
  private:
    const size_t capacity_;  // = N = size of array   - fixed during life of
    T            data_[N];   // array of T objects    - where T objects are stored
    size_t       size_;      // current size of stack - dynamic during life of
    // stack
  }; // end class
  template < typename T , size_t N >
  std::ostream& operator << (std::ostream& os, const Stack<T,N>& S)
  { 
    S.Display (os, '\0');
    return os;
   }
//contents through os, top to bottom
/****************************************************/
/************ Stack = if in, last out ***************/
/****************************************************/
// CONSTRUCTOR
// Pre-Condtion:
// Post-Condiiton: iniitlize empty stack wtih capacity = N
template <typename T, size_t N>
Stack<T,N >::Stack() : capacity_{ N }, data_{ 0 }, size_{ 0 }
{
  // std::cout << ">>>TEST: STACK() " << std::endl;
}
// CONSTRUCTOR T FILL
// Pre-Condiiotn: pass data type T named fill
// Post-Condtion: puts "fill" in each slot of underlying array ( keep size = 0 )
template <typename T,  size_t N>
Stack<T,N>::Stack( T fill ) : capacity_{ N }, data_{ 0 }, size_{ 0 }
{
  // std::cout << ">>>TEST: STACK( T fill )" << std::endl;
  for( size_t i = 0; i < capacity_; ++i )
  {
    data_[ i ] = fill;
  }// fill data slots with "fill"
}
// COPY CONSTRUCTOR
template <typename T, size_t N>
Stack<T,N>::Stack( const Stack& orig ) : capacity_{ N }, data_{ 0 }, size_{ 0 }
{
  for( size_t i = 0; i < orig.Size(); ++i )
  {
    Push( orig.data_[ i ] );
  }
}
// ASSIGNMENT OPERATOR
template <typename T, size_t N>
Stack<T,N>& Stack<T,N>::operator=( const Stack& orig )
{

  if( this != &orig )
  {
    this->Clear();
    for( size_t i = 0; i < orig.Size(); ++i )
    {
      Push( orig.data_[ i ] );
    }// end for
  }// end if
  return *this;
}// end function
// DESTRUCTOR
template <typename T, size_t N >
Stack<T,N>::~Stack()
{
  Clear();
}
// TOP
template <typename T, size_t N>
T& Stack<T,N>::Top()
{
  T& retVal = data_[ size_ -1 ];
  // return top element of stack; error if stack is empty
  return retVal;
}
// CONST TOP
template <typename T, size_t N>
const T& Stack<T,N>::Top      () const
{
  T temp = data_[ size_ -1 ];
  T &retval = temp; 
  // return top element of stack; error if stack is empty
  return retval;
}
// EMPTY
template <typename T, size_t N>
bool Stack<T,N>::Empty() const
{
  if( size_ == 0 )
  {
    return true;
  }
  return false;
}
// PUSH
// Pre-Condition:
// Post-Condition: push t onto stack; error if full
template<typename T, size_t N>
void Stack<T,N>::Push( const T& t )
{
  // full array
  if( size_ == capacity_ )
  {
    // std::cerr << "** Error. Cannot push: " << t << " onto stack. Full" <<
    // std::endl;
  }
  else
  {
    data_[ size_++ ] = t;
  }
}

// POP
// Pre-Condiiton:
// Post-Condition: pop stacj and return removed element; error if stack is empty
template<typename T, size_t N>
T Stack<T,N>::Pop()
{
  T returnData;
  // top to bottom. first in , last out
  // data_[ 0 ] = the bottom of the stack  -- first in
  // data_[size_ - 1] = the top of the stack -- last in
  returnData = data_[ size_ - 1 ];
  data_[ size_ - 1 ] = 0;
  --size_;
  return returnData;
}
// DISPLAY
// Pre-Condition: elements in a Stack
// Post-Condition: output through os, top to bottom
template <typename T, size_t N>
void Stack<T,N>::Display( std::ostream& os, char ofc ) const
{
  // top to bottom. first in , last out
  // data_[ 0 ] = the bottom of the stack
  // data_[size_-1] = the top of the stack'
  for( int i = size_ - 1; i >= 0 ; --i )
  {
    os << ofc <<  data_[ i ];
  }
  // Dump Private Use only
}
// DUMP
// Pre-Condition:
// Post-Condition: output all private data (for development use only)
template<typename T, size_t N>
void Stack<T,N>::Dump( std::ostream& os )
{
  os<< '\n';
  os << "---capacity: " << capacity_ << "\n";
  os << "---size: " << size_ << "\n";
  os << "---top: " << Top() << "\n";
}
// CLEAR
template <typename T, size_t N>
void Stack<T,N>::Clear()
{
 int i = 0;
 while( !Empty() )
  {
    Pop();
    ++i;
  }
}
} // end namspace fsu
#endif
