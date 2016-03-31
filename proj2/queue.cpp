// queue.t
#ifndef QUEUE_T
#define QUEUE_T
#include<iostream:

namespace fsu
{
  template<typename T>
  class Queue
  {
  public:
    Queue             ();              // default constructor
    Queue             (const Queue&); // copy constructor
    ~Queue            ();              // destructor
    Queue& operator = (const Queue&); // assignment operator
    void      Push    (const T& t); // push t onto queue
    T         Pop     ();           // pop queue and return removed element;
                                    // error if queue is empty
    T&        Front   ();           // return front element of queue; error if
                                    // queue is empty
    const T&  Front   () const;     // const version
    size_t    Size    () const;     // return number of elements in queue
    bool      Empty   () const;     // return 1 if queue is empty, 0 if not
                                    // empty
    void      Clear   ();           // make the queue empty
    void      Display (std::ostream& os, char ofc = '\0') const; // output
                                                                 // contents
  private:
  class Link
  {
    Link ( const T& t ) : element_(t), nextLink_(0) {}
    T      element_;
    Link * nextLink_;
    friend class Queue<T>;
  };
    Link * firstLink_;
    Link * lastLink_;
  };//end class

  /***************************************************************/
  /****************** first in, first out ************************/
  /***************************************************************/
  // QUEUE
  // Pre-Condition: none
  // Post-Condition:create a new stack
  template <typename T>
  Queue<T>::Queue()
  {
    std::cout << "--- Queue() " << std::endl;
    firstLink_ = new Link( 0 );
    lastLink_ = new Link( 0 );
    firstLink->nextLink_ = lastLink_;
  }
  // COPY QUEUE
  // Pre-Condition:  none
  // Post-Condition: dynamically new Queue
  template <typename T>
  Queue::Queue( const Queue& orig )
  {
    std::cout << "--- Queue( const Queue& ) " << std::endl;
    firstLink_ = new Link( 0 );
    lastLink_ = new Link( 0 );
    Queue::Link * linkPtr = orig.firstLink->next_;
    while( linkPtr != orig.lastLink_ )
      {
	Push( linkPtr->element_ );
	linkPtr = linkPtr->nextLink_; 
      } 
  }
  // ASSIGNMENT OPERATOR
  // Pre-Condition: a predeclared stck
  // Post-Condition: staack is reassigned with rhs stack
  template <typename T>
  Queue<T>& Queue<T>::operator=( const Queue& rhs )
  {
    if( this != &rhs )
      {
	this->Clear();
	Queue::Link * linkPtr = rhs.firstLink->nextLink_;
	while( linkPtr != rhs.lastLink )
	  {
	    Push( linkPtr->element_ );
	    linkPtr = linkPtr->nextLink_;
	  }
      }// end if
    return *this;
  }// end function
  // DESTRUCTOR
  // Pre-Condtion:
  // Post-Condtion: 
  template <typename T>
  Queue<T>::~Queue()
  {
    Clear();
    delete firstLink_;
    delete lastLink_;
  }
  /**** Accessors ****/
  // SIZE
  // Pre-Condition: none
  // Post-Condition: return  number of links between first link and ast link
  template <typename T>
  size_t Queue<T>::Size() const
  {
    size_t sz = 0;
    Queue::Link* linkPtr = firstLink_->next;;
    while( linkPtr != lastLink_ )
      {
	linkPtr_ = linkPtr->nextLink_;
	++sz;
      }
    return sz;
  }
  // EMPTY
  // Pre-Condition:
  // Post-Codntion: returns boolean value if empty
  template <typename T>
  bool Queue<T>::Empty() const
  {
    if( firstLink_->nextLink_ == lastLink_ )
      {
	return true;
      }
    return false;
  }
  // FRONT
  // Pre-Condition:
  // Post-Condition:
  template <typename T>
  T& Queue<T>::Front()
  {
    T& retval;
    if( !Empty() )
      {
	retVal = firstLink_->nextLink_->element_;
      }
    else
      {
	// return first Link
	retval = firstLink_->element_;
      }
    return retval;
  }
  // CONST FRONT
  // Pre-Condition:
  // Post-Condition: returns first link
  template <typename T>
  const T& Queue<T>::Front() const
  {
    T& retval;
    if( !Empty() )
      {
	retVal = firstLink_->nextLink_->element_;
      }
    else
      {
	// return first Link
	retval = firstLink_->element_;
      }
    return retval;
  }// queue.t
  // DISPLAY
  // Pre-Condition:
  // Post-Condition: display all elements of the queue
  template <typename T>
  void Queue<T>::Display( std::ostream& os )
  {
    Queue::Link *linkPtr = firstLink_->nextLink_;
    if( !Empty() )
      {
	while( linkPtr != lastLink_ )
	  {
	    os << linkPtr->data_ << " ";
	  }
      }
    /******** Mutators *********/
    //PUSH
    // Pre-Condtion:
    // Post-condition: insert item to end of queue
    template <typename T>
      void Queue<T>::Push( const T& t )
    {
      Queue::Link * linkPtr = firstLink_;
      Queue::Link * newLink = new Queue::Link( t );
      while( linkPtr->nextLink_ != lastLink_ )
	{
	  linkPtr = linkPtr->nextLink_; 
	}
      linkPtr->nextLink_ = newLink;
    }
    // POP
    // Pre-Conditon:  if not empty
    // Post-Conditon: first in , first out
    template <typename T>
      T Queue<T>::Pop()
    {
      Queue::Link * linkPtr = firstLink->nextLink_;
      T retval;
      if( !Empty() )
	{
	  firstLink->nextLink_ = linkPtr->nextLink_;
	  linkPtr->nextLink_ = nullptr;
	  retval = linkPtr->element_;
	  delete linkPtr;
	}
      else
	{
	  // only first and last link exists
	  // return fristPtr
	  retval = firstPtr->element_;
	}
      return retval;
    }
    // CLEAR
    // Pre-Condition: links in the queue
    // Post-Condtion: deallocate elements between first and last link
    template <typename T>
      void Queue::Clear()
    {
      while( !Empty() )
	{
	  Pop();
	}
    }

  } //end of namespace
#endif
