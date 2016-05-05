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
#include <string>
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
  unsigned int matrix_size; // (mesh_size - 1)^2
  Qr<double> solve; // Solver for matricies
  DenseMatrix<double> A; // Matrix to be solved

  /**********************
  * 1. Create Matricies *
  ***********************/
  if (argc > 1)
  {
    mesh_size = std::stoi(argv[1]);
    matrix_size = (mesh_size - 1) * (mesh_size - 1);
  }
  else
  {
    cerr << "ARGUMENT ERROR - Requires one argument for filepath" << endl;
    exit(-1);
  }

  // Prepare matricies
  A = DenseMatrix<double>(matrix_size);

  // Populate matrix
  for (auto i = 0u; i < matrix_size; i++)
  {
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

  }

  cout << A;

  return 0;
}
