/* I pledge that I have neither given nor received any help on this assignment */

// This class assists the client in iterating through Array objects. In order to achieve this, this class
// is a friend class of the Array class.

#ifndef _ARRAY_ITERATOR_
#define _ARRAY_ITERATOR_

#include "Array.h"

template <typename T>
class Array_Iterator
{
public:
  typedef T type;

  // Initializing constructor that takes a reference to the Array this object will iterate over
  Array_Iterator(Array<T> & array);

  // Destructor
  ~Array_Iterator(void);

  // Method that returns whether the entire iteration is over yet (made it to the end of the array)
  bool is_done(void);

  // Method that advances to the next iteration
  void advance(void);

  // Operator overload of the '*' operator. Returns a reference to the element at the current indice
  T & operator * (void);

  // Operator overload of the '->' operator. Returns a pointer to the element at the current indice
  T * operator -> (void);

private:
  // Array this iterate has access to and will iterate
  Array<T> & array_;

  // Variable that tracks which iteration we are on
  size_t currentIteration_;
};

// Include the .cpp file because this is a template class
#include "Array_Iterator.cpp"

// Include the Inline Implemenation
#include "Array_Iterator.inl"

#endif
