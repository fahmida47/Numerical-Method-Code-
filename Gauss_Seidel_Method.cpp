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
#include <cmath>
#include <iomanip>
using namespace std;

bool checkDiagonalDominance(double a[20][21], int n)
{
    bool dominant = true;

    for(int i=0;i<n;i++)
    {
        double sum = 0;

        for(int j=0;j<n;j++)
        {
            if(i!=j)
                sum += fabs(a[i][j]);
        }

        cout<<"(a["<<i<<"]["<<i<<"]) = "<<a[i][i]
            <<", Sum of other coefficients = "<<sum;

        if(fabs(a[i][i]) >= sum)
            cout<<" -> dominant"<<endl;
        else
        {
            cout<<" -> not dominant"<<endl;
            dominant=false;
        }
    }

    return dominant;
}

int main()
{
    int n,i,j,iter=0;
    double a[20][21],x[20]={0};
    double temp,maxError,error,sum;
    double allowed_error=0.00001;

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
        cin>>a[i][n];
    }

    cout<<fixed<<setprecision(6);

    // Check diagonal dominance
    checkDiagonalDominance(a,n);

    cout<<"\nApplying Gauss Seidel Method we get:\n";

    do
    {
        maxError = 0;
        iter++;

        for(i=0;i<n;i++)
        {
            sum=0;

            for(j=0;j<n;j++)
            {
                if(j!=i)
                    sum += a[i][j]*x[j];
            }

            temp = (a[i][n]-sum)/a[i][i];

            error = fabs(temp-x[i]);

            if(error>maxError)
                maxError=error;

            x[i]=temp;
        }

        cout<<"Iter = "<<iter<<" ";

        for(i=0;i<n;i++)
        {
            cout<<"x["<<i<<"] = "<<x[i]<<" ";
        }

        cout<<"Maximum Error = "<<maxError<<endl;

    }while(maxError > allowed_error);

    cout<<"\nFinal Solution:\n";

    for(i=0;i<n;i++)
    {
        cout<<"x["<<i<<"] = "<<x[i]<<endl;
    }

    return 0;
}
