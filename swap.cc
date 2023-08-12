#include <iostream>
#include <vector>
#include <utility>
using namespace std;
typedef vector<double> Row; // One row of the matrix
typedef vector<Row> Matrix; // Matrix: a vector of rows
int main() 
{
  int m;
  cout << "Size of matrix, m: ";
  cin >> m;

  Matrix Amat(m,Row(m)),vA(m,Row(m));
  Matrix Bmat(m,Row(m)),vB(m,Row(m));

  Amat[10][10]=10.0;
  Bmat[10][10]=5.0;
  std::swap(Amat,Bmat);
  cout << Amat[10][10] << endl;
  cout << Bmat[10][10] << endl;
  return 0;
}
