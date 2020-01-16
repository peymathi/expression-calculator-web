/* Honor Pledge:

I pledge that I have neither given nor
recieved any help on this Assignment
*/

/* Queue class implementation */

/* Default Constructor */
template <typename T>
Queue<T>::Queue(void)
: data_(Array<T>()),
  size_(0),
  max_size_(0)
{}

/* Initializing Constructor */
template <typename T>
Queue<T>::Queue(size_t max_size)
: data_(Array<T>(max_size)),
  size_(0),
  max_size_(max_size)
{}

/* Copy Constructor */
template <typename T>
Queue<T>::Queue(const Queue & queue)
: data_(Array<T>(queue.data_)),
  size_(queue.size_),
  max_size_(queue.max_size_)
{}

/* Destructor */
template <typename T>
Queue<T>::~Queue(void)
{}

/* Assignment Operator Overload */
template <typename T>
const Queue<T> & Queue<T>::operator = (const Queue & rhs)
{
  // Check for self assignment by calling the Array equality operator
  if(this->data_ == rhs.data_)
  {
      return *this;
  }

  // Set this Queue's state equal to the state of the rhs queue by calling the
  // Array equality operator and setting this queue's member variables to rhs queue's members
  this->data_ = rhs.data_;
  this->size_ = rhs.size_;
  this->max_size_ = rhs.max_size_;

  return *this;
}

/* Enqueue */
template <typename T>
void Queue<T>::enqueue(T element)
{
    // COMMENT This approach can work, but its design is very expensive. You
    // should find a better design that tries to use as much space as possible
    // while minimizing the amount of copying that must occur.

    // REPLY Instead of resizing the Array member everytime enqueue is called, I have
    // added a max size member variable that will set a max number of values that can be enqueued
    // on the queue. In addition to this, I have added a resize method that allows the user to grow
    // or shrink the number of possible values in the queue. This will minimize the number of copying
    // while allowing the user to use as much space as the operating system will let them.

    // Check to see if the queue is full
    if(this->size_ == this->max_size_)
    {
        throw full_exception();
    }

    // Check to see if we need to shift all elements in the array over by one
    if(this->size_ > 0)
    {
      for(int i = this->size_; i > 0; i--)
      {
        this->data_[i] = this->data_[i - 1];
      }
    }

    // Add the new element at indice 0
    this->data_[0] = element;
    this->size_ ++;
}

/* Dequeue */
template <typename T>
T Queue<T>::dequeue(void)
{
  // Check to see if the queue is empty before dequeueing
  // If it is, empty_exception is thrown
  if(this->is_empty())
  {
    throw empty_exception();
  }

  // Save the element at the end of the Array object before shrinking the array
  T dequeuedElement = this->data_[this->size_ - 1];

  // Decrement the size of the Array object by one
  this->data_.resize((this->size_) - 1);
  this->size_ --;

  return dequeuedElement;
}

/* Resize */
template <typename T>
void Queue<T>::resize(size_t new_size)
{
  // Try to resize the array to the new size
  try
  {
    this->data_.resize(new_size);
    this->max_size_ = new_size;

    // If the new_size is lower than the last max_size_, size_ member must change to new_size as well
    if(new_size < this->max_size_)
    {
      this->size_ = new_size;
    }
  }

  catch(std::bad_alloc ex)
  {
    std::cerr << "Failed to Allocate more memory for this Queue" << std::endl;
  }
}

/* Clear */
template <typename T>
void Queue<T>::clear(void)
{
  // Clear all data in the queue and set size member to 0
  // Make sure the queue is not already cleared
  if(this->size_ != 0)
  {
    this->data_.clear();
    this->size_ = 0;
  }
}
