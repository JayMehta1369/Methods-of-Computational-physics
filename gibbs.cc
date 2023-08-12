#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <fstream>
#include <utility>

using namespace std;

typedef vector<double> Row; // One row of the matrix
typedef vector<Row> Matrix; // Matrix: a vector of rows

// Main function
int main() {
    int m, N;

    cout << "Size of matrix, m (odd): ";
    cin >> m;

    cout << "Enter N (sufficiently large): " << endl;
    cin >> N;

    // Row y (m), U_th (m);

    // double h = 1./m;
    // int xj = (m-1)/2;

    // for (int i = 0; i < m; i++) {
    //     y[i] = (h*i);
    //     U_th [i] = 0;
    //     int n = 1;
    //     while (n < N) {
    //         double c1, c2, c3;
    //         c1 = 400./(n * M_PI);
    //         c2 = sin (n * M_PI * (0.5));
    //         c3 = (sinh (n * M_PI * y[i]))/(sinh (n * M_PI));
    //         U_th [i] += c1 * c2 * c3;
    //         n += 2;
    //     }
    // }

    Row x (m), U_th (m);

    double h = 1./m;

    for (int i = 0; i < m; i++) {
        x[i] = (h*i);
        U_th [i] = 0;
        int n = 1;
        while (n < N) {
            double c1, c2, c3;
            c1 = 400./(n * M_PI);
            c2 = sin (n * M_PI * (x[i]));
            U_th [i] += c1 * c2;
            n += 2;
        }
    }
    
    // Printing out the final grid U
    cout << "\nThe U_th is: " << endl;
    for (double &k : U_th) {
        cout << k << ' '; 
    }
    cout << endl;

    ofstream file1("U_th_2.txt");

    for (int i = 0; i < m; i++) {
        file1 << x[i] << "\t" << U_th[i] << "\n";
    }
    file1.close();

    return 0;
}
