/*****************************************************************************
 * Author:     Brian Catanzaro
 * Username :  bpchyd
 * Class:      CS5201
 * Assignment: 6
 * File:       driver.cpp

  Purpose: To find the eigenvalues of the passed matricies
 *****************************************************************************/

#include <fstream>
#include <iostream>
#include <math.h>
#include "Qr.h"
#include "DenseMatrix.h"
#include "DiagMatrix.h"
#include "UpTriMatrix.h"

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::string;

int main(int argc, char *argv[])
{
  // Variables
  const unsigned int SAFETY = 1000; // Maximum iterations
  const unsigned int NUM_MATRICIES = 2; // Number of matricies to test
  unsigned int matrix_size; // The size of the target matrix
  string file_path; // Provided file path
  Qr<double> solve; // Solver for matricies
  DenseMatrix<double> x[NUM_MATRICIES]; // Matrix to be solved

  /******************************
  * 1. Create Vectors from file *
  *******************************/
  if (argc > 1)
  {
    file_path = argv[1];
  }
  else
  {
    cerr << "ARGUMENT ERROR - Requires one argument for filepath" << endl;
    exit(-1);
  }

  std::ifstream file_data(file_path);
  if (!file_data.is_open())
  {
    cerr << "FILE ERROR - Bad file path" << endl;
    exit(-1);
  }
  else // use the file
  {
    for (auto k = 0u; k < NUM_MATRICIES; k++)
    {
      // Check for size of matrix
      if (!(file_data >> matrix_size && matrix_size > 2))
      {
        cerr << "FILE ERROR - Cannot parse file or too few elements "
             << "in entry" << endl;
        exit(-1);
      }

      // Prepare matrix
      x[k] = DenseMatrix<double>(matrix_size);

      // Populate matrix
      for (auto i = 0u; i < matrix_size; i++)
      {
        for (auto j = 0u; j < matrix_size; j++)
        {
          if (!(file_data >> x[k][j][i]))
          {
            cerr << "FILE ERROR - Cannot parse file or too few elements "
                 << "in entry" << endl;
            exit(-1);
          }
        }
      }
    }

    // Close file
    file_data.close();
  }

 /*************************************
  * 2. Perform functions on Matricies *
  *************************************/
  // Misc tests
  UpTriMatrix<int> ut1 = UpTriMatrix<int>(4);
  UpTriMatrix<int> ut2 = UpTriMatrix<int>(4);
  DiagMatrix<int> d1 = DiagMatrix<int>(4);
  DiagMatrix<int> d2 = DiagMatrix<int>(4);

  for (auto i = 0u; i < 4u; i++)
  {
    d1[i][i] = i + 1;
    d2[i][i] = 2 * (i + 1);
    for (auto j = 0u; j <= i; j++)
    {
      ut1[i][j] = i + 1;
      ut2[i][j] = 2 * (i + 1);
    }
  }


  cout << "UpperTriangular X UpperTriangular:" << endl;
  cout << ut1 << "X" << endl << ut2 << "=" << endl << (ut1 * ut2) << endl;
  cout << "Diaginal X Diagonal:" << endl;
  cout << d1 << "X" << endl << d2 << "=" << endl << (d1 * d2) << endl;

  // QR iteration
  for (auto k = 0u; k < NUM_MATRICIES; k++)
  {
    for (auto iter_count = 1u; iter_count < SAFETY; iter_count++)
    {
      solve(x[k]);
      const BaseMatrix<double>* r = &solve.R();
      const BaseMatrix<double>* q = &solve.Q();
      x[k] = *r * *q;
      if (iter_count == 5 || iter_count == 10)
      {
        cout << "=== Iteration " << iter_count << " - Matrix " << (k + 1) << " ==="
             << endl << x[k];
      }

      // Check for early convergence
      bool converge = false;
      for (auto i = 0u; i < x[k].width(); i++)
      {
        for (auto j = 0u; j < x[k].width(); j++)
        {
          if (i < j)
          {
            converge = (x[k][i][j] == 0);
            if (!converge)
            {
              i = j = x[k].width();
            }
          }
        }
      }
      if (converge)
      {
        iter_count = SAFETY;
      }
    }

    cout << "=== Final Iteration - Matrix " << (k + 1) << " ===" << endl << x[k];
    cout << "=== Reason - Matrix " << (k + 1) << " ===" << endl
         << "Eigenvalues converged" << endl;
    cout << "=== Eigenvalues - Matrix " << (k + 1) << " ===" << endl;
    for (auto i = 0u; i < x[k].width(); i++)
    {
      cout << x[k][i][i] << " ";
    }
    cout << endl;
  }

  return 0;
}
