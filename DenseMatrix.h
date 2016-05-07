/*****************************************************************************
 * Author:     Brian Catanzaro
 * Username:   bpchyd
 * Class:      CS5201
 * Assignment: 6
 * File:       DenseMatrix.h

  Class: DenseMatrix
  Interface for a basic DenseMatrix class. A standard representation of a
  DenseMatrix with compatible linear algebra operations.
 *****************************************************************************/

/********************
 * Member Functions *
 *****************************************************************************

 Name: DenseMatrix()
 Description: Default constructor
 Parameters: None
 Exceptions: None
 Return: None
 Pre: None
 Post: A DenseMatrix object is created with no size or data

 *****************************************************************************

  Name: DenseMatrix(const unsigned int width)
  Description: Constructor to create DenseMatrix of specified height and size
  Parameters: const unsigned int width - The width of the DenseMatrix
  Exceptions: None
  Return: None
  Pre: None
  Post: A DenseMatrix object is created with specifeid height and width and is
        allocated memory

 *****************************************************************************

  Name: DenseMatrix(DenseMatrix<T>&& original)
  Description: Constructor to move original DenseMatrix to new DenseMatrix
  Parameters: DenseMatrix<T>&& original - rvalue to the original DenseMatrix
  Exceptions: None
  Return: None
  Pre: None
  Post: A DenseMatrix object becomes the original DenseMatrix

 *****************************************************************************

  Name: DenseMatrix(const DenseMatrix<T>& original)
  Description: Constructor to copy original DenseMatrix to new DenseMatrix
  Parameters: const DenseMatrix<T>& original - Reference to original DenseMatrix to copy
  Exceptions: None
  Return: None
  Pre: None
  Post: A DenseMatrix object is created with size and memory of original DenseMatrix

 *****************************************************************************

  Name: ~DenseMatrix()
  Description: Destuctor for DenseMatrix
  Parameters: None
  Exceptions: None
  Return: None
  Pre: None
  Post: A DenseMatrix object is destroyed after freeing memory from m_data

 *****************************************************************************

  Name: Vector<T>& operator[](const unsigned int index)
  Description: Indexes into the DenseMatrix to return element at $(index)
  Parameters: const unsigned int index - The index of the element to access
  Exceptions: out_of_range - Thrown when index is out of bounds of m_data
  Return: A reference to Vector<T> object located at index $(index)
  Pre: None
  Post: A reference to Vector<T> object located at index $(index) is returned

 *****************************************************************************

  Name: const Vector<T>& operator[](const unsigned int index) const
  Description: Indexes into the DenseMatrix to return const element at $(index)
  Parameters: const unsigned int index - The index of the element to access
  Exceptions: out_of_range - Thrown when index is out of bounds of m_data
  Return: A constant reference to Vector<T> object located at index $(index)
  Pre: None
  Post: A constant reference to Vector<T> object located at index $(index) is
        returned

 *****************************************************************************

  Name: DenseMatrix<T>& operator=(const T& rhs)
  Description: Assigns the DenseMatrix to a 1x1 containing element T
  Parameters: const T& rhs - The object to set the DenseMatrix equal to
  Exceptions: None
  Return: A reference to the calling object after it was modified
  Pre: None
  Post: The calling object's element is equal to rhs


 *****************************************************************************

  Name: DenseMatrix<T>& operator=(const DenseMatrix<T>& rhs)
  Description: Assignment to copy rhs into the calling object
  Parameters: DenseMatrix<T> rhs - The object to be copied
  Exceptions: None
  Return: A reference to the calling object after it was modified
  Pre: None
  Post: The calling objects elements are equal to rhs's elements

 *****************************************************************************

  Name: DenseMatrix<T>& operator=(DenseMatrix<T>&& rhs)
  Description: Move assignment to move rhs into the calling object
  Parameters: DenseMatrix<T>&& rhs - The rvalue to the object to be moved
  Exceptions: None
  Return: A reference to the calling object after it was modified
  Pre: None
  Post: The calling objects elements are equal to rhs's elements

 *****************************************************************************

  Name: DenseMatrix<T>& operator+=(const DenseMatrix<T>& rhs)
  Description: Adds the values of rhs to the calling object
  Parameters: const DenseMatrix<T>& rhs - The DenseMatrix to add to the calling object
  Exceptions: None
  Return: A reference to the modified calling object
  Pre: Template type T requires an overloaded += operator
       Matricies are of the same size
  Post: A reference to the calling object is returned after adding the values
        of rhs to it

 *****************************************************************************

  Name: DenseMatrix<T>& operator-=(const DenseMatrix<T>& rhs)
  Description: Subtracts the values of rhs from the calling object
  Parameters: const DenseMatrix<T>& rhs - The DenseMatrix to subtract from the calling
                                     object
  Exceptions: None
  Return: A reference to the modified calling object
  Pre: Template type T requires an overloaded += and unary - operator
       Matricies are of the same size
  Post: A reference to the calling object is returned after subtracting the
        values of rhs from it

 *****************************************************************************

  Name: DenseMatrix<T> operator-() const
  Description: Negates the values of the calling object
  Parameters: None
  Exceptions: None
  Return: A negated copy of the calling object
  Pre: Template type T requires an overloaded = and unary - operator
  Post: A copy of the calling object is returned with negated elements

 *****************************************************************************

  Name: DenseMatrix<T> operator~() const
  Description: Transposes the values of the calling object
  Parameters: None
  Exceptions: None
  Return: A transposed copy of the calling object
  Pre: None
  Post: A copy of the calling object is returned with transposed elements

 *****************************************************************************

  Name: bool operator==(const DenseMatrix<T>& rhs) const
  Description: Compares the values of two DenseMatrix
  Parameters: const DenseMatrix<T>& rhs - The DenseMatrix to be compared with the calling
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

  Name: DenseMatrix<T> operator+(DenseMatrix<T> lhs, const DenseMatrix<T>& rhs)
  Description: Allows for addition of Matricies
  Parameters: DenseMatrix<T> lhs - DenseMatrix that is being added to
              const DenseMatrix<T>& rhs - DenseMatrix to be added
  Exceptions: None
  Return: A DenseMatrix with combined values of the passing objects
  Pre: Template type T must have defined +=, =, and == operators
       Matricies are of the same size
  Post: The two Matricies are added together

 *****************************************************************************

  Name: DenseMatrix<T> operator-(DenseMatrix<T> lhs, const DenseMatrix<T>& rhs)
  Description: Allows for subtraction of Matricies
  Parameters: DenseMatrix<T> lhs - DenseMatrix that is being subtracted from
              const DenseMatrix<T>& rhs - DenseMatrix to be subtracted
  Exceptions: None
  Return: A DenseMatrix with combined values of the passing objects
  Pre: Template type T must have defined +=, =, unary -, and == operators
       Matricies are of the same size
  Post: The two Matricies are added together

 *****************************************************************************

  Name: DenseMatrix<T> operator*(const DenseMatrix<T> lhs, const DenseMatrix<T>& rhs)
  Description: Allows for the multiplication of Matricies by other Matricies
  Parameters: const DenseMatrix<T> lhs - DenseMatrix that is being multiplied
              const DenseMatrix<T>& rhs - DenseMatrix to multiply
  Exceptions: None
  Return: A DenseMatrix with multiplied values of the passed objects or an empty
          DenseMatrix if the two Matricies cannot be multiplied
  Pre: Template type T must have a defined *= and == operators
       lhs.m_width must equal rhs.m_height
  Post: Returns a new DenseMatrix with multiplied elements if the Matricies can be
        multiplied otherwise an empty DenseMatrix.

 *****************************************************************************

  Name: DenseMatrix<T> operator*(DenseMatrix<T> lhs, const T& rhs)
  Description: Allows for the multiplication of Matricies by scalars
  Parameters: DenseMatrix<T> lhs - DenseMatrix that is being multiplied
              const T& rhs - Scalar value to multiply
  Exceptions: None
  Return: A DenseMatrix with multiplied values of the passed objects
  Pre: Template type T must have a defined *= and == operators
  Post: Returns a value equal to the lhs multiplied by the rhs

 *****************************************************************************

  Name: DenseMatrix<T> operator*(const T& lhs, DenseMatrix<T> rhs)
  Description: Allows for the multiplication of Matricies by scalars
  Parameters: const T& lhs - Scalar value to multiply
              DenseMatrix<T> rhs - DenseMatrix that is being multiplied
  Exceptions: None
  Return: A DenseMatrix with multiplied values of the passed objects
  Pre: Template type T must have a defined *= and == operators
  Post: Returns a value equal to the lhs multiplied by the lhs

 *****************************************************************************/

