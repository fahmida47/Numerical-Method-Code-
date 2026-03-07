Topics
1. Basic Code
2. Add Iteration Part
3. Add error and find Sum of other 

//---------------------------START--------------------------//

Topic-01
Basic Code
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n, i, j;
    double a[20][20], x[20], temp, sum;
    double error, temperror, allowed_error;

    cout << "Enter order of matrix: ";
    cin >> n;

    cout << "Enter coefficients of matrix A:" << endl;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }

    cout << "Enter vector b:" << endl;
    for (i = 1; i <= n; i++)
    {
        cin >> a[i][n + 1];
    }

    cout << "Enter allowed error: ";
    cin >> allowed_error;

    // Initial guess
    for (i = 1; i <= n; i++)
    {
        x[i] = 0;
    }

    // Gauss Seidel Iteration
    do
    {
        temperror = 0;

        for (i = 1; i <= n; i++)
        {
            sum = 0;

            for (j = 1; j <= n; j++)
            {
                if (j != i)
                {
                    sum = sum + a[i][j] * x[j];
                }
            }

            temp = (a[i][n + 1] - sum) / a[i][i];

            error = fabs(x[i] - temp);

            if (error > temperror)
            {
                temperror = error;
            }

            x[i] = temp;
        }

    } while (temperror >= allowed_error);

    cout << "\nSolution:\n";
    for (i = 1; i <= n; i++)
    {
        cout << "x[" << i << "] = " << x[i] << endl;
    }

    return 0;
}

Topic-02
Add Iteration
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    int n, i, j, iter = 0;
    double a[20][20], x[20], temp, sum;
    double error, temperror;

    cout << "Enter order of matrix: ";
    cin >> n;

    cout << "Enter coefficients of matrix A:" << endl;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }

    cout << "Enter vector b:" << endl;
    for (i = 1; i <= n; i++)
    {
        cin >> a[i][n + 1];
    }

    // Initial guess
    for (i = 1; i <= n; i++)
    {
        x[i] = 0;
    }

    cout << fixed << setprecision(6);

    // Gauss Seidel Iteration (11 iterations only)
    do
    {
        temperror = 0;
        iter++;

        for (i = 1; i <= n; i++)
        {
            sum = 0;

            for (j = 1; j <= n; j++)
            {
                if (j != i)
                {
                    sum = sum + a[i][j] * x[j];
                }
            }

            temp = (a[i][n + 1] - sum) / a[i][i];

            error = fabs(x[i] - temp);

            if (error > temperror)
            {
                temperror = error;
            }

            x[i] = temp;
        }

        cout << "Iter = " << iter << "   ";
        for (i = 1; i <= n; i++)
        {
            cout << x[i] << "   ";
        }
        cout << endl;

    } while (iter < 11);

    cout << "\nFinal Solution:\n";
    for (i = 1; i <= n; i++)
    {
        cout << "x[" << i << "] = " << x[i] << endl;
    }

    return 0;
}


Topic-03
Add Error and  find Sum of other Coefficient
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
    vector<double> b(n), x(n);
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

    // Initial guess x[i] = 0
    for (int i = 0; i < n; i++)
        x[i] = 0;

    cout << "\nChecking Diagonal Dominance:\n";
    checkDiagonalDominance(a);

    cout << "\nApplying Gauss Seidel Method we get:\n";

    int iter = 0;
    double maxError;

    do {
        maxError = 0;
        iter++;

        for (int i = 0; i < n; i++) {

            double sum = 0;

            for (int j = 0; j < n; j++)
                if (i != j)
                    sum += a[i][j] * x[j];

            double temp = (b[i] - sum) / a[i][i];

            double err = fabs(temp - x[i]);

            if (err > maxError)
                maxError = err;

            x[i] = temp;   // immediate update (Gauss-Seidel)
        }

        cout << "Iter = " << iter;
        for (int i = 0; i < n; i++)
            cout << " x[" << i << "] = " << fixed << setprecision(6) << x[i];

        cout << " Maximum Error = " << fixed << setprecision(6) << maxError << endl;

    } while (maxError > tol);

    cout << "\nFinal Solution:\n";
    for (int i = 0; i < n; i++)
        cout << "x[" << i << "] = " << fixed << setprecision(6) << x[i] << endl;

    return 0;
}
