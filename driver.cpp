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
  Qr<double> solve; // Solver for matricies
  DenseMatrix<double> A; // Matrix to be solved

  /**********************
  * 1. Create Matricies *
  ***********************/
  if (argc > 1)
  {
    mesh_size = std::stoi(argv[1]);
  }
  else
  {
    cerr << "ARGUMENT ERROR - Requires one argument for filepath" << endl;
    exit(-1);
  }

  // Prepare matricies
  A = DenseMatrix<double>(mesh_size);

  // Populate matrix
  for (auto i = 0u; i < mesh_size; i++)
  {
    for (auto j = 0u; j < mesh_size; j++)
    {
      // Border conditions
      if (j == 0 || j == mesh_size || i == 0 || i == mesh_size)
      {
        // Do magic
      }
      else // Center conditions
      {
        // Do more magic
      }
    }
  }

  return 0;
}
