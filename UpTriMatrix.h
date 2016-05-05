/*****************************************************************************
 * Author:     Brian Catanzaro
 * Username:   bpchyd
 * Class:      CS5201
 * Assignment: 6
 * File:       UpTriMatrix.h

  Class: UpTriMatrix
  Interface for a basic UpTriMatrix class. A standard representation of a
  UpTriMatrix with compatible linear algebra operations.
 *****************************************************************************/

/********************
 * Member Functions *
 *****************************************************************************

 Name: UpTriMatrix()
 Description: Default constructor
 Parameters: None
 Exceptions: None
 Return: None
 Pre: None
 Post: A UpTriMatrix object is created with no size or data

 *****************************************************************************

  Name: UpTriMatrix(const unsigned int width)
  Description: Constructor to create UpTriMatrix of specified height and size
  Parameters: const unsigned int width - The width of the UpTriMatrix
  Exceptions: None
  Return: None
  Pre: None
  Post: A UpTriMatrix object is created with specifeid height and width and is
        allocated memory

 *****************************************************************************

  Name: UpTriMatrix(UpTriMatrix<T>&& original)
  Description: Constructor to move original UpTriMatrix to new UpTriMatrix
  Parameters: UpTriMatrix<T>&& original - rvalue to the original UpTriMatrix
  Exceptions: None
  Return: None
  Pre: None
  Post: A UpTriMatrix object becomes the original UpTriMatrix

 *****************************************************************************

  Name: UpTriMatrix(const UpTriMatrix<T>& original)
  Description: Constructor to copy original UpTriMatrix to new UpTriMatrix
  Parameters: const UpTriMatrix<T>& original - Reference to original UpTriMatrix to copy
  Exceptions: None
  Return: None
  Pre: None
  Post: A UpTriMatrix object is created with size and memory of original UpTriMatrix

 *****************************************************************************

  Name: ~UpTriMatrix()
  Description: Destuctor for UpTriMatrix
  Parameters: None
  Exceptions: None
  Return: None
  Pre: None
  Post: A UpTriMatrix object is destroyed after freeing memory from m_data

 *****************************************************************************

  Name: Vector<T>& operator[](const unsigned int index)
  Description: Indexes into the UpTriMatrix to return element at $(index)
  Parameters: const unsigned int index - The index of the element to access
  Exceptions: out_of_range - Thrown when index is out of bounds of m_data
  Return: A reference to Vector<T> object located at index $(index)
  Pre: None
  Post: A reference to Vector<T> object located at index $(index) is returned

 *****************************************************************************

  Name: const Vector<T>& operator[](const unsigned int index) const
  Description: Indexes into the UpTriMatrix to return const element at $(index)
  Parameters: const unsigned int index - The index of the element to access
  Exceptions: out_of_range - Thrown when index is out of bounds of m_data
  Return: A constant reference to Vector<T> object located at index $(index)
  Pre: None
  Post: A constant reference to Vector<T> object located at index $(index) is
        returned

 *****************************************************************************

  Name: UpTriMatrix<T>& operator=(const T& rhs)
  Description: Assigns the UpTriMatrix to a 1x1 containing element T
  Parameters: const T& rhs - The object to set the UpTriMatrix equal to
  Exceptions: None
  Return: A reference to the calling object after it was modified
  Pre: None
  Post: The calling object's element is equal to rhs


 *****************************************************************************

  Name: UpTriMatrix<T>& operator=(const UpTriMatrix<T>& rhs)
  Description: Assignment to copy rhs into the calling object
  Parameters: UpTriMatrix<T> rhs - The object to be copied
  Exceptions: None
  Return: A reference to the calling object after it was modified
  Pre: None
  Post: The calling objects elements are equal to rhs's elements

 *****************************************************************************

  Name: UpTriMatrix<T>& operator=(UpTriMatrix<T>&& rhs)
  Description: Move assignment to move rhs into the calling object
  Parameters: UpTriMatrix<T>&& rhs - The rvalue to the object to be moved
  Exceptions: None
  Return: A reference to the calling object after it was modified
  Pre: None
  Post: The calling objects elements are equal to rhs's elements

 *****************************************************************************

  Name: UpTriMatrix<T>& operator+=(const UpTriMatrix<T>& rhs)
  Description: Adds the values of rhs to the calling object
  Parameters: const UpTriMatrix<T>& rhs - The UpTriMatrix to add to the calling object
  Exceptions: None
  Return: A reference to the modified calling object
  Pre: Template type T requires an overloaded += operator
       Matricies are of the same size
  Post: A reference to the calling object is returned after adding the values
        of rhs to it

 *****************************************************************************

  Name: UpTriMatrix<T>& operator-=(const UpTriMatrix<T>& rhs)
  Description: Subtracts the values of rhs from the calling object
  Parameters: const UpTriMatrix<T>& rhs - The UpTriMatrix to subtract from the calling
                                     object
  Exceptions: None
  Return: A reference to the modified calling object
  Pre: Template type T requires an overloaded += and unary - operator
       Matricies are of the same size
  Post: A reference to the calling object is returned after subtracting the
        values of rhs from it

 *****************************************************************************

  Name: UpTriMatrix<T> operator-() const
  Description: Negates the values of the calling object
  Parameters: None
  Exceptions: None
  Return: A negated copy of the calling object
  Pre: Template type T requires an overloaded = and unary - operator
  Post: A copy of the calling object is returned with negated elements

 *****************************************************************************

  Name: bool operator==(const UpTriMatrix<T>& rhs) const
  Description: Compares the values of two UpTriMatrix
  Parameters: const UpTriMatrix<T>& rhs - The UpTriMatrix to be compared with the calling
                                    object
  Exceptions: None
  Return: True if the Matricies are equal, else false
  Pre: Template type T requires an overloaded != operator
  Post: A boolean representing the comparison is returned

 *****************************************************************************

  Name: void swap_row(const unsigned int target, const unsigned int dest)
  Description: Swaps the two specified rows
  Parameters: const unsigned int target - Index of one of the rows to swap
              const unsigned int dest - Index of one of the rows to swap
  Exceptions: Throws out_of_range when dest or target exceed m_height
  Return: None
  Pre: None
  Post: Elements in the rows target and dest are swapped

 *****************************************************************************

 Name: void swap_col(const unsigned int target, const unsigned int dest)
 Description: Swaps the two specified columns
 Parameters: const unsigned int target - Index of one of the columns to swap
             const unsigned int dest - Index of one of the columns to swap
 Exceptions: Throws out_of_range when dest or target exceed m_width
 Return: None
 Pre: None
 Post: Elements in the columns target and dest are swapped

 ************************
 * Non-member Functions *
 *****************************************************************************

  Name: UpTriMatrix<T> operator+(UpTriMatrix<T> lhs, const UpTriMatrix<T>& rhs)
  Description: Allows for addition of Matricies
  Parameters: UpTriMatrix<T> lhs - UpTriMatrix that is being added to
              const UpTriMatrix<T>& rhs - UpTriMatrix to be added
  Exceptions: None
  Return: A UpTriMatrix with combined values of the passing objects
  Pre: Template type T must have defined +=, =, and == operators
       Matricies are of the same size
  Post: The two Matricies are added together

 *****************************************************************************

  Name: UpTriMatrix<T> operator-(UpTriMatrix<T> lhs, const UpTriMatrix<T>& rhs)
  Description: Allows for subtraction of Matricies
  Parameters: UpTriMatrix<T> lhs - UpTriMatrix that is being subtracted from
              const UpTriMatrix<T>& rhs - UpTriMatrix to be subtracted
  Exceptions: None
  Return: A UpTriMatrix with combined values of the passing objects
  Pre: Template type T must have defined +=, =, unary -, and == operators
       Matricies are of the same size
  Post: The two Matricies are added together

 *****************************************************************************/

