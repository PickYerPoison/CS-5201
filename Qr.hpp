/*****************************************************************************
 * Author:     Brian Catanzaro
 * Username :  bpchyd
 * Class:      CS5201
 * Assignment: 6
 * File:       Qr.hpp

  Implementation for Qr class in Qr.h.
  Performs QR decomposition on the passed Matricies.
 *****************************************************************************/

template <typename T>
void Qr<T>::operator()(const DenseMatrix<T>& A)
{
  // Allocate memory for Q and R
  m_Q = DenseMatrix<T>(A.width());
  m_R = UpTriMatrix<T>(A.width());

  // Base case
  m_R[0][0] = L2_norm(A[0]);
  if (m_R[0][0] == 0)
  {
    throw std::runtime_error("Divide by 0");
  }
  m_Q[0] = A[0] * (1.0 / m_R[0][0]);

  // K + 1
  for (auto i = 1u; i < A.width(); i++)
  {
    // Find all R[i][K] values
    Vector<T> sum = Vector<T>(A.width());
    sum = 0;

    for (auto j = 0u; j < i; j++)
    {
      m_R[i][j] = A[i] * m_Q[j];
      sum += m_R[i][j] * m_Q[j];
    }

    // Find R[i][i] value
    m_R[i][i] = L2_norm(A[i] - sum);
    if (m_R[i][i] == 0)
    {
      throw std::runtime_error("Divide by 0");
    }

    // Find Q[i]
    m_Q[i] = (A[i] - sum) * (1.0 / m_R[i][i]);
  }

  return;
}

template <typename T>
T Qr<T>::L2_norm(const Vector<T>& Ai) const
{
  T sum = 0;

  // Sum all the squares of each element
  for (unsigned int i = 0; i < Ai.size(); i++)
  {
    sum += (Ai[i] * Ai[i]);
  }

  // Return the sqrt of the summation
  return sqrt(sum);
}
