/*****************************************************************************
 * Author:     Brian Catanzaro
 *             Graham Netherton
 * Username :  bpchyd
 *             grncp5
 * Class:      CS5201
 * Assignment: 7
 * File:       driver.cpp

  Purpose: To decompose the differential equation
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

int main(int argc, char *argv[])
{
  unsigned int mesh_size;

  if (argc > 1)
  {
    mesh_size = std::stoi(argv[1]);
  }
  else
  {
    string getMeshSize;
    cout << "Enter mesh size: ";
    cin >> getMeshSize;
    mesh_size = std::stoi(getMeshSize);
//    cerr << "ARGUMENT ERROR - Requires one argument for mesh size" << endl;
//    exit(-1);
  }

  Qr<double> decompose;
  GaussianElimination<double> back_sub;
  DenseMatrix<double> matrix(mesh_size);
  Vector<double> simple_values((mesh_size - 1) * (mesh_size - 1));
  Vector<double> qr_values((mesh_size - 1) * (mesh_size - 1));
  Vector<double> true_values((mesh_size - 1) * (mesh_size - 1));

  // create Dirichlet object
  Dirichlet<double> d(0.0, 1.0, 0.0, 1.0);
  double h = 1.0 / mesh_size;
  d.setBottomBoundary([](const double& x)->double { return 1 - x * x; } );
  d.setTopBoundary([](const double& x)->double { return 2 * (1 - x * x); } );
  d.setLeftBoundary([](const double& y)->double { return 1 + y * y; } );
  d.setRightBoundary([](const double& y)->double { return 0 * y; } );
  d.setRHS([](const double& x, const double& y)->double { return -2 * (x * x + y * y); } );
  d.build(mesh_size);

  decompose(d.A());
  matrix = decompose.R();
  qr_values = (~decompose.Q()) * d.b();
  back_sub(matrix, qr_values);
  cout << "QR Method:" << endl << qr_values << endl << endl;

  simple_values = d.b();
  matrix = d.A();
  back_sub(matrix, simple_values);
  cout << "Simple Gaussian:" << endl << simple_values << endl << endl;

  for (auto i = 0u; i < true_values.size(); i++)
  {
    double x = (i % (mesh_size - 1) + 1) * h;
    double y = (static_cast<int>(i / (mesh_size - 1)) + 1) * h;
    true_values[i] = (1 - x * x) * (1 + y * y);
  }
  cout << "True Values:" << endl << true_values << endl << endl;

  cout << "QR Deltas:" << endl;
  for (auto i = 0u; i < true_values.size(); i++)
  {
    cout << (qr_values[i] - true_values[i]) << " ";
  }
  cout << endl << endl;

  cout << "Gaussian Deltas:" << endl;
  for (auto i = 0u; i < true_values.size(); i++)
  {
    cout << (simple_values[i] - true_values[i]) << " ";
  }
  cout << endl << endl;

  cout << "% Error QR:" << endl;
  for (auto i = 0u; i < true_values.size(); i++)
  {
    cout << "%" << ((true_values[i] - qr_values[i]) / true_values[i]) * 100 << " ";
  }
  cout << endl << endl;

  cout << "% Error Gaussian:" << endl;
  for (auto i = 0u; i < true_values.size(); i++)
  {
    cout << "%" << ((true_values[i] - simple_values[i]) / true_values[i]) * 100 << " ";
  }
  cout << endl << endl;

  return 0;
}
