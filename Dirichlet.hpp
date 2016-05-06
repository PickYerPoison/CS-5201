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

/* Boundary output function */
template<typename T>
T Dirichlet<T>::getAtBoundary(const T& x, const T& y) const
{
  // determine which boundary function to use
  bool left = false, right = false;
  bool top = false, bottom = false;

  if (y == m_yMin)
    bottom = true;
  else if (y == m_yMax)
    top = true;

  if (x == m_xMin)
    left = true;
  else if (x == m_xMax)
    right = true;

  // throw an error if the point was not on a boundary
  if (!left && !right && !top && !bottom)
    throw invalid_argument("Dirichlet ERROR: Tried to apply a boundary function to a point not on a boundary.");

  // determine which boundary function to use
  if (left && m_isLeftBoundarySet)
    return m_leftBoundary(y);
  else if (right && m_isRightBoundarySet)
    return m_rightBoundary(y);
  else if (top && m_isTopBoundarySet)
    return m_topBoundary(x);
  else if (bottom && m_isBottomBoundarySet)
    return m_bottomBoundary(x);
  else
    throw invalid_argument("Dirichlet ERROR: Tried to apply a non-existent boundary function to a point.");
}

/* Experimental functions */
template<typename T>
void Dirichlet<T>::build(const int mesh_size)
{
//  if (!m_isLeftBoundarySet)
//    throw invalid_argument("Dirichlet ERROR: Left boundary not set.");
//  if (!m_isRightBoundarySet)
//    throw invalid_argument("Dirichlet ERROR: Right boundary not set.");
//  if (!m_isTopBoundarySet)
//    throw invalid_argument("Dirichlet ERROR: Top boundary not set.");
//  if (!m_isBottomBoundarySet)
//    throw invalid_argument("Dirichlet ERROR: Bottom boundary not set.");
//  if (!m_isRHSSet)
//    throw invalid_argument("Dirichlet ERROR: RHS not set.");
  if (mesh_size <= 0)
    throw invalid_argument("Dirichlet ERROR: Mesh size less than 1.");

  std::cout << "Mesh size: " << mesh_size << std::endl;

  if (mesh_size == 1)
  {
    // some kind of special case when matrices are size zero?
  }

  // initialize variables and matrices
  unsigned int matrix_size = (mesh_size - 1) * (mesh_size - 1);
  T h = 1.0 / mesh_size;
  DenseMatrix<T> A(matrix_size);
  Vector<Point<T>> x(matrix_size);
  Vector<T> b(matrix_size);
  unsigned int yNum = 0;
  std::cout <<  "Matrix size: " <<  matrix_size << std::endl;
  std::cout << "h: " << h << std::endl;

  // build matrix A
  for (auto i = 0u; i < matrix_size; i++)
  {
    /* Build A */
    A[i][i] = 1;

    // Right adjacent
    if (i % (mesh_size - 1) != 0)
    {
      A[i][i - 1] = -(1.0 / mesh_size);
    }
    // Left adjacent
    if ((i + 1) % (mesh_size - 1) != 0)
    {
      A[i][i + 1] = -(1.0 / mesh_size);
    }
    // Bottom adjacent
    if (i < matrix_size - (mesh_size - 1))
    {
      A[i][i + (mesh_size - 1)] = -(1.0 / mesh_size);
    }
    if (i >= mesh_size - 1)
    {
      A[i][i - (mesh_size - 1)] = -(1.0 / mesh_size);
    }

    /* Build x */
    if (i % mesh_size == 0)
      yNum++;
    T xVal = (i % (mesh_size - 1) + 1) * h;
    T yVal = yNum * h;
    x[i] = Point<T>(xVal, yVal);

    /* Build b */
    // gather vector of points for this section
//    Vector<Point<T>> points(4u);
//    points[0] = Point<T>(xVal + h, yVal);
//    points[1] =
  }

  std::cout << A << std::endl;
  std::cout << std::endl;
  std::cout << x << std::endl;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const Point<T>& rhs)
{
  os << "(" << rhs.x << "," << rhs.y << ")";

  // Return os with added Point output
  return os;
}

#endif // DIRICHLET_HPP_INCLUDED
