/*****************************************************************************
 * Author:     Brian Catanzaro
 * Username :  bpchyd
 * Class:      CS5201
 * Assignment: 6
 * File:       DenseMatrix.hpp

  Implementation for a basic Matrix class found in DenseMatrix.h.
  A standard representation of a Matrix with compatible linear algebra
  operations.
  ****************************************************************************/

template <typename T>
DenseMatrix<T>::DenseMatrix(const unsigned int width)
{
  this->m_width = width;
  this->m_data = new Vector<T>[width];
  for (auto i = 0u; i < this->m_width; i++)
  {
    this->m_data[i] = Vector<T>(width);
    for (auto j = 0u; j < this->m_width; j++)
    {
      this->m_data[i][j] = 0;
    }
  }
}

template <typename T>
DenseMatrix<T>::DenseMatrix(DenseMatrix<T>&& original)
{
  // Move old matrix to new matrix
  this->m_width = original.m_width;
  this->m_data = original.m_data;

  // Set old matrix to null
  original.m_width = 0;
  original.m_data = nullptr;
}

template <typename T>
DenseMatrix<T>::DenseMatrix(const DenseMatrix<T>& original)
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
Vector<T>& DenseMatrix<T>::operator[](const unsigned int index)
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
const Vector<T>& DenseMatrix<T>::operator[](const unsigned int index) const
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
DenseMatrix<T>& DenseMatrix<T>::operator=(const T& rhs)
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
DenseMatrix<T>& DenseMatrix<T>::operator=(const BaseMatrix<T>& rhs)
{
  // Destroy old matrix
  this->m_width = rhs.width();
  delete[] this->m_data;

  // Create new matrix equal to rhs
  this->m_data = new Vector<T>[this->m_width];
  for (auto i = 0u; i < this->m_width; i++)
  {
    this->m_data[i] = Vector<T>(this->m_width);
    for (auto j = 0u; j < this->m_width; j++)
    {
      this->m_data[i][j] = rhs[i][j];
    }
  }

  return *this;
}

template <typename T>
DenseMatrix<T>& DenseMatrix<T>::operator=(DenseMatrix<T>&& rhs)
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
DenseMatrix<T>& DenseMatrix<T>::operator+=(const DenseMatrix<T>& rhs)
{
  // Do not operator if matrix addition is impossible due to size difference
  if (this->m_width == rhs.m_width)
  {
    for (auto i = 0u; i < this->m_width; i++)
    {
      for (auto j = 0u; j < this->m_width; j++)
      {
        this->m_data[i][j] += rhs.m_data[i][j];
      }
    }
  }

  return *this;
}

template <typename T>
DenseMatrix<T> DenseMatrix<T>::operator-() const
{
  DenseMatrix<T> neg_matrix(this->m_width);

  // Loop over every element in the vector and negate it
  for (auto i = 0u; i < this->m_width; i++)
  {
    for (auto j = 0u; j < this->m_width; j++)
    {
      neg_matrix[i][j] = -this->m_data[i][j];
    }
  }

  return neg_matrix;
}

template <typename T>
DenseMatrix<T> DenseMatrix<T>::operator~() const
{
  DenseMatrix<T> trans_matrix(this->m_width);

  // Loop over every element in the vector and transpose it
  for (auto i = 0u; i < this->m_width; i++)
  {
    for (auto j = 0u; j < this->m_width; j++)
    {
      trans_matrix[j][i] = this->m_data[i][j];
    }
  }

  return trans_matrix;
}

template <typename T>
bool DenseMatrix<T>::operator==(const BaseMatrix<T>& rhs) const
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

template <typename T>
DenseMatrix<T> operator*(const DenseMatrix<T>& lhs, const T& rhs)
{
  DenseMatrix<T> new_matrix = DenseMatrix<T>(lhs.width(), lhs.height());

  for (auto i = 0u; i < lhs.width(); i++)
  {
    for (auto j = 0u; j < lhs.height(); j++)
    {
      new_matrix[i][j] = lhs[i][j] * rhs;
    }
  }

  return new_matrix;
}

template <typename T>
void DenseMatrix<T>::swap_row(const unsigned int target, const unsigned int dest)
{
  // Throws out_of_range exception if index can't refer to allocated space
  if (target >= this->m_width || dest >= this->m_width)
  {
    std::string error = std::string("Index ") + std::to_string(target) +
                      " is out of bounds [0," + std::to_string(this->m_width) + "]";
    throw std::out_of_range(error);
  }

  for (auto i = 0u; i < this->m_width; i++)
  {
    std::swap(this->m_data[i][target], this->m_data[i][dest]);
  }
  return;
}

template <typename T>
void DenseMatrix<T>::swap_col(const unsigned int target, const unsigned int dest)
{
  if (target >= this->m_width || dest >= this->m_width)
  {
    std::string error = std::string("Index ") + std::to_string(target) +
                      " is out of bounds [0," + std::to_string(this->m_width) + "]";
    throw std::out_of_range(error);
  }

  for (auto i = 0u; i < this->m_width; i++)
  {
    std::swap(this->m_data[target][i], this->m_data[dest][i]);
  }
  return;
}

template <typename T>
DenseMatrix<T> operator*(const BaseMatrix<T>& lhs, const BaseMatrix<T>& rhs)
{
  DenseMatrix<T> new_matrix = DenseMatrix<T>(lhs.height());

  // Make sure matricies are able to be multiplied
  if (lhs.width() == rhs.height())
  {
    for (auto i = 0u; i < lhs.height(); i++)
    {
      for (auto j = 0u; j < rhs.width(); j++)
      {
        new_matrix[j][i] = 0;
        for (auto k = 0u; k < rhs.height(); k++)
        {
          new_matrix[j][i] += (lhs[k][i] * rhs[j][k]);
        }
      }
    }
  }

  return new_matrix;
}

template <typename T>
Vector<T> operator*(const BaseMatrix<T>& lhs, const Vector<T>& rhs)
{
  Vector<T> new_vector = Vector<T>(lhs.height());

  // Make sure matricies are able to be multiplied
  if (lhs.width() == rhs.size())
  {
    for (auto i = 0u; i < lhs.height(); i++)
    {
      new_vector[i] = 0;
      for (auto j = 0u; j < rhs.size(); j++)
      {
        new_vector[i] += lhs[i][j] * rhs[i];
      }
    }
  }

  return new_vector;
}
