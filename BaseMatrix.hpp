/*****************************************************************************
 * Author:     Brian Catanzaro
 *             Graham Netherton
 * Username :  bpchyd
 *             grncp5
 * Class:      CS5201
 * Assignment: 7
 * File:       BaseMatrix.hpp

  Implementation for a basic BaseMatrix class found in BaseMatrix.h.
  A standard representation of a matrix with compatible linear algebra
  operations.
  ****************************************************************************/

template <typename T>
std::ostream& operator<<(std::ostream& os, const BaseMatrix<T>& rhs)
{
  // Set formatting
  Vector<unsigned int> format_widths = Vector<unsigned int>(rhs.width());
  for (auto i = 0u; i < rhs.width(); i++)
  {
    format_widths[i] = 0;
    for (auto j = 0u; j < rhs.height(); j++)
    {
      if (std::to_string(rhs[i][j]).length() > format_widths[i])
      {
        format_widths[i] = std::to_string(rhs[i][j]).length();
      }
    }
  }

  // Read out matrix with added formatting
  for (auto i = 0u; i < rhs.height(); i++)
  {
    for (auto j = 0u; j < rhs.width() - 1; j++)
    {
      os << std::setw(format_widths[j]) << std::to_string(rhs[j][i]) << " ";
    }
    os << std::setw(format_widths[format_widths.size() - 1])
       << std::to_string(rhs[rhs.width() - 1][i]) << std::endl;
  }

  return os;
}

template <typename T>
std::istream& operator>>(std::istream& is, BaseMatrix<T>& rhs)
{
  // Add to each vector
  for (auto i = 0u; i < rhs.width(); i++)
  {
    is >> rhs[i];
  }
  return is;
}
