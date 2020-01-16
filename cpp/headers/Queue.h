/*
  Honor Pledge:

  I pledge that I have not given nor
  received any help on this Assignment
*/

#ifndef _QUEUE_H_
#define _QUEUE_H_

#include "Array.h"
#include <exception>
#include <iostream> // For exception handling std::cerr

/*
  This class uses a Dynamic_ Array object in order to implement a Queue data structure.
  Elements are pushed onto the queue at the front of the array (indice 0) and they are
  dequeued at the end of the array (last indice). As more elements are pushed onto the queue,
  the Array object used to hold the data will grow and shrink with the size of the queue. Whenever
  an elmenet is dequeued, the Array will decrease in size by 1. Likewise whenever an element is enqueued,
  the Array will increase in size by 1.
*/

template <typename T>
class Queue
{
  public:

    // Exception to be thrown whenever dequeue is called on an empty queue
    class empty_exception : public std::exception
    {
      public:
        // Default constructor
        empty_exception(void)
        : std::exception() {}

        // Initializing Constructor
        empty_exception(const char * msg)
        : std::exception(msg) {}
    };

    // Exception to be thrown whenever enqueue is called on a queue that is full
    class full_exception : public std::exception
    {
      public:
        // Default constructor
        full_exception(void)
        : std::exception() {}

        // Initializing Constructor
        full_exception(const char * msg)
        : std::exception(msg) {}
    };

    /*
      Default constructor
    */
    Queue(void);

    /*
      Initizlizing constructor
    */
    Queue(size_t max_size);

    /*
      Copy constructor
    */
    Queue(const Queue & queue);

    /*
      Destructor
    */
    ~Queue(void);

    /*
      Assignment Operator Overload
    */
    const Queue & operator = (const Queue & rhs);

    /*
      Enqueue an element onto the Queue
    */
    void enqueue(T element);

    /*
      Dequeue an element off of the Queue
    */
    T dequeue(void);

    /*
      Resize the amount of values allocated in the Array member
    */
    void resize(size_t new_size);

    /*
      Check to see if the queue is empty
    */
    bool is_empty(void);

    /*
      Get the current size of the queue
    */
    size_t size(void);

    /*
      Get the max size of the queue
    */
    size_t max_size(void);

    /*
      Clear the queue of all elements
    */
    void clear(void);

  private:
    // COMMENT There is no need to allocate the array on the heap. Always try to
    // allocate on the stack to reduce the complexity of your code.

    // REPLY Removed the allocation of the array on the heap. Array member is now allocated
    // on the stack instead.

    // Array object to hold the data
    Array<T> data_;

    // Size of the queue
    size_t size_;

    // Max size of the queue (size of the Array member)
    size_t max_size_;
};

// Include cpp file because this is a template class
#include "Queue.cpp"

// Include the inline method implementation
#include "Queue.inl"

#endif
