/*****************************************************************************
 * Author:     Brian Catanzaro
 *             Graham Netherton
 * Username :  bpchyd
 *             grncp5
 * Class:      CS5201
 * Assignment: 7
 * File:       GaussianElimination.hpp

  Implementation for gaussian_elimination class in gaussian_elimination.h.
  Performs gaussian elimination on the passed Matrix.
 *****************************************************************************/

template <typename T>
void GaussianElimination<T>::operator()(DenseMatrix<T>& target,
                                        Vector<T>& augment) const
{
  // Forward elimination
  double ratio; // Ratio by which to divide
  // n - 1 steps
  for (auto i = 0u; i < target.width() - 1; i++)
  {
    // Take next row below current row
    for (auto j = i + 1; j < target.height(); j++)
    {
      // When using pivoting
      if (!m_naive)
      {
        T max = target[i][j];
        auto index = j;
        // Find largest row and swap them
        for (auto k = j; k < target.height(); k++)
        {
          if (target[i][k] > max)
          {
            max = target[i][k];
            index = k;
          }
        }
        target.swap_row(j, index);
        std::swap(augment[index], augment[j]);
      }
      // Find the right ratio
      if (target[i][i] == 0)
      {
        throw "Divide by 0 error";
      }
      ratio = static_cast<double>(target[i][j]) / target[i][i];

      // Subtract ratio * row from target row
      for (auto k = 0u; k < target.width(); k++)
      {
        target[k][j] -= target[k][i] * ratio;
      }
      augment[j] -= augment[i] * ratio;
    }
  }

  // Backward substitution
  // Loop backward over solution
  for (auto i = augment.size() - 1; i >= 0; i--)
  {
    // Loop over elements backward in row i and solve for x
    for (auto j = target.width() - 1; j != i - 1; j--)
    {
      if (i == j)
      {
        if (target[j][i] == 0)
        {
          throw "Divide by 0 error";
        }
        augment[i] = augment[i] / target[j][i];
      }
      else
      {
        augment[i] -= augment[j] * target[j][i];
      }
    }
    if (i == 0)
    {
      break;
    }
  }

  return;
}
