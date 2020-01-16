/* I pledge that I have neither given nor received any help on this assignment */

//
// Array
//
template <typename T>
Array<T>::Array (void)
:	Array_Base<T>(0),
	max_size_(0)
{}

//
// Array (size_t)
//
template <typename T>
Array <T>::Array (size_t length)
:	Array_Base<T>(length),
	max_size_(length)
{}

//
// Array (size_t, char)
//
template <typename T>
Array <T>::Array (size_t length, T fill)
:	Array_Base<T>(length, fill),
	max_size_(length)
{
	this->fill(fill);
}

//
// Array (const Dynamic_Array &)
//
template <typename T>
Array <T>::Array (const Array<T> & array)
:	Array_Base<T>(array.max_size_),
	max_size_(array.max_size_)
{
	// Set all values of the new Array to the values of the old Array
	for (int i = 0; i < this->cur_size_; i++)
	{
		this->data_[i] = array.data_[i];
	}
}

//
// ~Array
//
template <typename T>
Array <T>::~Array (void)
{}

//
// operator =
//
template <typename T>
const Array <T> & Array <T>::operator = (const Array<T> & rhs)
{
	// Check for self assignment
	// Checks the pointers to the Char arrays to see if they match
	if (this->data_ == rhs.data_)
	{
		return *this;
	}

	// Check to see if we need to allocate more memory for the array
	// If we do then allocate it and copy values over
	if (this->max_size_ < rhs.max_size_)
	{
		delete [] this->data_;

		this->max_size_ = rhs.max_size_;

		this->cur_size_ = rhs.cur_size_;

		T * temp_ptr = new T[this->max_size_];

		for (int i = 0; i < this->cur_size_; i++)
		{
			temp_ptr[i] = rhs.data_[i];
		}

		this->data_ = temp_ptr;

		delete [] temp_ptr;
	}

	// This runs if we need to deallocate memory. All we do here is copy over
	// values and then run the shrink() method
	else if (this->max_size_ > rhs.max_size_)
	{
		for (int i = 0; i < rhs.cur_size_; i++)
		{
			this->data_[i] = rhs.data_[i];
		}

		this->cur_size_ = rhs.cur_size_;
		this->shrink();
	}

	// This runs if memory neither needs allocated nor deallocated
	// Copies the values over
	else
	{
		for (int i = 0; i < this->cur_size_; i++)
		{
			this->data_[i] = rhs.data_[i];
		}
	}

	return *this;
}

//
// resize
//
template <typename T>
void Array <T>::resize (size_t new_size)
{
	// Test to see if we are increasing or decreasing the size
	// If the new size is equal to our current size, then nothing happens
	if (new_size > this->cur_size_)
	{
		// Test to see if we need to allocate more memory
		if (new_size > this->max_size_)
		{
			// Preserve the data by allocating an array of the new size
			T * new_arr = new T[new_size];

			for (int i = 0; i < this->cur_size_; i++)
			{
				new_arr[i] = this->data_[i];
			}

			T * temp_ptr = this->data_;

			this->data_ = new_arr;

			delete[] temp_ptr;

			// Adjust size variables to the new size
			this->cur_size_ = new_size;
			this->max_size_ = new_size;
		}

		else
		{
			this->cur_size_ = new_size;
		}
	}

	else if (new_size < this->cur_size_)
	{
		this->cur_size_ = new_size;
	}
}

template <typename T>
void Array<T>::shrink()
{
	// Check to see if shrinking is necessary
	if (this->cur_size_ < this->max_size_)
	{
		// Create a new array only allocating enough space for the current size
		T * new_array = new T[this->cur_size_];

		for (int i = 0; i < this->cur_size_; i++)
		{
			new_array[i] = this->data_[i];
		}

		// Swap the pointers
		T * temp_ptr = this->data_;

		this->data_ = new_array;

		delete[] temp_ptr;

		this->max_size_ = this->cur_size_;
	}
}
