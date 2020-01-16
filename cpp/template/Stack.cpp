// $Id: Stack.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

//
// Stack
//
template <typename T>
Stack <T>::Stack (void)
:	data_(Array<T>()),
	cur_size_(0)
{}

//
// Stack
//
template <typename T>
Stack <T>::Stack(const Stack & stack)
:	data_(Array<T>((stack.data_))),
	cur_size_(stack.cur_size_)
{}

//
// ~Stack
//
template <typename T>
Stack <T>::~Stack (void)
{}

//
// push
//
template <typename T>
void Stack <T>::push (T element)
{
	// Catches bad_alloc exception if resizing the array object fails
	try
	{
		// Resize the array
		this->data_.resize(this->data_.size() + 1);
		this->cur_size_ += 1;

		// Add the element to the end of the array
		this->data_.set(this->cur_size_ - 1, element);
	}

	catch(std::bad_alloc ex)
	{
		std::cout << "Stack Failed to Push. Bad Allocation" << std::endl;
	}
}

//
// pop
//
template <typename T>
T Stack <T>::pop (void)
{
	// Test to see if the stack is empty, if it is then throw stack_is_empty Exception
	if(this->is_empty())
	{
		throw empty_exception();
	}

	// Save the top element
	T top_element = this->data_[this->cur_size_ - 1];

	// Resize the array down by one
	this->data_.resize(this->data_.size() - 1);
	this->cur_size_ -= 1;

	return top_element;
}

//
// operator =
//
template <typename T>
const Stack <T> & Stack <T>::operator = (const Stack & rhs)
{
	// Check for self assignment by calling the Array equality operator
	if (this->data_ == rhs.data_)
	{
		return *this;
	}

	// Set this Stack's state to the state of the rhs stack by calling Array assignment operator
	this->data_ = rhs.data_;

	this->cur_size_ = rhs.cur_size_;

	return *this;
}

//
// clear
//
template <typename T>
void Stack <T>::clear (void)
{
	// Check to see if the stack is already clear
	if(!this->is_empty)
	{
	  // Clear all the data in our Array object and set our size member to 0
		this->data_.resize(0);

	  // COMMENT There is no need to shrink the array since you
	  // will just request the space later. If you want to shrink
	  // the array, then you should expose a shrink() method on the
	  // Stack, which delegates its call to the array.

		// REPLY Implmented the suggested fuctionality. shrink() method is no longer called
		// by default whenever space is not being used. Implmented a shrink() method for the Stack
		// that delegates its call to the Array

		this->cur_size_ = 0;
	}
}

//
// shrink
//
template <typename T>
void Stack <T>::shrink(void)
{
	this->data_.shrink();
}
