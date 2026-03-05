Topics
1. Basic Code
2. All processing showed(upper and identity matrix)
3. Identity matrix

//-----------------------------------------START--------------------------------------//

Topic-01
Basic Code
#include <iostream>
#include <iomanip>  // for setprecision
using namespace std;

int main() {
    int n;
    cout << "Enter the order of the matrix (n x n): ";
    cin >> n;

    double a[n][n+1];  // Augmented matrix
    double x[n];       // Solution vector

    // Input augmented matrix
    cout << "Enter the augmented matrix (coefficients and constants):\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    // Gauss-Jordan Elimination
    for(int i = 0; i < n; i++) {
        if(a[i][i] == 0) {
            cout << "Mathematical Error! Pivot is zero." << endl;
            return 0;
        }

        // Normalize pivot row
        double normalized = a[i][i];
        for(int k = 0; k <= n; k++) {
            a[i][k] = a[i][k] / normalized;
        }

        // Make other rows zero in current column
        for(int j = 0; j < n; j++) {
            if(i != j) {
                double pivot = a[j][i];
                for(int k = 0; k <= n; k++) {
                    a[j][k] = a[j][k] - pivot * a[i][k];
                }
            }
        }
    }

    // Obtain solution
    for(int i = 0; i < n; i++) {
        x[i] = a[i][n]; // Last column is the constants after elimination
    }

    // Display solution
    cout << fixed << setprecision(6); // display up to 6 decimal places
    cout << "Solution:" << endl;
    for(int i = 0; i < n; i++) {
        cout << "x" << i+1 << " = " << x[i] << endl;
    }

    return 0;
}

Topic-02
Using Upper Triangular+Identity matrix=>all processing showed
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    int n;
    cout << "Enter the order of the matrix (n x n): ";
    cin >> n;

    double a[n][n+1];
    double x[n];

    // Input augmented matrix
    cout << "Enter the augmented matrix (coefficients and constants):\n";
    for(int i = 0; i < n; i++)
        for(int j = 0; j <= n; j++)
            cin >> a[i][j];

    cout << "\nInitial Augmented Matrix:\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= n; j++)
            cout << setw(10) << fixed << setprecision(6) << a[i][j] << " ";
        cout << endl;
    }

    // Gauss-Jordan Elimination with Partial Pivoting
    for(int i = 0; i < n; i++) {
        // Partial Pivoting
        int maxRow = i;
        for(int k = i+1; k < n; k++) {
            if(fabs(a[k][i]) > fabs(a[maxRow][i]))
                maxRow = k;
        }
        if(maxRow != i) {
            for(int j = 0; j <= n; j++)
                swap(a[i][j], a[maxRow][j]);
        }

        if(a[i][i] == 0) {
            cout << "Mathematical Error! Pivot is zero." << endl;
            return 0;
        }

        // Normalize pivot row
        double pivotVal = a[i][i];
        for(int k = 0; k <= n; k++)
            a[i][k] /= pivotVal;

        // Eliminate other rows
        for(int j = 0; j < n; j++) {
            if(j != i) {
                double factor = a[j][i];
                for(int k = 0; k <= n; k++)
                    a[j][k] -= factor * a[i][k];
            }
        }

        // Print matrix after each pivot step
        cout << "\nMatrix after processing pivot row " << i+1 << ":\n";
        for(int r = 0; r < n; r++) {
            for(int c = 0; c <= n; c++)
                cout << setw(10) << fixed << setprecision(6) << a[r][c] << " ";
            cout << endl;
        }
    }

    // Extract solution
    for(int i = 0; i < n; i++)
        x[i] = a[i][n];

    // Display Final Identity Matrix
    cout << "\nFinal Identity Matrix (Gauss-Jordan):\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            cout << setw(10) << fixed << setprecision(6) << a[i][j] << " ";
        cout << " | " << setw(10) << x[i] << endl;
    }

    // Display Solution Vector
    cout << "\nSolution Vector:\n";
    for(int i = 0; i < n; i++)
        cout << x[i] << " ";
    cout << endl;

    return 0;
}

Topic-03
Identity Matrix(Lab Online Ques)
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    int n;
    cout << "Enter the order of the matrix: ";
    cin >> n;

    double a[n][n+1]; // augmented matrix

    cout << "Enter augmented matrix (coefficients and constants):\n";
    for(int i = 0; i < n; i++)
        for(int j = 0; j <= n; j++)
            cin >> a[i][j];

    // Gauss-Jordan with partial pivoting
    for(int i = 0; i < n; i++) {
        // Partial Pivoting
        int maxRow = i;
        for(int k = i+1; k < n; k++)
            if(fabs(a[k][i]) > fabs(a[maxRow][i]))
                maxRow = k;
        if(maxRow != i)
            for(int j = 0; j <= n; j++)
                swap(a[i][j], a[maxRow][j]);

        // Normalize pivot row
        double pivotVal = a[i][i];
        for(int k = 0; k <= n; k++)
            a[i][k] /= pivotVal;

        // Eliminate other rows
        for(int j = 0; j < n; j++) {
            if(j != i) {
                double factor = a[j][i];
                for(int k = 0; k <= n; k++)
                    a[j][k] -= factor * a[i][k];
            }
        }
    }

    cout<<"Output"<<endl;

    // Print final identity matrix
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            cout << fixed << setprecision(0) << a[i][j] << " ";
        cout << endl;
    }

    // Print solution in one line
    cout << "Solution: ";
    for(int i = 0; i < n; i++)
        cout << fixed << setprecision(0) << a[i][n] << " ";
    cout << endl;

    return 0;
}



