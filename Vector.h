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

  Name: Vector()
  Description: Default constructor
  Parameters: None
  Exceptions: None
  Return: None
  Pre: None
  Post: A Vector object is created with no size or data

 *****************************************************************************

  Name: Vector(unsigned int size)
  Description: Constructor to create Vector of size $(size)
  Parameters: unsigned int size - The size of the to be created Vector
  Exceptions: None
  Return: None
  Pre: None
  Post: A Vector object is created with size $(size) and allocated memory

 *****************************************************************************

  Name: Vector(unsigned int size, unsigned int zer_tolerance)
  Description: Constructor to create Vector of size $(size)
  Parameters: unsigned int size - The size of the to be created Vector
              unsigned int zero_tolerance - The zero tolerance of the Vector
  Exceptions: None
  Return: None
  Pre: None
  Post: A Vector object is created with size $(size) and allocated memory

 *****************************************************************************

  Name: Vector(Vector<T>&& original)
  Description: Constructor to move original Vector to new Cector
  Parameters: Vector<T>&& original - rvalue to the original Vector
  Exceptions: None
  Return: None
  Pre: None
  Post: A Vector object becomes the original Vector

 *****************************************************************************

  Name: Vector(const Vector<T>& original)
  Description: Constructor to copy original vector to new Cector
  Parameters: const Vector<T>& original - Reference to original vector to copy
  Exceptions: None
  Return: None
  Pre: None
  Post: A Vector object is created with size and memory of original Cector

 *****************************************************************************

  Name: ~Vector()
  Description: Destuctor for Vector
  Parameters: None
  Exceptions: None
  Return: None
  Pre: None
  Post: A Vector object is destroyed after freeing memory from m_data

 *****************************************************************************

  Name: T& operator[](const unsigned int index)
  Description: Indexes into the vector to return element at $(index)
  Parameters: const unsigned int index - The index of the element to access
  Exceptions: out_of_range - Thrown when index is out of bounds of m_data
  Return: A reference to T object located at index $(index)
  Pre: None
  Post: A reference to T object located at index $(index) is returned

 *****************************************************************************

  Name: const T& operator[](const unsigned int index) const
  Description: Indexes into the vector to return const element at $(index)
  Parameters: const unsigned int index - The index of the element to access
  Exceptions: out_of_range - Thrown when index is out of bounds of m_data
  Return: A constant reference to T object located at index $(index)
  Pre: None
  Post: A constant reference to T object located at index $(index) is returned

 *****************************************************************************

  Name: Vector<T>& operator=(T rhs)
  Description: Assigns every element of the Vector to be rhs
  Parameters: T rhs - The object to set every element equal to
  Exceptions: None
  Return: A reference to the calling object after it was modified
  Pre: None
  Post: The calling objects elements are equal to rhs

 *****************************************************************************

  Name: Vector<T>& operator=(const Vector<T>& rhs)
  Description: Assignment to copy rhs into the calling object
  Parameters: Vector<T> rhs - The object to be copied
  Exceptions: None
  Return: A reference to the calling object after it was modified
  Pre: None
  Post: The calling objects elements are equal to rhs's elements

 *****************************************************************************

  Name: Vector<T>& operator=(Vector<T>&& rhs)
  Description: Move assignment to move rhs into the calling object
  Parameters: Vector<T>&& rhs - The rvalue to the object to be moved
  Exceptions: None
  Return: A reference to the calling object after it was modified
  Pre: None
  Post: The calling objects elements are equal to rhs's elements

 *****************************************************************************

  Name: Vector<T>& operator+=(const Vector<T>& rhs)
  Description: Adds the values of rhs to the calling object
  Parameters: const Vector<T>& rhs - The Vector to add to the calling object
  Exceptions: None
  Return: A reference to the modified calling object
  Pre: Template type T requires an overloaded += operator
       Vectors are of the same size
  Post: A reference to the calling object is returned after adding the values
        of rhs to it

  *****************************************************************************

  Name: Vector<T>& operator-=(const Vector<T>& rhs)
  Description: Subtracts the values of rhs to the calling object
  Parameters: const Vector<T>& rhs - The Vector to subtract from the calling
                                     object
  Exceptions: None
  Return: A reference to the modified calling object
  Pre: Template type T requires an overloaded += and unary - operator
       Vectors are of the same size
  Post: A reference to the calling object is returned after subtracting
        the values of rhs from it

 *****************************************************************************

  Name: Vector<T> operator-()
  Description: Negates the values of the calling object
  Parameters: None
  Exceptions: None
  Return: A negated copy of the calling object
  Pre: Template type T requires an overloaded = and unary - operator
  Post: A copy of the calling object is returned with negated elements

 *****************************************************************************

  Name: bool operator==(const Vector<T>& rhs) const
  Description: Compares the values of two Vectors
  Parameters: const Vector<T>& rhs - The Vector to be compared with the calling
                                     object
  Exceptions: None
  Return: True if the Vectors are equal, else false
  Pre: Template type T requires an overloaded != operator
  Post: A boolean representing the comparison is returned

 *****************************************************************************

  Name: bool operator!=(const Vector<T>& rhs) const
  Description: Compares the values of two Vectors
  Parameters: const Vector<T>& rhs - The Vector to be compared with the calling
                                     object
  Exceptions: None
  Return: True if the Vectors are not equal, else false
  Pre: Template type T requires an overloaded != operator
  Post: A boolean representing the comparison is returned

 *****************************************************************************

  Name: void resize(unsigned int new_size)
  Description: Resizes the vector to appropriate bounds
  Parameters: unsigned int new_size - The new size of the Vector
  Exceptions: None
  Return: None
  Pre: None
  Post: The calling objects contains $(new_size) number of default elements
        Does nothing if new_size is the current size of the Vector

 *****************************************************************************

  Name: ostream& operator<<(ostream& os, const Vector<T>& rhs)
  Description: Reads contents of Vector to ostream
  Parameters: ostream& os - The ostream to which the Vector will be written
              const Vector<T>& rhs - The Vector to be streamed
  Exceptions: None
  Return: A reference to the passed ostream object
  Pre: Templated type must have an overloaded << operator accepting an ostream
       followed by the object and returns an ostream
  Post: The ostream contains the contents of the passed Vector

 *****************************************************************************

  Name: istream& operator>>(istream& is, Vector<T>& rhs)
  Description: Reads contents of istream to insert to end of Vector
  Parameters: istream& us - The istream Vector will be written from
              Vector<T>& rhs - The Vector to be inserted into
  Exceptions: None
  Return: A reference to the passed istream object
  Pre: Templated type must have an overloaded >> operator accepting an istream
       followed by the object and returns an istream
       Templated type must have an overladed = operator
  Post: The istream is returned having inserted into the Vector

 ************************
 * Non-member Functions *
 *****************************************************************************

 Name: Vector<T> operator+(Vector<T> lhs, const Vector<T>& rhs)
 Description: Allows for addiion of Vectors
 Parameters: Vector<T> lhs - Vector that is being added to
             const Vector<T>& rhs - Vector to be added
 Exceptions: None
 Return: A Vector with combined values of the passing objects
 Pre: Template type T must have defined +=, =, and == operators
      Vectors are of the same size
 Post: The two Vectors are added together

 *****************************************************************************

 Name: Vector<T> operator-(Vector<T> lhs, const Vector<T>& rhs)
 Description: Allows for the subtraction of Vectors
 Parameters: Vector<T> lhs - Vector that is being subtracted from
             const Vector<T>& rhs - Vector to be subtracted
 Exceptions: None
 Return: A Vector with combined values of the passing objects
 Pre: Template type T must have defined +=, =, unary -, and == operators
      Vectors are of the same size
 Post: The rhs is subtracted from the lhs

 *****************************************************************************

 Name: T& operator*(const Vector<T>& lhs, const Vector<T>& rhs)
 Description: Dot product of two Vectors
 Parameters: Vector<T> lhs - Vector that is being dot producted
             Vector<T> rhs - Vector that is being dot producted
 Exceptions: None
 Return: A T type reference equal to the dot product of the parameters or 0 if
         Vectors were of differing sizes
 Pre: Vectors must contain the same number of elements
      Template type T must be able to be assigned primitive 0
      Template type T must also have defined += and * operators for T objects
 Post: Returns a T reference equal to the dot product of the passed Vectors or
       0 if Vectors were of different sizes

 *****************************************************************************

 Name: Vector<T> operator*(Vector<T> lhs, const T& rhs)
 Description: Allows for the multiplication of Vectors by scalars
 Parameters: Vector<T> lhs - Vector that is being multiplied
             const T& rhs - Scalar value to multiply
 Exceptions: None
 Return: A Vector with multiplied values of the passed objects
 Pre: Template type T must have a defined *= and == operators
 Post: Returns a value equal to the lhs multiplied by the rhs

 *****************************************************************************

 Name: Vector<T> operator*(const T& lhs, Vector<T> rhs)
 Description: Allows for the multiplication of Vectors by scalars
 Parameters: const T& lhs - Scalar value to multiply
             Vector<T> rhs - Vector that is being multiplied
 Exceptions: None
 Return: A Vector with multiplied values of the passed objects
 Pre: Template type T must have a defined *= and == operators
 Post: Returns a value equal to the lhs multiplied by the lhs

 *****************************************************************************/


