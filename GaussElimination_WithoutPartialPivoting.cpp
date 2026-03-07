// Without Partial Pivoting=> no Row swap 	direct elimination  division by zero

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of variables: ";
    cin >> n;

    vector<vector<double>> a(n, vector<double>(n+1));
    vector<double> x(n);

    cout << "Enter augmented matrix row-wise:\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<=n;j++){
            cin>>a[i][j];
        }
    }

    // Forward Elimination (No Pivoting)
    for(int k=0;k<n-1;k++){
        for(int i=k+1;i<n;i++){

            double factor = a[i][k] / a[k][k];

            for(int j=k;j<=n;j++){
                a[i][j] = a[i][j] - factor * a[k][j];
            }
        }
    }

    // Print Upper Triangular Matrix (only coefficient part)
    cout<<"\nUpper Triangular Matrix:\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<fixed<<setprecision(3)<<a[i][j]<<"\t";
        }
        cout<<endl;
    }

    // Back Substitution
    x[n-1] = a[n-1][n] / a[n-1][n-1];

    for(int i=n-2;i>=0;i--){
        double sum = 0;

        for(int j=i+1;j<n;j++){
            sum = sum + a[i][j] * x[j];
        }

        x[i] = (a[i][n] - sum) / a[i][i];
    }

    // Print solution
    cout<<"\nSolution: ";
    for(int i=0;i<n;i++){
        cout<<fixed<<setprecision(6)<<x[i]<<" ";
    }

    cout<<endl;

    return 0;
}