#ifndef UPTRIMATRIX_H
#define UPTRIMATRIX_H

#include <exception>
#include "Vector.h"
#include "BaseMatrix.h"

template <typename T>
class UpTriMatrix : public BaseMatrix<T>
{
public:
  // Constructors/Destructor
  UpTriMatrix() { this->m_width = 0; this->m_data = nullptr; }
  UpTriMatrix(const unsigned int width);
  UpTriMatrix(UpTriMatrix<T>&& original);
  UpTriMatrix(const UpTriMatrix<T>& original);
  ~UpTriMatrix() { delete[] this->m_data; }

  // Operators
  Vector<T>& operator[](const unsigned int index);
  const Vector<T>& operator[](const unsigned int index) const;
  UpTriMatrix<T>& operator=(const T& rhs);
  UpTriMatrix<T>& operator=(const UpTriMatrix<T>& rhs);
  UpTriMatrix<T>& operator=(UpTriMatrix<T>&& rhs);
  UpTriMatrix<T>& operator+=(const UpTriMatrix<T>& rhs);
  UpTriMatrix<T>& operator-=(const UpTriMatrix<T>& rhs) { return *this += -rhs; }
  UpTriMatrix<T> operator-() const;
  bool operator==(const BaseMatrix<T>& rhs) const;

  // Accessors and Modifiers
  void swap_row(const unsigned int target, const unsigned int dest);
  void swap_col(const unsigned int target, const unsigned int dest);
};

// Non-member operators
template <typename T>
UpTriMatrix<T> operator+(UpTriMatrix<T> lhs, const UpTriMatrix<T>& rhs) {return lhs+=rhs;}

template <typename T>
UpTriMatrix<T> operator-(UpTriMatrix<T> lhs, const UpTriMatrix<T>& rhs) {return lhs-=rhs;}

template <typename T>
DenseMatrix<T> operator*(const UpTriMatrix<T>& lhs, const DenseMatrix<T>& rhs);

#include "UpTriMatrix.hpp"

#endif // UPTRIMATRIX_H
