#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <fstream>
#include <utility>

using namespace std;

typedef vector<double> Row; // One row of the matrix
typedef vector<Row> Matrix; // Matrix: a vector of rows

double epsilon = 1e-3; // tolerance bound

// Building up the meshgrid w Laplace's boundary conditions
void grid (Matrix & U) {
    // Initializing U
    // nxn matrix of zeroes
    int n = U.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0) {
                U.at(i).at(j) = 100.;
            }
            else {
                U.at(i).at(j) = 0.;
            }
        }
    }
}

// Main function
int main() {
    int m;
    cout << "Size of matrix, m (odd): ";
    cin >> m;

    ofstream file1("temp.txt");
    Matrix U (m, Row(m));

    // Initializing the grid w boundary conditions
    grid (U);

    cout << "\nInital grid matrix U is: " << endl;
    for (Row &j : U) {
        for (double &k : j) {
            cout << k << ' '; 
        }
        cout << endl;
    }

    // "diff" converges to the tolerance bound
    double diff = 100.0;
    Matrix U_new (m, Row (m));
    int count = 0;

    while (diff > epsilon) {
        // Initializing U_new w BCs implemented
        grid (U_new);
        for (int i = 1; i < (m-1); i++) {
            for (int j = 1; j < (m-1); j++) {
                // Finite differences step
                U_new[i][j] = (0.25)*(U[i-1][j] + U[i+1][j] + U[i][j-1] + U[i][j+1]);
            }
        }

        // Convergence checking
        diff = 0.;
        for (int i = 1; i < (m-1); i++) {
            for (int j = 1; j < (m-1); j++) {
                diff = max (diff, abs(U[i][j] - U_new[i][j]));
            }
        }
        // Swapping the contents of U and U_new
        swap (U, U_new);

        // Counter within the while loop
        count += 1;
    }

    // Printing out the final grid U
    cout << "\nThe grid matrix U is: " << endl;
    for (Row &j : U) {
        for (double &k : j) {
            cout << k << ' '; 
        }
        cout << endl;
    }

    cout << "\nTotal count is " << count << endl;

    Row x (m);
    double h = 1./m;

    cout << h << endl;

    for (int i = 0; i < m; i++) {
        x[i] = 1.0 - (h*i);
        cout << x[i] << " ";
    }

    cout << "\n";

    int y = (m-1)/2;
    for (int i = 0; i < m; i++) {
        file1 << x[i] << "\t" << U[i][y] << "\n";
    }
    
    file1.close();
    
    return 0;
}