#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

// Forward Declarations for safe templates
template <typename T>
class Vector;

template <typename T>
std::ostream& operator<<(std::ostream& os, const Vector<T>& rhs);

template <typename T>
std::istream& operator>>(std::istream& os, Vector<T>& rhs);

template <typename T>
class Vector
{
public:
  // Constructors/Destructor
  Vector() : m_size(0), m_zero_tolerance(0), m_zero_buffer(0), m_buffer(0),
             m_data(nullptr), m_end(nullptr) { }
  Vector(const unsigned int size);
  Vector(const unsigned int size, const unsigned int zero_buffer,
         const unsigned int zero_tolerance);
  Vector(Vector<T>&& original);
  Vector(const Vector<T>& original);
  ~Vector() { delete[] m_data; }

  // Operators
  T& operator[](const unsigned int index);
  const T& operator[](const unsigned int index) const;
  Vector<T>& operator=(const T rhs);
  Vector<T>& operator=(const Vector<T>& rhs);
  Vector<T>& operator=(Vector<T>&& rhs);
  Vector<T>& operator+=(const Vector<T>& rhs);
  Vector<T>& operator-=(const Vector<T>& rhs) { return *this += -rhs; }
  Vector<T> operator-() const;
  bool operator==(const Vector<T>& rhs) const;
  bool operator!=(const Vector<T>& rhs) const { return !(*this == rhs); }

