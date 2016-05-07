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
#include "GaussianElimination.h"

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::string;

int main()
{
  cout << "Start?" << endl;

  string ssss;
  cin >> ssss;

  Qr<double> solve;
  GaussianElimination<double> back_sub;
  DenseMatrix<double> matrix(4);
  Vector<double> augmented(9);
  Dirichlet<double> d(0.0, 1.0, 0.0, 1.0);
  d.setBottomBoundary([](const double& x)->double { return 1 - x * x; } );
  d.setTopBoundary([](const double& x)->double { return 2 * (1 - x * x); } );
  d.setLeftBoundary([](const double& y)->double { return 1 + y * y; } );
  d.setRightBoundary([](const double& y)->double { return 0; } );
  d.setRHS([](const double& x, const double& y)->double { return -2 * (x * x + y * y); } );
  d.build(4);

  solve(d.A());
  augmented = d.b();
  matrix = solve.R();
  back_sub(matrix, augmented);
  cout << "QR Method:" << endl << augmented << endl;

  augmented = d.b();
  matrix = d.A();
  back_sub(matrix, augmented);
  cout << "Simple Gaussian:" << endl << augmented << endl;

  cout << "True Values:" << endl << augmented << endl;

  return 0;
}
