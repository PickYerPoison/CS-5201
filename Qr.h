/*****************************************************************************
 * Author:     Brian Catanzaro
 * Username:   bpchyd
 * Class:      CS5201
 * Assignment: 6
 * File:       Qr.h

  Class: Qr
  A function class for QR decomposition.
 *****************************************************************************/

/********************
 * Member Functions *
 *****************************************************************************

  Name: void operator()(const DenseMatrix<T>& A)
  Description: Performs QR decomposition on the passed matrix
  Parameters: const DenseMatrix<T>& A - The passed matrix to QR decompose
  Exceptions: May throw std::runtime_error
  Return: None
  Pre: A must be a set of linearly independent vectors
       Template type T must have overloaded /, +=, == and * operators
       Template type T must be compatible with sqrt() from math.h
  Post: m_Q is populated with a set of orthonormal vectors
        m_R is populated with the associated set of R vectors to form A from Q

 *****************************************************************************

  Name: T L2_norm(const Vector<T>& Ai) const
  Description: Performs 2-norm on passed Vector
  Parameters: const Vector<T>& Ai - A Vector to perform 2-norm on
  Exceptions: None
  Return: Template type T object representing the result of the nrom
  Pre:
      Template type T must have overloaded +=, = and * operators
      Template type T must be compatible with sqrt() from math.h
  Post: The 2-norm is returned of the passed vector

 *****************************************************************************

  Name: const DenseMatrix<T>& Q()
  Description: Accessor for m_Q
  Parameters: None
  Exceptions: None
  Return: A reference to the DenseMatrix - m_Q
  Pre: m_Q should be instantiated
  Post: Returns m_Q

 *****************************************************************************

  Name: UpTriMatrix<T>& R()
  Description: Accessor for m_R
  Parameters: None
  Exceptions: None
  Return: A reference to the UpTriMatrix - m_R
  Pre: m_R should be instantiated
  Post: Returns m_R

*****************************************************************************/

#ifndef QR_H
#define QR_H

#include <math.h>
#include <exception>
#include "DenseMatrix.h"
#include "UpTriMatrix.h"
#include "Vector.h"

template <typename T>
class Qr
{
public:
  void operator()(const DenseMatrix<T>& A);
  const DenseMatrix<T>& Q() const { return m_Q; }
  const UpTriMatrix<T>& R() const { return m_R; }

private:
  T L2_norm(const Vector<T>& Ai) const;
  DenseMatrix<T> m_Q;
  UpTriMatrix<T> m_R;
};

#include "Qr.hpp"

#endif // QR_H
