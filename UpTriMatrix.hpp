/*****************************************************************************
 * Author:     Brian Catanzaro
 * Username :  bpchyd
 * Class:      CS5201
 * Assignment: 6
 * File:       UpTriMatrix.hpp

  Implementation for a basic Matrix class found in UpTriMatrix.h.
  A standard representation of a Matrix with compatible linear algebra
  operations.
  ****************************************************************************/

template <typename T>
UpTriMatrix<T>::UpTriMatrix(const unsigned int width)
{
  this->m_width = width;
  this->m_data = new Vector<T>[this->m_width];
  for (auto i = 0u; i < this->m_width; i++)
  {
    this->m_data[i] = Vector<T>(i + 1);
    this->m_data[i].set_buffer(0, this->m_width - i - 1);
  }
}

template <typename T>
UpTriMatrix<T>::UpTriMatrix(UpTriMatrix<T>&& original)
{
  // Move old matrix to new matrix
  this->m_width = original.m_width;
  this->m_data = original.m_data;

  // Set old matrix to null
  original.m_width = 0;
  original.m_data = nullptr;
}

template <typename T>
UpTriMatrix<T>::UpTriMatrix(const UpTriMatrix<T>& original)
{
  this->m_width = original.m_width;
  this->m_data = new Vector<T>[this->m_width];

  // Copy over each element
  Vector<T>* new_p_iter = this->m_data + this->m_width;
  Vector<T>* old_p_iter = original.m_data + this->m_width;
  while (new_p_iter > this->m_data)
  {
    *--new_p_iter = *--old_p_iter;
  }
}

template <typename T>
Vector<T>& UpTriMatrix<T>::operator[](const unsigned int index)
{
  // Throws out_of_range exception if index can't refer to allocated space
  if (index >= this->m_width)
  {
    std::string error = std::string("Index ") + std::to_string(index) +
                        " is out of bounds [0," + std::to_string(this->m_width) + "]";
    throw std::out_of_range(error);
  }

  // Return the data at the indexed location
  return this->m_data[index];
}

template <typename T>
const Vector<T>& UpTriMatrix<T>::operator[](const unsigned int index) const
{
  // Throws out_of_range exception if index can't refer to allocated space
  if (index >= this->m_width)
  {
    std::string error = std::string("Index ") + std::to_string(index) +
                        " is out of bounds [0," + std::to_string(this->m_width) + "]";
    throw std::out_of_range(error);
  }

  // Return the data at the indexed location
  return this->m_data[index];
}

template <typename T>
UpTriMatrix<T>& UpTriMatrix<T>::operator=(const T& rhs)
{
  // Destroy old matrix
  this->m_width = 1;
  delete[] this->m_data;

  // Create new 1x1 matrix containing rhs
  this->m_data = new Vector<T>[1];
  this->m_data[0] = Vector<T>(1);
  this->m_data[0][0] = rhs;

  return *this;
}

template <typename T>
UpTriMatrix<T>& UpTriMatrix<T>::operator=(const UpTriMatrix<T>& rhs)
{
  // Destroy old matrix
  this->m_width = rhs.m_width;
  delete[] this->m_data;

  // Create new matrix equal to rhs
  this->m_data = new Vector<T>[this->m_width];
  for (auto i = 0u; i < this->m_width; i++)
  {
    this->m_data[i] = rhs[i];
  }

  return *this;
}

template <typename T>
UpTriMatrix<T>& UpTriMatrix<T>::operator=(UpTriMatrix<T>&& rhs)
{
  // Move old matrix to new matrix
  delete[] this->m_data;
  this->m_width = rhs.m_width;
  this->m_data = rhs.m_data;

  // Set old matrix to null
  rhs.m_data = nullptr;
  rhs.m_width = 0;

  return *this;
}

template <typename T>
UpTriMatrix<T>& UpTriMatrix<T>::operator+=(const UpTriMatrix<T>& rhs)
{
  // Do not operator if matrix addition is impossible due to size difference
  if (this->m_width == rhs.m_width)
  {
    for (auto i = 0u; i < this->m_width; i++)
    {
      this->m_data[i][i] += rhs.m_data[i][i];
    }
  }

  return *this;
}

template <typename T>
UpTriMatrix<T> UpTriMatrix<T>::operator-() const
{
  UpTriMatrix<T> neg_matrix(this->m_width);

  // Loop over every element in the vector and negate it
  for (auto i = 0u; i < this->m_width; i++)
  {
    neg_matrix[i][i] = -this->m_data[i][i];
  }

  return neg_matrix;
}

template <typename T>
bool UpTriMatrix<T>::operator==(const BaseMatrix<T>& rhs) const
{
  bool same = true;

  // Vectors must be the same size
  if (this->m_width == rhs.width() && this->m_width == rhs.height())
  {
    // Vector elements must be same
    for (auto i = 0u; i < this->m_width; i++)
    {
      for (auto j = 0u; j < this->m_width; j++)
      {
        same = (this->m_data[i][j] == rhs[i][j]);
        if (!same)
        {
          i = j = this->m_width;
        }
      }
    }
  }
  else same = false;

  return same;
}