  // Friends
  friend std::ostream& operator<<<T>(std::ostream& os, const Vector& rhs);
  friend std::istream& operator>><T>(std::istream& is, Vector& rhs);

  // Accessors and Modifiers
  unsigned int size() const { return m_size; }
  void resize(const unsigned int new_size);
  void set_buffer(const unsigned int buffer, const unsigned int tolerance);

private:
  // Member Variables
  unsigned int m_size; // Number of elements in vector
  unsigned int m_zero_tolerance; // Num extra indicies beyond data will return buffer
  unsigned int m_zero_buffer; // Num extra indicies before data will return buffer
  T m_buffer; // Value to retrun when zero_tol or buffer is accessed
  T* m_data; // Pointer to data
  T* m_end; // Pointer to last element allocated
};

// Non-member operators
template <typename T>
Vector<T> operator+(Vector<T> lhs, const Vector<T>& rhs) { return lhs += rhs; }

template <typename T>
Vector<T> operator-(Vector<T> lhs, const Vector<T>& rhs) { return lhs -= rhs; }

template <typename T>
T operator*(const Vector<T>& lhs, const Vector<T>& rhs);

template <typename T>
Vector<T> operator*(Vector<T> lhs, const T& rhs);

template <typename T>
Vector<T> operator*(const T& lhs, Vector<T>& rhs) { return rhs * lhs; }

#include "Vector.hpp"

#endif // VECTOR_H
