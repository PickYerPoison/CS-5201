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
#include "Dirichlet.h"

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::string;

int main()
{
  // Variables
//  unsigned int mesh_size; // The size of the target matrix
//  unsigned int matrix_size; // (mesh_size - 1)^2
////  Qr<double> solve; // Solver for matrices
//  DenseMatrix<double> A; // Matrix to be solved

  /**********************
  * 1. Create Matrices *
  ***********************/

  cout << "Start?" << endl;

  string ssss;
  cin >> ssss;

  Dirichlet<double> d(0.0, 1.0, 0.0, 1.0);
  d.setBottomBoundary([](const double& x)->double { return 1 - x * x; } );
  d.setTopBoundary([](const double& x)->double { return 2 * (1 - x * x); } );
  d.setLeftBoundary([](const double& y)->double { return 1 + y * y; } );
  d.setRightBoundary([](const double& y)->double { return 0; } );
  d.setRHS([](const double& x, const double& y)->double { return -2 * (x * x + y * y); } );
  d.build(4);

  return 0;
}
