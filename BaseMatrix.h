/*****************************************************************************
 * Author:     Brian Catanzaro
 * Username :  bpchyd
 * Class:      CS5201
 * Assignment: 6
 * File:       Vector.h

  Class: Vector
  Interface for a basic vector class. A standard representation of a
  vector with compatible linear algebra operations.
 *****************************************************************************/

/********************
 * Member Functions *
 *****************************************************************************

  Name: bool operator==(const BaseMatrix<T>& rhs) const
  Description: Compares the values of two Matricies
  Parameters: const BaseMatrix<T>& rhs - The Matrix to be compared with the calling
                                         object
  Exceptions: None
  Return: True if the Matricies are equal, else false
  Pre: Template type T requires an overloaded != operator
  Post: A boolean representing the comparison is returned

 *****************************************************************************

  Name: bool operator!=(const BaseMatrix<T>& rhs) const
  Description: Compares the values of two Matricies
  Parameters: const BaseMatrix<T>& rhs - The Matrix to be compared with the calling
                                         object
  Exceptions: None
  Return: True if the Matricies are not equal, else false
  Pre: Template type T requires an overloaded != operator
  Post: A boolean representing the comparison is returned

 *****************************************************************************

  Name: Vector<T>& operator[](const unsigned int index)
  Description: Indexes into the matrix to return const element at $(index)
  Parameters: const unsigned int index - The index of the element to access
  Exceptions: out_of_range - Thrown when index is out of bounds of m_data
  Return: A constant reference to T object located at index $(index)
  Pre: None
  Post: A constant reference to T object located at index $(index) is returned

 *****************************************************************************

  Name: const Vector<T>& operator[](const unsigned int index) const
  Description: Indexes into the matrix to return const element at $(index)
  Parameters: const unsigned int index - The index of the element to access
  Exceptions: out_of_range - Thrown when index is out of bounds of m_data
  Return: A constant reference to T object located at index $(index)
  Pre: None
  Post: A constant reference to T object located at index $(index) is returned

 *****************************************************************************

  Name: unsigned int height() const
  Description: Returns the height of the matrix
  Parameters: None
  Exceptions: None
  Return: The height of the matrix
  Pre: None
  Post: The height of the matrix is returned

 *****************************************************************************

  Name: unsigned int width() const
  Description: Returns the width of the matrix
  Parameters: None
  Exceptions: None
  Return: The width of the matrix
  Pre: None
  Post: The width of the matrix is returned

 *****************************************************************************

  Name: ostream& operator<<(ostream& os, const BaseMatrix<T>& rhs)
  Description: Reads contents of Vector to ostream
  Parameters: ostream& os - The ostream to which the BaseMatrix will be written
             const BaseMatrix<T>& rhs - The BaseMatrix to be streamed
  Exceptions: None
  Return: A reference to the passed ostream object
  Pre: Templated type must have an overloaded << operator accepting an ostream
      followed by the object and returns an ostream
  Post: The ostream contains the contents of the passed BaseMatrix

 *****************************************************************************

  Name: istream& operator>>(istream& is, BaseMatrix<T>& rhs)
  Description: Reads contents of istream to insert to end of BaseMatrix
  Parameters: istream& us - The istream BaseMatrix will be written from
             BaseMatrix<T>& rhs - The BaseMatrix to be inserted into
  Exceptions: None
  Return: A reference to the passed istream object
  Pre: Templated type must have an overloaded >> operator accepting an istream
      followed by the object and returns an istream
      Templated type must have an overladed = operator
  Post: The istream is returned having inserted into the BaseMatrix

 *****************************************************************************/


#ifndef BASEMATRIX_H
#define BASEMATRIX_H

#include <iostream>
#include <iomanip>
#include "Vector.h"

// Forward Declarations for safe templates
template <typename T>
class BaseMatrix;

template <typename T>
std::ostream& operator<<(std::ostream& os, const BaseMatrix<T>& rhs);

template <typename T>
std::istream& operator>>(std::istream& os, BaseMatrix<T>& rhs);

template <typename T>
class BaseMatrix
{
public:
  virtual bool operator==(const BaseMatrix<T>& rhs) const = 0;
  virtual bool operator!=(const BaseMatrix<T>& rhs) const { return !(*this == rhs); }
  virtual Vector<T>& operator[](const unsigned int index) = 0;
  virtual const Vector<T>& operator[](const unsigned int index) const = 0;
  virtual unsigned int height() const { return m_width; }
  virtual unsigned int width() const { return m_width; }
  friend std::ostream& operator<<<T>(std::ostream& os, const BaseMatrix& rhs);
  friend std::istream& operator>><T>(std::istream& is, BaseMatrix& rhs);

protected:
  unsigned int m_width; // Number of Vectors in matrix
  Vector<T>* m_data; // Pointer to the vector
};

#include "BaseMatrix.hpp"

#endif // BASEMATRIX_H