#ifndef DENSEMATRIX_H
#define DENSEMATRIX_H

#include <exception>
#include "Vector.h"
#include "BaseMatrix.h"

template <typename T>
class DenseMatrix : public BaseMatrix<T>
{
public:
  // Constructors/Destructor
  DenseMatrix() { this->m_width = 0; this->m_data = nullptr; }
  DenseMatrix(const unsigned int width);
  DenseMatrix(DenseMatrix<T>&& original);
  DenseMatrix(const DenseMatrix<T>& original);
  ~DenseMatrix() { delete[] this->m_data; }

  // Operators
  Vector<T>& operator[](const unsigned int index);
  const Vector<T>& operator[](const unsigned int index) const;
  DenseMatrix<T>& operator=(const T& rhs);
  DenseMatrix<T>& operator=(const BaseMatrix<T>& rhs);
  DenseMatrix<T>& operator=(DenseMatrix<T>&& rhs);
  DenseMatrix<T>& operator+=(const DenseMatrix<T>& rhs);
  DenseMatrix<T>& operator-=(const DenseMatrix<T>& rhs) { return *this += -rhs; }
  DenseMatrix<T> operator-() const;
  DenseMatrix<T> operator~() const;
  bool operator==(const BaseMatrix<T>& rhs) const;

  // Accessors and Modifiers
  void swap_row(const unsigned int target, const unsigned int dest);
  void swap_col(const unsigned int target, const unsigned int dest);
};

// Non-member operators
template <typename T>
DenseMatrix<T> operator+(DenseMatrix<T> lhs, const DenseMatrix<T>& rhs) {return lhs+=rhs;}

template <typename T>
DenseMatrix<T> operator-(DenseMatrix<T> lhs, const DenseMatrix<T>& rhs) {return lhs-=rhs;}

template <typename T>
DenseMatrix<T> operator*(const DenseMatrix<T>& lhs, const T& rhs);

template <typename T>
DenseMatrix<T> operator*(const T& lhs, const DenseMatrix<T>& rhs) { return rhs * lhs; }

template <typename T>
DenseMatrix<T> operator*(const BaseMatrix<T>& lhs, const BaseMatrix<T>& rhs);

template <typename T>
Vector<T> operator*(const BaseMatrix<T>& lhs, const Vector<T>& rhs);

#include "DenseMatrix.hpp"

#endif // DENSEMATRIX_H
