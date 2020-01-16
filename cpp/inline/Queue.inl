/* Honor Pledge:

I pledge that I have neither given nor
recieved any help on this assignment
*/

/* Inline method implementation for Queue class */

template <typename T>
inline
size_t Queue<T>::size(void)
{
  return this->size_;
}

template <typename T>
inline
size_t Queue<T>::max_size(void)
{
  return this->max_size_;
}

template <typename T>
inline
bool Queue<T>::is_empty(void)
{
  return this->size_ == 0;
}
