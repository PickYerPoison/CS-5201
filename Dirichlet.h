/*****************************************************************************
 * Author:     Brian Catanzaro (bpchyd)
 *             Graham Netherton (grncp5)
 * Class:      CS5201
 * Assignment: 7 (Final)
 * File:       Dirichlet.h

  Class: Dirichlet
  Stores data and functionality for solving the Dirichlet problem for a PDE.
 *****************************************************************************/

#ifndef DIRICHLET_H_INCLUDED
#define DIRICHLET_H_INCLUDED

template<typename T>
class Dirichlet
{
private:
  /** Boundary functions **/
  T (*m_boundaryLeft)(const T& x, const T& y);
  T (*m_boundaryRight)(const T& x, const T& y);
  T (*m_boundaryTop)(const T& x, const T& y);
  T (*m_boundaryBottom)(const T& x, const T& y);

  /** Uxx + Uyy = g(x, y) **/
  T (*m_g)(const T& x, const T& y);

  /** Boundaries for x and y **/
  T m_xMin, m_xMax;
  T m_yMin, m_yMax;

public:
  /** CONSTRUCTOR **/
  Dirichlet();

  /** DESTRUCTOR **/
};

#endif // DIRICHLET_H_INCLUDED
