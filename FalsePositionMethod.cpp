//------------------------------FALSE POSITION METHOD-------------------------------------------//

#include<bits/stdc++.h>
#include<math.h>
using namespace std;

double f(double x1)
{
    return(x1*x1-5*x1+6);
}

int main()
{
    double a=1.5;
    double b=2.9;
    int i=0;
    double x,error,prev;
    double fa,fb;
    if(f(a)*f(b)>0)
    {
        cout<<"Take Input Again";
    }
    else
    {
         prev = a;   // previous approximation (important!)
        do
        {
            i++;
            x=a - ((b-a) * f(a))/(f(b) - f(a));
            cout<<"x= "<<x<<endl;

            if(f(a)*f(x)<0)
            {
                b=x;
            }
            else
            {
                a=x;
            }
        // Absolute error
                error = abs(x - prev);

        // Store current value for next iteration
                prev = x;
        }
    while(error>=0.001);//Error=abs(x-prev)
    }
    cout<<"Root: \n"<<x;
    return 0;
}



//-----------------ONLINE QUESTION SOLVE------------------//

///QUESTION-01

//Problem Description:
/*A projectile is launched at velocity v = 50ms^-1 to hit a target d = 200 meters away on level
ground. Assuming no air resistance, the horizontal range is given by R(theta) ={v^2/g} * (1 - cos 2 theta) where g = 9.8 ms^-2 .
To find the required launch angle theta(in radian), you need to solve the equation R(theta) = d.
Programming RequirementsMethod:
Write a C/C++ program to find the approximate angle theta using the False Position Method.
Search Interval:
     theta in [17.2 degree, 57.3 degree].
Stopping Criterion:
     Based on the absolute value of the function at theta becoming less than 10^-5 (0.00001).
Output Format:
     Your output should match the provided sample output table.
  Conversion Formula:
      degree = radian *(180/pi) and pi = 3.14159
Special Note:
         For the first iteration, calculate the "previous root" as the lower bound.
Sample Output Data TableThe image displays a table tracking the false position through 17 iterations.
Key columns include:Iter: Iteration number (1 through 17).a / b:
        The lower and upper bounds of the current interval.xθ(rad): The midpoint (calculated root) in radians.f(xθ):
        The value of the function theta= R(theta)-d at the current midpoint.xθ(degree):
        The root converted to degrees.Abs Error: The absolute error or interval width progression.
Final Results from Sample:Final Root (approx): 0.450542 radian} and Final Root (approx): 25.814165 degree*/

#include<bits/stdc++.h>
using namespace std;

//Given that

double v=50.0;
double d=200.0;
double g=9.8;
double pi=3.14159;

// Calculate radians to degree
double  Degree(double rad)
{
    return rad*180.0/pi;
}

double f(double theta)
{
    return (v*v/g)*(sin(2*theta))-d;
}

int main()
{
    double a=0.300196;//convert radian
    double b=1.000073;//convert radian
    double prev=a;
    double x0,absolute_err,interval_width;

    cout<<fixed<<setprecision(6);
    cout << "Iter\t"
     << "a\t\t"
     << "b\t\t"
     << "x0(rad)\t\t"
     << "f(x0)\t\t"
     << "x0(deg)\t\t"
     << "sin(2θ)\t"
     << "Abs Error\t"
     << "Interval Width\n";

     for(int i=1;i<=10;i++)
     {
         x0=a - ((b-a) * f(a))/(f(b) - f(a));
         absolute_err=fabs(x0-prev);
         interval_width=(b-a);

         cout << i << "\t"
               << a << "\t"
               << b << "\t"
               << x0 << "\t"
               << f(x0) << "\t"
               << Degree(x0) << "\t"
               << (sin(2 * x0)) << "\t"
               << absolute_err<< "\t"
               << interval_width << endl;

               if(f(a)*f(x0)<0)
               {
                   b=x0;
               }
               else
               {
                   a=x0;
               }
        prev=x0;
         if (absolute_err < 0.00001)
            break;
     }
    cout<<"\nFinal Root:"<<x0<<" radian"<<endl;
    cout<<"Final Root"<<Degree(x0)<<" degree"<<endl;
}


///QUESTION-02

#include<bits/stdc++.h>
using namespace std;

double f(double w)
{
    return pow(w,4)-1156*pow(w,2)+244036;
}

int main()
{
    double a=15.0;
    double b=17.0;
    double x0,prev,absolute_err;
    prev=a;

     cout<<fixed<<setprecision(6);
     cout << "No|| a || f(a) || b || f(b) || x0 || f(x0) || Absolute Error || Update\n";

    for(int i=1;i<=5;i++)
    {
        x0=a-((b-a)*f(a))/(f(b)-f(a));
        absolute_err=abs(x0-prev);

        cout << i << "|| "
             << a << "|| "
             << f(a) << "|| "
             << b << "|| "
             << f(b) << "|| "
             << x0 << "|| "
             << f(x0) << "|| "
             << absolute_err;

             if (f(a) * f(x0) < 0)
        {
            b = x0;
            cout << "|| b-> x0";
        }
        else
        {
            a = x0;
            cout << "|| a -> x0";
        }
        cout << endl;

             prev=x0;
             if(absolute_err<0.00001)
             {
                 break;
             }
     }
     cout<<"Final Root(approx): "<<x0<<endl;
     return 0;
}

















