#include<bits/stdc++.h>
using namespace std;
double f(double *a,double x,int n)
{
    double res=0;
    for(int i=0;i<=n;i++)
    {
        res=res*x+a[i];
    }
    return res;
}

double f_der(double *a,double x,int n)
{
    double res=0;
    for(int i=0;i<n;i++)
    {
        res=res*x+(n-i)*a[i];
    }
    return res;
}

int main()
{
    double a[10]={1,-3,-3,11,-6};
    double error,tol=0.000001;
    int degree=4;
    cout<< fixed << setprecision(10);

    // Search Bracket
    double bracket = sqrt(15);
    cout<<"Search Bracket: ["<< -bracket <<", "<< bracket <<"]\n";

    while(degree > 1)
    {
        error=100;
        double x0 = bracket;   // initial guess
        double x1 ;
        int iter=1;
        cout<<"\nApplying Newton-Raphson for degree = "<<degree<<endl;
        cout<<"Iter\t x0\t\t f(x0)\t\t f'(x0)\t\t x1\t\t Error\n";
        while(error >= tol)
        {
            double fval= f(a,x0,degree);
            double fdval= f_der(a,x0,degree);
            x1=x0-fval/fdval;
            error =fabs(x1-x0);
            cout<<iter<<"\t"
                <<x0<<"\t"
                <<fval<<"\t"
                <<fdval<<"\t"
                <<x1<<"\t"
                <<error<<endl;
            x0=x1;
            iter++;
        }
        cout<< "\nRoot = " << x1 << endl;

        //Deflation(Synthetic Division)
        double b[10]= {0};
        b[0]=a[0];
        for(int i=1;i<=degree;i++)
        {
            b[i]=b[i-1]*x1+a[i];
        }
        degree--;
        cout<< "Polynomial coefficients for degree = " << degree <<endl;
        for(int i=0;i<=degree;i++)
        {
            cout<< b[i] << "\t";
            a[i]=b[i];
        }
    }
    // Final Root
    //double FRoot= -a[1]/a[0];
    cout<< "\nFinalRoot = " << -a[1]/a[0] <<endl;
    return 0;
}
