#ifndef DIRICHLET_HPP_INCLUDED
#define DIRICHLET_HPP_INCLUDED

using std::invalid_argument;

template<typename T>
Dirichlet<T>::Dirichlet()
{
  m_xMin = 0; m_xMax = 1;
  m_yMin = 0; m_yMax = 1;
}

// DESC: Range constructor.
// PRE: xMin <= xMax, yMin <= yMax (throws std::invalid_argument)
// POST: The object is initialized across the given range.
template<typename T>
Dirichlet<T>::Dirichlet(const T& xMin, const T& xMax, const T& yMin, const T& yMax)
{
  if (xMin > xMax)
    throw invalid_argument("Dirichlet constructor ERROR: xMin greater than xMax.");
  if (yMin > yMax)
    throw invalid_argument("Dirichlet constructor ERROR: yMin greater than yMax.");

  m_xMin = xMin; m_xMax = xMax;
  m_yMin = yMin; m_yMax = yMax;
}

/* Destructor */
// DESC: Releases any memory held.
// PRE: None.
// POST: Any memory held has been released.
template<typename T>
Dirichlet<T>::~Dirichlet()
{
  // nothing required
}

/* Boundary function mutators */
// DESC: Allows the boundary functions to be modified.
// PRE: None.
// POST: The appropriate boundary function is set.
template<typename T>
void Dirichlet<T>::setLeftBoundary(T (f)(const T& y))
{
  m_leftBoundary = f;
  m_isLeftBoundarySet = true;
}
template<typename T>
void Dirichlet<T>::setRightBoundary(T (f)(const T& y))
{
  m_rightBoundary = f;
  m_isRightBoundarySet = true;
}
template<typename T>
void Dirichlet<T>::setTopBoundary(T (f)(const T& x))
{
  m_topBoundary = f;
  m_isTopBoundarySet = true;
}
template<typename T>
void Dirichlet<T>::setBottomBoundary(T (f)(const T& x))
{
  m_bottomBoundary = f;
  m_isBottomBoundarySet = true;
}

/* RHS function mutator */
// DESC: Allows the RHS function to be modified.
// PRE: None.
// POST: The RHS function is set.
template<typename T>
void Dirichlet<T>::setRHS(T (f)(const T& x, const T& y))
{
  m_RHS = f;
  m_isRHSSet = true;
}

/* Range mutators */
// DESC: Allows the range to be modified.
// PRE: xMin <= xMax, yMin <= yMax (throws std::invalid_argument)
// POST: The range is adjusted.
template<typename T>
void Dirichlet<T>::setXMin(const T& xMin)
{
  if (xMin > m_xMax)
    throw invalid_argument("Dirichlet ERROR: Tried to set xMin above xMax.");
  m_xMin = xMin;
}
template<typename T>
void Dirichlet<T>::setXMax(const T& xMax)
{
  if (m_xMin > xMax)
    throw invalid_argument("Dirichlet ERROR: Tried to set xMax below xMin.");
  m_xMax = xMax;
}
template<typename T>
void Dirichlet<T>::setYMin(const T& yMin)
{
  if (yMin > m_yMax)
    throw invalid_argument("Dirichlet ERROR: Tried to set yMin above yMax.");
  m_yMin = yMin;
}
template<typename T>
void Dirichlet<T>::setYMax(const T& yMax)
{
  if (m_yMin > yMax)
    throw invalid_argument("Dirichlet ERROR: Tried to set yMax below yMin.");
  m_yMax = yMax;
}

#endif // DIRICHLET_HPP_INCLUDED
