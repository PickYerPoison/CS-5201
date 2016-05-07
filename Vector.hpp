/*****************************************************************************
 * Author:     Brian Catanzaro
 *             Graham Netherton
 * Username :  bpchyd
 *             grncp5
 * Class:      CS5201
 * Assignment: 7

  Implementation for a basic Vector class found in Vector.h.
  A standard representation of a vector with compatible linear algebra
  operations.
  ****************************************************************************/

template <typename T>
Vector<T>::Vector(const unsigned int size)
{
  m_size = size;
  m_data = new T[size];
  m_buffer = 0;
  m_end = &m_data[size - 1];
  m_zero_tolerance = 0;
  m_zero_buffer = 0;
}

template <typename T>
Vector<T>::Vector(const unsigned int size, const unsigned int zero_buffer,
                  const unsigned int zero_tolerance)
{
  m_zero_tolerance = zero_tolerance;
  m_zero_buffer = zero_buffer;
  m_buffer = 0;
  m_size = size;
  m_data = new T[size];
  m_end = &m_data[size - 1];
}

template <typename T>
Vector<T>::Vector(Vector<T>&& original)
{
  m_size = original.m_size;
  m_data = original.m_data;
  m_end = original.m_end;
  m_zero_buffer = original.m_zero_buffer;
  m_zero_tolerance = original.m_zero_tolerance;
  m_buffer = original.m_buffer;

  original.m_zero_buffer = 0;
  original.m_zero_tolerance = 0;
  original.m_size = 0;
  original.m_end = nullptr;
  original.m_data = nullptr;
}

template <typename T>
Vector<T>::Vector(const Vector<T>& original)
{
  m_size = original.m_size;
  m_data = new T[m_size];
  m_end = &m_data[m_size - 1];
  m_zero_buffer = original.m_zero_buffer;
  m_zero_tolerance = original.m_zero_tolerance;
  m_buffer = original.m_buffer;

  // Copy over each element
  T* new_p_iter = m_data + m_size;
  T* old_p_iter = original.m_data + m_size;
  while (new_p_iter > m_data)
  {
    *--new_p_iter = *--old_p_iter;
  }
}

template <typename T>
T& Vector<T>::operator[](const unsigned int index)
{
  // Throws out_of_range exception if index can't refer to allocated space
  if (index >= m_size + m_zero_tolerance + m_zero_buffer)
  {
    std::string error = std::string("Index ") + std::to_string(index) +
                        " is out of bounds [0," + std::to_string(m_size) + "]";
    throw std::out_of_range(std::string(error));
  }

  // Return the data at the indexed location
  return (index - m_zero_buffer < m_size) ? m_data[index - m_zero_buffer] : m_buffer;
}

template <typename T>
const T& Vector<T>::operator[](const unsigned int index) const
{
  // Throws out_of_range exception if index can't refer to allocated space
  if (index >= m_size + m_zero_tolerance + m_zero_buffer)
  {
    std::string error = std::string("Index ") + std::to_string(index) +
                        " is out of bounds [0," + std::to_string(m_size) + "]";
    throw std::out_of_range(std::string(error));
  }

  // Return the data at the indexed location
  return (index - m_zero_buffer < m_size) ? m_data[index - m_zero_buffer] : m_buffer;
}

template <typename T>
Vector<T>& Vector<T>::operator=(const T rhs)
{
  T* p_iter = m_data + m_size;
  while (p_iter > m_data)
  {
    *--p_iter = rhs;
  }

  // Return the modified calling object
  return *this;
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& rhs)
{
  m_size = rhs.m_size;
  delete[] m_data;
  m_data = new T[m_size];
  m_end = &m_data[m_size - 1];

  // Copy over each element
  T* new_p_iter = m_data + m_size;
  T* old_p_iter = rhs.m_data + m_size;
  while (new_p_iter > m_data)
  {
    *--new_p_iter = *--old_p_iter;
  }

  // Return the modified calling object
  return *this;
}

