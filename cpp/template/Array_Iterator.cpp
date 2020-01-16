/* I pledge that I have neither given nor received any help on this assignment */

// Implementation of the Array_Iterator Class

// Initializing constructor
template <typename T>
Array_Iterator<T>::Array_Iterator(Array<T> & array)
: array_(array),
  currentIteration_(0)
{}

template <typename T>
Array_Iterator<T>::~Array_Iterator()
{}
