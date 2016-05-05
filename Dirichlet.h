/*****************************************************************************
 * Author:     Brian Catanzaro (bpchyd)
 *             Graham Netherton (grncp5)
 * Class:      CS5201
 * Assignment: 7 (Final)
 * File:       Dirichlet.h

  Class: Dirichlet
  Stores data and functionality for solving the Dirichlet problem for a PDE.

  Template parameter T is expected to have the following overloaded:
    -T, T += T, T + T, T - T, T * T, T / T
    T = T, T == T, T != T
 *****************************************************************************/

#ifndef DIRICHLET_H_INCLUDED
#define DIRICHLET_H_INCLUDED

template<typename T>
class Dirichlet
{
private:
  /* Boundary functions */
  T (*m_boundaryLeft)(const T& y);
  T (*m_boundaryRight)(const T& y);
  T (*m_boundaryTop)(const T& x);
  T (*m_boundaryBottom)(const T& x);

  /* "Boundary functions set" flags */
  bool m_isLeftBoundarySet = false;
  bool m_isRightBoundarySet = false;
  bool m_isTopBoundarySet = false;
  bool m_isBottomBoundarySet = false;

  /* Uxx + Uyy = g(x, y) */
  T (*m_g)(const T& x, const T& y);

  /* "g(x, y) function set" flag */
  bool m_isGSet = false;

  /* Boundaries for x and y */
  T m_xMin, m_xMax;
  T m_yMin, m_yMax;

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

  /* DESTRUCTOR */
  ~Dirichlet();

  /* Boundary function mutators */
  // DESC: Allows the boundary functions to be modified.
  // PRE: None.
  // POST: The appropriate boundary function is set.
  void setLeftBoundary(T (f)(const T& y));
  void setRightBoundary(T (f)(const T& y));
  void setTopBoundary(T (f)(const T& x));
  void setBottomBoundary(T (f)(const T& x));

  /* Range mutators */
  // DESC: Allows the range to be modified.
  // PRE: xMin <= xMax, yMin <= yMax (throws std::invalid_argument)
  // POST: The range is adjusted.
  void setXMin(const T& xMin);
  void setXMax(const T& xMax);
  void setYMin(const T& yMin);
  void setYMax(const T& yMax);
};

#endif // DIRICHLET_H_INCLUDED
