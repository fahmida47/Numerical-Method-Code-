// Without Partial Pivoting=> no Row swap 	direct elimination  division by zero

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter the order of the matrix: ";
    cin >> n;

    // Create augmented matrix of size n x (n+1)
    vector<vector<double>> a(n, vector<double>(n + 1));
    vector<double> x(n);

    // Input coefficients
    cout << "Enter the augmented matrix coefficients row-wise:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    // Forward Elimination
    for (int k = 0; k < n - 1; k++) {
        for (int i = k + 1; i < n; i++) {
            double factor = a[i][k] / a[k][k];
            for (int j = k; j <= n; j++) {
                a[i][j] -= factor * a[k][j];
            }
        }
    }

    // Back Substitution
    x[n - 1] = a[n - 1][n] / a[n - 1][n - 1];
    for (int k = n - 2; k >= 0; k--) {
        double sum = 0;
        for (int j = k + 1; j < n; j++) {
            sum += a[k][j] * x[j];
        }
        x[k] = (a[k][n] - sum) / a[k][k];
    }

    // Print solution vector
    cout << "Solution vector:\n";
    for (int i = 0; i < n; i++) {
        cout << "x" << i + 1 << " = " << x[i] << endl;
    }

    return 0;
}
