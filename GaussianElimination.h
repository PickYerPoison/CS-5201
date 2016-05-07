/*****************************************************************************
 * Author:     Brian Catanzaro
 *             Graham Netherton
 * Username :  bpchyd
 *             grncp5
 * Class:      CS5201
 * Assignment: 7
 * File:       Gaussian_Elimination.h

  Class: Gaussian_Elimination
  Performs Gaussian elimination on a Matrix.
 *****************************************************************************/

/********************
 * Member Functions *
 *****************************************************************************

  Name: void operator()(Matrix<T>& target, Vector<T>& augment) const
  Description: Solves the passed set of linear equations
  Parameters: Matrix<T>& target - The Matrix to solve
              Vector<T>& augment - The Vector containing the solution of the
                                   linear equations
  Exceptions: Throws divide by 0 error
  Return: None
  Pre: Template type T must have defined =, /, -=, *, and == operators
  Post: target is modified to be an equivalent Matrix in echelon formatting
        augment is modified to be the solutions to the linear equations

 *****************************************************************************

  Name: set_method(const bool flag)
  Description: Toggles the method of gaussian elimination used
  Parameters: const bool flag - A boolean deciding whether to use naive solving
  Exceptions: None
  Return: None
  Pre: None
  Post: Gaussian elimination will be performed in naively if true

 *****************************************************************************

  Name: get_method() const
  Description: Returns whether or not naive gaussian elimination is being used
  Parameters: None
  Exceptions: None
  Return: True if naive elimination is being used, otherwise false
  Pre: None
  Post: The value of m_naive is returned

 *****************************************************************************/

#ifndef GAUSSIAN_ELIMINATION_H
#define GAUSSIAN_ELIMINATION_H

#include <math.h>
#include "Vector.h"
#include "DenseMatrix.h"

template <typename T>
class GaussianElimination
{
public:
  void operator()(DenseMatrix<T>& target, Vector<T>& augment) const;
  void set_method(const bool flag) { m_naive = flag; }
  bool get_method() const { return m_naive; }
private:
  bool m_naive = true; // Toggle naive vs. pivoting elimination
};

#include "GaussianElimination.hpp"

#endif // GAUSSIAN_ELIMINATION_H
