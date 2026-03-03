#include<bits/stdc++.h>
using namespace std;

//vector<double>coeff={1,1,-2,3};// eta hobe na karon multiplae roots ache
vector<double>coeff={1,-2,-5,6};

//Horner's method apply for polynomial
double f(double x){
    double result=0;
    for(int i=0;i<coeff.size();i++){
        result=result*x+coeff[i];
    }
    return result;
}

int main()
{
    double a=-4,b=4,x0,x1,x2,error,tolerable=0.00001,prev_root,ds=0.1;
    error=100;
    prev_root=a;
    x1=a;
    x2=x1+ds;
    while(x2<=b){
            error=100;
            prev_root=x1;
    if(f(x1)*f(x2)<0)
    {
        while(error>=tolerable)
        {
            x0=(x1+x2)/2;
            error=fabs(x0-prev_root);
            if(f(x0)==0)
            {
                break;
            }
            else if(f(x0)*f(x1)<0)
            {
                x2=x0;
            }
            else
            {
                x1=x0;
            }
            prev_root=x0;
        }
        cout<<" Value of Root= " << x0<<endl;
      }
      x1=x2;
      x2=x1+ds;
    }
}
