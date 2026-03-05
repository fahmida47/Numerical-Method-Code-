#include <iostream>
using namespace std;

int main()
{
    int n;
    float a[20][40], pivot;

    // 2. Read Order of Matrix
    cout << "Enter order of matrix: ";
    cin >> n;

    // 3. Read Matrix A
    cout << "Enter Matrix A:\n";
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin >> a[i][j];
        }
    }

    // 4. Augment Identity Matrix
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j)
                a[i][j+n] = 1;
            else
                a[i][j+n] = 0;
        }
    }

    // 5. Apply Gauss Jordan Elimination
    for(int i=1;i<=n;i++)
    {
        if(a[i][i]==0)
        {
            cout<<"Mathematical Error!";
            return 0;
        }

        for(int j=1;j<=n;j++)
        {
            if(i!=j)
            {
                pivot = a[j][i] / a[i][i];

                for(int k=1;k<=2*n;k++)
                {
                    a[j][k] = a[j][k] - pivot * a[i][k];
                }
            }
        }
    }

    // 6. Convert Principal Diagonal to 1
    for(int i=1;i<=n;i++)
    {
        for(int j=n+1;j<=2*n;j++)
        {
            a[i][j] = a[i][j] / a[i][i];
        }
    }

    // 7. Display Inverse Matrix
    cout<<"\nInverse Matrix:\n";
    for(int i=1;i<=n;i++)
    {
        for(int j=n+1;j<=2*n;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
