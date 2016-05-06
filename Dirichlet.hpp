#ifndef DIRICHLET_HPP_INCLUDED
#define DIRICHLET_HPP_INCLUDED

using std::invalid_argument;

/* Constructors */
template<typename T>
Dirichlet<T>::Dirichlet() : Dirichlet(0, 1, 0, 1) { }

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
template<typename T>
Dirichlet<T>::~Dirichlet()
{
  // nothing required
}

/* Boundary function mutators */
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
template<typename T>
void Dirichlet<T>::setRHS(T (f)(const T& x, const T& y))
{
  m_RHS = f;
  m_isRHSSet = true;
}

/* Range mutators */
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

/* Experimental functions */
template<typename T>
void Dirichlet<T>::build(const int mesh_size)
{
  if (!m_isLeftBoundarySet)
    throw invalid_argument("Dirichlet ERROR: Left boundary not set.");
  if (!m_isRightBoundarySet)
    throw invalid_argument("Dirichlet ERROR: Right boundary not set.");
  if (!m_isTopBoundarySet)
    throw invalid_argument("Dirichlet ERROR: Top boundary not set.");
  if (!m_isBottomBoundarySet)
    throw invalid_argument("Dirichlet ERROR: Bottom boundary not set.");
  if (!m_isRHSSet)
    throw invalid_argument("Dirichlet ERROR: RHS not set.");
  if (mesh_size <= 0)
    throw invalid_argument("Dirichlet ERROR: Mesh size less than 1.");

  if (mesh_size == 1)
  {
    // some kind of special case when matrices are size zero?
  }

  // build matrices
  m_A = DenseMatrix<T>(mesh_size - 1);
  m_x = Vector<T>(mesh_size - 1);
  m_b = DenseMatrix<T>(mesh_size - 1);

  // build A, x, b
}

#endif // DIRICHLET_HPP_INCLUDED
