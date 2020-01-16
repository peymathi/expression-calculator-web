/* I pledge that I have neither given nor received any help on this assignment */

#include <stdexcept>	// for std::out_of_bounds exception

//
// Array_Base
//
template <typename T>
Array_Base<T>::Array_Base (void)
:	data_(new T [0]),
	cur_size_(0)
{

}

//
// Array_Base (size_t)
//
template <typename T>
Array_Base <T>::Array_Base (size_t length)
:	data_(new T [length]),
	cur_size_(length)
{

}

//
// Array_Base (size_t, char)
//
template <typename T>
Array_Base <T>::Array_Base (size_t length, T fill)
:	data_(new T [length]),
	cur_size_(length)
{
	this->fill(fill);
}

//
// Array_Base (const Array &)
//
template <typename T>
Array_Base <T>::Array_Base (const Array_Base & array)
:	data_(new T [array.cur_size]),
	cur_size_(array.cur_size_)
{
	// Set all values of the new Array to the values of the old Array
	for (int i = 0; i < this->cur_size_; i++)
	{
		this->data_[i] = array[i];
	}
}

//
// ~Array_Base
//
template <typename T>
Array_Base <T>::~Array_Base (void)
{
	delete [] this->data_;
}

//
// operator []
//
template <typename T>
T & Array_Base <T>::operator [] (size_t index)
{
	// Check for if the index is in range
	if (index > this->cur_size_ - 1)
	{
		throw std::out_of_range("Index out of range for this Array");
	}

	return this->data_[index];
}

//
// operator []
//
template <typename T>
const T & Array_Base <T>::operator [] (size_t index) const
{
	// Check for if the index is in range
	if (index > this->cur_size_ - 1)
	{
		throw std::out_of_range("Index is out of range for this Array");
	}

	return this->data_[index];
}

//
// get
//
template <typename T>
T Array_Base <T>::get (size_t index) const
{
	// Check for if the index is in range
	if (index > this->cur_size_ - 1)
	{
		throw std::out_of_range("Index is out of range for this Array");
	}

	return this->data_[index];
}

//
// set
//
template <typename T>
void Array_Base <T>::set (size_t index, T value)
{
	// Check for if the index is in range
	if (index > this->cur_size_ - 1)
	{
		throw std::out_of_range("Index out of bounds for this Array");
	}

	this->data_[index] = value;
}

//
// find (char)
//
template  <typename T>
int Array_Base <T>::find (T value) const
{
	// Search the array from beginning to end for the specified char
	for (int i = 0; i < this->cur_size_; i++)
	{
		if (value == this->data_[i])
		{
			return i;
		}
	}
	return -1;
}

//
// find (char, size_t)
//
template <typename T>
int Array_Base <T>::find (T val, size_t start) const
{
	// Check if start value is in range
	if (start > this->cur_size_ - 1)
	{
		throw std::out_of_range("Index is out of range for this Array");
	}

	// Search the array from start index to end for the specified char
	for (int i = start; i < this->cur_size_; i++)
	{
		if (val == this->data_[i])
		{
			return i;
		}
	}

	return -1;
}

//
// operator ==
//
template <typename T>
bool Array_Base <T>::operator == (const Array_Base & rhs) const
{
	// Check for self comparison
	if (this->data_ == rhs.data_)
	{
		return true;
	}

	// Compare the state of this array to the other array
	// Test the size member to see if they're equal
	if (this->cur_size_ == rhs.cur_size_)
	{
		// Test each value in the array for equality
		for (int i = 0; i < this->cur_size_; i++)
		{
			// If the last element in the array is equal, return true
			if (i == this->cur_size_ - 1)
			{
					return this->data_[i] == rhs.data_[i];
			}

			if (!(this->data_[i] == rhs.data_[i]))
			{
				return false;
			}
		}
	}

	// This runs if size members are not equal
	return false;
}

//
// operator !=
//
template <typename T>
bool Array_Base <T>::operator != (const Array_Base & rhs) const
{
	return !(*this == rhs);
}

//
// fill
//
template <typename T>
void Array_Base <T>::fill (T value)
{
	for (int i = 0; i < this->cur_size_; i++)
	{
		this->data_[i] = value;
	}
}
