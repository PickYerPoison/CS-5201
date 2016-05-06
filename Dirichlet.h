/*****************************************************************************
 * Author:     Brian Catanzaro (bpchyd)
 *             Graham Netherton (grncp5)
 * Class:      CS5201
 * Assignment: 7 (Final)
 * File:       Dirichlet.h

  Class: Dirichlet
  Stores data and functionality for solving the Dirichlet problem for a PDE.

  Template parameter T is expected to have the following operators overloaded:
    -T, T += T, T + T, T - T, T * T, T / T
    T = T, T == T, T != T
 *****************************************************************************/

#ifndef DIRICHLET_H_INCLUDED
#define DIRICHLET_H_INCLUDED

#include "DenseMatrix.h"
#include "Vector.h"

template <typename T>
struct Point;

template <typename T>
std::ostream& operator<<(std::ostream& os, const Point<T>& rhs);

template<typename T>
struct Point
{
  T x;
  T y;

  Point() : Point(0, 0) {}
  Point(const T& x) : Point(x, x) {}
  Point(const T& x, const T& y) : x(x), y(y) {}
  friend std::ostream& operator<<<T>(std::ostream& os, const Point& rhs);
};

template<typename T>
class Dirichlet
{
private:
  /* Boundary functions */
  T (*m_leftBoundary)(const T& y);
  T (*m_rightBoundary)(const T& y);
  T (*m_topBoundary)(const T& x);
  T (*m_bottomBoundary)(const T& x);

  /* "Boundary functions set" flags */
  bool m_isLeftBoundarySet = false;
  bool m_isRightBoundarySet = false;
  bool m_isTopBoundarySet = false;
  bool m_isBottomBoundarySet = false;

  /* The right-hand side of Uxx + Uyy = g(x, y) */
  T (*m_RHS)(const T& x, const T& y);

  /* "RHS function set" flag */
  bool m_isRHSSet = false;

  /* Boundaries for x and y */
  T m_xMin, m_xMax;
  T m_yMin, m_yMax;

  /* Matrices and vectors for Ax = b */
  DenseMatrix<T> m_A;
  Vector<Point<T>> m_x;
  Vector<T> m_b;

public:
  /* Constructors */
  // DESC: Default constructor.
  // PRE: None.
  // POST: The object is initialized with default values.
  Dirichlet();

  // DESC: Range constructor.
  // PRE: xMin <= xMax, yMin <= yMax (throws std::invalid_argument)
  // POST: The object is initialized across the given range.
  Dirichlet(const T& xMin, const T& xMax, const T& yMin, const T& yMax);

  /* Destructor */
  // DESC: Releases any memory held.
  // PRE: None.
  // POST: Any memory held has been released.
  ~Dirichlet();

  /* Boundary function mutators */
  // DESC: Allows the boundary functions to be modified.
  // PRE: None.
  // POST: The appropriate boundary function is set.
  void setLeftBoundary(T (f)(const T& y));
  void setRightBoundary(T (f)(const T& y));
  void setTopBoundary(T (f)(const T& x));
  void setBottomBoundary(T (f)(const T& x));

  /* RHS function mutator */
  // DESC: Allows the RHS function to be modified.
  // PRE: None.
  // POST: The RHS function is set.
  void setRHS(T (f)(const T& x, const T& y));

  /* Range mutators */
  // DESC: Allows the range to be modified.
  // PRE: xMin <= xMax, yMin <= yMax (throws std::invalid_argument)
  // POST: The range is adjusted.
  void setXMin(const T& xMin);
  void setXMax(const T& xMax);
  void setYMin(const T& yMin);
  void setYMax(const T& yMax);

  /* Boundary output function */
  // DESC: Returns a point on the boundary.
  // PRE: Point (x, y) is on a boundary (throws std::invalid_argument)
  //      Appropriate boundary function is set (throws std::invalid_argument)
  // POST: Returns the resulting T value.
  T getAtBoundary(const T& x, const T& y) const;

  /* Experimental functions
     The names, arguments, usage, and existence of the following
     functions is subject to change. This category should be removed
     before submission. */

  // DESC: Builds A, x, and b with the given mesh size.
  // PRE: All functions are set (throws std::invalid_argument)
  //      mesh_size > 0 (throws std::invalid_argument)
  // POST: A, x, and b are loaded with their proper values.
  void build(const int mesh_size);
};

#include "Dirichlet.hpp"

#endif // DIRICHLET_H_INCLUDED
