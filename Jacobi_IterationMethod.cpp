///Topic-01
// Basic Code
/*#include <iostream>
#include <cmath>
#include <iomanip>  // For setprecision

using namespace std;

int main() {
    int n;
    cout << "Enter the order of the matrix: ";
    cin >> n;

    double a[10][10], b[10], x[10], temp[10];
    double allowed_error;

    cout << "Enter the coefficients of the matrix a[i][j]:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    cout << "Enter the vector b:\n";
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    cout << "Enter allowed error: ";
    cin >> allowed_error;

    // Initial guess x[i] = b[i]/a[i][i]
    for (int i = 0; i < n; i++) {
        x[i] = b[i] / a[i][i];
    }

    double temperror;
    int iteration = 0;
    do {
        temperror = 0.0;
        for (int i = 0; i < n; i++) {
            double sum = 0.0;
            for (int j = 0; j < n; j++) {
                if (j != i) {
                    sum += a[i][j] * x[j];
                }
            }
            temp[i] = (b[i] - sum) / a[i][i];
            double error = fabs(x[i] - temp[i]);
            if (error > temperror)
                temperror = error;
        }

        // Update x with new temp values
        for (int i = 0; i < n; i++)
            x[i] = temp[i];

        iteration++;
        cout << "Iteration " << iteration << ": ";
        for (int i = 0; i < n; i++)
            cout << fixed << setprecision(6) << x[i] << " ";
        cout << endl;

    } while (temperror >= allowed_error);

    cout << "\nSolution after " << iteration << " iterations:\n";
    for (int i = 0; i < n; i++) {
        cout << "x[" << i + 1 << "] = " << fixed << setprecision(6) << x[i] << endl;
    }

    return 0;
}*/
///Topic-02
//Online Question=> 12x+2y+z=30, 3x+15y+4z=40, 2x+3y+20z=50
/*#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int n,i,j,iter;
    double a[20][20], b[20], x[20], temp[20], sum;

    cout<<"Enter order of matrix: ";
    cin>>n;

    cout<<"Enter coefficients of matrix A:\n";
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }

    cout<<"Enter vector b:\n";
    for(i=0;i<n;i++)
    {
        cin>>b[i];
    }

    for(i=0;i<n;i++)
    x[i]=0;

    for(iter=1;iter<=11;iter++)
    {
        for(i=0;i<n;i++)
        {
            sum=0;

            for(j=0;j<n;j++)
            {
                if(j!=i)
                sum=sum+a[i][j]*x[j];
            }

            temp[i]=(b[i]-sum)/a[i][i];
        }

        for(i=0;i<n;i++)
        x[i]=temp[i];

        cout<<"Iteration "<<iter<<": ";

        for(i=0;i<n;i++)
        {
            cout<<"x["<<i<<"]="<<fixed<<setprecision(6)<<x[i]<<" \t\t";
        }

        cout<<endl;
    }

    return 0;
}*/

///Topic-03
//Online Question=>
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

// Function to check diagonal dominance
void checkDiagonalDominance(const vector<vector<double>>& a) {
    int n = a.size();
    for (int i = 0; i < n; i++) {
        double sum = 0;
        for (int j = 0; j < n; j++)
            if (i != j) sum += abs(a[i][j]);
        if (abs(a[i][i]) >= sum)
            cout << "(a[" << i << "][" << i << "]) = " << a[i][i]
                 << ", Sum of other coefficients = " << sum
                 << " -> dominant" << endl;
        else
            cout << "(a[" << i << "][" << i << "]) = " << a[i][i]
                 << ", Sum of other coefficients = " << sum
                 << " -> NOT dominant" << endl;
    }
}

int main() {
    int n;
    cout << "Enter matrix order (n x n): ";
    cin >> n;

    vector<vector<double>> a(n, vector<double>(n));
    vector<double> b(n), x(n), x_new(n);
    double tol;

    cout << "Enter A matrix (" << n << "x" << n << "):\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    cout << "Enter constants vector b:\n";
    for (int i = 0; i < n; i++)
        cin >> b[i];

    cout << "Enter allowed absolute error tolerance: ";
    cin >> tol;

    // Initial guess x[i] = b[i]/a[i][i]
    for (int i = 0; i < n; i++)
        x[i] = b[i]/a[i][i];

    cout << "\nChecking Diagonal Dominance:\n";
    checkDiagonalDominance(a);

    cout << "\nApplying Jacobi Method we get:\n";
    int iter = 1;
    double maxError;
    const int maxIter = 100; // safety limit

    do {
        iter++;
        maxError = 0;

        for (int i = 0; i < n; i++) {
            x_new[i] = b[i];
            for (int j = 0; j < n; j++)
                if (i != j) x_new[i] -= a[i][j]*x[j];
            x_new[i] /= a[i][i];

            double err = fabs(x_new[i]-x[i]);
            if (err > maxError) maxError = err;
        }

        x = x_new;

        // Print iteration exactly like picture
        cout << "Iter = " << iter;
        for (int i = 0; i < n; i++)
            cout << " x[" << i << "] = " << fixed << setprecision(6) << x[i];
        cout << " Maximum Error = " << fixed << setprecision(6) << maxError << endl;

    } while (maxError > tol && iter < maxIter);

    cout << "\nFinal Solution:\n";
    for (int i = 0; i < n; i++)
        cout << "x[" << i << "] = " << fixed << setprecision(6) << x[i] << endl;

    return 0;
}
