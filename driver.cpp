/*****************************************************************************
 * Author:     Brian Catanzaro
 *             Graham Netherton
 * Username :  bpchyd
 *             grncp5
 * Class:      CS5201
 * Assignment: 7
 * File:       driver.cpp

  Purpose: To solve the differential equation
 *****************************************************************************/

#include <fstream>
#include <iostream>
#include <math.h>
#include "Qr.h"
#include "DenseMatrix.h"
#include "UpTriMatrix.h"

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::string;

int main(int argc, char *argv[])
{
  // Variables
  unsigned int mesh_size; // The size of the target matrix
  Qr<double> solve; // Solver for matricies
  DenseMatrix<double> A; // Matrix to be solved

  /**********************
  * 1. Create Matricies *
  ***********************/
  if (argc > 1)
  {
    mesh_size = argv[1];
  }
  else
  {
    cerr << "ARGUMENT ERROR - Requires one argument for filepath" << endl;
    exit(-1);
  }

  // Prepare matricies
  x[k] = DenseMatrix<double>(mesh_size);

  // Populate matrix
  for (auto i = 0u; i < matrix_size; i++)
  {
    for (auto j = 0u; j < matrix_size; j++)
    {
      // Do magic
    }
  }

 /*************************************
  * 2. Perform functions on Matricies *
  *************************************/
  /* Misc tests
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
  }*/

  return 0;
}