template <typename T>
Vector<T>& Vector<T>::operator=(Vector<T>&& rhs)
{
  delete[] m_data;
  m_size = rhs.m_size;
  m_data = rhs.m_data;
  m_end = rhs.m_end;
  rhs.m_data = nullptr;
  rhs.m_end = nullptr;
  rhs.m_size = 0;

  // Return the modified calling object
  return *this;
}

template <typename T>
Vector<T>& Vector<T>::operator+=(const Vector<T>& rhs)
{
  // Do not operate if vector addition is impossible due to size difference
  if (m_size == rhs.m_size)
  {
    for (unsigned int i = 0; i < m_size; i++)
    {
      m_data[i] += rhs.m_data[i];
    }
  }

  // Return the modified calling object
  return *this;
}

template <typename T>
Vector<T> Vector<T>::operator-() const
{
  Vector<T> neg_vector(m_size);

  // Loop over every element of the Vector
  for (unsigned int i = 0; i < m_size; i++)
  {
    // Negate every element
    neg_vector.m_data[i] = -m_data[i];
  }

  // Return vector copy with negated values
  return neg_vector;
}

template <typename T>
bool Vector<T>::operator==(const Vector<T>& rhs) const
{
  bool same = true;

  // Vectors must be same size
  if (m_size == rhs.m_size)
  {
    // Vector elements must be same
    for (unsigned int i = 0; i < m_size; i++)
    {
      if (m_data[i] != rhs.m_data[i])
      {
        same = false;
        break;
      }
    }
  }
  else same = false;

  // Return true if rhs == calling object
  return same;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const Vector<T>& rhs)
{
  for (unsigned int i = 0; i < rhs.m_size - 1; i++)
  {
    os << rhs.m_data[i] << " ";
  }
  os << rhs.m_data[rhs.m_size - 1];

  // Return os with added Vector output
  return os;
}

template <typename T>
std::istream& operator>>(std::istream& is, Vector<T>& rhs)
{
  T new_element;
  is >> new_element;

  // If there's space allocated but unused try to expand into that space
  if (rhs.m_end != &rhs.m_data[rhs.m_size - 1])
  {
    rhs.m_data[rhs.m_size] = new_element;
    rhs.m_size++;
  }
  // If the array has run out of allocated space, double it
  else
  {
    T* new_data = new T[rhs.m_size * 2];

    // Don't try to memcpy in order to optimize, this breaks user-defined types
    for (unsigned int i = 0; i < rhs.m_size; i++)
    {
      new_data[i] = rhs.m_data[i];
    }
    new_data[rhs.m_size] = new_element;

    // Update rhs
    rhs.m_end = &new_data[(rhs.m_size * 2) - 1];
    rhs.m_size++;
    delete[] rhs.m_data;
    rhs.m_data = new_data;
  }

  // Return the passed is
  return is;
}

template <typename T>
void Vector<T>::resize(unsigned int new_size)
{
  if (m_size != new_size)
  {
    delete[] m_data;
    m_size = new_size;
    m_data = new T[m_size];
    m_end = &m_data[m_size - 1];
  }
  return;
}

template<typename T>
T operator*(const Vector<T>& lhs, const Vector<T>& rhs)
{
  T sum = 0;
  if (lhs.size() == rhs.size())
  {
    for (unsigned int i = 0; i < lhs.size(); i++)
    {
      sum += (lhs[i] * rhs[i]);
    }
  }
  return sum;
}

template<typename T>
Vector<T> operator*(Vector<T> lhs, const T& rhs)
{
  // Check the 0 case
  if (rhs != 0)
  {
    for (unsigned int i = 0; i < lhs.size(); i++)
    {
      lhs[i] *= rhs;
    }
  }
  else lhs = 0;

  // Return the newly multiplied Vector equal to the calling object
  return lhs;
}

template<typename T>
void Vector<T>::set_buffer(const unsigned int buffer, const unsigned int tolerance)
{
  m_zero_buffer = buffer;
  m_zero_tolerance = tolerance;
  return;
}
